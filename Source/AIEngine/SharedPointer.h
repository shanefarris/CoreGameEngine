// Reference counting smart pointer.
#ifndef OPENSTEER_SHAREDPOINTER_H
#define OPENSTEER_SHAREDPOINTER_H

#include <algorithm>
#include <cassert>

namespace Core 
{
namespace AI
{
    /**
     * Helper class for @c SharedPointer.
     */
    struct SharedPointerReferenceCount 
	{
        explicit SharedPointerReferenceCount(): referenceCount_( 1 ) { }
        u32 referenceCount_;
    };
    
    /**
     * Smart pointer implementation using reference counting. Dereferencing is
     * as fast as it can get and might reach the speed of dereferencing raw
     * pointers if a good optimizing compiler is used.
     *
     * Doesn't manage arrays.
     *
     * Isn't designed to be used outside of OpenSteer. Boost library
     * smart pointers are preferable if a solid and platform agnostic 
     * implementation is needed. It should be quite easy to replace this smart
     * pointer with a Boost @c shared_ptr because of many intentional design 
     * parallels.
     *
     * See Andrei Alexandrescu, Modern C++ Design, Addison-Wesley, 2002, 
     * pp. 165--167.
     *
     * See http://Boost.org shared_ptr 
     * ( http://www.boost.org/libs/smart_ptr/shared_ptr.htm ).
     *
     * @attention Beware of cycles of smart pointers as these will lead to 
     * memory leaks.
     */
    template< typename T > class SharedPointer 
	{
    public:
        typedef u32 u32;
        typedef T value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef value_type* pointer;
        typedef value_type const* const_pointer;
        
        template< typename U > friend class SharedPointer;
        
        
        /**
         * Constructs an empty @c SharedPointer. The use count is unspecified.
         *
         * @post <code>get() == 0</code>
         *
         * @throw @c std::bad_alloc if memory could not be obtained.
         */
        SharedPointer() : data_( 0 ), referenceCount_( new SharedPointerReferenceCount() ) { }
        
        /**
         * Constructs a @c SharedPointer that owns the pointer @a _data.
         *
         * @post <code> use_count() == 1 </code> and <code>get() == _data )</code>
         *
         * @throw @c std::bad_alloc if memory could not be obtained.
         */
        explicit SharedPointer( T* _data ) : data_( _data ), referenceCount_( new SharedPointerReferenceCount() ) { }
        
        /**
         * Constructs a @c SharedPointer that shares ownership with @a other.
         *
         * @post <code>get() == other.get()</code> and 
         *       <code>useCount() == other.useCount()</code>
         *
         * @throw Nothing.
         */
        SharedPointer( SharedPointer const& other ) : data_( other.data_ ), referenceCount_( other.referenceCount_ ) 
		{
            retain();
        }
        
        /**
         * Constructs a @c SharedPointer that shares ownership with @a other.
         * A pointer of type @c U must be assignable to a pointer of type @c T.
         *
         * @post <code>get() == other.get()</code> and 
         *       <code>useCount() == other.useCount()</code>
         *
         * @throw Nothing. 
         */
        template< typename U >
        SharedPointer( SharedPointer< U > const& other ) : data_( other.data_ ), referenceCount_( other.referenceCount_ ) 
		{
            retain();
        }
        
        /**
         * Decreases the use count by one. If the use count hits @c 0 the 
         * managed pointer is deleted.
         *
         * @throw Might throw an exception if the destructor of the managed 
         *        pointer throws an exception if called.
         */
        ~SharedPointer() 
		{
            release();
        }
        
        /**
         * Shares the ownership of the pointer managed by @a other with @a other.
         * The old managed pointer is deleted if ownership decreases to @c 0.
         *
         * @throw Nothing.
         */
        SharedPointer& operator=( SharedPointer other ) 
		{
            swap( other );
            return *this;
        }
        
        /**
         * Swaps the managed data and the ownership of it with @a other.
         *
         * @throw Nothing.
         */
        void swap( SharedPointer& other )
		{
            std::swap( data_, other.data_ );
            std::swap( referenceCount_, other.referenceCount_ );
        }
        
        reference operator*() const 
		{
            assert( 0 != data_ && "Unable to dereference a 0-pointer." );
            return *data_;
        }
        
        pointer operator->() const 
		{
            assert( 0 != data_ && "Unable to dereference a 0-pointer." );
            return data_;
        }
        
        u32 useCount() const 
		{
            return referenceCount_->referenceCount_;
        }
        
        /**
         * Get direct control of the raw managed pointer.
         *
         * @attention Don't delete the pointer behind the back of the smart
         *            pointer because this leads to undefined behavior.
         *
         * @attention Don't put the pointer under the management of this or
         *            another smart pointer!
         */
        pointer get() const 
		{
            return data_;
        }
        
        /**
         * Sets a new pointer to be managed by the smart pointer.
         *
         * @attention Don't add a pointer that is already managed by another
         *            smart pointer. Otherwise behavior is undefined.
         */
        void reset( T* _data = 0 ) 
		{
            SharedPointer( _data ).swap( *this );
        }
        

        /**
         * See http://Boost.org shared_ptr 
         * ( http://www.boost.org/libs/smart_ptr/shared_ptr.htm ).
         */
        typedef T* (SharedPointer::*unspecified_bool_type)() const;
        
        /**
         * Automatic cast operator to enable use of a smart pointer inside a
         * conditional, for example to test if the smart pointer manages a @c 0
         * pointer.
         *
         * See http://Boost.org shared_ptr 
         * ( http://www.boost.org/libs/smart_ptr/shared_ptr.htm ).
         */
        operator unspecified_bool_type () const 
		{
            return 0 == data_ ? 0 : &SharedPointer::get;
        }

        template< typename U > bool operator<( SharedPointer< U > const& rhs )
		{
            // Because of sub-typing two different pointers might
            // nonetheless point to the same class instance. Therefore use
            // the reference count pointer for comparisons.
            return referenceCount_ < rhs.referenceCount_;
        }

    private:
        
        /**
         * Decreases the reference count of the managed pointer. If the 
         * reference count reaches @c 0 the managed pointer is deleted, too.
         * 
         * @attention @c release and @c retain are used internally and only
         *            public to allow developers to gain more control over
         *            the smart pointer. But beware, if release is called and
         *            the managed pointer is destroyed further calls to the 
         *            dereference operators or even the destructor show
         *            undefined behavior and might crash the application.
         */
        void release() 
		{
            assert( 0 < referenceCount_->referenceCount_ && "Only call release for reference counts greater than 0." );
            
            --( referenceCount_->referenceCount_ );
            if ( 0 == referenceCount_->referenceCount_ )
			{
                delete data_;
                data_ = 0;
                delete referenceCount_;
                referenceCount_ = 0;
            }
        }
        
        /**
         * Increases the reference count for the managed pointer.
         *
         * Mostly used internally, therefor beware of wrong usage that might
         * lead to memory leaks.
         */
        void retain() 
		{
            ++( referenceCount_->referenceCount_ );
        }
        
        
    private:
        pointer data_;
        SharedPointerReferenceCount* referenceCount_;

    }; // class SharedPointer
    

    template< typename T, typename U > bool operator==( SharedPointer< T > const& lhs, SharedPointer< U > const& rhs ) 
	{
        return lhs.get() == rhs.get();
    }
    
    template< typename T, typename U > bool operator!=( SharedPointer< T > const& lhs, SharedPointer< U > const& rhs ) 
	{
        return !( lhs == rhs );
    }
    
    template< typename T > void swap( SharedPointer< T >& lhs, SharedPointer< T >& rhs ) 
	{
        lhs.swap( rhs );
    }
    
}
}

#endif // OPENSTEER_SHAREDPOINTER_H


## Building Core: ##

### Overview: ###
This is an overview of the steps required for building Core from scratch.  For 99% of the time you build Core from scratch, you should only need to worry about the *repositories* section, and the *dependency* section.  This will cover most of the cases.  The rest of this wiki is more notes and past pitfalls that have been discovered.

(((Note: Currently the obj, dll, and lib files for both x64 and x86 output to the same directory.  If you are switching to and from 64 and 86, you will need to do a rebuild so it won't try and inter-link obj and lib files.)))

### Steps: ###

#### Dependencies: ####
* Ogre: This will need to be built first.
* Second, build the following library and ensure the output is in the Libs directory:
* **Hydrax**
* The solution is in the engine repository.
* The solution is in the dependencies repository.
* Should only need OgreMain.
* *ScriptEngine* (Lua)
* The solution is in the dependencies repository.
* **Ode** (ode_single, and optional if you are not using the Ode plugin)
* **Caelum**
* The solution is in the engine repository.
* Should only need OgreMain.
* **MyGUI**
* freetype2411.lib, freetype2411_D.lib
* MyGUIEngine
* MyGUI.OgrePlatform
* The solution is in the dependencies repository.
* **GUIlib-1.2.1** (Optional)
* The solution is in the dependencies repository.* 
* **RakNet** (Option based on config settings in FpsFramework)
* The solution is in the dependencies repository.

### Building Ogre: ###
Few notes on building Ogre from scratch:
* You can set boost and Ogre dependency directories to the core dependency root directory, it will recursively search.
* Ensure threading and boost are set and found.
* Replace the Vector3 class [^Custom Ogre Vector3 class|here]
* zziplib is required for zips.  zlib is a dependency of zziplib, so you need both.  zlib will allow you to use gz files.
** In zziplib, you need to change line 46 of plugin.c

#### Windows: ####

```C++
static const struct zzip_plugin_io default_io # {
	&open,
	&close,
	&_zzip_read,
	&_zzip_lseek,
	&zzip_filesize,
	1, 1,
	&_zzip_write
};

// TO

static const struct zzip_plugin_io default_io # {
	&_open,
	&_close,
	&_zzip_read,
	&_zzip_lseek,
	&zzip_filesize,
	1, 1,
	&_zzip_write
};
```

#### Linux (CentOS 6.3): ####
Building libjpeg, you need to modify the Makefile if this is built in 64-bit
** CFLAGS# -02 -fPIC -I$(srcdir)  # you need to add "-fPIC"
Automake is your friend and far faster then creating a project in code::blocks.
** libMNG should be made in code::blocks.

##### Installing OpenGL: #####
OpenGL is a pain to install, so don't if you don't need to.  After installing all dev libraries under the filter of "mesa", cmake was able to find opengl, but this is how far I got before I tried yum (for the 3rd time).
* Download source: ftp.freedesktop.org/pub/mesa/
**Dependencies:**
* makedepend: https://xorg.freedesktop.org/releases/individual/util
* yum install flex bison imake libtool xorg-x11-proto-devel libdrm-devel gcc-c++ xorg-xll-server-devel libXi-devel libXmu-devel libXdamage-devel git expat-devel llvm-devel
* talloc: www.linuxfromscratch.org/blfs/view/svn/general/talloc.html: automake

(((Note: Make sure GLUT libraries are installed as well.)))

##### Installing GCC 4.7.1: #####
Dependencies:
* GMP: gmplib.org (ftp://ftp.gnu.org/gnu/gmp)
* MPFR: mpfr.ogr/mpfr-current/
* MPC: Make sure you install 0.8.2 multiprecision.org
* Cloog: ftp://ftp.gnu.org/gnu/gmp
* ISL: ftp://gcc.gnu.org/pub/gcc/infrastructure/
Possible Errors:
* "canot compute suffix of object files"
* While building , add gmp and mpfr installation path in LD_LIBRARY_PATH environment variable. Do as follows
```
export LD_LIBRARY_PATH#/usr/local/gmp-4.1.3/lib:/usr/local/mpfr-2.3.2/lib:$LD_LIBRARY_PATH
```
* "fatal error: gnu/stubs-32.h: No such file or directory"
* You're missing the 32 bit libc dev package:
* Ubuntu it's called libc6-dev-i386 - do sudo apt-get install libc6-dev-i386
* Red Hat distros, the package name is glibc-devel.i686 (Thanks to David Gardner's comment)
* CentOS 5.8, the package name is glibc-devel.i386 (Thanks to JimKleck's comment)
* CentOS 6.3, the package name is glibc-devel.i686.
* SLES it's called glibc-devel-32bit - do zypper in glibc-devel-32bit


##### Tips: #####
Here are a few tips that you can use, but might not be required.
**Adding new repositories to yum:**
* EPEL is an enterprise level database (found clang in it)
* rpm -Uvh http://download.fedoraproject.org/pub/epel/5/i386/epel-release-5-4.noarch.rpm
* CentOS Plus: additional packages
* vi /etc/yum.repos.d/CentOS-Base.repo
* Under centosplus check enable#1

##### CMake: #####
* You can install cmake using automake
* cd ogre ; mkdir build ; cd build ; cmake ..
* This creates the make file, so you are ready to build.

(((Note: If you manually add features to Ogre, remember to ensure the cpp file is included in the Ogre project.)))

#### 64 Bit: ####
**Building Boost:**
```
b2 toolset#msvc-11.0 --build-type#complete --with-date_time --with-thread --with-chrono address-model#64
// --with-regex if you want HTTP support (need OpenSSL if you want HTTPS support)
```

* Building ODE:
```
premake4.exe --only-static --os-windows --platform#x64 vs2008
```

Use **--DBOOST_ALL_NO_LIB** if you want to specify linking boost manually.

* Precompiled Dependencies:
[http://www.ogre3d.org/forums/viewtopic.php?f#4&t#69274]


##### Notes: #####
Make sure all your dependencies are 64 bit as well and built with VS2012 compiler (when on Windows).
### Notes: ###
#### ScriptEngine (Lua): ####
To build Lua yourself in VS you need three projects:
* library - this should be either DLL or static library project. Should include every .c file under src/ except luac.c and lua.c. You only need this if you are embedding.
* Compiler - console executable, containing luac.c
* Interpreter - console executable, containing lua.c

#### Assimp: ####
In cmake, the zlib.lib file needs to be specified, not the directory location.  The boost include directory is required, not the library.  The assimp library is created in the build/code/ directory (weird), the INSTALL project doesn't actually install anything.  Cmake for OgreAssimp is a joke, just create your own project, add assimpd.lib, ogremain_d.lib, add ogre_includes, core_includes, and assimp includes.

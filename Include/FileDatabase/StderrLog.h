#ifndef _STDERRLOG_H_SQLITE
#define _STDERRLOG_H_SQLITE

#ifdef WIN32
#ifdef CORE_DLL
	#define CORE_EXPORT __declspec(dllexport)
#else
	#define CORE_EXPORT __declspec(dllimport)
#endif
#endif

#ifdef SQLITEW_NAMESPACE
namespace SQLITEW_NAMESPACE {
#endif

/** Log class writing to standard error. */
class CORE_EXPORT StderrLog : public IError
{
public:
	void error(Database&,const std::string&);
	void error(Database&,Query&,const std::string&);

};



#ifdef SQLITEW_NAMESPACE
} // namespace SQLITEW_NAMESPACE {
#endif

#endif // _STDERRLOG_H

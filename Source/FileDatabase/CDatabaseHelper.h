#ifndef _CppSQLite3_H_
#define _CppSQLite3_H_

#include "sqlite3.h"
#include <cstdio>
#include <cstring>

#define CPPSQLITE_ERROR 1000

class CSQLite3Exception
{
public:
    CSQLite3Exception(const int nErrCode,
                    char* szErrMess,
                    bool bDeleteMsg=true);
    CSQLite3Exception(const CSQLite3Exception&  e);
    virtual ~CSQLite3Exception();
    const int errorCode() { return mnErrCode; }
    const char* errorMessage() { return mpszErrMess; }
    static const char* errorCodeAsString(int nErrCode);

private:
    int mnErrCode;
    char* mpszErrMess;
};

class CSQLite3Buffer
{
public:
    CSQLite3Buffer();
    ~CSQLite3Buffer();
    const char* format(const char* szFormat, ...);
    operator const char*() { return mpBuf; }
    void clear();

private:

    char* mpBuf;
};


class CSQLite3Binary
{
public:
    CSQLite3Binary();
    ~CSQLite3Binary();
    void setBinary(const unsigned char* pBuf, int nLen);
    void setEncoded(const unsigned char* pBuf);

    const unsigned char* getEncoded();
    const unsigned char* getBinary();

    int getBinaryLength();
    unsigned char* allocBuffer(int nLen);
    void clear();

private:
    unsigned char* mpBuf;
    int mnBinaryLen;
    int mnBufferLen;
    int mnEncodedLen;
    bool mbEncoded;
};


class CSQLite3Query
{
public:
    CSQLite3Query();
    CSQLite3Query(const CSQLite3Query& rQuery);
    CSQLite3Query(sqlite3* pDB, sqlite3_stmt* pVM, bool bEof, bool bOwnVM=true);
    CSQLite3Query& operator=(const CSQLite3Query& rQuery);
    virtual ~CSQLite3Query();

    int numFields();

    int fieldIndex(const char* szField);
    const char* fieldName(int nCol);

    const char* fieldDeclType(int nCol);
    int fieldDataType(int nCol);

    const char* fieldValue(int nField);
    const char* fieldValue(const char* szField);

    int getIntField(int nField, int nNullValue=0);
    int getIntField(const char* szField, int nNullValue=0);

    double getFloatField(int nField, double fNullValue=0.0);
    double getFloatField(const char* szField, double fNullValue=0.0);

    const char* getStringField(int nField, const char* szNullValue="");
    const char* getStringField(const char* szField, const char* szNullValue="");

    const unsigned char* getBlobField(int nField, int& nLen);
    const unsigned char* getBlobField(const char* szField, int& nLen);

    bool fieldIsNull(int nField);
    bool fieldIsNull(const char* szField);

    bool eof();
    void nextRow();
    void finalize();

private:
    void checkVM();

	sqlite3* mpDB;
    sqlite3_stmt* mpVM;
    bool mbEof;
    int mnCols;
    bool mbOwnVM;
};


class CSQLite3Table
{
public:
    CSQLite3Table();
    CSQLite3Table(const CSQLite3Table& rTable);
    CSQLite3Table(char** paszResults, int nRows, int nCols);
    virtual ~CSQLite3Table();
    CSQLite3Table& operator=(const CSQLite3Table& rTable);

    int numFields();
    int numRows();

    const char* fieldName(int nCol);
    const char* fieldValue(int nField);
    const char* fieldValue(const char* szField);

    int getIntField(int nField, int nNullValue=0);
    int getIntField(const char* szField, int nNullValue=0);

    double getFloatField(int nField, double fNullValue=0.0);
    double getFloatField(const char* szField, double fNullValue=0.0);

    const char* getStringField(int nField, const char* szNullValue="");
    const char* getStringField(const char* szField, const char* szNullValue="");

    bool fieldIsNull(int nField);
    bool fieldIsNull(const char* szField);

    void setRow(int nRow);

    void finalize();

private:
    void checkResults();

    int mnCols;
    int mnRows;
    int mnCurrentRow;
    char** mpaszResults;
};


class CSQLite3Statement
{
public:
    CSQLite3Statement();
    CSQLite3Statement(const CSQLite3Statement& rStatement);
    CSQLite3Statement(sqlite3* pDB, sqlite3_stmt* pVM);
    virtual ~CSQLite3Statement();
    CSQLite3Statement& operator=(const CSQLite3Statement& rStatement);
    int execDML();
    CSQLite3Query execQuery();

    void bind(int nParam, const char* szValue);
    void bind(int nParam, const int nValue);
    void bind(int nParam, const double dwValue);
    void bind(int nParam, const unsigned char* blobValue, int nLen);
    void bindNull(int nParam);

    void reset();
    void finalize();

private:
    void checkDB();
    void checkVM();

    sqlite3* mpDB;
    sqlite3_stmt* mpVM;
};

class CSQLite3DB
{
public:
    CSQLite3DB();
    virtual ~CSQLite3DB();
    void open(const char* szFile);
    void close();
	bool tableExists(const char* szTable);
    int execDML(const char* szSQL);
    CSQLite3Query execQuery(const char* szSQL);
    int execScalar(const char* szSQL);
    CSQLite3Table getTable(const char* szSQL);
    CSQLite3Statement compileStatement(const char* szSQL);
    sqlite_int64 lastRowId();
    void interrupt() { sqlite3_interrupt(mpDB); }
    void setBusyTimeout(int nMillisecs);
    static const char* SQLiteVersion() { return SQLITE_VERSION; }

private:
    CSQLite3DB(const CSQLite3DB& db);
    CSQLite3DB& operator=(const CSQLite3DB& db);

    sqlite3_stmt* compile(const char* szSQL);

    void checkDB();

    sqlite3* mpDB;
    int mnBusyTimeoutMs;
};

#endif

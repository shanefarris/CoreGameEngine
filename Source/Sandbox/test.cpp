#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <string>

#include "IO/CFileSystem.h"
#include "IO/CWriteFile.h"

using namespace std;

void show_error(unsigned int handletype, const SQLHANDLE& handle)
{
	SQLCHAR sqlstate[1024];
	SQLCHAR message[1024];
	if(SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
		cout<<"Message: "<<message<<"\nSQLSTATE: "<<sqlstate<<endl;
}

int main()
{
	string fileName;
	string material;
	SQLHANDLE sqlenvhandle;    
	SQLHANDLE sqlconnectionhandle;
	SQLHANDLE sqlstatementhandle;
	SQLRETURN retcode;

	do
	{
		if(SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			break;

		if(SQL_SUCCESS != SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) 
			break;

		if(SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			break;

		SQLCHAR retconstring[1024];
		switch(SQLDriverConnect (sqlconnectionhandle, NULL, 
			(SQLCHAR*)"DRIVER={SQL Server};SERVER=localhost,1433;DATABASE=AssetManager;UID=sa;PWD=t00lb0x;", 
			SQL_NTS, retconstring, 1024, NULL,SQL_DRIVER_NOPROMPT))
		{
		case SQL_SUCCESS_WITH_INFO:
			show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
			break;
		case SQL_INVALID_HANDLE:
		case SQL_ERROR:
			show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
			retcode = -1;
			break;
		default:
			break;
		}

		if(retcode == -1)
			break;

		if(SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			break;

		if(SQL_SUCCESS != SQLExecDirect(sqlstatementhandle, (SQLCHAR*)"select data, filename from asset where name = 'mat_ammo_box_5_1' and assettypeid = 1", SQL_NTS))
		{
			show_error(SQL_HANDLE_STMT, sqlstatementhandle);
			break;
		}
		else
		{
			while (SQLFetch(sqlstatementhandle) != SQL_NO_DATA) 
			{
				const int SIZE = 512;
				char name[SIZE] = {0};
				SQLINTEGER BinaryLenOrInd;
				while(SQLGetData(sqlstatementhandle, 1, SQL_BINARY, name, SIZE, &BinaryLenOrInd) != SQL_NO_DATA)
				{
					std::string temp(name);
					material += temp.substr(0, SIZE < BinaryLenOrInd ? SIZE : BinaryLenOrInd);
				}
				cout << material << endl;

				char file[255];
				SQLGetData(sqlstatementhandle, 2, SQL_CHAR, file, 255, nullptr);
				fileName = file;
			}
		}
	}
	while(FALSE);

	SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
	SQLDisconnect(sqlconnectionhandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

	fileName = "../../Media/" + fileName;
	IO::CFileSystem FileSystem;
	auto write = FileSystem.CreateAndWriteFile(fileName.c_str(), false, false);
	write->Write(material.c_str(), material.length());
	CORE_DELETE(write);
}
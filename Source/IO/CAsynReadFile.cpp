// Added 5-8-08

#include "CAsynReadFile.h"

#include <vector>

using namespace IO;

namespace IO
{
	IReadFile* CreateAsynReadFile(const char* Filename)
	{
		CAsynReadFile* file = new CAsynReadFile(Filename);
		if(file->IsOpen())
			return file;

		return nullptr;
	}
}

CAsynReadFile::CAsynReadFile(const char* Filename) : FileSize(0)
{
	FileName = Filename;
	NumBlocksMask = NumBlocks - 1;
	BlockSize = 131072; //64 * 1024 * 2;	
	
	// Get file size TODO: there may be a better to to get the size 05-22-08
	if(FileName.size() == 0)
	{
		m_File = nullptr;
		return; 
	}
	m_File = fopen(FileName.c_str(), "rb");
	if(m_File)
	{
		fseek(m_File, 0, SEEK_END);
		FileSize = ftell(m_File);
		fseek(m_File, 0, SEEK_SET);
		fclose(m_File);
	}
	else
		return;      
}

CAsynReadFile::~CAsynReadFile()
{
	if(m_File)
		fclose(m_File);
}

s32 CAsynReadFile::Read(void* Buffer)
{
	ReaderPos = 0;
	IOPos = 0;
	Pos = 0;
	WriterPos = 0;

	// VirtualAlloc() creates storage that is page aligned and so is disk sector aligned
	for(int i = 0; i < NumBlocks; i++)
	{			
		m_Blocks[i] = static_cast<char*>(VirtualAlloc(0, BlockSize, MEM_COMMIT, PAGE_READWRITE));
		ZeroMemory(&m_Overlapped[i], sizeof(OVERLAPPED));
		m_Overlapped[i].hEvent = CreateEvent(0, false, false, 0);
	}

	HANDLE hFile  = CreateFile(FileName.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_NO_BUFFERING | 
			FILE_FLAG_OVERLAPPED | FILE_FLAG_SEQUENTIAL_SCAN, 0);

	do		
	{    
		while(WriterPos - ReaderPos != NumBlocks  && IOPos < FileSize)
		{
			m_Overlapped[WriterPos & NumBlocksMask].Offset = IOPos;

			int Left = FileSize - IOPos;
			int BytesToRead = Left > BlockSize ? BlockSize: Left;

			const int MaskedWriterPos = WriterPos & NumBlocksMask;
			if(ReadFile(hFile, m_Blocks[MaskedWriterPos], BytesToRead, 0, &m_Overlapped[MaskedWriterPos]))
			{
				WriterPos++;
				IOPos += BytesToRead;	
			}
		}

		const int MaskedReaderPos = ReaderPos & NumBlocksMask;

		WaitForSingleObject(m_Overlapped[MaskedReaderPos].hEvent, INFINITE);

		int Left = FileSize - Pos;
		int BytesToRead = Left > BlockSize ? BlockSize: Left;		       			
		memcpy((char*)Buffer + Pos, m_Blocks[MaskedReaderPos], BytesToRead);

		ReaderPos++;
		Pos += BytesToRead;

	}
	while(Pos < FileSize);
								
	CloseHandle(hFile);	
	for(int i = 0; i < NumBlocks; i++)
	{							
		if(m_Blocks[i])
			VirtualFree(m_Blocks[i], 0, MEM_RELEASE);
		if(m_Overlapped[i].hEvent)
			CloseHandle(m_Overlapped[i].hEvent);
	}

	return IOPos;
}

s32 CAsynReadFile::Read(void* Buffer, s32 ReadSize)
{
	if(!IsOpen())
		return 0;

	return (s32)fread(Buffer, 1, ReadSize, m_File);
}

bool CAsynReadFile::Seek(s32 FinalPos, bool RelativeMovement)
{
	if(!IsOpen())
		return false;

	return fseek(m_File, FinalPos, RelativeMovement ? SEEK_CUR : SEEK_SET) == 0;
}


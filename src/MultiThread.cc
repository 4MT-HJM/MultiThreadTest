#include "MultiThread.h"
#include <fstream>

#include<iostream>

using namespace std;

FileReadWriter::FileReadWriter(const string p_Filename)
{
	OF1.open(p_Filename, ios::out|ios::trunc);
}

char FileReadWriter::ReadLastLetter()
{
    return lastLetter;
}

void FileReadWriter::WriteLetterToFile(const char letterToWrite)
{
	OF1 << letterToWrite;
	lastLetter = letterToWrite;
}

FileProssor::FileProssor(char p_letterToRead, char p_letterToWrite, FileReadWriter& p_FRW1,FileReadWriter& p_FRW2,FileReadWriter& p_FRW3,FileReadWriter& p_FRW4)
		:FRW1(p_FRW1),FRW2(p_FRW2),FRW3(p_FRW3),FRW4(p_FRW4)
{
   letterToRead = p_letterToRead;
   letterToWrite = p_letterToWrite;

}
void FileProssor::oneloop()
{
	if(FRW1.ReadLastLetter() == letterToRead || (letterToWrite == 'A' && FRW1.ReadLastLetter() == EOF))
	{
		FRW1.WriteLetterToFile(letterToWrite);
		count++;
	}
	if(FRW2.ReadLastLetter() == letterToRead || (letterToWrite == 'B' && FRW2.ReadLastLetter() == EOF))
	{
		FRW2.WriteLetterToFile(letterToWrite);
		count++;
	}
	if(FRW3.ReadLastLetter() == letterToRead || (letterToWrite == 'C' && FRW3.ReadLastLetter() == EOF))
	{
		FRW3.WriteLetterToFile(letterToWrite);
		count++;
	}
	if(FRW4.ReadLastLetter() == letterToRead || (letterToWrite == 'D' && FRW4.ReadLastLetter() == EOF))
	{
		FRW4.WriteLetterToFile(letterToWrite);
		count++;
	}
}

void FileProssor::startloop()
{
	cout<< "start writing "<< letterToWrite<< endl;
	while(count < 1000)
	{
		oneloop();
	}
}

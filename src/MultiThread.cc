#include "MultiThread.h"
#include <fstream>

#include<iostream>

using namespace std;

FileReadWriter::FileReadWriter(const string p_Filename)
{
	//IF1.open(Filename,ios::in);
	//OF1 = ofstream(Filename, std::ios::ate);
	Filename = p_Filename;
}

char FileReadWriter::ReadLastLetter()
{
   ifstream IF1(Filename);
   char lastLetter = EOF;
   while(!IF1.eof())
   {

	   IF1>>lastLetter;
	  // cout << "read" <<lastLetter<<endl;
   }
   IF1.close();
   return lastLetter;
}

void FileReadWriter::WriteLetterToFile(const char input)
{
	ofstream OF1(Filename,ios::ate);
	OF1 << input;
	OF1.close();
	return;
}

FileProssor::FileProssor(char p_letterToRead, char p_letterToWrite, FileReadWriter& p_FRW1,FileReadWriter& p_FRW2,FileReadWriter& p_FRW3,FileReadWriter& p_FRW4)
		:FRW1(p_FRW1),FRW2(p_FRW2),FRW3(p_FRW3),FRW4(p_FRW4)
{
   letterToRead = p_letterToRead;
   letterToWrite = p_letterToWrite;

}
void FileProssor::oneloop()
{
	if(FRW1.ReadLastLetter() == letterToRead)FRW1.WriteLetterToFile(letterToWrite);
	if(FRW2.ReadLastLetter() == letterToRead)FRW2.WriteLetterToFile(letterToWrite);
	if(FRW3.ReadLastLetter() == letterToRead)FRW3.WriteLetterToFile(letterToWrite);
	if(FRW4.ReadLastLetter() == letterToRead)FRW4.WriteLetterToFile(letterToWrite);
}

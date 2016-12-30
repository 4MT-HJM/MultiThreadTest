
#include <string>
#include <fstream>
using namespace std;
class FileReadWriter
{

public:
	FileReadWriter(const string );
	virtual char ReadLastLetter();
	virtual void WriteLetterToFile(const char);

private:
	//fstream IF1;
	//ofstream OF1;
	string Filename;
};

class FileProssor
{
public:
	FileProssor(char,char, FileReadWriter&,FileReadWriter&,FileReadWriter&,FileReadWriter&);
	void oneloop();
private:
	FileReadWriter& FRW1;
	FileReadWriter& FRW2;
	FileReadWriter& FRW3;
	FileReadWriter& FRW4;
	char letterToRead;
	char letterToWrite;
};


#include <string>
#include <fstream>
using namespace std;

class IFileReadWriter
{
public:
	IFileReadWriter() = default;
	virtual char ReadLastLetter() = 0;
	virtual void WriteLetterToFile(const char) = 0;
	virtual ~IFileReadWriter() = default;
};

class FileReadWriter: public IFileReadWriter
{

public:
	FileReadWriter(const string );
	virtual char ReadLastLetter();
	virtual void WriteLetterToFile(const char);
private:
	ofstream OF1;
	char lastLetter=EOF;
};

class FileProssor
{
public:
	FileProssor(char,char, IFileReadWriter&,IFileReadWriter&,IFileReadWriter&,IFileReadWriter&);
	void oneloop();
	void startloop();
private:
	IFileReadWriter& FRW1;
	IFileReadWriter& FRW2;
	IFileReadWriter& FRW3;
	IFileReadWriter& FRW4;
	char letterToRead;
	char letterToWrite;
	int count = 0;
};

#include "MultiThread.h"

#include <iostream>
#include "gmock/gmock.h"

using namespace std;

//using ::testing;
using ::testing::Return;

class FileReadWriterMock : public FileReadWriter
{
public:
	FileReadWriterMock(const string filename):FileReadWriter(filename){}
	MOCK_METHOD1(WriteLetterToFile,void(const char));
	MOCK_METHOD0(ReadLastLetter,char());
};

TEST(MultiThreadTest,ReadLastLetterOfAFile)
{
	//in A.txt  "ABC"
	FileReadWriter F1("A_UTCase1.txt");
	F1.WriteLetterToFile('A');
	F1.WriteLetterToFile('B');
	F1.WriteLetterToFile('C');
	EXPECT_EQ('C',F1.ReadLastLetter());
	//in B.txt  "AB"
	FileReadWriter F2("B_UTCase1.txt");
	F2.WriteLetterToFile('A');
	F2.WriteLetterToFile('B');
	EXPECT_EQ('B',F2.ReadLastLetter());
}

TEST(MultiThreadTest,ReadEmptyFile)
{
	//in empty file
	FileReadWriter F1("C_UTCase2.txt");
	EXPECT_EQ(EOF, F1.ReadLastLetter());
}

TEST(MultiThreadTest, WriteLettertoFile)
{
	FileReadWriter F1("C_UTCase3.txt");
	F1.ReadLastLetter();
	F1.WriteLetterToFile('C');
	EXPECT_EQ('C', F1.ReadLastLetter());
}

TEST(MultiThreadTest, WriteAIfLastLetterIsD)
{
	FileReadWriterMock F1("A_UTCase5");
	FileReadWriterMock F2("B_UTCase5");
	FileReadWriterMock F3("C_UTCase5");
	FileReadWriterMock F4("D_UTCase5");


	FileProssor Po1('D','A',F1,F2,F3,F4);
	EXPECT_CALL(F1,ReadLastLetter()).WillRepeatedly(Return('D'));
	EXPECT_CALL(F2,ReadLastLetter()).WillRepeatedly(Return('A'));
	EXPECT_CALL(F3,ReadLastLetter()).WillRepeatedly(Return('A'));
	EXPECT_CALL(F4,ReadLastLetter()).WillRepeatedly(Return('A'));
	EXPECT_CALL(F1,WriteLetterToFile('A'));
	Po1.oneloop();
}

TEST(MultiThreadTest, WriteIfFileEmptyAndNameCorrect)
{
	FileReadWriterMock F1("A_UTCase5");
	FileReadWriterMock F2("B_UTCase5");
	FileReadWriterMock F3("C_UTCase5");
	FileReadWriterMock F4("D_UTCase5");
				  
	FileProssor Po1('D','A',F1,F2,F3,F4);
	EXPECT_CALL(F1,ReadLastLetter()).WillRepeatedly(Return(EOF));
 	EXPECT_CALL(F2,ReadLastLetter()).WillRepeatedly(Return(EOF));
    EXPECT_CALL(F3,ReadLastLetter()).WillRepeatedly(Return(EOF));
    EXPECT_CALL(F4,ReadLastLetter()).WillRepeatedly(Return(EOF));
    EXPECT_CALL(F1,WriteLetterToFile('A'));
	Po1.oneloop();
}

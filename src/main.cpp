#include "MultiThread.h"
#include <thread>
#include <string>
int main()
{

	FileReadWriter fw1("A.txt");
	FileReadWriter fw2("B.txt");
	FileReadWriter fw3("C.txt");
	FileReadWriter fw4("D.txt");

	FileProssor fp1('D','A',fw1,fw2,fw3,fw4);
	FileProssor fp2('A','B',fw1,fw2,fw3,fw4);
	FileProssor fp3('B','C',fw1,fw2,fw3,fw4);
	FileProssor fp4('C','D',fw1,fw2,fw3,fw4);

	thread th1(&FileProssor::startloop, &fp1);
	thread th2(&FileProssor::startloop, &fp2);
	thread th3(&FileProssor::startloop, &fp3);
	thread th4(&FileProssor::startloop, &fp4);

	th1.join();
	th2.join();
	th3.join();
	th4.join();

	return 0;
}

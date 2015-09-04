#include <iostream>

#include "converter.h"
#include "hlpr.h"
#include "utest.h"

using namespace og;

int main(int argc, char *argv[])
{
#ifdef  WIN32
	std::locale::global(std::locale("russian_russia.1251"));
#else
	std::locale::global(std::locale("ru_RU.cp1251"));
#endif
	std::cout << std::locale().name() << std::endl;
	//	
	std::cout << "Привет" << std::endl;
	//
	Tests::Cmplx();
	//
	std::string w1;
	std::string w2;
	std::list<TStr> dict;
	//
	try {
		Hlpr::CheckMainArgs(argc, argv);
		Hlpr::mkWords(argv[1], w1, w2);
		Hlpr::mkDict(argv[2], dict);
	}
	catch (const smthBad& e)
	{
		std::cerr << "Program stopped with an error: " << e.what() << std::endl;
		std::cerr << "Error in program usage. The correct usage is:" << std::endl;
		std::cerr << "\t" << argv[0] << " [pathToWords] [pathToDic]" << std::endl;
		std::cerr << "where:" << std::endl;
		std::cerr << "[pathToWords] is full path to the file with source and target words" << std::endl;
		std::cerr << "[pathToDic] is full path to the file with Dictionary" << std::endl;
	}
	catch (const notExist& e)
	{
		std::cerr << "Program stopped with an error: file \"" << e.what() << "\" is not exist" << std::endl;
		std::cerr << "Please, check correctness of file path " << std::endl;
	}
	//
	Converter Conv(dict);
	std::vector<TStr> result;
	result = Conv.Do_(w1, w2);
	//
	const bool predNO = result.empty();
	if (predNO)
	{
		std::cout << "NOT found yet" << std::endl;
	} 
	else
	{
		for (const auto&word : result)
		{
			std::cout << word << std::endl;
		}
	}
	//
	return 0;
}

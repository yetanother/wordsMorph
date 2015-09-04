#include "utest.h"

namespace og
{

void Tests::Cmplx()
{
	using namespace std;
	//
	{
		std::string w1 = "";
		std::string w2 = "";
		std::list<TStr> dict;
		std::vector<std::string> result;
		Tests::test(w1, w2, dict, result, "Ïóñòûå ñëîâà");
	}

	{
		std::string w1 = "ÌÓÕÀ";
		std::string w2 = "ÑËÎÍ";
		std::list<TStr> dict;
		std::vector<std::string> result;
		Tests::test(w1, w2, dict, result, "Ïóñòîé ñëîâàğü");
	}

	{
		std::string w1 = "ÌÓÕÀ";
		std::string w2 = "ÌÓÕÀ";
		std::list<TStr> dict;
		std::vector<std::string> result;
		result.push_back("ÌÓÕÀ");
		Tests::test(w1, w2, dict, result, "Îäèíàêîâûå ñëîâà");
	}

	{
		std::string w1 = "ÊÎÒ";
		std::string w2 = "ÒÎÍ";
		std::list<TStr> dict;
		dict.push_back("ÊÎÒ");
		dict.push_back("ÒÎÍ");
		dict.push_back("ÍÎÒÀ");
		dict.push_back("ÊÎÒÛ");
		dict.push_back("ĞÎÒ");
		dict.push_back("ĞÎÒÀ");
		dict.push_back("ÒÎÒ");
		std::vector<std::string> result;
		result.push_back("ÊÎÒ");
		result.push_back("ÒÎÒ");
		result.push_back("ÒÎÍ");
		Tests::test(w1, w2, dict, result, "ÊÎÒ-ÒÎÍ");
	}

	{
		std::string w1 = "ÊÎÒ";
		std::string w2 = "ÊÎÒÛ";
		std::list<TStr> dict;
		dict.push_back("ÊÎÒ");
		dict.push_back("ÒÎÍ");
		dict.push_back("ÍÎÒÀ");
		dict.push_back("ÊÎÒÛ");
		dict.push_back("ĞÎÒ");
		dict.push_back("ĞÎÒÀ");
		dict.push_back("ÒÎÒ");
		std::vector<std::string> result;
		Tests::test(w1, w2, dict, result, "ÊÎÒ-ÊÎÒÛ");
	}
}

}

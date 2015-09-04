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
		Tests::test(w1, w2, dict, result, "������ �����");
	}

	{
		std::string w1 = "����";
		std::string w2 = "����";
		std::list<TStr> dict;
		std::vector<std::string> result;
		Tests::test(w1, w2, dict, result, "������ �������");
	}

	{
		std::string w1 = "����";
		std::string w2 = "����";
		std::list<TStr> dict;
		std::vector<std::string> result;
		result.push_back("����");
		Tests::test(w1, w2, dict, result, "���������� �����");
	}

	{
		std::string w1 = "���";
		std::string w2 = "���";
		std::list<TStr> dict;
		dict.push_back("���");
		dict.push_back("���");
		dict.push_back("����");
		dict.push_back("����");
		dict.push_back("���");
		dict.push_back("����");
		dict.push_back("���");
		std::vector<std::string> result;
		result.push_back("���");
		result.push_back("���");
		result.push_back("���");
		Tests::test(w1, w2, dict, result, "���-���");
	}

	{
		std::string w1 = "���";
		std::string w2 = "����";
		std::list<TStr> dict;
		dict.push_back("���");
		dict.push_back("���");
		dict.push_back("����");
		dict.push_back("����");
		dict.push_back("���");
		dict.push_back("����");
		dict.push_back("���");
		std::vector<std::string> result;
		Tests::test(w1, w2, dict, result, "���-����");
	}
}

}

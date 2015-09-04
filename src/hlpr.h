#pragma once

#include <stdexcept>
#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <list>
#include <vector>


namespace og
{

class smthBad : public std::runtime_error
{
public:
	smthBad(const TStr& whatUsage)
		: runtime_error(whatUsage)
	{}

};

class notExist : public std::runtime_error
{
public:
	notExist(const TStr& whatFile)
		: runtime_error(whatFile)
	{}
};

class Hlpr
{
public:
	static void CheckMainArgs(int argc, char *argv[])
	{
		if (argc != 3)
		{
			throw smthBad("Invalid counts of arguments");
		}
	}

	static void mkDict(const TStr& pathToDic, std::list<TStr>& dict)
	{
		dict.clear();

		std::ifstream dicFile(pathToDic);
		if (!dicFile.is_open())
		{
			throw notExist(pathToDic);
		}

		TStr word;
		while (std::getline(dicFile, word))
		{
			toNormForm(word);
			dict.push_back(word);
		}
		//
		dict.sort();
		dict.unique();
	}

	static void mkWords(const TStr& pathToWords, TStr& w1, TStr& w2)
	{
		w1.clear();
		w2.clear();

		std::ifstream File(pathToWords);
		if (!File.is_open())
		{
			throw notExist(pathToWords);
		}

		std::string word;
		std::getline(File, word);
		w1 = toNormForm(word);

		std::getline(File, word);
		w2 = toNormForm(word);
	}

	static TStr& toNormForm(TStr& word)
	{
		static const std::locale loc;
		//
		if (!word.empty())
		{
			for (auto& wc : word)
			{
				wc = std::toupper(wc, loc);
			}
		}
		//
		return word;
	}
};

}


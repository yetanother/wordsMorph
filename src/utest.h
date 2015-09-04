#pragma once

#include <iostream>
#include <algorithm>

#include "converter.h"


namespace og
{

class Tests
{
public:
	static bool test(const TStr& w1
		, const TStr& w2
		, const std::list<TStr>& dict
		, const std::vector<TStr>& match
		, const TStr& name = "test0")
	{
		Converter converter;
		converter.setDictionary(dict);
		std::vector<TStr> result;
		//
		result = converter.Do_(w1, w2);
		//
		std::size_t iStep = 0;
		while (iStep != std::min(match.size(), result.size()) && match[iStep] == result[iStep])
		{
			++iStep;
		}
		//
		if (iStep < std::max(match.size(), result.size()))
		{
			std::cout << "Test [" << name << "] is failed on step " << iStep << std::endl;
			std::cout << "State of match: " << (iStep < match.size() ? match[iStep] : "has no word") << std::endl;
			std::cout << "State of result: " << (iStep < result.size() ? result[iStep] : "has no word") << std::endl;
			return false;
		}
		else
		{
			std::cout << "Test [" << name << "] is successfully passed" << std::endl;
			return true;
		}
	}

	static void Cmplx();

};

}


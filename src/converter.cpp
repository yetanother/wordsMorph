#include <deque>
#include <algorithm>
#include <iostream>

#include "converter.h"

namespace og
{

	std::vector<TStr> Converter::Do_(const TStr& w1, const TStr& w2)
{
		std::vector<TStr> result;

	if (w1.empty() || w2.empty()) {
		return result;
	}

	if (w1.length() != w2.length()) {
		return result;
	}

	if (w1 == w2) {
		result.push_back(w2);
		return result;
	}

	std::list<TStr> dictionary = dict_;
	std::size_t l1 = w1.length();
	//
	dictionary.remove_if
	(
		[l1](const TStr &w)->bool
		{
			return w.length() != l1;
		}
	);

	std::deque<std::shared_ptr<Word>> intermediateWords;
	std::shared_ptr<Word> word = std::make_shared<Word>(w1);
	intermediateWords.push_back(word);
	while (!intermediateWords.empty()) {
		word = intermediateWords.front();
		intermediateWords.pop_front();

		if (word->value() == w2) {
			intermediateWords.clear();
			dictionary.clear();
			break;
		}

		auto it = dictionary.begin();
		while (it != dictionary.end()) {
			auto diff = word->diffFromWord(*it);
			if (diff == 1) {
				intermediateWords.push_back(std::make_shared<Word>(*it));
				intermediateWords.back()->setPrev(word);
				dictionary.erase(it++);
				continue;
			}
			++it;
		}
	}

	if (word->value() == w2) {
		std::list<std::string> reverseResult;
		while (word) {
			reverseResult.push_back(word->value());
			word = word->prev();
		}
		result.assign(reverseResult.rbegin(), reverseResult.rend());
	}

	return result;
}

std::size_t Converter::Word::diffFromWord(const TStr& word)
{
	if (m_word == word) {
		return 0;
	}

	if (m_word.length() != word.length()) {
		return std::max(m_word.length(), word.length());
	}

	std::string::size_type diffChars(0);
	for (std::string::size_type i = 0; i != m_word.size(); ++i) {
		if (m_word[i] != word[i]) {
			++diffChars;
		}
	}
	return diffChars;
}

}

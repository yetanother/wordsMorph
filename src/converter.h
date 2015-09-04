#pragma once

#include <string>
#include <list>
#include <vector>
#include <memory>


namespace og
{
	typedef std::string TStr;

class Converter
{
public:
	Converter()
	{}
	Converter(const std::list<TStr>& dictionary)
		: dict_(dictionary)
	{}
	void setDictionary(const std::list<TStr>& dictionary) { dict_ = dictionary; }
	std::vector<TStr> Do_(const TStr& w1, const TStr& w2);

private:
	std::list<TStr> dict_;

private:
	class Word
	{
	public:
		Word(const std::string &word)
			: m_word(word)
		{}
		const std::string& value() const { return m_word; }
		void setPrev(const std::shared_ptr<Word> &prev) { m_prev = prev; }
		const std::shared_ptr<Word> &prev() const { return m_prev; }
		std::size_t diffFromWord(const TStr& word);

	private:
		std::string m_word;
		std::shared_ptr<Word> m_prev;
	};
};

}


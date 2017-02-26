#pragma once
#include<iostream>
#include<string>
#include<map>
#include<list>

using namespace std;

class Word
{
private:
	string word;
public:
	Word(string word)
	{
		this->word = word;
	}
	
	string getWord()
	{
		return this->word;
	}
};

int main(void)
{
	map<char, list<Word>> m;

	list<Word> aList;
	list<Word> bList;

	aList.push_back(Word("apple"));
	aList.push_back(Word("avoid"));
	aList.push_back(Word("appear"));

	bList.push_back(Word("bread"));
	bList.push_back(Word("bring"));
	bList.push_back(Word("bow"));

	m['a'] = aList;
	m['b'] = bList;

	map<char, list<Word>>::const_iterator iter = m.begin();

	while (iter != m.end())
	{
		cout << iter->first << " : " << endl;

		list<Word> temp = iter->second;
		list<Word>::const_iterator iter_list = temp.begin();

		while (iter_list != temp.end())
		{
			Word word = *iter_list;
			cout << word.getWord() << ", ";
			iter_list++;
		}
		
		cout << "\n=====" << endl;
		iter++;
	}

	return 0;
}
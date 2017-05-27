#ifndef WORD_H
#define WORD_H

class Word;
class Sentence;

#include <stdlib.h>

using namespace std;

class Word {


public:

	Word();
	~Word();
	Word(const string& aString);
	Word(const Word& aWord);
	
	friend Sentence operator+(const Word& a, const Word& b);

	void show();
	friend ostream& operator<<(ostream& out, const Word& a);
	//postfix
	Word& operator++(int);
	Word& operator--(int);
	//postfix
	
	void operator=(const Word& aword);
	Word& operator+(const int& i);
	
	//prefix
	Word& operator++();
	Word& operator--();
	//prefix
	
	string dummyString;
private:
	
	
};





#endif

#ifndef SENTENCE_H
#define SENTENCE_H

class Sentence;
class Paragraph;

#include "Word.h"


class Sentence {


public:

	Sentence();
	~Sentence();
	Sentence(const Sentence& aSen);
	Sentence(const string& aString);
	
	void show();
	
	friend Sentence operator+(const Word& a, const Sentence& b);
	friend Paragraph operator+(const Sentence& a, const Sentence& b);
	friend ostream& operator<<(ostream& out, const Sentence& b);
	
	Sentence operator+(const Word& a);
	//postfix
    Sentence& operator++(int);
	Sentence& operator--(int);
	//postfix
	
	void operator=(const Sentence& aSen);
	Sentence& operator+(const int& i);
	
	//prefix
	Sentence& operator++();
	Sentence& operator--();
	//prefix

	Word first();
	Sentence rest();
	
private:
	Word* w;
	

};

#endif


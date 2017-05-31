#ifndef PARAGRAPH_H
#define PARAHRAPH_H

class Paragraph;

#include "Sentence.h"
#include <vector>


class Paragraph {


public:

	Paragraph();
	~Paragraph();
	Paragraph(const Paragraph& aPara);
	Paragraph(const string& aString);

	void show();
	friend Paragraph operator+(const Sentence& a, const Paragraph& b);
	friend ostream& operator<<(ostream& out, const Paragraph& b);
	
	Paragraph operator+(const Sentence& b);
	Paragraph operator+(const Paragraph& b);
	//postfix
	Paragraph operator++(int);
	Paragraph operator--(int);
	//postfix
	
	Paragraph& operator=(const Paragraph& aPara);
	Paragraph& operator+(const int& i);

	//prefix
	Paragraph& operator++();
	Paragraph& operator--();
	//prefix
	
	Sentence first();
	Paragraph rest();
	
	Sentence* head;
	Paragraph* next;
	
	
private:
	vector<string> v;

};

#endif

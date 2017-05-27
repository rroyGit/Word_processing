#include <iostream>
#include "Sentence.h"


using namespace std;

Sentence::Sentence() {
	cout << "Entering Sentence::Sentence() Constructor" << endl;

	cout << "	Exiting Sentence::Sentence() Constructor" << endl;
}
Sentence::~Sentence() {
	cout << "Entering Sentence::~Sentence() Deconstructor" << endl;

	cout << "	Exiting Sentence::~Sentence() Deconstructor" << endl;
}
Sentence::Sentence(const string& aString){
  	cout << "Entering Sentence::Sentence(string arg) Value Constructor" << endl;

	cout << "	Exiting Sentence::Sentence(string arg) Value Constructor" << endl;
}
Sentence::Sentence(const Sentence& aSen) {
	cout << "Entering Sentence::Sentence(Sentence arg) Copy Constructor" << endl;

	cout << "	Exiting Sentence::Sentence(Sentence arg) Copy Constructor" << endl;
}
//Sentence + Word
//new Sentence with the Word added to the end
Sentence Sentence::operator+(const Word& b) {
	cout << "Entering Sentence::operator+(Word arg)" << endl;
	Sentence newSen;


	cout << "	Exiting Sentence::operator+(Word arg)" << endl;
	return newSen;
}

//Word + Sentence
//new Sentence with the Word added to the beginning
Sentence operator+(const Word& a, const Sentence& b) {
	cout << "Entering Sentence operator+(Word arg, Sentence arg)" << endl;
	Sentence newSen;


	cout << "	Exiting Sentence operator+(Word arg, Sentence arg)" << endl;
	return newSen;
}
//Word + Word
//new Sentence containing the two words
Sentence operator+(const Word& a, const Word& b) {
	cout << "Entering Sentence operator+(Word arg, Word arg)" << endl;
	Sentence newSen;

	cout << "	Exiting Sentence operator+(Word arg, Word arg)" << endl;
	return newSen;
}
//If a is a Sentence
//makes the whole sentence all caps
Sentence& Sentence::operator++(int) {
	cout << "Entering Sentence::operator++, postfix" << endl;

	cout << "	Exiting Sentence::operator++, postfix" << endl;
	return *this;
}

//If a is a Sentence
//makes the whole sentence all lowercase.
Sentence& Sentence::operator--(int) {
	cout << "Entering Sentence::operator--, postfix" << endl;

	cout << "	Exiting Sentence::operator--, postfix" << endl;
	return *this;
}
//If a is a Sentence
//capitalizes the first letter of the sentence. 
Sentence&  Sentence::operator+(const int& i) {
	cout << "Entering Sentence::operator-" << endl;
	//	if (i != 1) return;

	cout << "	Exiting Sentence::operator-" << endl;
	return *this;
}
//If a is a Sentence
//converts the whole sentence to Pig Latin. 
Sentence& Sentence::operator++() {
	cout << "Entering Sentence::operator++, prefix" << endl;

	cout << "	Exiting Sentence::operator++, prefix" << endl;
	return *this;
}
//If a is a Sentence
//converts all contained Words that are in Pig Latin back to English.  
Sentence& Sentence::operator--() {
	cout << "Entering Sentence::operator--, prefix" << endl;

	cout << "	Exiting Sentence::operator--, prefix" << endl;
	return *this;
}

void Sentence::show() {
	cout << "Entering Sentence::show" << endl;


	cout << "	Exiting Sentence::show" << endl;
}
//The Sentence class should output each word. All but the last word should be followed by a single space. 
//The last word should be followed by the punctuation mark associated with the Sentence (�.�, �!�, or �?�), and then a single space.
ostream& operator<<(ostream& out, const Sentence& b) {
	cout << "Entering Sentence operator<<" << endl;

	cout << "	Exiting Sentence operator<<" << endl;
	return out;
}
//mySent.first() returns a Word containing a copy of the first word of mySent. 
Word Sentence::first() {
	cout << "Entering Sentence::first()" << endl;
	Word newW;

	cout << "	Exiting Sentence::first()" << endl;
	return newW;
}
//mySent.rest() returns a Sentence containing a copy of all but the first word of mySent.
Sentence Sentence::rest(){
	cout << "Entering Sentence::rest()" << endl;
	Sentence newS;

	cout << "	Exiting Sentence::rest()" << endl;
	return newS;
}

void Sentence::operator=(const Sentence& aSen) {
	cout << "Entering Sentence::operator=(Sentence arg)" << endl;
		
	cout << "	Exiting Sentence::operator=(Sentence arg)" << endl;
}

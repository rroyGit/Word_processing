#include <iostream>
#include "Word.h"


using namespace std;

Word::Word() {
	cout << "Entering Word::Word() Constructor" << endl;

	cout << "	Exiting Word::Word() Constructor" << endl;
}
Word::Word(const string& aString){
	cout << "Entering Word::Word(string arg) Value Constructor" << endl;
	cout << aString << endl;

	cout << "	Exiting Word::Word(string arg) Value Constructor" << endl;
}
Word::~Word() {
	cout << "Entering Word::~Word() Deconstructor" << endl;


	cout << "	Exiting Word::~Word() Deconstructor" << endl;
}
Word::Word(const Word& aWord) {
	cout << "Entering Word::Word(Word arg) Copy Constructor" << endl;
	
	

	cout << "	Exiting Word::Word(Word arg) Copy Constructor" << endl;
}
void Word::show() {
	cout << "Entering Word::show" << endl;


	cout << "	Exiting Word::show" << endl;
}
//If a is a Word
//make it all caps
Word& Word::operator++(int) {
	cout << "Entering Word::operator++, postfix" << endl;



	cout << "	Exiting Word::operator++, postfix" << endl;
	return *this;
}

//If a is a Word
//makes it all lowercase.
Word& Word::operator--(int) {
	cout << "Entering Word::operator--, postfix" << endl;


	cout << "	Exiting Word::operator--, postfix" << endl;
	return *this;
}

//If a is a Word
//capitalizes the first letter.
Word&  Word::operator+(const int& i) {
	cout << "Entering Word::operator+" << endl;
	//	if (i != 1) return;


	cout << "	Exiting Word::operator+" << endl;
	return *this;
}
//If a is a Word
//converts it to Pig Latin.
Word& Word::operator++() {
	cout << "Entering Word::operator++, prefix" << endl;


	cout << "	Exiting Word::operator++, prefix" << endl;
	return *this;
}
//If a is a Word in Pig Latin
//converts it from Pig Latin to plain English. 
Word&  Word::operator--() {
	cout << "Entering Word::operator--, prefix" << endl;


	cout << "	Exiting Word::operator--, prefix" << endl;
	return *this;
}
//A Word class should output only the words characters, in order. 
ostream& operator<<(ostream& out, const Word& b) {
	cout << "Entering Word operator<<" << endl;


	cout << "	Exiting Word operator<<" << endl;
	return out;
}
void Word::operator=(const Word& aWord) {
	cout << "Entering Word::operator=(Word arg)" << endl;
	

	cout << "	Exiting Word::operator=(Word arg)" << endl;
}

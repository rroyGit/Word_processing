#include <iostream>
#include "Paragraph.h"


using namespace std;

Paragraph::Paragraph() {
	cout << "Entering Paragraph::Paragraph() Constructor" << endl;

	cout << "	Exiting Paragraph::Paragraph() Constructor" << endl;
}
Paragraph::Paragraph(const string& aString){
  cout << "Entering Paragraph::Paragraph(string arg)"<< endl;

  cout << "    Exiting Paragraph::Paragraph(string arg)"<< endl;
}
Paragraph::~Paragraph() {
	cout << "Entering Paragraph::-Paragraph() Deconstructor" << endl;

	cout << "	Exiting Paragraph::~Paragraph() Deconstructor" << endl;
}
Paragraph::Paragraph(const Paragraph& aPara) {
	cout << "Entering Paragraph::Paragraph(Paragraph arg) Copy Constructor" << endl;

	cout << "	Exiting Paragraph::Paragraph(Paragraph arg) Copy Constructor" << endl;
}
//Paragraph + Sentence
//new Paragraph with an additional Sentence at the end
Paragraph Paragraph::operator+(const Sentence& b) {
	cout << "Entering Paragraph::operator+(Sentence arg)" << endl;
	Paragraph newPara;

	cout << "	Exiting Paragraph::operator+(Sentence arg)" << endl;
	return newPara;
}
//Sentence + Paragraph
//new Paragraph with an additional Sentence at the beginning 
Paragraph operator+(const Sentence& a, const Paragraph& b) {
	cout << "Entering Paragraph operator+(Paragraph arg, Sentence arg)" << endl;
	Paragraph newPara;


	cout << "	Exiting Paragraph operator+(Paragraph arg, Sentence arg)" << endl;
	return newPara;
}
//Sentence + Sentence
//new Paragraph containing the two sentences
Paragraph operator+(const Sentence& a, const Sentence& b) {
	cout << "Entering Paragraph operator+(Sentence arg, Sentence arg)" << endl;
	Paragraph newPara;

	cout << "	Exiting Paragraph operator+(Sentence arg, Sentence arg)" << endl;
	return newPara;
}
//Para + Para
//new Para
Paragraph Paragraph::operator+(const Paragraph& b){
  cout << "Entering Paragraph::operaror+(Para arg)"<< endl;
  Paragraph newPara;


  cout <<"      Exiting Paragraph::operator+(Para arg)"<<endl;
  return newPara;
}


//If a is a Paragraph
//makes the whole paragraph all caps.
Paragraph& Paragraph::operator++(int) {
	cout << "Entering Paragraph::operator++, postfix" << endl;

	cout << "	Exiting Paragraph::operator++, postfix" << endl;
	return *this;
}

//If a is a Paragraph
//makes the whole paragraph all lowercase. 
Paragraph& Paragraph::operator--(int) {
	cout << "Entering Paragraph::operator--, postfix" << endl;

	cout << "	Exiting Paragraph::operator--, postfix" << endl;
	return *this;
}

//If a is a Paragraph
//capitalizes the first words of all contained sentences. 
Paragraph&  Paragraph::operator+(const int& i) {
	cout << "Entering Paragraph::operator+" << endl;
	//	if (i != 1) return;

	cout << "	Exiting Paragraph::operator+" << endl;
	return *this;
}
//If a is a Paragraph
//converts the whole paragraph to Pig Latin. 
Paragraph& Paragraph::operator++() {
	cout << "Entering Paragraph::operator++, prefix" << endl;

	cout << "	Exiting Paragraph::operator++, prefix" << endl;
	return *this;
}
//If a is a Paragraph
//converts all contained Words that are in Pig Latin back to English.  
Paragraph& Paragraph::operator--() {
	cout << "Entering Paragraph::operator--, prefix" << endl;

	cout << "	Exiting Paragraph::operator--, prefix" << endl;
	return *this;
}
//The Paragraph class should output each Sentence, should be indented with a single tab character, and should be followed by a single newline character. 
ostream& operator<<(ostream& out, const Paragraph& b) {
	cout << "Entering Paragraph operator<<" << endl;

	cout << "	Exiting Paragraph operator<<" << endl;
	return out;
}
void Paragraph::show() {
	cout << "Entering Paragraph::show()<<" << endl;

	cout << "	Exiting Paragraph::show()<<" << endl;
}
//myPara.first() returns a Sentence containing a copy of the first sentence of myPara. 
Sentence Paragraph::first() {
	cout << "Entering Paragraph::first()<<" << endl;
	Sentence newS;


	cout << "	Exiting Paragraph::first()<<" << endl;
	return newS;
}
//myPara.rest() returns a Paragraph containing a copy of all but the first sentence of myPara. 
Paragraph Paragraph::rest() {
	cout << "Entering Paragraph::rest()<<" << endl;
	Paragraph newP;


	cout << "	Exiting Paragraph::rest()<<" << endl;
	return newP;
}
void Paragraph::operator=(const Paragraph& aPara) {
	cout << "Entering Paragraph::operator=(Paragraph arg)" << endl;

	cout << "	Exiting Paragraph::operator=(Paragraph arg)" << endl;
}

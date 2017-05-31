#include <iostream>
#include <vector>
#include "Word.h"


using namespace std;

Word::Word() {
	//cout << "Entering Word::Word() Constructor" << endl;
	next = NULL;
	//cout << "	Exiting Word::Word() Constructor" << endl;
}
Word::Word(const string& aString){
	//cout << "Entering Word::Word(string arg) Value Constructor" << endl;
	//cout << "Passed Value Constructor:" << aString << endl;
	
	dummyString = aString;
	next = NULL;
	
	//cout << "	Exiting Word::Word(string arg) Value Constructor" << endl;
}
Word::~Word() {
	//cout << "Entering Word::~Word() Deconstructor" << endl;
	

	//cout << "	Exiting Word::~Word() Deconstructor" << endl;
}
Word::Word(const Word& aWord) {
	//cout << "Entering Word::Word(Word arg) Copy Constructor" << endl;
	
	dummyString = aWord.dummyString;
	next = NULL;
	
	//cout << "	Exiting Word::Word(Word arg) Copy Constructor" << endl;
}
void Word::show() {
	//cout << "Entering Word::show" << endl;

	cout << dummyString << endl;
	
	//cout << "	Exiting Word::show" << endl;
}
//If a is a Word
//make it all caps
Word Word::operator++(int) {
	//cout << "Entering Word::operator++, postfix" << endl;
	Word w(*this);
			
		for(int i =0; i < this->dummyString.length(); i++){
			w.dummyString[i] = toupper(w.dummyString[i]);
		}
			
	//cout << "	Exiting Word::operator++, postfix" << endl;
	return w;
}

//If a is a Word
//makes it all lowercase.
Word Word::operator--(int) {
	//cout << "Entering Word::operator--, postfix" << endl;
	Word w(*this);
	
	for(int i =0; i <  this->dummyString.length(); i++){
		w.dummyString[i] = tolower(w.dummyString[i]);
	}
	
	//cout << "	Exiting Word::operator--, postfix" << endl;
	return w;
}

//If a is a Word
//capitalizes the first letter.
Word&  Word::operator+(const int& i) {
	//cout << "Entering Word::operator+" << endl;
	if (i != 1) return *this;

	this->dummyString[0] = toupper(this->dummyString[0]);

	//cout << "	Exiting Word::operator+" << endl;
	return *this;
}
//If a is a Word
//converts it to Pig Latin.
Word& Word::operator++() {
	//cout << "Entering Word::operator++, prefix" << endl;
	char array[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
	
	v.push_back(this->dummyString);
	
	string temp;
	string newWord;
	int counter = 0;
	int index = 0;
	
	int len = this->dummyString.length();
	
	for(int i =0; i < 10; i++){
		if(this->dummyString[0] == array[i]){
			
			this->dummyString += "way";
			return *this;
		}
	}
	//Like
	for(int j = 0; j < len; j++){
	
		if(this->dummyString[j] == 'a') break;
		if(this->dummyString[j] == 'e') break;
		if(this->dummyString[j] == 'i') break;
		if(this->dummyString[j] == 'o') break;
		if(this->dummyString[j] == 'u') break;
		
	
		if(this->dummyString[j] != 'a') 
		{
			if(this->dummyString[j] != 'e') 
			{
				if(this->dummyString[j] != 'i') 
				{
					if(this->dummyString[j] != 'o') 
					{
						if(this->dummyString[j] != 'i') 
						{
							counter++;
						}
					}
				}
			}
		}
	}
	temp = this->dummyString.substr(counter, len);
	newWord = this->dummyString.substr(0,counter);
	newWord = (temp + newWord + "ay");
	
	if(isupper(this->dummyString[0])){
		for(int i=0; i < len; i++)
   		{
      		newWord[i] = tolower(newWord[i]);
   		}
	   newWord[0] = toupper(newWord[0]);
	}
		this->dummyString = newWord;
	
	//cout << "	Exiting Word::operator++, prefix" << endl;
	return *this;
}
//If a is a Word in Pig Latin
//converts it from Pig Latin to plain English. 
Word&  Word::operator--() {
	//cout << "Entering Word::operator--, prefix" << endl;

	this->dummyString = v.at(0);

	//cout << "	Exiting Word::operator--, prefix" << endl;
	return *this;
}
//A Word class should output only the words characters, in order. 
ostream& operator<<(ostream& out, const Word& b) {

	//cout << "Entering Word operator<<" << endl;
	
	out << b.dummyString;
	
	//cout << "	Exiting Word operator<<" << endl;
	return out;
}
Word& Word::operator=(const Word& aWord) {
	//cout << "Entering Word::operator=(Word arg)" << endl;
	this->dummyString = aWord.dummyString;
	return *this;

	//cout << "	Exiting Word::operator=(Word arg)" << endl;
}

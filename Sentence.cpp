#include <iostream>
#include "Sentence.h"


using namespace std;

string arr;
int yo = 0;

Sentence::Sentence() {
	//cout << "Entering Sentence::Sentence() Constructor" << endl;
	next = NULL;
	//cout << "	Exiting Sentence::Sentence() Constructor" << endl;
}
Sentence::~Sentence() {
	//cout << "Entering Sentence::~Sentence() Deconstructor" << endl;
	/*
	delete head;
	head = NULL;
	*/
	
	//cout << "	Exiting Sentence::~Sentence() Deconstructor" << endl;
}
Sentence::Sentence(const string& aString){
  	//cout << "Entering Sentence::Sentence(string arg) Value Constructor" << endl;
	next = NULL;
	head = NULL;
	Word* temp = head;//create a linked list of words 
	
	//cout << "Sen:" << aString << endl; 
	Word* word;
	string tempWord;

	
	for(int i=0; i < aString.length(); i++){
		//compile word
		if(aString[i] != ' ' && aString[i] != '.' && aString[i] != '!' && aString[i] != '?'){
			tempWord += aString[i];
		}
		//sent out completed word
		if(aString[i] == ' '){
			word = new Word(tempWord);
			
			if(head == NULL){
				head = word;
				temp = head;
			}else{
				temp->next = word;
				temp = word;
			}
			 
			tempWord = "";
		}
		if(aString[i] == '.'){
			word = new Word(tempWord); 
			arr += '.';
			if(head == NULL){
				head = word;
				temp = head;
			}else{
				temp->next = word;
				temp = word;
			}
			
			tempWord = "";
		}
		if(aString[i] == '!'){
			word = new Word(tempWord);
			arr += '!';
			if(head == NULL){
				head = word;
				temp = head;
			}else{
				temp->next = word;
				temp = word;
			}
			
			tempWord = "";
		}
		if(aString[i] == '?'){
			word = new Word(tempWord);
			arr += '?';
			if(head == NULL){
				head = word;
				temp = head;
			}else{
				temp->next = word;
				temp = word;
			}
			 
			tempWord = "";   
		}
		
	}//end of for loop
	
	temp = NULL; //set temp to null
	
	//cout << "	Exiting Sentence::Sentence(string arg) Value Constructor" << endl;
}
Sentence::Sentence(const Sentence& aSen) {
	//cout << "Entering Sentence::Sentence(Sentence arg) Copy Constructor" << endl;
	
	if (aSen.head == NULL){
	cout << "aSen.head is null" << endl;
	return;
	}
	
	head = new Word(*aSen.head);
	
	if (head == NULL) {
	cout << "head is null in sent copy struct" << endl;
	return;
	}
	
	Word* temp = aSen.head->next;
	Word* newTemp = head;
	
	while (temp != NULL) {
		newTemp->next = new Word(*temp);
		newTemp = newTemp->next;
		
		temp = temp->next;
	}
		newTemp->next = NULL;
	//cout << "	Exiting Sentence::Sentence(Sentence arg) Copy Constructor" << endl;
}
//Sentence + Word
//new Sentence with the Word added to the end
Sentence Sentence::operator+(const Word& b) {
	//cout << "Entering Sentence::operator+(Word arg)" << endl;
	Sentence newSen(*this);
	
	if(this->head == NULL) {
		cout << "b.head is NULL in Setence + Word" << endl;
		newSen.head = new Word(b);
		return newSen;
	}
	
	Word* newWord = new Word(b);
	Sentence* sen = new Sentence(*this);
	Word* temp = sen->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	newWord->next = NULL;
	temp->next = newWord;
	
	newSen.next = NULL;
	newSen.head = sen->head;
	
	//cout << "	Exiting Sentence::operator+(Word arg)" << endl;
	return newSen;
}

//Word + Sentence
//new Sentence with the Word added to the beginning
Sentence operator+(const Word& a, const Sentence& b) {
	//cout << "Entering Sentence operator+(Word arg, Sentence arg)" << endl;
	Sentence newSen;
	
	if(b.head == NULL){
		cout << "b.head is NULL in Word + Sentence" << endl;
		return newSen;
	}
	
	Word* newWord = new Word(a);
	Sentence* nSen = new Sentence(b);
	
	Word *temp = newWord;
	temp->next = nSen->head;
	
	newSen.head = newWord;
	newSen.next = NULL;

	//cout << "	Exiting Sentence operator+(Word arg, Sentence arg)" << endl;
	
	return newSen;
}
//Word + Word
//new Sentence containing the two words
//friend function declared in word.h
Sentence operator+(const Word& a, const Word& b) {
	//cout << "Entering Sentence operator+(Word arg, Word arg)" << endl;
	//cout << "Passed Values for operator+ word word:-->"<< a << " " << b;
	
	Sentence newSen;
	
	Word* nwleft = new Word(a);
	Word* nwright = new Word(b);

	nwleft->next = nwright;
	nwright->next = NULL;
	
	newSen.head = nwleft;
	newSen.next = NULL;

	//cout << "	Exiting Sentence operator+(Word arg, Word arg)" << endl;
	return newSen;
}
//If a is a Sentence
//makes the whole sentence all caps
//postfix 
Sentence Sentence::operator++(int) {
	//cout << "Entering Sentence::operator++, postfix" << endl;
	Sentence s(*this);
	
	if(this->head == NULL) cout << "this->head is NULL" << endl;
	
	Word* temp = s.head;
	while(temp){
		*temp = (*temp)++;
		temp = temp->next;
	}
	
	//cout << "	Exiting Sentence::operator++, postfix" << endl;
	return s;
}

//If a is a Sentence
//makes the whole sentence all lowercase.
Sentence Sentence::operator--(int) {
	//cout << "Entering Sentence::operator--, postfix" << endl;
	Sentence s(*this);
	
	if(this->head == NULL) cout << "this->head is NULL" << endl;
	
	Word* temp = s.head;
	while(temp){
		*temp = (*temp)--;
		temp = temp->next;
	}
	//cout << "	Exiting Sentence::operator--, postfix" << endl;
	return s;
}
//If a is a Sentence
//capitalizes the first letter of the sentence. 
Sentence&  Sentence::operator+(const int& i) {
	//cout << "Entering Sentence::operator-" << endl;
	if (i != 1) return *this;
	
	else{
		Word* temp = head;
			(*temp)+1;
	}

	//cout << "	Exiting Sentence::operator-" << endl;
	return *this;
}
//If a is a Sentence
//converts the whole sentence to Pig Latin. 
Sentence& Sentence::operator++() {
	//cout << "Entering Sentence::operator++, prefix" << endl;
	 
	Word* temp = this->head;
	
	while(temp != NULL){
		v.push_back(temp->dummyString);
		*temp = ++(*temp);
		temp = temp->next;
	}
	
	//cout << "	Exiting Sentence::operator++, prefix" << endl;
	return *this;
}
//If a is a Sentence
//converts all contained Words that are in Pig Latin back to English.  
Sentence& Sentence::operator--() {
	//cout << "Entering Sentence::operator--, prefix" << endl;
	
	Word* temp = this->head;
	int i = 0;
	 while(temp != NULL){
	 	temp->dummyString = v.at(i); 
		i++;
		temp = temp->next;
	 }
	 
	//cout << "	Exiting Sentence::operator--, prefix" << endl;
	return *this;
}

void Sentence::show() {
	//cout << "Entering Sentence::show" << endl;

		Word* temp = head;
		
		while(temp !=NULL){
			cout << temp->dummyString << endl;
			temp = temp->next;
		}
		
	//cout << "	Exiting Sentence::show" << endl;
}
//The Sentence class should output each word. All but the last word should be followed by a single space. 
//The last word should be followed by the punctuation mark associated with the Sentence (., !, or ?), and then a single space.
ostream& operator<<(ostream& out, const Sentence& b) {
	//cout << "Entering Sentence operator<<" << endl;

	Word* temp = b.head;

	while(temp != NULL){
		out << temp->dummyString;
		if(temp->next != NULL) out << ' ';
		temp = temp->next;
	}
	out << arr[1] << ' ';
	
	//cout << "	Exiting Sentence operator<<" << endl;
	return out;
}
//mySent.first() returns a Word containing a copy of the first word of mySent. 
Word Sentence::first() {
	//cout << "Entering Sentence::first()" << endl;
	Sentence copy(*this);
	Word newW; 
	
	Word* temp = copy.head;
	newW = *temp;

	//cout << "	Exiting Sentence::first()" << endl;
	return newW;
}
//mySent.rest() returns a Sentence containing a copy of all but the first word of mySent.
Sentence Sentence::rest(){
	//cout << "Entering Sentence::rest()" << endl;
	Sentence copy(*this);
	Sentence newS;
	
	if(head == NULL) cout <<"Head is NULL with sent.rest()" << endl;
	
	Word* temp = copy.head;
	newS.head = temp->next;
	
	//cout << "	Exiting Sentence::rest()" << endl;
	return newS;
}

Sentence& Sentence::operator=(const Sentence& aSen) {
	//cout << "Entering Sentence::operator=(Sentence arg)" << endl;
	//perform destructor
	
	if (aSen.head == NULL){
	cout << "aSen.head is null" << endl;
		this->head = NULL;
		return *this;
	}
	
	head = new Word(*aSen.head);
	
	Word* temp = aSen.head->next;
	Word* newTemp = head;
	
	while (temp != NULL) {
		newTemp->next = new Word(*temp);
		newTemp = newTemp->next;
		temp = temp->next;
	}
		newTemp->next = NULL;	
	
		return *this;
	//cout << "	Exiting Sentence::operator=(Sentence arg)" << endl;
}

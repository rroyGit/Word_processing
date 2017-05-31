#include <iostream>
#include "Paragraph.h"


using namespace std;


Paragraph::Paragraph() {
	cout << "Entering Paragraph::Paragraph() Constructor" << endl;

	cout << "	Exiting Paragraph::Paragraph() Constructor" << endl;
}
Paragraph::Paragraph(const string& aString){
  cout << "Entering Paragraph::Paragraph(string arg)"<< endl;
	head = NULL;
	next = NULL;
	//create linked list of sentences
	Sentence* temp = head;
	
	Sentence* sent;
	string tempSent;
	
	
	for(int i=0; i < aString.length(); i++){
		
		if(aString[i] != '.' || aString[i] != '?' || aString[i] != '!'){
			tempSent += aString[i];
		}
		if(aString[i] == '!' || aString[i] == '.' ||  aString[i] == '?'){
			tempSent.erase(0, tempSent.find_first_not_of(' '));
			//cout << "Sent:" << tempSent << endl;
			sent = new Sentence(tempSent);
			if(head == NULL){
				head = sent;
				temp = head;
			}else{
				temp->next = sent;
				temp = sent;
			}
			tempSent = "";
		}
	}

	temp = NULL; //set temp to NULL
  cout << "    Exiting Paragraph::Paragraph(string arg)"<< endl;
}
Paragraph::~Paragraph() {
	cout << "Entering Paragraph::-Paragraph() Deconstructor" << endl;
	/*
	Sentence* temp = head;
	while(temp != NULL) {
    	delete temp;
    	temp = temp->next; 
	}
	head = NULL;
		*/
	cout << "	Exiting Paragraph::~Paragraph() Deconstructor" << endl;
}
Paragraph::Paragraph(const Paragraph& aPara) {
	cout << "Entering Paragraph::Paragraph(Paragraph arg) Copy Constructor" << endl;

	if(aPara.head == NULL){
		cout << "aPara.head is NULL" << endl;
		return;
	}
	head = new Sentence(*aPara.head);
	
	if(head == NULL){
		cout << "head is null in Paragraph Copy Constructor" << endl;
		return;
	}

	Sentence* temp = aPara.head->next;
	Sentence* newTemp = head;
	
	while(temp != NULL){
		newTemp->next = new Sentence(*temp);
		newTemp = newTemp->next;
		temp = temp->next;
	}
		newTemp->next = NULL;

	cout << "	Exiting Paragraph::Paragraph(Paragraph arg) Copy Constructor" << endl;
}
//Paragraph + Sentence
//new Paragraph with an additional Sentence at the end
Paragraph Paragraph::operator+(const Sentence& b) {
	cout << "Entering Paragraph::operator+(Sentence arg)" << endl;
	Paragraph newPara(*this);
	
	if(this->head == NULL){ 
		cout << "this->head is NULL"<< endl;
		newPara.head = new Sentence(b);
		return newPara;
	}
	
	Sentence* newSen = new Sentence(b);
	Paragraph* nPara = new Paragraph(*this);
	
	Sentence* temp = nPara->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	newSen->next = NULL;
	temp->next = newSen;
	
	newPara.next = NULL;
	newPara.head = nPara->head;
	
	cout << "	Exiting Paragraph::operator+(Sentence arg)" << endl;
	return newPara;
}
//Sentence + Paragraph
//new Paragraph with an additional Sentence at the beginning 
Paragraph operator+(const Sentence& a, const Paragraph& b) {
	cout << "Entering Paragraph operator+(Paragraph arg, Sentence arg)" << endl;
	Paragraph newPara;
	
	if(b.head == NULL){
		cout << "b.head is NULL in Sentence + Paragraph" << endl;
		return newPara;
	}
	
	Sentence* newSen = new Sentence(a);
	Paragraph* nPara = new Paragraph(b);
	Sentence* temp = newSen;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = nPara->head;
	
	newPara.head = newSen;
	newPara.next = NULL;
	
	cout << "	Exiting Paragraph operator+(Paragraph arg, Sentence arg)" << endl;
	return newPara;
}
//Sentence + Sentence
//new Paragraph containing the two sentences
Paragraph operator+(const Sentence& a, const Sentence& b) {
	cout << "Entering Paragraph operator+(Sentence arg, Sentence arg)" << endl;
	Paragraph newPara;
	
	Sentence* sen1 = new Sentence(a);
	Sentence* sen2 = new Sentence(b);
	
	sen1->next = sen2;
	sen2->next = NULL;
	
	newPara.head = sen1;
	newPara.next = NULL;

	cout << "	Exiting Paragraph operator+(Sentence arg, Sentence arg)" << endl;
	return newPara;
}
//Para + Para
//new Para with sentences of first + sentences of second
Paragraph Paragraph::operator+(const Paragraph& b){
  cout << "Entering Paragraph::operaror+(Para arg)"<< endl;
  Paragraph newPara;

	if(b.head == NULL){
		cout << "b.head == NULL" << endl;
		return newPara;
	}
	Paragraph* para1 = new Paragraph(*this);
	Paragraph* para2 = new Paragraph(b);
	
	Sentence* temp = para1->head;
	
	while(temp->next !=NULL){
		temp = temp->next;
	}
	temp->next = para2->head;
	para2->next = NULL;

	newPara.head = para1->head;
	newPara.next = NULL;

  cout <<"      Exiting Paragraph::operator+(Para arg)"<<endl;
  return newPara;
}

//If a is a Paragraph
//makes the whole paragraph all caps.
Paragraph Paragraph::operator++(int) {
	cout << "Entering Paragraph::operator++, postfix" << endl;
	
	Paragraph para(*this);
	Sentence* temp = para.head;
	
	while(temp){
		*temp = (*temp)++;
		temp = temp->next;
	}
	
	cout << "	Exiting Paragraph::operator++, postfix" << endl;
	return para;
}

//If a is a Paragraph
//makes the whole paragraph all lowercase. 
Paragraph Paragraph::operator--(int) {
	cout << "Entering Paragraph::operator--, postfix" << endl;
	
	Paragraph para(*this);
	Sentence* temp = para.head;
	
	while(temp){
		*temp = (*temp)--;
		temp = temp->next;
	}
	
	cout << "	Exiting Paragraph::operator--, postfix" << endl;
	return para;
}

//If a is a Paragraph
//capitalizes the first words of all contained sentences. 
Paragraph& Paragraph::operator+(const int& i) {
	cout << "Entering Paragraph::operator+" << endl;
	
	if (i != 1) return *this;
	
	Sentence *temp = this->head;
	
	while(temp != NULL){
		Word* temp2 = temp->head;
		*temp2 = (*temp2)+1;
		temp = temp->next;
	}
 	
	cout << "	Exiting Paragraph::operator+" << endl;
	return *this;
}
//If a is a Paragraph
//converts the whole paragraph to Pig Latin. 
Paragraph& Paragraph::operator++() {
	cout << "Entering Paragraph::operator++, prefix" << endl;
	
	Sentence* temp = this->head;
	Word* temp2;
	while(temp != NULL){
		temp2 = temp->head;
		while(temp2 != NULL){
			v.push_back(temp2->dummyString);
			*temp2 = ++(*temp2);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	
	cout << "	Exiting Paragraph::operator++, prefix" << endl;
	return *this;
}
//If a is a Paragraph
//converts all contained Words that are in Pig Latin back to English.  
Paragraph& Paragraph::operator--() {
	cout << "Entering Paragraph::operator--, prefix" << endl;
	
	Sentence* temp = this->head;
	Word* temp2;
	int i = 0;
	
	while(temp != NULL){
		temp2 = temp->head;
		while(temp2 != NULL){
			temp2->dummyString = v.at(i);
			i++;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	
	cout << "	Exiting Paragraph::operator--, prefix" << endl;
	return *this;
}
//The Paragraph class should output each Sentence, should be indented with a single tab character, and should be followed by a single newline character. 
ostream& operator<<(ostream& out, const Paragraph& b) {
	cout << "Entering Paragraph operator<<" << endl;

	Sentence* temp = b.head;
	
	while(temp != NULL){
		out << *temp;
		temp = temp->next;
	}
	
	cout << "\n	Exiting Paragraph operator<<" << endl;
	return out;
}
void Paragraph::show() {
	cout << "Entering Paragraph::show()<<" << endl;

	if (head ==  NULL){
		cout << "head NULL in show()" << endl;
		return;
	}
	Sentence* temp = head;
	
	while(temp != NULL){
		cout << *temp;
		temp = temp->next;
	}

	cout << "	Exiting Paragraph::show()<<" << endl;
}
//myPara.first() returns a Sentence containing a copy of the first sentence of myPara. 
Sentence Paragraph::first() {
	cout << "Entering Paragraph::first()<<" << endl;
	Paragraph copy(*this);
	Sentence newS;
	
	Sentence* temp = copy.head;
	newS = *temp;

	cout << "	Exiting Paragraph::first()<<" << endl;
	return newS;
}
//myPara.rest() returns a Paragraph containing a copy of all but the first sentence of myPara. 
Paragraph Paragraph::rest() {
	cout << "Entering Paragraph::rest()<<" << endl;
	Paragraph copy(*this);
	Paragraph newP;
	
	Sentence* temp = copy.head;
	newP.head = temp->next;

	cout << "	Exiting Paragraph::rest()<<" << endl;
	return newP;
}
Paragraph& Paragraph::operator=(const Paragraph& aPara) {
	cout << "Entering Paragraph::operator=(Paragraph arg)" << endl;
	//perform destructor 

	if(aPara.head == NULL){
		cout << "aPara.head is NULL" << endl;
		this->head = NULL;
		return *this;
	}
	head = new Sentence(*aPara.head);

	Sentence* temp = aPara.head->next;
	Sentence* newTemp = head;
	
	while(temp != NULL){
		newTemp->next = new Sentence(*temp);
		newTemp = newTemp->next;
		temp = temp->next;
	}
		newTemp->next = NULL;
	
	cout << "	Exiting Paragraph::operator=(Paragraph arg)" << endl;
	return *this;
	
	
}

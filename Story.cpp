#include <iostream>
#include <fstream>
#include <string>
#include "Story.h"

using namespace std;


Story::Story() {
	//cout << "Entering Story::Story Constructor" << endl;
	
	//cout << "	Exiting Story::Story Constructor" << endl;
}
//open the file named the passed string value
//construct from it a new instance of the Story class, with contents appropriately divided into objects that contain linked lists of Paragraphs, Sentences, and Words. 
Story::Story(const string& a) {
	//cout << "Entering Story::Story(string arg)" << endl;
	head = NULL;
	next = NULL;
	//open file
	//construct new instance of Story class
	//Story *newStory = new Story();
	Paragraph* newPara;
	Paragraph* temp = head; //creating a linked list of paragraphs
	
	ifstream myFile;
	string line;
	myFile.open(a.c_str());
	
	 
	if (myFile.is_open()){
   		while (getline(myFile,line)){
      
			if(line.length() != 0){	
				line.erase(0, line.find_first_not_of('\t'));

				//cout << "Para:" << line << endl;
				newPara = new Paragraph(line);
				if(head == NULL){
					head = newPara;
					temp = head;
				}else{
					temp->next = newPara; 
					temp = newPara;
				}
			}
		
    	}//end of while loop
   		myFile.close();
  	}else cout << "Cannot find file" << endl;
	
	temp = NULL; //set last paragraph node NULL
	
	//cout << "	Exiting Story::Story(string arg)" << endl;
}
Story::Story(const Story& aStory) {
	//cout << "Entering Story::Story(Story arg) Copy Constructor" << endl;
	
	if(aStory.head == NULL){
		cout << "aStory.head is NULL" << endl;
		return;
	}
	head = new Paragraph(*aStory.head);
	
	if(head == NULL){
		cout << "head is null in Story Copy Constructor" << endl;
		return;
	} 

	Paragraph* temp = aStory.head->next;
	Paragraph* newTemp = head;
	
	while(temp != NULL){
		newTemp->next = new Paragraph(*temp);
		newTemp = newTemp->next;
		temp = temp->next;
	}
		newTemp->next = NULL;

	//cout << "	Exiting Story::Story(Story arg) Copy Constructor" << endl;
}
Story::~Story() {
	//cout << "Entering Story::~Story Deconstructor" << endl;
	/*
	Paragraph* temp = head;
	while(temp != NULL) {
		
    	delete temp;
    	temp = temp->next; 
	}
	head = NULL;
	*/
	//cout << "	Exiting Story::~Story Deconstructor" << endl;
}
//Story + Story
//new Story containing the paragraphs of the first Story followed by the paragraphs of the second Story
Story Story::operator+(const Story& b) {
	//cout << "Entering Story::operator+ (Story arg)" << endl;
	Story newStory;
	
	if(b.head == NULL){
		cout << "Story b.head is NULL" << endl;
		return newStory;
	}
	Story* story1 = new Story(*this);
	Story* story2 = new Story(b);
	
	Paragraph* temp = story1->head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = story2->head;
	
	newStory.head = story1->head;
	newStory.next = NULL;
	
	//cout << "	Exiting Story::operator+ (Story arg)" << endl;
	return newStory;
}
//Story + Paragraph
//new Story with an additional paragraph at the end 
Story Story::operator+(const Paragraph& b) {
	//cout << "Entering Story::operator+ (Paragraph arg)" << endl;
	Story newStory;

	if(b.head == NULL){
		cout << "b.head is NULL" << endl;
		newStory.head = this->head;
		return newStory;
	}
	
	Story* story1 = new Story(*this);
	Paragraph* para1 = new Paragraph(b);
	
	Paragraph* temp = story1->head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = para1;
	//solved segfault occured in operator<<
	para1->next = NULL;
	
	newStory.head = story1->head;
	newStory.next = NULL;
	//cout << "	Exiting Story::operator+ (Paragraph arg)" << endl;
	return newStory;
}
//Paragraph + Story
//new Story with an additional paragraph at the beginning
Story operator+(const Paragraph& a, const Story& b) {
	//cout << "Entering operator+(Story arg, Paragraph arg)" << endl;
	Story newStory;

	if(a.head == NULL || b.head == NULL){
		cout << "a.head or b.head is null in Para + Story" << endl;
		return newStory;
	}
	
	Paragraph* para = new Paragraph(a);
	Story* story = new Story(b);
	
	para->next = story->head;
	story->next = NULL;
	
	newStory.head = para;
	newStory.next = NULL;


	//cout << "	Exiting operator+(Story arg, Paragraph arg)" << endl;
	return newStory;
}

//If a is a Story
//makes the whole story all caps. 
Story Story::operator++(int) {
	//cout << "Entering Story::operator++, postfix" << endl;
	
	Story story(*this);
	Paragraph* temp = story.head;
	
	while(temp){
		*temp = (*temp)++;
		temp = temp->next;
	}
	
	//cout << "	Exiting Story::operator++, postfix" << endl;
	return story;
}
//If a is a Story
//makes the whole story all lowercase
Story Story::operator--(int) {
	//cout << "Entering Story::operator--, postfix" << endl;
	
	Story story(*this);
	Paragraph* temp = story.head;
	
	while(temp){
		*temp = (*temp)--;
		temp = temp->next;
	}
	
	//cout << "	Exiting Story::operator--, postfix" << endl;
	return story;
}
//If a is a Story, 
//capitalizes the first words of all contained sentences.
Story& Story::operator+(const int& i) {
	//cout << "Entering Story::operator+" << endl;
	if (i != 1) return *this;
	
	Paragraph *temp = this->head;
	
	while(temp != NULL){
		Sentence* temp2 = temp->head;
		*temp2 = (*temp2)+1;
		temp = temp->next;
	}
	
	//cout << "	Exiting Story::operator+" << endl;
	return *this;
}

void Story::show() {
	//cout << "Entering Story::show()" << endl;
	
	if (head ==  NULL){
		cout << "head NULL in Story::show()" << endl;
		return;
	}
	Paragraph* temp = head;
	
	while(temp != NULL){
		cout << *temp;
		temp = temp->next;
	}
	
	//cout << "	Exiting Story::show()" << endl;
}

//If a is a Story
//converts the whole story to Pig Latin. 
Story& Story::operator++() {
	//cout << "Entering Story::operator++, prefix" << endl;
	
	Paragraph* temp0 = this->head;
	Sentence* temp;
	Word* temp2;
	
	while(temp0 != NULL){
		temp = temp0->head;
		
		while(temp != NULL){
			temp2 = temp->head;
			while(temp2 != NULL){
				v.push_back(temp2->dummyString);
				*temp2 = ++(*temp2);
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		temp0 = temp0->next;
	}	
	
	//cout << "	Exiting Story::operator++, prefix" << endl;
	return *this;
}
//If a is a Story
//converts all contained Words that are in Pig Latin back to English.  
Story& Story::operator--() {
	//cout << "Entering Story::operator--, prefix" << endl;
	
	Paragraph* temp0 = this->head;
	Sentence* temp;
	Word* temp2;
	int i = 0;
	
	while(temp0 != NULL){
		temp = temp0->head;
		while(temp != NULL){
			temp2 = temp->head;
			while(temp2 != NULL){
				temp2->dummyString = v.at(i);
				*temp2 = --(*temp2);
				i++;
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		temp0 = temp0->next;
	}	
	
	//cout << "	Exiting Story::operator--, prefix" << endl;
	return *this;
}

//The Story class should output contained paragraphs, with blank lines between them
ostream& operator<<(ostream& out, const Story& b) {
	//cout << "Entering Story operator<<" << endl;
	
	Paragraph* temp = b.head;
	int i = 0;
	while(temp != NULL){
		out <<'\t';
		out << *temp;
		out <<'\t' << '\n' << '\n';
		temp = temp->next;
		i++;
	}
	
	//cout << "	Exiting Story operator<<" << endl;
	return out;
}
//myStory.first() returns a Paragraph containing a copy of the first paragraph of myStory. 
Paragraph Story::first() {
	//cout << "Entering Story::first()" << endl;
	
	Story copy(*this);
	Paragraph newP;
	
	Paragraph* temp = copy.head;
	newP = *temp;
	
	//cout << "	Exiting Story::first()" << endl;
	return newP;
}
//myStory.rest() returns a Story containing a copy of all but the first paragraph of myStory. 
Story Story::rest() {
	//cout << "Entering Story::rest()" << endl;
	Story copy(*this);	
	Story newS;
	
	Paragraph* temp = copy.head;
	newS.head = temp->next;

	//cout << "	Exiting Story::rest()" << endl;
	return newS;
}

void Story::save(const string& a) {
	//cout << "Entering Story::save(string arg)" << endl;
	
	Story copy(*this);
	
	ofstream myFile;
	myFile.open(a.c_str());
	
	if (myFile.is_open()){
   		myFile << copy;
  
   		myFile.close();
 	} else cout << "Unable to open file";


	//cout << "	Exiting Story::save(string arg)" << endl;
}

Story& Story::operator=(const Story& aStory) {
	//cout << "Entering Story::operator=(Story arg)" << endl;

	//perform destructor 

	if(aStory.head == NULL){
		cout << "aStory.head is NULL" << endl;
		this->head = NULL;
		return *this;
	}
	head = new Paragraph(*aStory.head);

	Paragraph* temp = aStory.head->next;
	Paragraph* newTemp = head;
	
	while(temp != NULL){
		newTemp->next = new Paragraph(*temp);
		newTemp = newTemp->next;
		temp = temp->next;
	}
		newTemp->next = NULL;

	return *this;
	//cout << "	Exiting Story::operator=(Story arg)" << endl;
}

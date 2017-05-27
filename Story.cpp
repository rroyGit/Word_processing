#include <iostream>
#include <string>
#include "Story.h"

using namespace std;


Story::Story() {
	cout << "Entering Story::Story Constructor" << endl;

	cout << "	Exiting Story::Story Constructor" << endl;
}
//open the file named the passed string value
//construct from it a new instance of the Story class, with contents appropriately divided into objects that contain linked lists of Paragraphs, Sentences, and Words. 
Story::Story(const string& a) {
	cout << "Entering Story::Story(string arg)" << endl;

	cout << "	Exiting Story::Story(string arg)" << endl;
}
Story::Story(const Story& aStory) {
	cout << "Entering Story::Story(Story arg) Copy Constructor" << endl;

	cout << "	Exiting Story::Story(Story arg) Copy Constructor" << endl;
}
Story::~Story() {
	cout << "Entering Story::~Story Deconstructor" << endl;

	cout << "	Exiting Story::~Story Deconstructor" << endl;
}
//Story + Story
//new Story containing the paragraphs of the first Story followed by the paragraphs of the second Story
Story Story::operator+(const Story& b) {
	cout << "Entering Story::operator+ (Story arg)" << endl;
	Story newStory;
	
	cout << "	Exiting Story::operator+ (Story arg)" << endl;
	return newStory;
}
//Story + Paragraph
//new Story with an additional paragraph at the end 
Story Story::operator+(const Paragraph& b) {
	cout << "Entering Story::operator+ (Paragraph arg)" << endl;
	Story newStory;


	cout << "	Exiting Story::operator+ (Paragraph arg)" << endl;
	return newStory;
}
//Paragraph + Story
//new Story with an additional paragraph at the beginning
Story operator+(const Paragraph& a, const Story& b) {
	cout << "Entering operator+(Story arg, Paragraph arg)" << endl;
	Story newStory;


	cout << "	Exiting operator+(Story arg, Paragraph arg)" << endl;
	return newStory;
}

//If a is a Story
//makes the whole story all caps. 
Story& Story::operator++(int) {
	cout << "Entering Story::operator++, postfix" << endl;

	cout << "	Exiting Story::operator++, postfix" << endl;
	return *this;
}
//If a is a Story
//makes the whole story all lowercase
Story& Story::operator--(int) {
	cout << "Entering Story::operator--, postfix" << endl;

	cout << "	Exiting Story::operator--, postfix" << endl;
	return *this;
}
//If a is a Story, 
//capitalizes the first words of all contained sentences.
Story& Story::operator+(const int& i) {
	cout << "Entering Story::operator+" << endl;
	//	if (i != 1) return;

	cout << "	Exiting Story::operator+" << endl;
	return *this;
}

void Story::show() {
	cout << "Entering Story::show()" << endl;

	cout << "	Exiting Story::show()" << endl;
}

//If a is a Story
//converts the whole story to Pig Latin. 
Story& Story::operator++() {
	cout << "Entering Story::operator++, prefix" << endl;

	cout << "	Exiting Story::operator++, prefix" << endl;
	return *this;
}
//If a is a Story
//converts all contained Words that are in Pig Latin back to English.  
Story& Story::operator--() {
	cout << "Entering Story::operator--, prefix" << endl;

	cout << "	Exiting Story::operator--, prefix" << endl;
	return *this;
}

//The Story class should output contained paragraphs, with blank lines between them
ostream& operator<<(ostream& out, const Story& b) {
	cout << "Entering Story operator<<" << endl;

	cout << "	Exiting Story operator<<" << endl;
	return out;
}
//myStory.first() returns a Paragraph containing a copy of the first paragraph of myStory. 
Paragraph Story::first() {
	cout << "Entering Story::first()" << endl;
	Paragraph newP;

	cout << "	Exiting Story::first()" << endl;
	return newP;
}
//myStory.rest() returns a Story containing a copy of all but the first paragraph of myStory. 
Story Story::rest() {
	cout << "Entering Story::rest()" << endl;
	Story newS;

	cout << "	Exiting Story::rest()" << endl;
	return newS;
}

void Story::save(const string& a) {
	cout << "Entering Story::save(string arg)" << endl;
	

	cout << "	Exiting Story::save(string arg)" << endl;
}

void Story::operator=(const Story& aStory) {
	cout << "Entering Story::operator=(Story arg)" << endl;

	cout << "	Exiting Story::operator=(Story arg)" << endl;
}

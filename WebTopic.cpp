/* Name: Louise Victoria Cancino, Devon Pirestani
 * TA: Nikhil Gothanker; Email Address: gnikhil@udel.edu; OH: Smith 201 on Wed from 3:30-5:30 PM
 * Due Date: 3/25/2018
 * This file contains the method declarations for the WebTopic class.
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cctype>
using namespace std;

WebTopic::WebTopic(string filename) {
	file = filename;
	wordlist = new SLL();
	currpriority = -1;
}

void WebTopic::getPriority(string line) {
	//the line is the tag, without the first <; this method uses the line to
	//determine the current priority as follows:
	//if the first 5 characters in the line match the word “title” (I used
	//line.compare for this), or the first 2 characters match either h2 or h2,
	//then the current priority is set to 1; if the first 2 characters are
	//anything between h3 and h6, then the priority is set to 2, and if it’s
	//anything else, it’s set to 3	//cout << endl; //
	//cout << line << endl; //
	if (line.compare(0,5,"title") == 0 || line.compare(0,2,"h1")==0 || line.compare(0,2, "h2")==0) {
		currpriority = 1;
	} else if (line.compare(0,2,"h3") == 0 ||line.compare(0,2,"h4") == 0||line.compare(0,2,"h5") == 0||line.compare(0,2,"h6") == 0) {
		currpriority = 2;
	} else {
		currpriority = 3;
	}
	//cout << "Curr Priority: " << currpriority << endl; //
}

void WebTopic::printPage() {
	//prints out the list of words on the web page, ordered by their priority (and
	//listing each word’s priority)
	//cout << "This is wordlist:" << endl;
	//wordlist->printSLL();
	cout << "Priority 1:" << endl;
	wordlist->printSLL(1);
	cout << endl << endl;
	cout << "Priority 2:" << endl;
	wordlist->printSLL(2);
	cout << endl << endl;
	cout << "Priority 3:" << endl;
	wordlist->printSLL(3);
}

void WebTopic::readFile() {
	//reads in the web page, character by character, into a line, setting the
	//current priority based on the latest tag read in; this method calls
	//getPriority when a tag has been read in, and it calls parseString when the
	//text between tags has been read in
	ifstream infile(file.c_str(),ios::in); // open file
	string line = "";
	char c;
	while (infile.get(c)) {
		if (c == '<') {
			if (!line.empty()) {
				//cout << "Line outside of tag: " << endl; //
				//cout << line << endl << endl; //
				parseString(line);
				line = "";
			}
		} else if (c == '>') {
			//cout << "Line inside of tag: " << endl; //
			//cout << line << endl << endl; //
			getPriority(line);
			line = "";
		} else {
			line += c;
		}
	}
	cout << "*****************************************" << endl;
	cout << "BEFORE REMOVING STOP WORDS" << endl;
	printPage();
	cout << endl << endl;
	removeStopWords();
	cout << "*****************************************" << endl;
	cout << "AFTER REMOVING STOP WORDS" << endl;
	printPage();
	cout << endl << endl;
	infile.close();
}

string WebTopic::stripSpace(string s) {
	//strips out any character that isn’t alphanumeric and returns the stripped
	//string
	unsigned int i = 0;
	while (i < s.length()) {
		if (!isalpha(s[i])) {
			s.erase(i);
		}
		i++;
	}
	return s;
}

void WebTopic::parseString(string line) {
	//takes a line of characters and breaks the line up into words by creating a
	//new string of only alphabetical characters
	char *l=const_cast<char *>(line.c_str());
	char *token = strtok(l, " ");
	while (token != NULL) {
		string s = stripSpace(token);
		if (s != "") {
			wordlist->priorityInsert(s,currpriority);
		}
		token = strtok(NULL, " ");
	}
}

void WebTopic::removeStopWords(){
	//after the linked list has been created, this method removes all the
	//stopwords in the array of stopwords from the linked list (using the
	//removeAll method)
	int removedWordCount = 0;
	for (int i = 0; i < 50; i++) {
		cout << "removing " << stopwords[i] << endl;
		removedWordCount += (wordlist->removeAll(stopwords[i]));
	}
	//cout << removedWordCount << " words were removed." << endl;
}

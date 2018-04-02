/* Name: Louise Victoria Cancino, Devon Pirestani
 * TA: Nikhil Gothanker; Email Address: gnikhil@udel.edu; OH: Smith 201 on Wed from 3:30-5:30 PM
 * Due Date: 3/25/2018
 * This file contains the method definitions for the WebTopic class.
 */

#ifndef WEBTOPIC_HPP_
#define WEBTOPIC_HPP_
#include "SNode.hpp"
#include "SLL.hpp"
#include <stdlib.h>
using namespace std;

class WebTopic {
	int currpriority;
	//this priority changes as the web page is traversed based on the last tag
	//that has been read in
	SLL *wordlist;
	//the list of words ordered by priority
	string file;
	//the name of the web page file being read in

	//the ARRAY of stopwords, to be removed from the linked list (below)
	string stopwords[50]={"a",
		"along",
		"although",
		"am",
		"among",
		"and",
		"are",
		"as",
		"at",
		"be",
		"because",
		"between",
		"can",
		"do",
		"dont",
		"either",
		"for",
		"got",
		"has",
		"have",
		"havent",
		"he",
		"i",
		"in",
		"is",
		"isnt",
		"it",
		"more",
		"much",
		"neither",
		"no",
		"none",
		"nor",
		"not",
		"of",
		"one",
		"or",
		"that",
		"the",
		"they",
		"this",
		"though",
		"was",
		"when",
		"while",
		"why",
		"with",
		"without",
		"you",
		"your"
	};
	int swlen = 50; //the length of the ARRAY stopwords, above
	public:
		WebTopic(string filename);
		//constructor
		void readFile();
		//reads in the web page, character by character, into a line, setting the
		//current priority based on the latest tag read in; this method calls
		//getPriority when a tag has been read in, and it calls parseString when the
		//text between tags has been read in
		void parseString(string line);
		//takes a line of characters and breaks the line up into words by creating a
		//new string of only alphabetical characters
		string stripSpace(string s);
		//strips out any character that isn’t alphanumeric and returns the stripped
		//string
		void getPriority(string line);
		//the line is the tag, without the first <; this method uses the line to
		//determine the current priority as follows:
		//if the first 5 characters in the line match the word “title” (I used
		//line.compare for this), or the first 2 characters match either h2 or h2,
		//then the current priority is set to 1; if the first 2 characters are
		//anything between h3 and h6, then the priority is set to 2, and if it’s
		//anything else, it’s set to 3
		void printPage();
		//prints out the list of words on the web page, ordered by their priority (and
		//listing each word’s priority)
		void removeStopWords();
		//after the linked list has been created, this method removes all the
		//stopwords in the array of stopwords from the linked list (using the
		//removeAll method)
};

#endif /* WEBTOPIC_HPP_ */

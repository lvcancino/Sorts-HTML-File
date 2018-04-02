/* Name: Louise Victoria Cancino, Devon Pirestani
 * TA: Nikhil Gothanker; Email Address: gnikhil@udel.edu; OH: Smith 201 on Wed from 3:30-5:30 PM
 * Due Date: 3/25/2018
 * This file contains the method declarations for the SNode class.
 */

#ifndef SNODE_HPP_
#define SNODE_HPP_
#include <stdlib.h>
#include <iostream>
using namespace std;

class SNode {
	friend class SLL;
	friend class WebTopic;
	string word; //instead of int data, now the data is a string
	int priority; //the priority of a node (1,2, or 3)
	SNode *next;
	public:
		SNode(string w, int p);
		~SNode();
		void printNode();
};

#endif /* SNODE_HPP_ */

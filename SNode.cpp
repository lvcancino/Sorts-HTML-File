/* Name: Louise Victoria Cancino, Devon Pirestani
 * TA: Nikhil Gothanker; Email Address: gnikhil@udel.edu; OH: Smith 201 on Wed from 3:30-5:30 PM
 * Due Date: 3/25/2018
 * This file contains the method definitions for the SNode class.
 */

#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

SNode::SNode(string w, int p) {
	word = w;
	priority = p;
	next = NULL;
}

SNode::~SNode() {
	cout << "deleting " << word << " may cause a memory leak" << endl;
}

void SNode::printNode() {
	// prints out the data contained within a node
	cout << word << ":" << priority;
}

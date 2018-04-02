/* Name: Louise Victoria Cancino, Devon Pirestani
 * TA: Nikhil Gothanker; Email Address: gnikhil@udel.edu; OH: Smith 201 on Wed from 3:30-5:30 PM
 * Due Date: 3/25/2018
 * This file contains the method declarations for the SLL class.
 */

#ifndef SLL_HPP_
#define SLL_HPP_
#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class SLL {
	friend class WebTopic;
	SNode *first;
	SNode *last;
	SNode *p2; //points to the node in the list that is the last node with a
	//priority of 2; if you add another node with a priority of 2 to the list, it will be
	//added after this node;
	//note that you still only have one list
	int size;
	public:
		SLL();
		~SLL();
		void printSLL();
		//used for testing purposes – not actually needed for this
		//lab, but useful
		void printSLL(int p);
		void priorityInsert(string s, int p);
		//This method creates a new node with s as the word and p as the priority and,
		//if the priority is 1, adds the new node to the beginning of the list, if it
		//is 3, adds the node to the end of the list, and if it’s 2, it will insert it
		//into the list right after pointer p2 (which is the last node with a priority
		//of 2. In essence, all the nodes with a priority of 1 are at the beginning
		//of the list, all the nodes with a priority of 2 are in the middle of the
		//list, and all the nodes with a priority of 3 are at the end of the list.
		void push(string s, int p);
		//pushes a new node (with priority p and word s) onto the end of the stack
		//(remember to reset the last pointer)
		void addAtFront(string s, int p);
		//adds a new node (made from word s and priority p) to the beginning of the
		//list (remember to reset the first pointer)
		void addFirst(string s, int p);
		//adds the very first node (made from word s and priority p) to an empty list
		void addAtP2(string s, int p);
		// inserts a new node into the middle of the list right after the priority2 p2
		// pointer
		int removeAll(string w);
		//removes all occurrences of word w from the linked list
		//this is used to remove every word in the array of stop words from the
		//linked list; return the number of times the word w was removed from
		//the list
		string pop();
		//removes the last node from the linked list, and returns the word from the
		//node removed
};

#endif /* SLL_HPP_ */

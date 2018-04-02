/* Name: Louise Victoria Cancino, Devon Pirestani
 * TA: Nikhil Gothanker; Email Address: gnikhil@udel.edu; OH: Smith 201 on Wed from 3:30-5:30 PM
 * Due Date: 3/25/2018
 * This file contains the method definitions for the SLL class.
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

SLL::SLL() {
	first = NULL;
	last = NULL;
	p2 = NULL; // a special pointer used to insert a word with priority 2 into the linked list
	size = 0;
}

SLL::~SLL() {
	SNode *temp1 = first;
	SNode *temp2 = first->next;
	while (temp2 != NULL) {
		delete temp1;
		temp1 = temp2;
		temp2 = temp2->next;
	}
	delete temp1;
	size = 0;
}

void SLL::printSLL() {
	// prints out all of the nodes in the linked list
	SNode *temp = first;
	while (temp != NULL) {
		temp->printNode();
		cout << ", ";
		temp = temp->next;
	}
}

void SLL::printSLL(int p) {
	// only prints out nodes with priority p in the linked list
	SNode *temp = first;
	while (temp != NULL) {
		if (temp->priority == p) {
			temp->printNode();
			cout << ", ";
		}
		temp = temp->next;
	}
}

void SLL::priorityInsert(string s, int p) {
	/* creates a new node with s as the word and p as the priority
	 * if the priority is 1, it adds the new node to the beginning of the list
	 * if the priority is 3, it adds the node to the end of the list
	 * if it’s 2, it inserts it into the list right after pointer p2
	 * (which is the last node with a priority of 2)
	 * TL;DR: all the nodes with a priority of 1 are at the beginning of the list,
	 * all the nodes with a priority of 2 are in the middle of the list,
	 * and all the nodes with a priority of 3 are at the end of the list.
	 */
	if (size == 0) {
		addFirst(s, p);
	} else if (p == 1) {
		addAtFront(s, p);
	} else if (p == 2) {
		addAtP2(s, p);
	} else if (p == 3) {
		push(s, p);
	}
}

void SLL::push(string s, int p) {
	/* pushes a new node (with priority p and word s) onto the end of the stack
	 * (remember to reset the last pointer)
	 */
	SNode *temp = new SNode(s, p);
	last->next = temp;
	last = temp;
	size++;
}

void SLL::addAtFront(string s, int p) {
	/* adds a new node (made from word s and priority p) to the beginning of the
	 * list (remember to reset the first pointer)
	 */
	SNode *temp = new SNode(s, p);
	temp->next = first;
	first = temp;
	size++;
}

void SLL::addFirst(string s, int p) {
	// adds the very first node (made from word s and priority p) to an empty list
	if (first == NULL) {
		SNode *temp = new SNode(s, p);
		first = temp;
		last = temp;
		size++;
	}
}

void SLL::addAtP2(string s, int p) {
	// inserts a new node into the middle of the list right after the priority2 p2 pointer
	SNode *newSNode = new SNode(s, p);
	SNode *temp1 = first;
	SNode *temp2 = first->next;
	if (p2 == NULL) { // if p2 does not currently exist, create it
		p2 = newSNode;
		if (first->priority == 1) {
			while (temp2->priority != 1) {
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			p2->next = temp2;
			temp1->next = p2;
		} else if (first->priority == 3) {
			p2->next = first;
			first = p2;
		}
	} else { // insert another word with priority 2 using p2 and make p2 point to this new node
		while (temp1 != p2) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		newSNode->next = temp2;
		temp1->next = newSNode;
		p2 = newSNode;
	}
	size++;
}

int SLL::removeAll(string w) {
	/* removes all occurrences of word w from the linked list;
	 * this is used to remove every word in the array of stop words from the
	 * linked list; return the number of times w is removed from the list
	 */
	SNode *temp1 = first;
	SNode *temp2 = first->next;
	int count = 0;
	if (size == 2) { // for size 2 lists
		if (temp2->word == w) {
			pop();
			count++;
			if (temp1->word == w) {
				pop();
				count++;
			}
		} else if (first->word == w) {
			delete first;
			first = temp2;
			count++;
		}
	} else if ((size == 1) && (first->word == w)) { // for size 1 lists
		pop();
		count++;
	} else if (size > 2) { // for lists greater than size 2
		while (temp2->next != NULL) { // iterates through the list and deletes nodes with occurrence w
			if (temp2->word == w) {
				temp1->next = temp2->next;
				delete temp2;
				count++;
				temp2 = temp1->next;
				size--;
			} else {
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		if (temp2->word == w) { // deletes the last word in the list if it contains w
			delete last;
			count++;
			last = temp1;
			size--;
		}
		if (first->word == w) { // deletes the first word in the list if it contains w
			temp2 = first->next;
			delete first;
			count++;
			first = temp2;
			temp1 = first;
			temp2 = temp2->next;
			size--;
		}
	}
	return count;
}

string SLL::pop() {
	/* removes the last node from the linked list and returns the word from the
	 * node removed
	 */
	SNode *temp1 = first;
	string tempWord;
	if (size == 0) { // if there are no nodes, do nothing
		tempWord = "";
	} else if (size == 1) { // if there is 1 node, remove just the one
		tempWord = first->word;
		delete first;
		first = NULL;
		last = NULL;
		size--;
	} else { // if there is more than 1 node, delete the last node
		SNode *temp2 = first->next;
		while (temp2 != NULL) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		tempWord = last->word;
		delete last;
		last = temp1;
		size--;
	}
	return tempWord;
}

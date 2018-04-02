/* Name: Louise Victoria Cancino, Devon Pirestani
 * TA: Nikhil Gothanker; Email Address: gnikhil@udel.edu; OH: Smith 201 on Wed from 3:30-5:30 PM
 * Due Date: 3/25/2018
 * Purpose of this lab: The purpose of this lab is to process an HTML file, get rid of its tags,
 * create a linked list with nodes consisting of words and their priorities, create another
 * linked list similar to the previous linked list except with all the stop words removed,
 * and then print both of them out. This file contains main().
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;
int main() {
	WebTopic *x = new WebTopic("webpage.html");
	x->readFile();
	x->printPage();
	return 0;
}

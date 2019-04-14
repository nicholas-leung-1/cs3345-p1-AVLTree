/*
 * AVLNode.h
 *
 *  Created on: Feb 20, 2019
 *      Author: Nicholas Leung
 *      		nml170001
 */

#ifndef AVLNODE_H_
#define AVLNODE_H_

#include <string>
#include <iostream>

#include "book.h"

// Node for AVL tree
class AVLNode
{
	public:
		// Key
		std::string key;
		// Book value
		book value;
		// Node height
		int height;
		// Children
		AVLNode *leftPtr;
		AVLNode *rightPtr;
		// Constructors
		AVLNode();
		AVLNode(std::string aKey, book aValue, AVLNode *aLeftPtr, AVLNode *aRightPtr);
		AVLNode(std::string aKey, book aValue, int aHeight, AVLNode *aLeftPtr, AVLNode *aRightPtr);
		// Functions
		void displayNode();
};

// Default construction
AVLNode::AVLNode()
	: key(), value(), height(), leftPtr(), rightPtr()
{

}

// Constructor with 4 variables
AVLNode::AVLNode(std::string aKey, book aValue, AVLNode *aLeftPtr, AVLNode *aRightPtr)
{
	key = aKey;
	value = aValue;
	height = -1;
	leftPtr = aLeftPtr;
	rightPtr = aRightPtr;
}

// Constructor with 5 variables
AVLNode::AVLNode(std::string aKey, book aValue, int aHeight, AVLNode *aLeftPtr, AVLNode *aRightPtr)
{
	key = aKey;
	value = aValue;
	height = aHeight;
	leftPtr = aLeftPtr;
	rightPtr = aRightPtr;
}

// Display node properties
void AVLNode::displayNode()
{
	std::cout << std::endl;
	std::cout << "ISBN:   " << key << std::endl;
	std::cout << "Title:  " << value.title << std::endl;
	std::cout << "Author: " << value.name << std::endl;
	std::cout << "Height: " << height << std::endl;
}

#endif /* AVLNODE_H_ */

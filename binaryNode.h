/*
 * binaryNode.h
 *
 *  Created on: Feb 28, 2019
 *      Author: Nicholas Leung
 *      		nml170001
 */

#ifndef BINARYNODE_H_
#define BINARYNODE_H_

#include <string>
#include <iostream>

#include "book.h"

// Node for binary tree
class binaryNode
{
	public:
		// Key
		std::string key;
		// Book value
		book value;
		// Node height
		int height;
		// Hidden key for random insertion
		int hiddenKey;
		// Children
		binaryNode *leftPtr;
		binaryNode *rightPtr;
		// Constructors
		binaryNode();
		binaryNode(std::string aKey, book aValue, int aHidden, binaryNode *aLeftPtr, binaryNode *aRightPtr);
		binaryNode(std::string aKey, book aValue, int aHeight, int aHidden, binaryNode *aLeftPtr, binaryNode *aRightPtr);
		// Functions
		void displayNode();
};

// Default construction
binaryNode::binaryNode()
	: key(), value(), height(), hiddenKey(), leftPtr(), rightPtr()
{

}

// Constructor with 5 variables
binaryNode::binaryNode(std::string aKey, book aValue, int aHiddenKey, binaryNode *aLeftPtr, binaryNode *aRightPtr)
{
	key = aKey;
	value = aValue;
	height = -1;
	hiddenKey = aHiddenKey;
	leftPtr = aLeftPtr;
	rightPtr = aRightPtr;
}

// Constructor with 6 variables
binaryNode::binaryNode(std::string aKey, book aValue, int aHeight, int aHiddenKey, binaryNode *aLeftPtr, binaryNode *aRightPtr)
{
	key = aKey;
	value = aValue;
	height = aHeight;
	hiddenKey = aHiddenKey;
	leftPtr = aLeftPtr;
	rightPtr = aRightPtr;
}

// Display node properties
void binaryNode::displayNode()
{
	std::cout << std::endl;
	std::cout << "ISBN:   " << key << std::endl;
	std::cout << "Title:  " << value.title << std::endl;
	std::cout << "Author: " << value.name << std::endl;
	std::cout << "Height: " << height << std::endl;
}

#endif /* BINARYNODE_H_ */

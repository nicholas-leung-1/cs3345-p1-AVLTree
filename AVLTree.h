/*
 * AVLTree.h
 *
 *  Created on: Feb 20, 2019
 *      Author: Nicholas Leung
 *				nml170001
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <string>
#include <iostream>

#include "book.h"
#include "AVLNode.h"

// Self balancing binary search tree
class AVLTree
{
	public:
		// Root node
		AVLNode *root;
		// Constructor
		AVLTree();
		// Functions
		AVLNode* insert(AVLNode *node, book info, std::string key);
		AVLNode* balance(AVLNode *node);
		AVLNode* rrRotate(AVLNode *node);
		AVLNode* llRotate(AVLNode *node);
		AVLNode* rlRotate(AVLNode *node);
		AVLNode* lrRotate(AVLNode *node);
		int getHeight(AVLNode *node);
		int getBalance(AVLNode *node);
		void adjust(AVLNode *node);
		void display(AVLNode *node);
};

// Default constructor
AVLTree::AVLTree()
	:root()
{

}

// Insert a node
AVLNode* AVLTree::insert(AVLNode *node, book info, std::string key)
{
	// If place of insertion found
	if (node == nullptr)
	{
		node = new AVLNode(key, info, 0, nullptr, nullptr);
		return node;
	}
	std::string nodeKey = node->key;
	// Go left
	if (key.compare(nodeKey) < 0)
	{
		node->leftPtr = insert(node->leftPtr, info, key);
		node = balance(node);
	}
	// Go right
	else if (key.compare(nodeKey) > 0)
	{
		node->rightPtr = insert(node->rightPtr, info, key);
		node = balance(node);
	}
	return node;
}

// Determine if the tree needs to be balanced
AVLNode* AVLTree::balance(AVLNode *node)
{
	int balance = getBalance(node);
	if (balance < -1)
	{
		// Right left rotation
		if (getBalance(node->rightPtr) > 0)
		{
			std::cout << "\nImbalance occurred at inserting ISBN " << node->key
						<< "; fixed in LeftRight Rotation\n" << std::endl;
			node = rlRotate(node);
		}
		// Right rotation
		else
		{
			std::cout << "\nImbalance occurred at inserting ISBN " << node->key
						<< "; fixed in Right Rotation\n" << std::endl;
			node = rrRotate(node);
		}

	}
	if (balance > 1)
	{
		// Left rotation
		if (getBalance(node->leftPtr) > 0)
		{
			std::cout << "\nImbalance occurred at inserting ISBN " << node->key
							<< "; fixed in Left Rotation\n" << std::endl;
			node = llRotate(node);
		}
		// Right left rotation
		else
		{
			std::cout << "\nImbalance occurred at inserting ISBN " << node->key
						<< "; fixed in RightLeft Rotation\n" << std::endl;
			node = lrRotate(node);
		}
	}
	return node;
}

// Right rotation
AVLNode* AVLTree::rrRotate(AVLNode *node)
{
	AVLNode *temp;
	temp = node->rightPtr;
	node->rightPtr = temp->leftPtr;
	temp->leftPtr = node;
	return temp;
}

// Left rotation
AVLNode* AVLTree::llRotate(AVLNode *node)
{
	AVLNode *temp;
	temp = node->leftPtr;
	node->leftPtr = temp->rightPtr;
	temp->rightPtr = node;
	return temp;
}

// Right left rotation
AVLNode* AVLTree::rlRotate(AVLNode *node)
{
	AVLNode *temp;
	temp = node->rightPtr;
	node->rightPtr = llRotate(temp);
	return rrRotate(node);
}

// Left right rotation
AVLNode* AVLTree::lrRotate(AVLNode *node)
{
	AVLNode *temp;
	temp = node->leftPtr;
	node->rightPtr = rrRotate(temp);
	return llRotate(node);
}

// Get height of a certain node
int AVLTree::getHeight(AVLNode *node)
{
	if (node != nullptr)
	{
		int leftHeight = getHeight(node->leftPtr);
		int rightHeight = getHeight(node->rightPtr);
		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
	}
	return 0;
}

// Get balance of a certain node
int AVLTree::getBalance(AVLNode *node)
{
	if (node != nullptr)
	{
		int leftHeight = getHeight(node->leftPtr);
		int rightHeight = getHeight(node->rightPtr);
		return leftHeight - rightHeight;
	}
	return 0;
}

// Adjust heights of the nodes
void AVLTree::adjust(AVLNode *node)
{
	if (node != nullptr)
	{
		adjust(node->leftPtr);
		node->height = getHeight(node) - 1;
		adjust(node->rightPtr);
	}
}

// Display tree
void AVLTree::display(AVLNode *node)
{
	if (node != nullptr)
	{
		display(node->leftPtr);
		node->displayNode();
		display(node->rightPtr);
	}
}

#endif /* AVLTREE_H_ */

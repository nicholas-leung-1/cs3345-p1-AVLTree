/*
 * binaryTree.h
 *
 *  Created on: Feb 28, 2019
 *      Author: Nicholas Leung
 *      		nml170001
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <string>
#include <iostream>
#include <queue>

#include "book.h"
#include "binaryNode.h"

// Random binary tree
class binaryTree
{
	public:
		// Root node
		binaryNode *root;
		// Constructor
		binaryTree();
		// Functions
		binaryNode* randomInsert(binaryNode *node, book info, std::string key, int hiddenKey);
		binaryNode* levelOrderInsert(binaryNode *node, book info, std::string key); // UNUSED
		void treeBalance(binaryNode *node);
		void balance(binaryNode *node);
		void treeOrder(binaryNode *node);
		int getHeight(binaryNode *node);
		int getBalance(binaryNode *node);
		bool getOrder(binaryNode *node);
		void adjust(binaryNode *node);
		void display(binaryNode *node);
};

// Default constructor
binaryTree::binaryTree()
	: root()
{

}

// Insert node into a random binary tree
binaryNode* binaryTree::randomInsert(binaryNode *node, book info, std::string key, int hidden)
{
	if (node == nullptr)
	{
		node = new binaryNode(key, info, 0, hidden, nullptr, nullptr);
		return node;
	}
	if (hidden < node->hiddenKey)
	{
		node->leftPtr = randomInsert(node->leftPtr, info, key, hidden);
	}
	else if (hidden > node->hiddenKey)
	{
		node->rightPtr = randomInsert(node->rightPtr, info, key, hidden);
	}
	return node;
}

// Insert node into random binary tree in level order
// UNUSED
binaryNode* binaryTree::levelOrderInsert(binaryNode *node, book info, std::string key)
{
	// If first node
	if (node == nullptr)
	{
		node = new binaryNode(key, info, 0, nullptr, nullptr);
		return node;
	}
	std::queue<binaryNode*> order;
	order.push(node);
	// Searching for insertion spot
	while (!order.empty())
	{
		// Grab next node to see if spot of insertion is one of its children slots
		binaryNode* temp = order.front();
		order.pop();
		// If insertion spot is found to the left of the node
		if (temp->leftPtr == nullptr)
		{
			binaryNode *newNode = new binaryNode(key, info, 0, nullptr, nullptr);
			temp->leftPtr = newNode;
			break;
		}
		// Push left child onto stack to be checked later
		else
		{
			order.push(temp->leftPtr);
		}
		// If insertion spot is found to the right of the node
		if (temp->rightPtr == nullptr)
		{
			binaryNode *newNode = new binaryNode(key, info, 0, nullptr, nullptr);
			temp->rightPtr = newNode;
			break;
		}
		// Push right child onto stack to be checked later
		else
		{
			order.push(temp->rightPtr);
		}
	}
	return node;
}

// Check balance of the tree
void binaryTree::treeBalance(binaryNode *node)
{
	if (node != nullptr)
	{
		treeBalance(node->leftPtr);
		balance(node);
		treeBalance(node->rightPtr);
	}
}

// Detect if the node is unbalanced
void binaryTree::balance(binaryNode *node)
{
	int balance = getBalance(node);
	if (balance < -1)
	{
		// Right left rotation needed
		if (getBalance(node->rightPtr) > 0)
		{
			std::cout << "\nImbalance occurred at ISBN " << node->key
						<< "; fix with LeftRight Rotation";
		}
		// Right rotation needed
		else
		{
			std::cout << "\nImbalance occurred at ISBN " << node->key
						<< "; fix with Right Rotation";
		}
	}
	if (balance > 1)
	{
		// Left rotation needed
		if (getBalance(node->leftPtr) > 0)
		{
			std::cout << "\nImbalance occurred at ISBN " << node->key
							<< "; fix with Left Rotation";
		}
		// Right left rotation needed
		else
		{
			std::cout << "\nImbalance occurred at ISBN " << node->key
						<< "; fix with RightLeft Rotation";
		}
	}
}

// Check BST order of the tree
void binaryTree::treeOrder(binaryNode *node)
{
	if (node != nullptr)
	{
		treeOrder(node->leftPtr);
		if (!getOrder(node))
		{
			std::cout << "BST order violation occurred at ISBN " << node->key << std::endl;
		}
		treeOrder(node->rightPtr);
	}
}

// Get height of the given node
int binaryTree::getHeight(binaryNode *node)
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

// Get balance of the given node
int binaryTree::getBalance(binaryNode *node)
{
	if (node != nullptr)
	{
		int leftHeight = getHeight(node->leftPtr);
		int rightHeight = getHeight(node->rightPtr);
		return leftHeight - rightHeight;
	}
	return 0;
}

// Determine if the node follows BST order
// Determine if the node's left child is smaller than the right child
bool binaryTree::getOrder(binaryNode *node)
{
	// No children
	if (node->leftPtr == nullptr && node->rightPtr == nullptr)
	{
		return true;
	}
	// Just a left child
	else if (node->rightPtr == nullptr)
	{
		std::string nodeKey = node->key;
		std::string leftKey = node->leftPtr->key;
		if (nodeKey.compare(leftKey) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// Just a right child
	else if (node->leftPtr == nullptr)
	{
		std::string nodeKey = node->key;
		std::string rightKey = node->rightPtr->key;
		if (nodeKey.compare(rightKey) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// Both a left and right child
	else
	{
		std::string nodeKey = node->key;
		std::string leftKey = node->leftPtr->key;
		std::string rightKey = node->rightPtr->key;
		if (nodeKey.compare(leftKey) > 0 && nodeKey.compare(rightKey) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

// Adjust heights of the nodes
void binaryTree::adjust(binaryNode *node)
{
	if (node != nullptr)
	{
		adjust(node->leftPtr);
		node->height = getHeight(node) - 1;
		adjust(node->rightPtr);
	}
}

// Display tree
void binaryTree::display(binaryNode *node)
{
	if (node != nullptr)
	{
		display(node->leftPtr);
		node->displayNode();
		display(node->rightPtr);
	}
}

#endif /* BINARYTREE_H_ */

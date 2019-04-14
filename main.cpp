/*
 * main.cpp
 *
 *  Created on: Feb 20, 2019
 *      Author: Nicholas Leung
 *      		nml170001
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <ctime>

#include "AVLTree.h"
#include "AVLNode.h"
#include "binaryTree.h"
#include "binaryNode.h"
#include "book.h"

// Create an AVL and random binary tree with the same given set of items
int main()
{
	// AVL Tree
	// Create the AVL Tree
	AVLTree aTree;
	std::ifstream inAVL;
	inAVL.open("test.txt");
	std::cout << "AVL Insertion: \n\n";
	// Insert all items
	while (inAVL)
	{
		std::string theISBN;
		std::string theTitle;
		std::string theName;
		inAVL >> theISBN >> theTitle >> theName;
		book toAdd(theTitle, theName);
		// Inserts into, checks balance, and balances tree
		if (!theISBN.empty())
		{
			std::cout << "Insert book with ISBN:" << theISBN << std::endl;
			aTree.root = aTree.insert(aTree.root, toAdd, theISBN);
			aTree.adjust(aTree.root);
		}
	}
	// Display tree
	std::cout << "\n\n\nAVL Tree: \n";
	aTree.display(aTree.root);

	// Random binary tree
	// Create random order for the random binary tree
	srand((int) time(0));
	int array[15];
	int index = 0;
	while(index < 15)
	{
		int hiddenKey = (rand() % 15);
		bool check = true;
		for (int k = 0; k < index; k++)
		{
			if (array[k] == hiddenKey)
			{
				check = false;
			}
		}
		if (check)
		{
			array[index] = hiddenKey;
			index++;
		}
	}

	// Create the random binary tree
	binaryTree bTree;
	std::ifstream inBinary;
	inBinary.open("test.txt");
	std::cout << "\n\n\n\n\nBinary Insertion: \n\n";
	// Insert all items
	int count = 0;
	while (inBinary)
	{
		std::string theISBN;
		std::string theTitle;
		std::string theName;
		inBinary >> theISBN >> theTitle >> theName;
		book toAdd(theTitle, theName);
		// Inserts into tree
		if (!theISBN.empty())
		{
			std::cout << "Insert book with ISBN:" << theISBN << std::endl;
			bTree.root = bTree.randomInsert(bTree.root, toAdd, theISBN, array[count]);
			bTree.adjust(bTree.root);
			count++;
		}
	}
	// Display tree
	std::cout << "\n\n\nBinary Tree: \n";
	bTree.display(bTree.root);
	// Check BST order
	std::cout << "\n\n\nCheck BST Order: \n\n";
	bTree.treeOrder(bTree.root);
	// Check balance
	std::cout << "\n\n\nCheck Balance: \n";
	bTree.treeBalance(bTree.root);
	return 0;
}

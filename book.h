/*
 * book.h
 *
 *  Created on: Feb 20, 2019
 *      Author: Nicholas Leung
 *      		nml170001
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <iostream>

// Book, holds title and author name
class book
{
	public:
		// Book title
		std::string title;
		// Author name
		std::string name;
		// Constructors
		book();
		book(std::string aTitle, std::string aName);

};

// Default constructor
book::book()
	: title(), name()
{

}

// Constructor
book::book(std::string aTitle, std::string aName)
	: title(aTitle), name(aName)
{

}

#endif /* BOOK_H_ */

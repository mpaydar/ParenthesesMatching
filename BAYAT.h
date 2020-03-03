/*
 * BAYAT.h
 *
 *  Created on: Mar 2, 2020
 *      Author: USER
 */




#ifndef BAYAT_H_
#define BAYAT_H_




class stack;
class Node
{
public:
	Node ()
	{
		next=NULL;
		pre=NULL;
	}


private:
	Node * next;
	Node * pre;
	char element;
	friend class stack;
};



# include <iostream>

class stack
{
private:
	Node * top;
	Node * bottom;
public:
	stack ()
{
		top=NULL;
		bottom=NULL;
}

	void pushing (std::string& );
	void pop ();

};




#endif /* BAYAT_H_ */

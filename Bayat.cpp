/*
 * Bayat.cpp
 *
 *  Created on: Mar 2, 2020
 *      Author: USER
 */






// global variable

# include <iostream>
# include "BAYAT.h"

static bool isnotMatch=false;

void stack :: pushing(std::string& a)
{

		int counter=0;					// counter variable holding the number of iteration
    	int size=a.length();
    	for(int k=0;k<size;k++)
    	{
    		counter++;

    	    if(a[k]=='(' || a[k]=='{' || a[k]=='[' )			// first if
    	    		{
    	    		 Node * new_node=new Node;
    	    		 new_node->element=a[k];


    	    			if(top==NULL)								// second if
    	    				{

    	    					top=new_node;
    	    					top->pre=NULL;
    	    					top->next=NULL;
    	    				}
    	    			else										// first else
    	    				{
    	    					Node * temp=top;
    	    					top->next=new_node;
    	    					top=new_node;
    	    					new_node->pre=temp;
    	    				}
    	    		}

    	    	// EDGE Case: there is a scenario where the stack is empty but we still need to evaluate the rest of the string
    	         if (top==NULL && counter!=size)
    	        	 {
    	        	    		continue;				// go to the next index for the loop
    	        	 }



    	        else if(top->element=='('&& a[k]==')' )
    	    	     {
    	    	    	pop();
    	    	     }
    	        else if(top->element=='{'&& a[k]=='}' )
    	    	    {
    	    	       pop();
    	    	    }
    	        else if(top->element=='['&& a[k]==']' )
    	    	    {
    	    	       pop();
    	    	    }




    	}



    	// for case 3 ((()) where there are left over in the stack or open parentheses at the beginning ;or close parentheses at the end

    	if(top!=NULL || a[0]==')' || a[size-1]=='(')
    	{
    	isnotMatch=true;
    	}
    	// same as case 3 with different form of parentheses;
    	else if(top!=NULL || a[0]==']' || a[size-1]=='[')
    	{
    		isnotMatch=true;
    	}


    	// same as case 3 with different form of parentheses;
    	else if(top!=NULL || a[0]=='}' || a[size-1]=='{')
    	{
    		isnotMatch=true;
    	}



    	// isnotMatch bool is becomes true when case2 or case3 occurs

    	if(isnotMatch)
    	{
    		std::cout << "Parentheses not matched!" << std::endl;
    	}
    	else
    	{
    		std::cout << "Parentheses Matched!" << std::endl;
    	}


}



void stack::pop()
{

	if(top==NULL)
	{
		std::cout << "Underflow condition";
	}

	else
	{
		Node * remove=top;
		top=remove->pre;
		delete remove;
	}

}






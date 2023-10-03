/**
 * @file main.cpp
 * @author DSN
 * @brief This program implements a stack using a fixed-size array
 * @version 0.1
 * @date 2023-07-15
 * 
 */

#include "stack.h"

int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();
    
    stack.push(4);

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
    // stack.pop(); 

	stack.print();

	return 0;
}

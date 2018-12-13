//Header file of the class template Stack

#ifndef _STACK
#define _STACK

#include<iostream>
using namespace std;
template<class ItemType>
class Stack
{
private:
	ItemType items[100];
	int top;  //index of the item that is on the top of the stack
	int getCurrentTop() {
		return top;
	}
	void setCurrentTop(int s) {
		top = s;
	}
public:
	Stack();
	bool isEmpty();
	bool push(ItemType newItem);
	bool pop();
	ItemType peek();
	void clean();
	bool display();
};
template<class ItemType>
Stack<ItemType>::Stack()
{
	setCurrentTop(-1);
}
template<class ItemType>
bool Stack<ItemType>::isEmpty()
{
	return (top == -1);
}
template<class ItemType>
bool Stack<ItemType>::push(ItemType newItem)
{
	if (top == 99) {
		cout << "Push failed, the Stack is full!\n";
		return false;
	}
	else {
		items[top + 1] = newItem;
		top++;
		return true;
	}
}
template<class ItemType>
bool Stack<ItemType>::pop()
{
	if (isEmpty()) {
		cout << "Pop failed, the stack is empty\n";
		return false;
	}
	else {
		top--;
		return true;
	}
}
template<class ItemType>
ItemType Stack<ItemType>::peek()
{
	if (isEmpty()) {
		cout << "The stack is empty, program aborted!\n";
		exit(0);
	}
	else {
		return items[top];
	}
}
template<class ItemType>
void Stack<ItemType>::clean()
{
	setCurrentTop(-1);
}
template<class ItemType>
bool Stack<ItemType>::display()
{	
	if (isEmpty()) {
		cout << "It is an empty stack!\n";
		return false;
	}
	else {
		cout << "The stack contains following items:\n";
		for (int i = 0; i <= top; i++)
			cout << items[i] << endl;
		return true;
	}
}
#endif
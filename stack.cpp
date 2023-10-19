#include<iostream>
using namespace std;



struct node {
	int info;
	struct node *next;

};

class stack {

	typedef struct node *nodeptr;
	nodeptr top;
	public:
		stack();
		void push(int x);
		int pop();
		int topdata();
		int isempty();
	



};

 stack::stack(){
 
 	top = NULL;
 
 }

void stack::push(int x){

	nodeptr p;
	p = new node;
	p -> info = x;
	p -> next = top;
	top = p;


}

int stack::pop(){

	nodeptr p;
	p = top;
	int x = p -> info;
	top = top -> next;//check whether here top = p -> next
	delete p;
	
	return x;

}

int stack::isempty(){

	if ( top == NULL){
		
		return 1;
	}
	else{
		
		return 0;
	}


}

int stack::topdata(){


	
	return top ->info;


}



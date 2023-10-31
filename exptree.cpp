
#include<string.h>
#include<iostream>


using namespace std;


struct tnode {

	char info;
	tnode *lc;
	tnode *rc;


};


class exptree{
	char post[20];
	public:
		exptree();
		void postexp();
		//void recin( nodeptr r);

	typedef struct tnode *nodeptr;
};
exptree::exptree(){



};


class stack{

tnode *data[20];

int top;

public:
	stack(){ top = -1;}
	void push ( tnode *);
	tnode* pop();
	int gettop();
	int isempty();




};

void stack::push( tnode *p){

	data[++top] = p;

}

tnode* stack::pop(){

return data[top--];

}

int stack::isempty(){

	if  ( top == -1){
	return 1;
	
	}
return 0;
}

int stack::gettop(){

	return top;
}
void exptree::postexp(){
	stack s;
	cout<<"Enter the postfix expression"<<endl;
	cin>>post;
	nodeptr root;
	nodeptr p;
	for ( int i =0; i<strlen(post); i++){
		
		char x = post[i];
		
		
		if ( isalnum(x)){
		
			p = new tnode;
			p -> rc = NULL;
			p -> lc = NULL;
			p -> info = x;
			s.push(p);
		
		}
		
		
		else{
		
		p  -> info = x;
		
		 p -> rc = s.pop();
		p -> lc = s.pop();
		
		s.push(p);
		
		}
	
	}
	
	root = s.pop();
	
	cout<<root -> info<<endl;

}

/*void exptree::recin( nodeptr r){

	nodeptr p;
	
	if ( p != NULL){
	
	recin( p -> lc);
	p -> info;
	}



}*/

int main(){

exptree e;

e.postexp();






}


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
		tnode *root;
		exptree();
		void create();
		void recin( tnode *p);
		void recpre( tnode *p);
		void recpost( tnode *p);
		void nrin( tnode *p);
		void nrpre( tnode *p);
		void nrpost ( tnode *p);
	
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
void exptree::create(){
	stack s;
	cout<<"Enter the postfix expression"<<endl;
	cin>>post;
	
	tnode *p;
	for ( int i =0; i<strlen(post); i++){
		p = new tnode;
		p -> info = post[i];
		p -> lc = NULL;
		p -> rc = NULL;
		
		if ( isalnum(post[i])){
		
			s.push(p);
		}
		else {
		
			p -> rc = s.pop();
			p -> lc = s.pop();
			s.push(p);
		
		}
	
	}
	
	root = s.pop();
	
	cout<<root -> info<<endl;

}

void exptree::recin( tnode *p){

	
	
	if ( p != NULL){
	
	recin( p -> lc);
	cout<<p -> info;
	
	recin( p -> rc);
	}



}

void exptree::recpost( tnode *p){


	if ( p!= NULL){
	
		recpost( p -> lc);
		recpost( p -> rc);
		cout<<p -> info;
	
	}


}

void exptree::recpre( tnode *p){

	if ( p!= NULL){
	
		cout<<p ->info;
		recpre( p -> lc);
		recpre( p -> rc);
	
	
	}




}

void exptree::nrin(tnode *p){

	stack s;
	
	while ( p!= NULL || !s.isempty()){
	
		if ( p!= NULL){
			s.push(p);
			p = p ->lc;
		
		}
		else {
		
			p = s.pop();
			
			cout<<p -> info;
			p = p -> rc;
		
		
		}
	
	
	
	
	}




}

void exptree::nrpre( tnode *p){
stack s;
	
	while ( p!= NULL || !s.isempty()){
	
		if ( p!= NULL){
			s.push(p);
			cout<<p -> info;
			p = p ->lc;
		
		}
		else {
		
			p = s.pop();
			
			
			p = p -> rc;
		
		
		}
	
	
	
	
	}




}

void exptree::nrpost( tnode *p){

	stack s1,s2;
	
	s1.push(p);
	
	while ( !s1.isempty()){
	
		p = s1.pop();
		s2.push(p);
		
		if ( (p -> lc)!= NULL){
		
			s1.push( p -> lc);
		
		}
		if ( (p -> rc) != NULL){
		
			s1.push( p -> rc);
		}
	
	}

	while ( !s2.isempty()){
	
		p = s2.pop();
		cout<< p -> info;
	
	
	}




}

int main(){

exptree e;

e.create();
int ch1;
do {
	cout<<"***********************Menu*************************"<<endl;
	int ch2;
	cout<<"1.Recursive way \n2.Non-Recursive way \n3.Exit"<<endl;
	cin>>ch1;
	
	switch( ch1){
	
	
		case 1: do{cout<<"1.Preorder \n2.Inorder \n3.Postorder \n4.Exit"<<endl;
			cin>>ch2;
			
			switch( ch2){
			
				case 1: e.recpre( e.root);
					cout<<endl;
					break;
					
				case 2: e.recin( e.root);
					cout<<endl;
					break;
					
				case 3: e.recpost( e.root);
					cout<<endl;
					break;
			
			
			
			
			
			}
			
			}while ( ch2 < 4);
	
			break;
	
		case 2: do{cout<<"1.Preorder \n2.Inorder \n3.Postorder \n4.Exit"<<endl;
			cin>>ch2;
			
			switch( ch2){
			
				case 1: e.nrpre( e.root);
					cout<<endl;
					break;
					
				case 2: e.nrin( e.root);
					cout<<endl;
					break;
					
				case 3: e.nrpost( e.root);
					cout<<endl;
					break;
			
			
			
			
			
			}
			
			}while ( ch2 < 4);
	
		break;
	
	
	
	}













}while ( ch1 < 3);


}

#include<string.h>
#include<iostream>
#include<cmath>


using namespace std;


struct tnode {

	int info;
	tnode *lc;
	tnode *rc;


};


class bst{
	
	
	public:
		int flag = 0;
		tnode *root;
		bst(){ root = NULL;}
		void search(tnode* p,int key);
		tnode* insert(tnode* p, int key);
		tnode* newnode(int z);
		tnode* deletenode( int key);
		
		void inorder(tnode *p);
		void preorder(tnode *p);
		void postorder(tnode *p);
	
};

tnode* bst::newnode( int z){

	tnode* x;
	
	 x = new tnode;
	 x -> info = z;
	 x -> lc = x -> rc = NULL;
	 return x;



}


tnode* bst::insert( tnode *p, int key){
	tnode *temp;
	if ( p == NULL){
		
		p = newnode(key);
	
	}else{
	
		if( key < p -> info){
		
			p-> lc = insert(p -> lc, key);
		
		}
		else if( key > p -> info){
		
			p -> rc = insert( p -> rc, key);
		
		}
		else if ( key == p -> info){
		
			cout<<"Duplicate key"<<endl;
		
		}

	}

	return p;

}

void bst::search( tnode *p,int key){
	if ( p -> info != NULL){
	if ( p -> info == key ){
		cout<<"Key Found: "<<p -> info<<endl;
		flag = 1;
	}
	else if ( key < p -> info ){
			search( p -> lc , key);
		
		}
		else if ( key > p -> info ){
		
			search( p -> rc, key);
		
		}
	
		
	
	}
	else {
	
	cout<<"Key not found"<<endl;
	}

	


}

void bst::inorder(tnode *p){


	if ( p != NULL){
	
	inorder( p -> lc);
	cout<<p -> info<<endl;
	
	inorder( p -> rc);
	}


}

void bst::preorder( tnode *p){

	if ( p!= NULL){
	
		cout<<p ->info;
		preorder( p -> lc);
		preorder( p -> rc);
	
	
	}


}

void bst::postorder( tnode *p){

	if ( p!= NULL){
	
		postorder( p -> lc);
		postorder( p -> rc);
		cout<<p -> info;
	
	}


}

int main(){

bst b;

b.root = b.insert(b.root,10);

b.insert(b.root,5);
b.insert(b.root,20);
b.insert(b.root,3);
b.insert(b.root,15);
b.insert(b.root,17);
b.insert(b.root,19);
b.insert(b.root,1);
b.insert(b.root,4);
b.insert(b.root,4);

b.inorder(b.root);
b.search(b.root, 200);







}

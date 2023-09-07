#include<iostream>

using namespace std;


 class list{
struct node {


  int info;

  struct node *next;



};

typedef struct node *nodeptr;
nodeptr listptr;

public:
  list();
  ~list();
  void push(int newvalue);
  void insertafter(int oldvalue, int newvalue);
   void deletenode(int oldvalue);
  void display();

 };



  list::list(){

  listptr = 0;

}

 list:: ~list(){

  

}


void list::push ( int newvalue){


  nodeptr p;

  p = new node;

  p -> info = newvalue;

  //p -> next = listptr;

  listptr = p;




}

void list::insertafter(int oldvalue, int newvalue){

  nodeptr p,q;




  for ( p= listptr; p!= 0 && p -> info != oldvalue; p = p -> next){

    if (p==0){
      cout<<"No data found"<<endl;

    }
  }
    
  q = new node;

  q -> info = newvalue;
  q -> next = p -> next;
  p -> next = q;







}


void list::display(){
  nodeptr p;

  

  for ( p = listptr; p!=0;p = p -> next){
   
    cout<<p->info<<endl;
    

  }
  
 
}

void list::deletenode(int oldvalue){

 
nodeptr p,q;

  for ( p = listptr; p -> next != 0 && ( p -> next) -> info != oldvalue; p = p -> next){


    if ( p == 0){
      cout<<"no data found"<<endl;
    }


  }

  q = p -> next;

  p -> next = q -> next;
  q -> next = 0;
  delete q;


}


int main (){

  list l;
  
  l.push(10);
 
   l.insertafter(10,20);
  l.insertafter(20,30);
   l.insertafter(30,40);
   l.deletenode(40);
   l.insertafter(30,50);
   l.insertafter(50,60);
   l.deletenode(50);
  l.display();



}
  

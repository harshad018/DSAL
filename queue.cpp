#include<iostream>

using namespace std;

class Queue{

	int a[5];

	int front;
	int rear;
	
	
	public:
		Queue();
		int isEmpty();
		int isFull();
		void enqueue(int x);
		void dequeue();
		void deletion();
		void display();


};

Queue::Queue(){
	 front = -1;
	rear = -1;
}
int Queue::isEmpty(){

	if (  front == -1){
	
		cout<<"Queue is empty"<<endl;
		return 1;
	
	}
	
	else{
		cout<<"Queue is not empty"<<endl;
		return 0;
	
	}



}
void Queue::enqueue(int x){

	 if ( isFull()){
	 
	 	cout<<"The queue is full, so can't perform this operation"<<endl;
	 
	 	//a[front + 1] = x;
	 	//front++;
	 	//rear = front;
	 
	 }
	 else {
	 
	 	if ( front == -1){
	 	front = rear = 0;
	 	
	 	
	 
	 	
	 	}
	 	
	 	else {
	 	
	 	
	 	rear = (rear +1)%5;
	 	}
	 	//a[rear +1] = x;
	 	//rear++;
	 a[rear] = x;
	 }


}


void Queue::dequeue(){

	if ( isEmpty()){
	
		cout<<"The Queue has no data"<<endl;
	
	}
	else {
		int temp = a[front];
		
		front = (front+1)%5;
		if ( front == ((rear +1)%5)){
		
			front = rear = -1;
		}
		cout<<temp<<endl;
	}





}

int Queue::isFull(){

	if ( front == ( rear +1)%5) {
	
	
	cout<<"Queue is full"<<endl;
	return 1;
	
	}
	
	else {
	
		cout<<"Queue is not full"<<endl;
		return 0;
	}


}

void Queue::display(){

	for ( int i= front; i != rear; i = ((i+1)%5)){
		
		cout<<a[i]<<endl;
		
	
	}

	cout<<a[rear]<<endl;
}

int main(){
Queue q;
int k;
int ch;
do {
	
	cout<<"Enter Your Choice of Operation \n 1.isFull \n 2.isEmpty \n 3.enqueue \n 4.dequeue \n 5.display \n 6.Exit"<<endl;
	cin>>ch;

	switch(ch){
	
		case 1: q.isFull();
			break;
		
		case 2: q.isEmpty();
			break;
			
		case 3: cout<<"Enter the element to be added"<<endl;
			cin>>k;
			q.enqueue(k);
			break;
			
		case 4: q.dequeue();
			break;
			
		case 5:q.display();
			break;
			
		
	
	
	
	
	}






}while ( ch < 6);


//q.isEmpty();
//q.enqueue(1);
//q.enqueue(2);
//q.enqueue(3);
//q.enqueue(4);
//q.dequeue();
//q.isFull();
//q.display();
//q.isEmpty();





}

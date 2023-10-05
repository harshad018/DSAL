#include<iostream>
#include<cmath>
using namespace std;

class SEIT {


	
	struct student {
	int rn;
        string name;
	float sgpa;
	}s[20];
	
	
	
	
	public:
		int n;
		void setdata();
		void display();
		void search();
		void bubblesort();
		void bsearch();
		void insertsort();
		void quickdisplay();
		void quicksort(int l, int h);
		int Partition( int l, int h);
		
};


void SEIT::setdata(){

	cout<<"Enter number of students"<<endl;
	cin>>n;
	
	for ( int i = 0; i< n; i++){
	
		cout<<"Enter roll no, name, sgpa"<<endl;
		cin>>s[i].rn>>s[i].name>>s[i].sgpa;
	
	}

}

void SEIT::display(){


	for ( int j=0; j<n; j++){
	
		cout<<"Roll no: "<<s[j].rn<<endl;
		cout<<"name: "<<s[j].name<<endl;
		cout<<"sgpa: "<<s[j].sgpa<<endl;
	
	}


}
void SEIT::search(){
	float x;
	cout<<"Enter the sgpa"<<endl;
	cin>>x;

	for ( int p = 0; p < n ; p++){
	
	    if ( s[p].sgpa == x){
	    
	    	cout<<"Student found Roll no"<<s[p].rn<<endl;
	    	cout<<"Name"<<s[p].name<<endl;
	    	cout<<"Sgpa"<<s[p].sgpa<<endl;
	    
	    }
	
	}




}


void SEIT::bubblesort(){

	for ( int i = 0; i<n; i++){
	
		for ( int j=0; j<n-i-1; j++){
		
			if ( s[j].rn > s[j+1].rn){
			
				struct student temp  = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			
			}
		
		}
	
	}

display();

}

void SEIT::insertsort(){
	int key;
	int posi;

	for ( int i = 1; i<n; i++){
	
		
	
	
	
	}



}

void SEIT::bsearch(){
	string key;
	cout<<"Enter the name that you want to search"<<endl;
	cin>>key;
	int l=0; 
	int h = n-1;
	int m;
	
	while  ( l<= h){
	
		m = floor((l+h)/2);
		
		if ( key == s[m].name){
		
			cout<<"Key is found: "<<s[m].name<<endl;
			break;
		
		}
	
		else if ( key < s[m].name){
		
			h = m-1;
		
		}
		
		else if ( key > s[m].name){
		
			 l = m +1;
		}
	
	
	}
	
	cout<<"Key is not found"<<endl;

}

void SEIT::quicksort(int l, int h){
	
	int j;
	if ( l < h)
	{
	
		j = Partition(l,h);
		quicksort(l,j-1);
		quicksort(j+1, h);
	
	}

}

int SEIT::Partition(int l, int h){

	int i,j;
	struct student pvt,temp;
	pvt = s[l];
	i = l + 1;
	j = h;
	
	while ( i <= j){
	
		while ( s[i].sgpa <= pvt.sgpa){
			i++;
		}
		while ( s[j].sgpa > pvt.sgpa){
			j--;
		}
	
		if ( i < j){
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		
		
		}
	
	
	}

	s[l] = s[j];
	s[j] = pvt;
	
	return j;




}

void SEIT::quickdisplay(){
	int d;
	cout<<"Enter no of toppers that you want to see"<<endl;
	cin>>d;
	cout<<"Names of the toppers: "<<endl;
	for ( int i = n-1; i >= n-d; i--){
	
		cout<<"Roll no of the student: "<<s[i].rn<<endl;
		cout<<"Name of the student: "<<s[i].name<<endl;
		cout<<"sgpa of the student: "<<s[i].sgpa<<endl;
	
	
	}




}

int main (){

	SEIT a;
	a.setdata();
	int ch;
	
	do {
	
		cout<<"Enter your choice of operation"<<endl;
		
		cout<<"1.Bubblesort for roll no"<<endl;
		cout<<"2.binary search for Student name"<<endl;
		cout<<"3.Linear search for sgpa of student"<<endl;
		cout<<"4.Quicksort for the toppers list display"<<endl;
		cout<<"5.exit"<<endl;
		cin>>ch;
		switch (ch){
	
			case 0: cout<<"Please choose a valid operation"<<endl;
				break;
				
			case 1: a.bubblesort();
				break;
				
			case 2: a.bsearch();
				break;
				
			case 3: a.search();
				break;
				
			case 4: a.quicksort(0, a.n-1); a.quickdisplay();
				break;
		}
	
	}while ( ch < 5);
	
	}





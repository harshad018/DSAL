#include"stack.cpp"

#include<iostream>
#include<string.h>


using namespace std;

class expcon{


char inf[20],pre[20], post[20];

public:
	
	void inf2pre();
	void inf2post();
	void preeval();
	void posteval();
	void strreve(char a[]);
	int icp( char x);
	int isp( char x);
	int eval(char x, int s1, int s2);
	

};



void expcon::strreve(char a[]){

	char temp;
	int i = 0;
	int j = strlen(a) -1;
	
	
	while ( i < j){
	
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		
		i++;
		j--;
	
	}



}

int expcon::icp(char x){

	int q;
	
	switch (x){		
		case '+' : q = 1;
			break;
			
		case '-': q = 1;
			break;
			
		case '*': q =2;
			break;
			
		case '/': q =2;
			break;
			
		case '%': q=3;
			break;
			
		case '^': q =4;
			break;			
		case '(': q = 0;
			break;
		
	}

	return q;

}

int expcon::isp(char x){

	int q;
	
	switch (x){		
		case '+' : q = 1;
			break;
			
		case '-': q = 1;
			break;
			
		case '*': q =2;
			break;
			
		case '/': q =2;
			break;
			
		case '%': q=3;
			break;
			
		case '^': q =4;
			break;
			
		case '(': q = 0;
			break;
		
	
	
	
	}

	return q;

}

void expcon::inf2pre(){

	int j=0;
	stack s;
	cout<<"Enter the infix expression"<<endl;
	cin>>inf;
	
	strreve(inf);
	
	for ( int i =0; i< strlen(inf);i++){
	
		if ( inf[i] == '(')		
			inf[i] = ')';
		else if ( inf[i] == ')')		
			inf[i] = '(';
		}
		
		for ( int i = 0; i < strlen(inf); i++)
		{
		
			int x = inf[i];
			
			if ( isalnum(x)){
			
				pre[j++] = x;
			}
			else if ( x == '('){
			
				s.push(x);
				
			}			
			else if (x==')')
			{			
				while((x=s.pop())!= '(')
				{
					pre[j++] = x;
				
				}				
			}			
			else{			
				while (!s.isempty() && icp(x) <= isp(s.topdata()))
				{				
				pre[j++] = s.pop();				
				}			
				s.push(x);			
			}		
		}	
		while ( !s.isempty())
		{		
			pre[j++] = s.pop();		
		}
	
		pre[j] = '\0';
		strreve(pre);		
		cout<<"prefix of the given expression is: "<<pre<<endl;	
	}

void expcon::inf2post(){

int j=0;
	stack s;
	cout<<"Enter the infix expression"<<endl;
	cin>>inf;
	
	
	
	
		for ( int i = 0; inf[i] != '\0'; i++)
		{
		
			char x = inf[i];
			
			if ( isalnum(x)){
			
				post[j++] = x;
			}
			else if ( x == '('){
			
				s.push(x);
			}
			else if ( x == ')'){
			
				while ( (x = s.pop()) != '('){
					post[j++] = x;
				
				}
			
			}
			
			else{
			
				while (!(s.isempty()) && icp(x) <= isp(s.topdata())){
				
				post[j++] = s.pop();
				
				}
			
				s.push(x);
			
			}
		
		
		}
	
		while ( !(s.isempty())){
		
			post[j++] = s.pop();
		
		}
	
		cout<<"postfix expression is: "<<post<<endl;
	
	}

int expcon::eval(char x, int s1, int s2){

	
	switch(x){
	
	case '+': return(s1+s2);
	case '-': return(s1-s2);
	case '*':return(s1*s2);
	case '/':return(s1/s2);
	case '^':return(s1^s2);
	case '%':return(s1%s2);
	
	
	}
	

}

void expcon::preeval(){

	stack s; int r;
	
	cout<<"Enter the prefix expression"<<endl;
	cin>>pre;
	
	strreve(pre);
	
	for ( int i =0; i < strlen(pre); i++){
		char x = pre[i];
		if ( isalpha(x)){
		
			cout<<"Enter the value of"<<x<<endl;
			cin>>x;
			s.push(x);
		
		}
		
		else if ( isdigit(x)){
		
			s.push(x-48);
		
		}
		
		else {
		
		int s1 = s.pop();
		int s2 = s.pop();
		
		r = eval(x,s1,s2);
		s.push(r);
	
		}
	
	}


	r = s.pop();
	
	cout<<"Result is: "<<r<<endl;



}

void expcon::posteval(){

	stack s; int r;
	
	cout<<"Enter the prefix expression"<<endl;
	cin>>pre;
	
	
	
	for ( int i =0; i < strlen(pre); i++){
		char x = pre[i];
		if ( isalpha(x)){
		
			cout<<"Enter the value of"<<x<<endl;
			cin>>x;
			s.push(x);
		
		}
		
		else if ( isdigit(x)){
		
			s.push(x-48);
		
		}
		
		else {
		
		int s2 = s.pop();
		int s1 = s.pop();
		
		r = eval(x,s1,s2);
		s.push(r);
	
		}
	
	}


	r = s.pop();
	
	cout<<"Result is: "<<r<<endl;



}



int main (){

expcon e;
		int ch;
		
	do {
		
		cout<<"Enter the operation that you want to perform: 1.infix to prefix 2.infix to postfix 3.preeval 4.posteval 5.exit "<<endl;
		cin>>ch;
	
		switch (ch){
		
		
			case 1: e.inf2pre();
				break;
				
			case 2: e.inf2post();
				break;
				
			case 3: e.preeval();
				break;
				
			case 4: e.posteval();
				break;
		
		
		}
	
	
	
	}while (  ch < 5);




}

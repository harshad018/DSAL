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








int main (){

expcon e;
		int ch;
		
	do {
		
		cout<<"Enter the operation that you want to perform: 1.infix to prefix 2.infix to postfix 3.exit"<<endl;
		cin>>ch;
	
		switch (ch){
		
		
			case 1: e.inf2pre();
				break;
				
			case 2: e.inf2post();
				break;
		
		
		}
	
	
	
	}while (  ch < 3);




}

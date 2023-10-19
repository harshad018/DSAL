#include"stack.cpp"


class expcon{


char inf[20],pre[20], post[20];

public:
	void inf2pre();
	void inf2post();
	void preeval();
	void posteval();
	void strreve(char a[]);

};

void strreve(char a[]){

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

void inf2pre(){

	int j=0;
	stack s;
	cout<<"Enter the infix expression"<<endl;
	cin>>inf;
	
	strreve(inf);
	
	for ( int i =0; i< strlen(a);i++){
	
		if ( inf[i] == '('){
		
			inf[i] = ')';
		}
		else if ( inf[i] == ')'){
		
			inf[i] = 'c'
		}
		
		for ( int i = 0; i < strlen(a); i++)
		{
		
			char x = inf[i];
			
			if ( isalnum(x)){
			
				pre[j++] = x;
			}
			else if ( x == '('){
			
				s.push(x);
			}
			else if ( x == ')'){
			
				while ( (x = s.pop()) != '('){
					pre[j++} = x;
				
				}
			
			}
			
			else{
			
			
			
			
			
			
			
			
			}
		
		
		
		
		}
	
	
	
	
	
	}





}

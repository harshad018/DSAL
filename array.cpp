#include<iostream>

using namespace std;
int x;

struct student{

  int rn;
  char name[30];
  float sgpa;




};

int main(){


  struct student s[15];


  for (int x = 0; x< 5; x++){

    cout<<"Enter roll no";
    cin>>s[x].rn;
    cout<<"Enter the name";
    cin>>s[x].name;
    cout<<"Enter the sgpa";
    cin>>s[x].sgpa;

  }

  for (int j=0; j<5;j++){

    cout<<s[j].rn<<endl;
    cout<<s[j].name<<endl;
    cout<<s[j].sgpa<<endl;
    






  }







}

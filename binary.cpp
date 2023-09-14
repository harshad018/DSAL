#include<iostream>
#include<cmath>

using namespace std;


void binary_search(int *L,int low,int high,int k){

     int mid = floor( (low + high)/ 2);


    if (  high < low){


      cout<<"key not found"<<endl;

      exit(0);

    }


    if (  k ==  L[mid]){

	cout<<"key found: "<<L[mid]<<endl;


      }
    else if ( k < L[mid]){


      binary_search(L,low, mid-1, k);

    }
    else if (  k > L[mid]){

      binary_search( L,mid +1, high , k); 

    }

    
      }

  int main () {

	int s[] = {1,2,3,4,5};

    binary_search(s,0,4,1);


}

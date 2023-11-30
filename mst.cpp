#include<iostream>

using namespace std;

#define v 7
#define inf 500
class MST
{
	public:
	//int v =7;
	
	int G[7][7] = {{0,2,1,3,0,0,0},
				 {2,0,0,0,0,0,4},
				 {1,0,0,0,5,8,6},
				 {3,0,0,0,0,4,0},
				 {0,0,5,0,0,7,9},
				 {0,0,8,4,7,0,0},
				 {0,4,6,0,9,0,0}};
	void display();
	void prims();
	int selectmin(int a[],int b[]);
};

void MST :: display()
{
	for(int i = 0;i<v;i++)
	{
		for(int j =0;j<v;j++)
		{
			cout<<G[i][j]<<"\t";
		}
		cout<<endl;
			
	}
}

int MST :: selectmin(int dist[],int visited[])
{
	int vertex;
	int min = inf;
	for(int i =0;i<v;i++)
	{
		if(visited[i]==0 && dist[i]<min)
		{
		vertex =i;
		min =dist[i];
		}
	}
	return vertex;
}


void MST :: prims()
{
	int s,sv;
	int dist[v],parent[v],visited[v];
	
	for(int i=0;i<v;i++)
	{
		parent[i]=-1;
		dist[i]=inf;
		visited[i]=0;
		
	}
	cout<<"Enter source vertex"<<endl;
	cin>>sv;
	s=sv;
	dist[s]=0;
	for(int j=0;j<v-1;j++)
	{
		visited[s]=1;
		for(int i=0;i<v;i++)
		{
			if(G[s][i]!=0 && visited[i]==0 && G[s][i]<dist[i])
			{
				dist[i] = G[s][i];
				parent[i] = s;
			}
			
		}
		s=selectmin(dist,visited);
	}
	cout<<"distance : ";
	for(int i = 0;i<v;i++)
	{
		cout<<dist[i]<<"\t";
	}
	cout<<endl;
	
	
	int cost =0;
	
	for(int i=0;i<v;i++)
	{
		 cost=cost+dist[i];
		
	}
	 cout<<"cost : "<<cost<<endl;
	 
	 
	 cout<<"parent : ";
	for(int i = 0;i<v;i++)
	{
		cout<<parent[i]<<"\t";
	}
	
	cout<<"\nVisited : ";
	for(int i = 0;i<v;i++)
	{
		cout<<visited[i]<<"\t";
	}
}


int main()
{
	MST m;
	m.display();
	m.prims();
}

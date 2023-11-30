#include<iostream>

using namespace std;

#define v 7
#define inf 500
class Assign8
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
	void dijkstra();
	int selectmin(int a[],int b[]);
};

void Assign8 :: display()
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

int Assign8 :: selectmin(int dist[],int visited[])
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


void Assign8 :: dijkstra()
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
			if(G[s][i]!=0 && visited[i]==0 && dist[s]+G[s][i]<dist[i])
			{
				dist[i] =dist[s]+ G[s][i];
				parent[i] = s;
			}
			
		}
		s=selectmin(dist,visited);
	}
	int i;
	for(i=0;i<v;i++)
	{
		if(dist[i]!=0)
		{
			int j=i;
			cout<<"\n"<<j;
			while(parent[j]!=sv && parent[j]!=-1)
			{
				cout<<"<-"<<parent[j];
				j=parent[j];
				
			}
			cout<<"<-"<<sv;
			cout<<"="<<dist[i]<<endl;
		}
	}
	
}


int main()
{
	Assign8 a;
	a.display();
	a.dijkstra();
}

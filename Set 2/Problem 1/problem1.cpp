#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std; 
class Graph 
{ 
	int V;
	list<int> *adj;
	void BFSUtil(int v, bool visited[]);
	public:
		Graph(int V)
		{
			this->V = V;
			adj = new list<int>[V];
		}
		~Graph()
		{
			delete [] adj;
		}
		void addEdge(int v, int w); 
		bool isSC(); 
		Graph getTranspose();
}; 

void Graph::BFSUtil(int v, bool visited[]) 
{
	list<int> queue;
	visited[v] = true; 
	
	queue.push_back(v);
	
	list<int>::iterator i;
	while(!queue.empty()) 
	{
		v = queue.front(); 
		
		queue.pop_front();
		
		for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		{ 
			if(!visited[*i]) 
			{ 
				visited[*i] = true; 
				
				queue.push_back(*i); 
			} 
		} 
	} 
}

Graph Graph::getTranspose() 
{ 
	Graph g(V); 
	
	for(int v = 0; v < V; v++) 
	{
		list<int>::iterator i; 
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	} 
	return g; 
}

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w);
}

bool Graph::isSC() 
{
	bool visited[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	} 
	
	BFSUtil(0, visited);  
	
	for(int i = 0; i < V; i++)
	{
		if(visited[i] == false)
		{
			return false;
		}
	}
	
	Graph gr = getTranspose(); 
	
	for(int i = 0; i < V; i++) 
	{
		visited[i] = false; 
	}
	
	gr.BFSUtil(0, visited);
	
	for(int i = 0; i < V; i++)
	{
		if(visited[i] == false)
		{
			return false;
		}
	}
	return true; 
} 

int main() 
{
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL)
	{
		printf("Error opening file.\n");
		exit(1);
	}
	int n,i,j;
	char ch;
	fscanf(fp,"%d",&n);
	fscanf(fp,"%c",&ch);
	
	Graph g1(n);
	
	for(i=0;i<n;i++)
	{
		int d;
		fscanf(fp,"%d",&d);
		if(d%2==0)
		{
			d=d+1;
		}
		for(j=0;j<d+1;j++)
		{
			if(j%2!=0)
			{
				int x;
				fscanf(fp,"%d",&x);
				g1.addEdge(i, x-1); 
			}
			else
			{
				fscanf(fp,"%c",&ch);
			}
		}
		fscanf(fp,"%c",&ch);
		if(ch==EOF)
		{
			break;
		}
	}
	g1.isSC()? cout << "Nai, to grafhma einai isxura sundedemeno.\n" : cout << "Oxi, to grafhma den einai isxura sundedemeno.\n";
	fclose(fp);
	return 0; 
} 








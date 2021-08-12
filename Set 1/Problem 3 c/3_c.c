#include<stdio.h>
#include<stdlib.h>
#define size 20
int A[size][size],visited[size],count=0,n;
int seq[size],acyclic=1;
void DFS();
void DFSearch(int cur);
int main() 
{    
	int i,j;
	printf("\nEnter no of Vertices: ");
	scanf("%d",&n);
	printf("\nEnter the Adjacency Matrix (1/0) with spaces between the numbers:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	DFS();
	if(acyclic)
	{
		printf("\nIt is an Acyclic Graph!\n\n");
	}
	else if(!acyclic)
	{
		printf("\nIt is a Cyclic Graph!\n\n");
	}
	return 0;
}
void DFS()
{ 
	int i;
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			DFSearch(i);
		} 
	}
}
void DFSearch(int cur) 
{
	int i,j;
	visited[cur]=++count;
	seq[count]=cur; 
	for(i=1;i<count-1;i++)
	{
		if(A[cur][seq[i]])
		{
			acyclic=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(A[cur][i] && !visited[i])
		{
			DFSearch(i);
		}
	}
}





#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define INFY 999999999
int **m,**s,*p,i,j,n;

void print_optimal(int i,int j)
{
	if (i == j)
	{
		printf(" A%d ",i);
	}
	else
	{
		printf("( ");
		print_optimal(i, s[i][j]);
		print_optimal(s[i][j] + 1, j);
		printf(" )");
	}
}

void matmultiply(void)
{
	long int q;
	int k;
	for(i=n;i>0;i--)
	{
		for(j=i;j<=n;j++)
		{
			if(i==j)
			{
				m[i][j]=0;
			}
			else
			{
				for(k=i;k<j;k++)
				{
					q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
					if(q<m[i][j])
					{
						m[i][j]=q;
						s[i][j]=k;
					}
				}
			}
		}
	}
}

int MatrixChainOrder(int p[], int i, int j)
{
	if(i == j)
	{
		return 0;
	}
	int k;
	int min = INT_MAX;
	int count;
	for (k = i; k <j; k++)
	{
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k+1, j) + p[i-1]*p[k]*p[j];
		if (count < min)
		{
			min = count;
		}
	}
	// Return minimum count
	return min;
}

void main(int argc, char *argv[])
{
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("Error opening file.\n");
		exit(1);
	}
	char ch;
	fscanf(fp,"%d",&n);
	fscanf(fp,"%c",&ch);
	//Malloc for p[]
	p=(int *)malloc((n+1)*sizeof(int));
	if(p==NULL)
	{
		printf("Error.\n");
		exit(1);
	}
	int g;
	//Malloc for m[][]
	m=(int **)malloc(n*sizeof(int *));
	if(m==NULL)
	{
		printf("Error.\n");
		exit(1);
	}
	for(g=1;g<=n;g++)
	{
		m[g]=(int *)malloc(n*sizeof(int));
		if(m[g]==NULL)
		{
			printf("Error.\n");
			exit(1);
		}
	}
	//Malloc for s[][]
	s=(int **)malloc(n*sizeof(int *));
	if(m==NULL)
	{
		printf("Error.\n");
		exit(1);
	}
	for(g=1;g<=n;g++)
	{
		s[g]=(int *)malloc(n*sizeof(int));
		if(s[g]==NULL)
		{
			printf("Error.\n");
			exit(1);
		}
	}
	//Read from file
	for(i=0;i<=n;i++)
	{
		fscanf(fp,"%d",&p[i]);
		fscanf(fp,"%c",&ch);
	}
	int k;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			m[i][i]=0;
			m[i][j]=INFY;
			s[i][j]=0;
		}
	}
	matmultiply();
	if(n<=15)
	{
		printf("\nCost Matrix M:\n");
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				printf("m[%d][%d]: %d\n",i,j,m[i][j]);
			}
		}
	}
	if(n<=100)
	{
		i=1,j=n;
		printf("\nMultiplication Sequence : ");
		print_optimal(i,j);
	}
	printf("\nMinimum number of multiplications is : %d\n",MatrixChainOrder(p, 1, n));
	fclose(fp);
	free(p);
	free(m);
	free(s);
}













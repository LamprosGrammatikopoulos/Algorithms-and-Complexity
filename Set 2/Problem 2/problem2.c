#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
	return (a > b) ? a : b;
} 

void printknapSack(int W, int wt[], int val[], int n) 
{ 
  int i, w; 
  int K[n + 1][W + 1];
  for (i = 0; i <= n; i++)
  { 
    for (w = 0; w <= W; w++)
  	{ 
      if (i == 0 || w == 0) 
        K[i][w] = 0; 
      else if (wt[i - 1] <= w) 
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
      else
        K[i][w] = K[i - 1][w]; 
    } 
  }
  int res = K[n][W],k;     
  printf("Axia veltistou sakidiou: %d\n", res);  
  w = W; 
  printf("Antikeimena: ");
  for (i = n; i > 0 && res > 0; i--)
  { 
    if (res == K[i - 1][w])
    { 
      continue;
    }        
    else
    {
      for(k=0;k<n;k++)
      {
      	if(wt[k]==wt[i-1])
      	{
      		printf("%d ",k+1);
      	}
      }
      res = res - val[i - 1]; 
      w = w - wt[i - 1]; 
    }
  }
  printf("\n");
}  

int main() 
{
	FILE *fp;
	fp=fopen("info.txt","r");
	if(fp==NULL)
	{
		printf("Error opening file.\n");
		exit(1);
	}
	int W,n,*wt,*val,i;
	char ch;
	fscanf(fp,"%d",&W);
	fscanf(fp,"%c",&ch);
	fscanf(fp,"%d",&n);
	fscanf(fp,"%c",&ch);
	wt=(int*)malloc(n*sizeof(int));
	if(wt==NULL)
	{
		printf("Error.\n");
		exit(1);
	}
	val=(int*)malloc(n*sizeof(int));
	if(val==NULL)
	{
		printf("Error.\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",&wt[i]);
		fscanf(fp,"%c",&ch);
		fscanf(fp,"%d",&val[i]);
		fscanf(fp,"%c",&ch);
	}
	printknapSack(W, wt, val, n);
	free(wt);
	free(val);
	fclose(fp);
	return 0; 
} 


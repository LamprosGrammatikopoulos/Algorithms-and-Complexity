#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void ScheduleTournament(int Athletes, int Season);
int main(void)
{
	int n;
	do
	{
	printf("\nGive the number of athletes (number must be a power of 2): ");
	scanf("%d",&n);
	}while(ceil(log2(n))!=floor(log2(n)));
	ScheduleTournament(n,n-1);
}
void ScheduleTournament(int Athletes, int Season)
{
	if(((Athletes%2!=0) && (Season!=Athletes-1)) || (Athletes<=0))
	{
		return;
	}
	int cycle[Athletes];
	int n=Athletes/2;
	int i=0,d=0;
	for(i=0;i<n;i++)
	{				
		cycle[i]=i+1;
		cycle[Athletes-i-1]=cycle[i]+n;
	}			
	for(d=1;d<=Season;d++)
	{
		printf("\nSeason %d matches: ",d);
		for(i=0;i<n;i++)
		{					
			printf("Athlete %d Vs Athlete %d",cycle[i],cycle[Athletes-i-1]);
			if(i!=n-1)
			{
				printf(", ");
			}
			else if(i==n-1)
			{
				printf(".");
			}							 
		}	
		int temp=cycle[1];
		for(i=1;i<Athletes-1;i++)
		{
			int pr=cycle[i+1];
			cycle[i+1]=temp;
			temp=pr;
		}
		cycle[1]=temp;		
	}
	printf("\n\nTotal number of matches: %d.\n",d*i/2);
	printf("Total number of matches per season: %d.\n",d/2);
	printf("Total number of seasons: %d.\n",Season);
}

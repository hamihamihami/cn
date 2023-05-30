#include<stdio.h>
int main()
{
	int i,n,j,k;
	printf("\n enter no of nodes:");
	scanf("%d",&n);
	int cost[n][n],dist[n][n],via[n][n];
	printf("\n enter the distances:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			cost[i][i]=0;
			dist[i][j]=cost[i][j];
			via[i][j]=j;
		}
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	for(k=1;k<=n;k++)
	if(dist[i][j]>cost[i][k]+cost[k][j])
	{
		dist[i][j]=cost[i][k]+cost[k][j];
		via[i][j]=k;
	}
	for(i=1;i<=n;i++)
	{
		printf("\n router %d:",i);
		for(j=1;j<=n;j++)
		{
			printf("\n distance to node %d via %d:%d",j,via[i][j],dist[i][j]);
		}
	}
	return 0;
}

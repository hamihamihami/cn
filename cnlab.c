//BITSTUFFING


#include<stdio.h>
int main()
{
	int n,a[30],i,j,count=0;
	printf("\n enter no of bits:");
	scanf("%d",&n);
	printf("\n enter bits of frame:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		count++;
		else if(a[i]==0)
		count=0;
		if(count==5)
		{
			for(j=n-1;j>=i+1;j--)
			{
				//a[j]=a[j-1];
				a[j+1]=a[j];
			}
			n++;
			a[i+1]=0;
			count=0;
		}
	}
	printf("\n frame after bitstuffing:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}

//CHARSTUFFING

#include<stdio.h>
#include<string.h>
int main()
{
	char a[50],b[50],sd,ed;
	int n,i=0,j=0;
	printf("\n enter characters to be stuffed:");
	scanf("%s",a);
	printf("\n enter starting delimiter:");
	scanf(" %c",&sd);
	printf("\n enter ending delimiter:");
	scanf(" %c",&ed);
	b[0]=sd;
	n=strlen(a);
	while(i<n)
	{
		b[j+1]=a[i];
		if(a[i]==sd)
		{
			j++;
			b[j+1]=a[i];
		}
		if(a[i]==ed)
		{
			j++;
			b[j+1]=a[i];
		}
		i++;
		j++;
	}
	j++;
	b[j]=ed;
	printf("\n aftercharacter stuffing:");
	for(i=0;i<=strlen(b);i++)
	printf("%c ",b[i]);
	return 0;
}

//DIJIKSTRA

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 6
int mindist(int dist[],bool sptset[])
{
	int i,min=INT_MAX,min_index;
	for(i=0;i<V;i++)
	if(sptset[i]==false&&dist[i]<=min)
	min=dist[i],min_index=i;
	return min_index;
}
void print(int dist[])
{
	int i;
	printf("\n VERTEX\t DISTANCE\n");
	for(i=0;i<V;i++)
	printf("%d\t\t%d\n",i,dist[i]);
}
void dij(int graph[V][V],int src)
{
	int i,u,v,count;
	int dist[V];
	bool sptset[V];
	for(i=0;i<V;i++)
	dist[i]=INT_MAX,sptset[i]=false;
	dist[src]=0;
	for(count=0;count<V-1;count++)
	{
		u=mindist(dist,sptset);
		sptset[u]=true;
		for(v=0;v<V;v++)
			if(!sptset[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v])
			dist[v]=dist[u]+graph[u][v];
	}
	print(dist);
}
int main()
{
	//int graph[V][V]={{0,20,40},{0,0,10},{0,0,0}};
	int graph[V][V] = { {0,4,5,0,0,0},
                        {4,0,11,9,7,0},
                        {5,11,0,0,3,0},
                        {0,9,0,0,13,2},
                        {0,7,3,13,0,6},
                        {0,0,0,2,6,0}};
	dij(graph,0);
	return 0;
}

//SLIDING

#include<stdio.h>
int main()
{
	int w,n,fr[30],i,j,k=0;
	printf("\n enter size of frame:");
	scanf("%d",&n);
	printf("\n enter window size:");
	scanf("%d",&w);
	printf("\n enter bits of frame:");
	for(i=0;i<n;i++)
	scanf("%d",&fr[i]);
	while(k!=n)
	{
		for(j=0;j<w;j++)
		{
			printf("%d ",fr[k]);
			k++;
			if(k==n)
			break;
		}
		printf("\n sender waiting for acknowledgement \n sender recieved acknowledgement\n");
	}
	return 0;
}

//BGP

#include<stdio.h>
int main()
{
        int i,n,j,k,a[10][10];
        printf("\n enter no of hosts:");
        scanf("%d",&n);
        printf("\n enter distance matrix:");
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        scanf("%d",&a[i][j]);
                }
        }
        for(k=1;k<=n;k++)
        {
                for(i=1;i<=n;i++)
                {
                        for(j=1;j<=n;j++)
                        {
                                if(a[i][j]>a[i][k]+a[k][j])
                                a[i][j]=a[i][k]+a[k][j];
                        }
                }
        }
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        if(i==j)
                        a[i][j]=0;
                }
        }
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        printf("%d ",a[i][j]);
                }
                printf("\n");
        }
        return 0;
}

//BROADCAST TREE

#include<stdio.h>
#include<stdlib.h>
int find(int);
int uni(int,int);
int i,j,k,ne=1,min,mincost=0,a,b,u,v,n,cost[9][9],parent[9];
int main()
{
	printf("\n enter no of nodes:");
	scanf("%d",&n);
	printf("\n enter cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
	}
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
				min=cost[i][j];
				a=u=i;
				b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("\n %d edge(%d,%d)=%d",ne++,a,b,min);
			mincost+=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n the minimum cost=%d",mincost);
	return 0;
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

//CRC

#include<stdio.h>
#include<string.h>
#define N strlen(gen_poly)
char data[30];
char check_value[28];
char gen_poly[10];
int data_length,i,j;
void XOR()
{
	for(j=1;j<N;j++)
	check_value[j]=((check_value[j]==gen_poly[j])?'0':'1');
}
void CRC()
{
	for(i=0;i<N;i++)
	check_value[i]=data[i];
	do{
		if(check_value[0]=='1')
		XOR();
		for(j=0;j<N-1;j++)
		check_value[j]=check_value[j+1];
		check_value[j]=data[i++];
	}while(i<=data_length+N-1);
}
int main()
{
	printf("\n enter data to be transmitted:");
	scanf("%s",data);
	printf("\n enter the general polynomial:");
	scanf("%s",gen_poly);
	data_length=strlen(data);
	for(i=data_length;i<data_length+N-1;i++)
	data[i]='0';
	printf("\n data after adding n-1 zeros:%s",data);
	CRC();
	printf("\n crc value or checkvalue:%s",check_value);
	for(i=data_length;i<data_length+N-1;i++)
    data[i]=check_value[i-data_length];	
    printf("\n final data to be sent:%s",data);
    printf("\n data received:%s",data);
    CRC();
    for(i=0;(i<N-1)&&(check_value[i]!='1');i++);
    if(i<N-1)
    printf("\n errror detected");
    else
    printf("\n no error detected");
    return 0;
}
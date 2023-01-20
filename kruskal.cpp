#include<iostream>
int i,j,k,a,b,u,v,n,e=1;
int Min,mincost=0,cost[9][9],parent[9];

class kruskal{
	public:
		void krus(){
	
   cout << "Enter the no. of vertices:";
    cin >> n;
    cout << "Enter the cost of adjacency matrix:\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> cost[i][j];
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    cout << "The edges of minimum cost spanning tree are:";
    while(e<n)
    {
        for(i=1,Min=999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<Min)
                {
                    Min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            cout << e << " edge (" << a << "," << b << ") = " << Min << endl;
            mincost+=Min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout << "\nMinimum cost: " << mincost << endl;

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
		parent [j]=i;
		return 1;
		
		}
		return 0;
	}	
};
int main()
{
kruskal k;
k.krus();
}

#include<iostream>
#include<cstring>
using namespace std;


char read[20][20];
int a[20][20]={0};
int c[20][20]={0};
int r[20][20]={0};
int cube[20][20]={0};


int nextRow(int row,int col)
{
	if(col==9)return row+1;
	else return row;
}


int nextCol(int row,int col)
{
	if(col==9)return 1;
	else return col+1;
}


int getCube(int row,int col)
{
	int rr=row/3;
	if(row%3)rr++;
	int cr=col/3;
	if(col%3)cr++;
	return (rr-1)*3+cr; 
}


bool dfs(int row, int col)
{
	//cout<<row<<' '<<col<<endl;
	bool b=false;
	if((row-1)*9+col>81)
	{
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
		return true;
	}
	if(a[row][col])
	{
		b=dfs(nextRow(row,col),nextCol(row,col));
		if(b)return true;
		else return false;
	}
	//cout<<r[1][4]<<' '<<c[2][4]<<' '<<cube[1][4];
	for(int j=1;j<=9;j++)
	{
		if(!r[row][j] && !c[col][j] && !cube[getCube(row,col)][j])
		{
			r[row][j]=1;
			c[col][j]=1;
			cube[getCube(row,col)][j]=1;
			a[row][col]=j;
			b=dfs(nextRow(row,col),nextCol(row,col));
			a[row][col]=0;
			if(b)return true;
			r[row][j]=0;
			c[col][j]=0;
			cube[getCube(row,col)][j]=0;
		}
	}
	return false;
}


int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(r,0,sizeof(r));
		memset(cube,0,sizeof(cube));
		for(int i=1;i<=9;i++)cin>>read[i]+1;
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
			{
				a[i][j]=read[i][j]-'0';
				//cout<<a[i][j]<<' ';
				if(a[i][j]>0)
				{
					r[i][a[i][j]]=1;
					c[j][a[i][j]]=1;
					cube[getCube(i,j)][a[i][j]]=1;
				}
			}
		//cout<<endl;
		}
		dfs(1,1);
	}
}

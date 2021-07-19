#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
 
const int N=102;
 
int r,c,ans;
//queue<pair<pair<int,int>,int>> q; dont use this; instead use structure
 
char college[N][N];
int dis[N][N][16];
 
 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
 
 
struct pos
{
	int x,y,keys;
	pos(){};
	pos(int a,int b,int c){
		x=a;
		y=b;
		keys=c;
	}
};
 
bool isValid(int x,int y)
{
	if(x<0 || y<0 || x>=r || y>=c)
	return false;
 
	return true;
}
 
 
 
int main() {
 
	while(true)
	{
		cin>>r>>c;
		if(r==0 && c==0)
		return 0;
 
		queue<pos> q;
		memset(dis,-1,sizeof(dis));
 
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>college[i][j];
 
				if(college[i][j]=='*')
				{
					q.push(pos(i,j,0));
					dis[i][j][0]=0;
				}
			}
		}
 
		ans=-1;
 
		while(!q.empty())
		{
			int x=q.front().x,y=q.front().y;
			int mask=q.front().keys;
			int newmask;
 
			q.pop();
 
			if(college[x][y]=='X')
			{
				ans=dis[x][y][mask];
				break;
			}
 
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i],ny=y+dy[i];
 
				if(nx < 0 || nx >= r || ny < 0 || ny >= c)
				{
					continue;
				}
 
				if(college[nx][ny]=='#')
				continue;
 
				newmask=mask;
 
				if(college[nx][ny]=='b') newmask|=1;
				else if(college[nx][ny]=='y') newmask|=2;
				else if(college[nx][ny]=='r') newmask|=4;
				else if(college[nx][ny]=='g') newmask|=8;
 
				if(dis[nx][ny][newmask]!=-1)
				continue;
 
				if(college[nx][ny]=='B' && !(mask&1)) continue;
				if(college[nx][ny]=='Y' && !(mask&2)) continue;
				if(college[nx][ny]=='R' && !(mask&4)) continue;
				if(college[nx][ny]=='G' && !(mask&8)) continue;
 
				dis[nx][ny][newmask]=dis[x][y][mask]+1;
				q.push(pos(nx,ny,newmask));
 
			}
		}
 
		if(ans==-1)
		cout<<"The poor student is trapped!"<<endl;
		else
		cout<<"Escape possible in "<<ans<<" steps."<<endl;
	}
}

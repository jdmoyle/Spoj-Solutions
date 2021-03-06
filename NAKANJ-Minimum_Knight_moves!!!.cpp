#include <iostream>
#include<vector>
#include<queue>
using namespace std;
#define N 1000000
 
 
int d[8][8];
 
bool valid(int x,int y)
{
	if(x<0||x>7||y<0||y>7)
	return false;
 
	return true;
}
 
 
vector<int> coordinates(string s)
{
	vector<int> position(2);
 
	position[0]=s[0]-97;
	position[1]='8'-s[1];
 
	return position;
}
 
//d[][] stores the distance of valid cell from the source
//setting the initial values
void init(vector<int> s)
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			d[i][j]=N;
		}
	}
	d[s[0]][s[1]]=0;
}
 
//int bfs(string s,string d) this is wrong
 
int bfs(vector<int> s_position,vector<int> d_position)
{
	//all these are invalid
 
	//vector<int> s_position=coordinates(s);
	//vector<int> d_position=coordinates(d);
 
	//vector<int> s_position(2);
	//vector<int> d_position(2);
 
	//s_position=coordinates(s);
	//d_position=coordinates(d);
 
	//vector<int> m(2); //this line is invalid;
 
	init(s_position);
 
	queue<vector<int>> q;
 
	q.push(s_position);
 
	while(!q.empty())
	{
		vector<int> m=q.front();
 
		m=q.front();
		q.pop();
 
		if(m[0]==d_position[0]&&m[1]==d_position[1])
		{
			return d[d_position[0]][d_position[1]];
		}
 
		int a[]={-2,-1,-2,-1,1,2,2,1};
		int b[]={-1,-2,1,2,-2,-1,1,2};
 
		for(int i=0;i<8;i++)
		{
			vector<int> temp(2);
			temp[0]=m[0]+a[i];
			temp[1]=m[1]+b[i];
 
			if(valid(temp[0],temp[1])&&d[temp[0]][temp[1]]>d[m[0]][m[1]]+1)
			{
				d[temp[0]][temp[1]]=d[m[0]][m[1]]+1; //the distance of child = distance of parent +1;
				q.push(temp);
			}
		}
	}
}
 
 
int main() {
 
	int t;
	cin>>t;
	while(t--)
	{
		string s,d;
		cin>>s>>d;
 
		int ans=bfs(coordinates(s),coordinates(d));
		cout<<ans<<endl;
	}
	return 0;
}



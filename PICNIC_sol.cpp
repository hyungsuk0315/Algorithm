#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int n;
bool areFriends[10][10];

int CountPairings(bool taken[10])
{
	int firstFree = -1;
	for(int i = 0 ; i < n ; ++i)
	{
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}
	if(firstFree == -1) return 1;
	int ret = 0;

	for(int pairWith = firstFree+1 ; pairWith < n ; ++pairWith)
	{
		if(!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += CountPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main()
{
	freopen("test.txt", "r", stdin);
	bool taken[10];
	int c,m;
	int a,b;
	cin >> c;
	for(int i = 0 ; i < c ; i++)
	{
		cin >> n >> m;
		for(int j = 0 ; j < m ; j++)
		{
			cin >> a >> b;
			if(a > b)
				areFriends[b][a] = true;
			else
				areFriends[a][b] = true;
			
		}
		cout << CountPairings(taken) << endl;
		for(int j = 0 ; j < 10 ; j++)
			memset(areFriends[j], false, 10);
	}
	return 0;
}

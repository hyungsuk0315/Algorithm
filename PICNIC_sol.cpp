#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int n; // number of students
bool areFriends[10][10]; // Check if they are friends

/*완전 탐색을 이용하여 가능한 모든 경우의 수를 찾는다.*/

int CountPairings(bool taken[10])
{
	int firstFree = -1; //Find first false index in array taken
	for(int i = 0 ; i < n ; ++i)
	{
		if(!taken[i]){
			firstFree = i;
			break;
		}
	}
	if(firstFree == -1) return 1; // When every student is matched
	int ret = 0;
	//Start from first false index
	for(int pairWith = firstFree+1 ; pairWith < n ; ++pairWith)
	{
		//Find false index and check if they are friends
		if(!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += CountPairings(taken); // Recursive
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
		//areFriends배열을 초기화 하지 않아 오류가 났었음.
		for(int j = 0 ; j < 10 ; j++)
			memset(areFriends[j], false, 10);
		
	}
	return 0;
}

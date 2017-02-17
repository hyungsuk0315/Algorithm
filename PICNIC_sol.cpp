/*Algospot ID:PICNIC*/

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
		memset(taken, 0, sizeof(taken));
		cin >> n >> m;
			memset(areFriends, 0, sizeof(areFriends));
/*
   배열을 초기화하는 과정에서 오류가 발생했었음
   for(int j=0 ; j < n ; j++)
   	memset(areFriends[j] , false, sizeof(bool)*10) 
	이 코드는 틀린 코드
 */
		for(int j = 0 ; j < m ; j++)
		{
			cin >> a >> b;
			areFriends[a][b] = areFriends[b][a] = true;
		}
		cout << CountPairings(taken) << endl;
	}
	return 0;
}

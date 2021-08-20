#include <iostream>
#include <queue>
using namespace std;

bool Check[1000000];

int BFS (int start, int target)
{
	queue<int>q;
	int Moves = 0;
	int Nodes_to_next = 0;
	int Nodes_left = 0;
	
	q.push(start);
	Check[start] = true;
	
	bool done = false;
	while(!q.empty() && !done)
	{
		int r = q.front(); q.pop();
		if(r == target)
			done = true;
		else
		{
			if(r + 1 <= 1000000 && !Check[r+1])
			{
				q.push(r + 1);
				Check[r + 1] = true;
				Nodes_to_next++;
			}
			if(r - 1 >= 0 && !Check[r-1])
			{
				q.push(r - 1);
				Check[r - 1] = true;
				Nodes_to_next++;
			}
			if(r * 2 <= 1000000 && !Check[r*2])
			{
				q.push(r * 2);
				Check[r * 2] = true;
				Nodes_to_next++;
			}
			if(r / 2 <= 1000000 && !Check[r/2])
			{
				q.push(r / 2);
				Check[r / 2] = true;
				Nodes_to_next++;
			}
			if(r * 3 <= 1000000 && !Check[r*3])
			{
				q.push(r * 3);
				Check[r * 3] = true;
				Nodes_to_next++;
			}
			
			Nodes_left--;
			if(Nodes_left <= 0)
			{
				Moves++;
				Nodes_left = Nodes_to_next;
				Nodes_to_next = 0;
			}		
		}	
	}
	
	if(done)
		return Moves;
	else
		return -1;
}
int main ()
{
	int start, target, K, C;
	cin >> start >> target >> K;
	for(int i=0; i<K; i++)
	{
		cin >> C;
		Check[C] = true;
	}	
	cout << BFS(start, target);
	return 0;
}
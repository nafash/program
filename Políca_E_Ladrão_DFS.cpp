#include <iostream>

using namespace std;

int M[5][5];
bool Global = 0;

void dfs(int x1, int y1)
{
	M[x1][y1] = 2;
	
	if(M[4][4] == 2)
	{
		Global = 1;
		return;
	}	
	if(x1+1 < 5 && !M[x1+1][y1])
	{
		dfs(x1+1, y1);
	}
	if(x1-1 >= 0 && !M[x1-1][y1])
	{
		dfs(x1-1, y1);
	}
	if(y1+1 < 5 && !M[x1][y1+1])
	{
		dfs(x1, y1+1);
	}
	if(y1-1 >= 0 && !M[x1][y1-1])
	{
		dfs(x1, y1-1);
	}
}

int main ()
{
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{	
		Global = 0;
		
		for(int j=0; j<5; j++)
		{
			for(int k=0; k<5; k++)
			{
				cin >> M[j][k];
			}
		}
		
		dfs(0,0);
		
		if(Global == 1)
			cout << "COPS" << endl;
			
		else
			cout << "ROBBERS" << endl;
	}
}
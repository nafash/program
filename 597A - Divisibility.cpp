#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int a, b, k, cont=0;
	cin >> k >> a >> b;
	for(int i=a; i<=b; i++)
	{
		if(i%k==0)
			cont++;
	}
	cout << cont << endl;	
	return 0;
}
#include <iostream>
#include <map>
using namespace std;
int main(int argc, char** argv)
{
	int t, n, tempo, d, caso=1;
	string nome, trabalho;
	
	map<string,int>mapa;
	map<string,int>::iterator it;
	
	cin >> t;
	for(int i=0; i<t; i++)
	{
		cin >> n;
		for(int j=0; j<n; j++)
		{
			cin >> nome >> tempo;
			mapa[nome] = tempo;
		}	
		cin >> d;
		cin >> trabalho;
		cout << "Case " << caso << ": ";
		it = mapa.find(trabalho);
		if(it != mapa.end())
		{
			if(it->second <= d)
				cout << "Yesss" << endl;
			if(d < it->second && it->second <= d+5)
				cout << "Late" << endl;
			if(it->second > d+5)
				cout << "Do your own homework!" << endl;
		}
		else
			cout << "Do your own homework!" << endl;	
		caso++;	
	}	
	return 0;
}
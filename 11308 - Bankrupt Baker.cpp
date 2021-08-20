#include <map>
#include <set>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	map<string, int>mapa;
	map<string, int>::iterator it;
	
	set<string>aceitos;
	set<string>rejeitados;
	
	int t, n, m, b, qnt, qt, p=0, preco;
	string loja, produto, ingrediente, bolo;
	
	cin >> t;
	for(int i=0; i<t; i++)
	{
		cin >> loja;
		cin >> m >> n >> b;
		for(int j=0; j<m; j++)
		{
			cin >> produto >> preco;
			mapa[produto] = preco;
		}	
		for(int j=0; j<n; j++)
		{
			cin >> bolo;
			cin >> qnt;
			for(int k=0; k<qnt; k++)
			{
				cin >> ingrediente >> qt;
				it = mapa.find(ingrediente);
				if(it != mapa.end())
					p = p +(qt * it->second);	
			}	
			if(p <= b)
			{	
				aceitos.insert(bolo);
			}	
			if(p > b)
			{
				rejeitados.insert(bolo);
			}
		}
	}			
	cout << endl;
	for(set<string>::iterator it=aceitos.begin(); it!=aceitos.end(); it++)
	{
		cout << *it << endl;
	}	
	cout << endl;
	if(rejeitados.size() !=0)
		cout << "Too expensive!" << endl;	
	return 0;
}
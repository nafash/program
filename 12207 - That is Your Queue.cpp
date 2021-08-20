#include <iostream>
#include <list>
using namespace std;
int main (){
	int P, C, x, lul=1;
	char c;
	cin >> P >> C;
			list<int>q;
			list<int>::iterator it;
			
			for(int i=1; i<=P; i++)
			{
				q.push_back(i);
			}	
			for(int i=1; i<=C; i++)
			{
				cin >> c;
				if(c == 'N')
				{
					q.push_back(q.front());
					q.pop_front();
				}	
				if(c == 'E')
				{
					cin >> x;
					for(it=q.begin(); it!=q.end() && *it!= x; it++);
					if(*it == x)
					{
						q.push_front(*it);
						q.erase(it);
					}		
				}	
			}	
			cout << "Case " << lul << ": " << endl;
			for(it = q.begin(); it != q.end(); it++)
			{
				cout << *it << endl;
			}	
			lul++;
	return 0;			  			
}
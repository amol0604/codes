#include <iostream>
#include <list>
using namespace std;

void print_list(list<int> a){

	cout << "printing_list" << endl;	
	/*for(int i=0; i < a.size(); i++)
		{

			cout << a(i) << " ";
		};*/

	list<int>::iterator i;
	for(i = a.begin(); i != a.end(); i++)
	{
		cout << *i << " ";
	};		
		cout << endl;
};

int main(){

	list<int> temp;
	for(int i=0; i < 10; i++)
		{
			temp.push_back(3*i);

		};
		print_list(temp);
	return 0;
};
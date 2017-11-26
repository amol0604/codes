#include <iostream>
#include <string>
using namespace std;

void swap(string &str, int l , int r)
{
	char temp = str[l];
	str[l]=str[r];
	str[r]=temp;
};

void allperm(string str, int l, int r)
{
	if( l > r )
		return;
	if( l == r )
	{	
		cout << str << endl; 
		return;	
	};
	for(int i = l; i <= r; i++)
	{
		swap(str,l,i);
		allperm(str,l+1,r);
		swap(str,l,i);
	};	

};

int main(){
	string str = "ABB";
	allperm(str, 0 , str.length()-1);
	return 0;
};

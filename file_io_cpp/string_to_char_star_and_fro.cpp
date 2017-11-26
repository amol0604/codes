#include <iostream>
#include <string>
using namespace std;

int main(){
	char a[] = "hola this is a string";
	cout << a << endl;

	//conversion from char * to str is very easy
	string str = a;
	cout  << str.substr(0,4) << endl;


	//pay special attention on how to convert string to char*
	string str1 = "this is a sentence";
	char *c = const_cast<char*>(str1.c_str());

	cout << "-"<< c << "-" << endl;
	cout << strlen(c) << endl;

	//now tokenize!
	char *ptr = strtok(c," ");
	while(ptr)
	{
		cout << ptr << endl;
		ptr = strtok(NULL, " ");
	}


	return 0;
}
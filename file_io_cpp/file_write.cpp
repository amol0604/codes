#include <iostream>
#include <fstream>
using namespace std;

int main(){

	ofstream temp;
	temp.open("hi.txt");
	temp << "hello world" << endl;
	temp.close();

	//this will overwrite the previous 
	temp.open("hi.txt");
	temp << "hello world123" << endl;
	temp.close();

	//do the following to append
	temp.open("hi.txt", ios::app);     //use ios::out for write mode
	if(temp.is_open())
		{
			temp << "yay ! Appendded text here" << endl;
			temp << "line"; 
		}	
	else cout << "error!" << endl;
	temp.close();


	return 0;    
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	string line;
	ifstream temp;

	
	//read file line by line
	temp.open("hi.txt");
	if(temp.is_open()){
		while(getline(temp,line))
			cout << line << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	temp.close();
	

	//read file word by word
	temp.open("hi.txt");
	string word;
	while(temp>>word){
		cout << word << endl;
	}
	temp.close();




	return 0;
}
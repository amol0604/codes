#include <iostream>
#include <string>
using namespace std;

int main(){

	string str = "0123456789";
	cout << str.erase(7) << endl;    //erase from index 7 onwards
	//shit! original string is now destroyed

	cout << str << endl;
	
	cout << str.erase(1,3) << endl;  //erase from index 1 onwards but length 3
 
}

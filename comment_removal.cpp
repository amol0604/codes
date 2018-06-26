#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

	ifstream temp ;
	temp.open("plus_one.cpp");
	if(temp.is_open())
	{
		//read file character character
		//if we find // then pen up untill end of line
		//if we find /* when pen up ultill we reach */

		char c;
		int pen_up1 = 0;   //for // based comments
		int pen_up2 = 0;   //for /**/ based comments
		char prev;
		temp.get(prev);
		while(temp.get(c)){
			if(pen_up1==1)
			{
				if(c=='\n')
				{
					pen_up1 = 0;
					prev = c;
					continue;
				}
				else{
					prev = c;
					continue;
				}
			}
			else if(pen_up2==1){
				if(prev == '*' && c == '/'){
					pen_up2 = 0;
					prev = c;
					continue;
				}
				else{
					prev = c;
					continue;
				}
			}
			else {
				if(prev=='/' && c == '/')
				{
					prev =c;
					pen_up1 = 1;
					continue;
				}
				else if(prev=='/' && c=='*'){
					prev = c;
					pen_up2 = 1;

					continue;
				}
				else{
					cout  << prev ;
					prev = c;
					continue;
					}
			}
		}
	}
	else{
		cout << "Error opening the specified file" << endl;
	}
	temp.close();

	return 0;
}

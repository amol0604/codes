#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int len = s.length();
	cout << "length = " << len << endl;
	int i=0;
	while(i<len){
		if(s[i]=='{'){

			cout << "{" << endl;

		}
		else if(s[i]=='}' && (i+1) < len && s[i+1]==','){
		cout << endl;
		cout << "},";
		i++;
		cout << endl;
		}
		else if(s[i]=='}'){
			cout << endl;
			cout << "}";
			cout << endl;
		}
		else if(s[i]==',' && i+1 < len && s[i+1]=='"' && s[i-1]=='"'){
			cout << ",";
			cout << endl;
		}
		else if(s[i]==','){
			cout << ",";
		}
		else
			cout << s[i];

		i++;
	}

	return 0;
}
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool contain(unordered_set<string> &dict, string s){
        if(find(dict.begin(), dict.end(),s)!= dict.end())
            return true;
        else 
            return false;
    }

bool wordBreak(string s, unordered_set<string> &dict) {
        
        if(s.length()<1)
            return true;
        //cout << s << endl;
        if(contain(dict, s))
            return true;
        int i=0;
        for(i= 0 ; i < s.length()-1; i++){
            //cout << s.substr(0,i+1) << " " << s.substr(i+1,s.length()-1-(i+1)+1) << endl;
        if(contain(dict, s.substr(0,i+1)))
            {   
                
                return wordBreak(s.substr(i+1,s.length()-1-(i+1)+1), dict);
            }
        }
        return false;
    }
    
int main(){

    string s = "ilikesamsung";
    unordered_set<string> dict;
    dict.insert("i");
    dict.insert("like");
    dict.insert("sam");
    dict.insert("sung");
    dict.insert("samsung");
    dict.insert("mobile");
    dict.insert("ice");
    dict.insert("cream");
    dict.insert("man");
    dict.insert("go");
    dict.insert("mango");
    dict.insert("icecream");
    dict.insert("and");
    
   wordBreak("ilikesamsung", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango", dict)? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok", dict)? cout <<"Yes\n": cout << "No\n"; 
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


bool is_valid(string S, vector<string> &L, int i, map<string,int> word_counts){
        int num_words = L.size();
        if(num_words<1)
            return true;
        int siz = L[0].size(); //size of each word
        if ( (i + num_words*siz)-1 > S.length()-1 ){
            return false;
        }
        int j = i;
        
        
        int k = 1;
        map<string,int> temp_map;
        while(k <= num_words){
            //pick word starting from j;
            string word = S.substr(j,siz);
            if(word_counts.find(word)==word_counts.end()){
                return false;
            }
            else
            {
                /*if(temp_map.find(word)==temp_map.end())
                    temp_map[word]= 1;
                else*/
                    temp_map[word]++;
                if(temp_map[word] > word_counts[word])
                    return false; //seen more number of times than required
            }
            
            j=j+ siz;
            k++;
        }
        return true;
    }

 vector<int> findSubstring(string S, vector<string> &L) {
        //check if ith index is a valid index
        vector<int> res;
        if(S.length()<1){
            return res;
        }
        
        map<string,int> word_count;
        for(int i=0; i < L.size(); i++){
            /*if(word_count.find(L[i])==word_count.end())
                word_count[L[i]] =1 ;
            else*/
                word_count[L[i]]++;
        }
        
        for(int i = 0; i < S.length(); i++){
            
            if(is_valid(S,L,i, word_count)){
                res.push_back(i);
            }
        }
        return res;
    }

int main(){
    string S = "barbarfoothefoobarman";
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");
    //L.push_back("a");
    
    vector<int> res = findSubstring(S, L);
    
    for(int i=0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    return 0;
}
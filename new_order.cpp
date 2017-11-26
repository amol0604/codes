#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<int> adj[], int i, bool visited[]){

    if(visited[i]==true) return;
    visited[i]=true;

     for(int j=0; j < adj[i].size(); j++){
            dfs(adj,adj[i].at(j), visited);
        }
    cout << i << " ";
}

void topological_sort(vector<int> adj[], bool visited[]){
    
    for(int i=0; i < 26; i++){
        if(visited[i]==false){
            dfs(adj,i,visited);
        }
    }
    
    }

int main()
{
    //cout << "Hello World!" << endl;
    int w = 0 ;
    cin >> w;
    vector<string> words;
    for(int i=0; i < w; i++){
        string temp;
        cin >> temp;
        words.push_back(temp);
    }
    //handle separately for case when there is only one word
    
    vector<int> adj[26];

    /*
    adj[0].push_back(1);
    adj[0].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(2);
    adj[2].push_back(4);
    adj[2].push_back(5);
    
    for(int i=0; i < 26 ; i++){
        cout << i << endl;
        for(int j=0; j < adj[i].size(); j++){
            cout << adj[i].at(j) << " "; 
        }
        cout << endl;
    }*/

    
    for(int i=0; i < w-1; i++){
        string word1, word2;
        word1 = words[i];
        word2 = words[i+1];
        //cout << word << endl;
        //find first non-matching character of the word
        int j=0; int k=0;
        while(j<word1.length() && k < word2.length()){
            if(word1[j]==word2[k]){
                j++;
                k++;
            }
            else{
                //add edge from j to k 
                int ind1 = word1[j]-'a';
                int ind2 = word2[k]-'a';
                if(find(adj[ind1].begin(), adj[ind1].end(), ind2 ) == adj[ind1].end() ){
                    adj[ind1].push_back(ind2);
                }
                break;
            }
        }
            
    }

    for(int i=0; i < 26 ; i++){
        char c = i+'a';
        cout << "Adjacency list for vertex = " << c << endl;
        for(int j=0; j < adj[i].size(); j++){
            c = adj[i].at(j) + 'a';
            cout << c << " "; 
        }
        cout << endl;
    }
    
    bool visited[26] = {false};
    
    //topological sort the graph and print the output
    topological_sort(adj,visited);
    return 0;
}

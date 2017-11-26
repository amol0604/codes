#include<iostream>
#include<list>
using namespace std;

class graph
{
	int v;
	list<int> *adj

public:
	graph(int v);
	void addedge(int v, int w);
	void BFS(int root);

};

graph::graph(int v){

	this ->v = v;
	adj = new list<int>[v];
};

void graph::addedge(int v, int w)
{
	adj[v].push_back(w);

};

void graph::bfs(int root)
{
	bool *visited = new bool[V];
	for(int i=0; i < V; i++)
		visited[i]=false;

	list<int> queue;
	visited[root]  = true;
	queue.push_back[root];

	list<int>::iterator i;
	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for( i = adj[s].begin(); i!adj[s].end())
			{

			};

	}

};



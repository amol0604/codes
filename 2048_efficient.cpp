#include <iostream> 
#include <stack>
#include <map>
#include <string>

using namespace std;

void print_stack(stack<int> inp)
{
	while(inp.size()>0)
	{
		printf("%d\n",inp.top());
		inp.pop();

	};	

};

string stack_to_string(stack<int> inp)
{
	string out = "";
	while(inp.size()>0)
	{
		out = out + to_string(inp.top());
		inp.pop();
	};	

	return(out);

};

stack<int> push_number(stack<int> inp, int num)
{
	stack<int> out = inp;

	if(out.size() == 0)
	{
		out.push(num);
		return(out);

	};	

	int val = num;
	while(out.size() > 0 && out.top()==val)
	{
		val = val + val;
		out.pop();
	};	
	out.push(val);

	return out;
};

double expected_value_of_max(stack<int> inp, int n, map<string,double> &cache)
{
	if(inp.size()==n)
	{
		int max = inp.top();
		inp.pop();
		while(inp.size()>0)
		{
			int temp = inp.top();
			if(temp > max)
				max = temp;
			inp.pop();
		};	
		return(max);
	};	

	stack<int> inp1 = push_number(inp,2);
	string key1 = stack_to_string(inp1);
	double val1;
	if(cache.find(key1) != cache.end())
	{
		val1 = cache.find(key1)->second;
	}
	else{
		val1 = expected_value_of_max(inp1,n,cache);
		cache[key1] = val1;
	};	

	stack<int> inp2 = push_number(inp,4);
	string key2 = stack_to_string(inp2);
	double val2;
	if(cache.find(key2) != cache.end())
	{
		val2 = cache.find(key2)->second;
	}
	else{
		val2 = expected_value_of_max(inp2,n,cache);
		cache[key2] = val2;
	};	


	return(0.5*val1 + 0.5*val2);
	

};

int main()
{
	stack<int> start;
	
	map<string,double> cache;

	double res = expected_value_of_max(start,5,cache);
	printf("ans = %f\n", res);


	return( 0 );
};
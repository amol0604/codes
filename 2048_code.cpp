#include <iostream> 
#include <stack>
#include <map>
#include <string>

using namespace std;

// function to convert stack to string 
// which is used as a key in the hashmap
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

// given an input state of row, this retuns the output
// row when "num" is pushed. here num can be either a 2
// or a 4 by the rules of the game
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

// function which computes the expected value of maximum in 
// a recursive fashion. to avoid solving the sub problems repeatedly
// we maintain a cache which stores the expected value of a given combination

double expected_value_of_max(stack<int> inp, int n, map<string,double> &cache)
{
	// if all places in the 2048 row are exhausted, simply return the maximum
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

	//push a 2
	stack<int> new_row = push_number(inp,2);
	string key = stack_to_string(new_row);
	double val1;
	if(cache.find(key) != cache.end())
	{
		val1 = cache.find(key)->second;
	}
	else{
		val1 = expected_value_of_max(new_row,n,cache);
		cache[key] = val1;
	};	

	//push a 4
	new_row = push_number(inp,4);
	key = stack_to_string(new_row);
	double val2;
	if(cache.find(key) != cache.end())
	{
		val2 = cache.find(key)->second;
	}
	else{
		val2 = expected_value_of_max(new_row,n,cache);
		cache[key] = val2;
	};	

	//find the expected value
	return(0.5*val1 + 0.5*val2);
};

int main()
{
	//start with an empty 2048 row and an empty cache
	stack<int> start;
	
	map<string,double> cache;

	double res = expected_value_of_max(start,5,cache);
	printf("ans = %f\n", res);


	return( 0 );
};
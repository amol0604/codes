#include <iostream> 
#include <stack>
using namespace std;

void print_stack(stack<int> inp)
{
	while(inp.size()>0)
	{
		printf("%d\n",inp.top());
		inp.pop();

	};	

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

double expected_value_of_max(stack<int> inp, int n)
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
	double val1 = expected_value_of_max(inp1,n);

	stack<int> inp2 = push_number(inp,4);
	double val2 = expected_value_of_max(inp2,n);

	return(0.5*val1 + 0.5*val2);
	

};

int main()
{
	stack<int> start;
	/*start = push_number(start,2);
	start = push_number(start,2);
	start = push_number(start,2);
	start = push_number(start,2);
	start = push_number(start,4);
	start = push_number(start,2);
	print_stack(start);*/

	double res = expected_value_of_max(start,5);
	printf("ans = %f\n", res);


	return( 0 );
};
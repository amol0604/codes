#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
};

ListNode *newNode(int val)
{
	ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	tmp->next=NULL;
	tmp->val=val;
	return(tmp);

};

void print_list(ListNode *head)
{

	while(head!=NULL)
	{	
		cout << head->val << " ";
		head=head->next;
	};

	cout << "\n";
};

void reverse_list(ListNode **inp)
    {
        if(*inp == NULL)
            return;
            
        if((*inp)->next==NULL)
            return;
        
        ListNode *tmp =  (*inp)->next;
        ListNode *prev = *inp;
        
        (*inp)->next=NULL;
        
        while(tmp!=NULL)
        {
            ListNode *tmp1 = tmp->next;
            tmp->next=prev;
            prev=tmp;
            tmp=tmp1;
        };

        *inp = prev;
    };


int main()
{
	ListNode *inp = newNode(1);
	inp->next=newNode(2);
	inp->next->next=newNode(3);
	inp->next->next->next=newNode(4);
	inp->next->next->next->next=newNode(1);

	print_list(inp);
	reverse_list(&inp);
	print_list(inp);

	return(0);
};
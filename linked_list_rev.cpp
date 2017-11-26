#include <iostream>
using namespace std;

struct node{
	int key;
	struct node *next;

};

struct node * addNode(int key)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> key = key;
	new_node -> next = NULL;

	//return new_node;
	
	if(head==NULL)
	{
		head = new_node;
		return;
	};
	struct node *last = head;
	while(last->next!=NULL)
	{
		last = last -> next;
	};
	last->next = new_node;	
	

};

void print_list( struct node *head )
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		cout << temp -> key << " ";
		temp = temp -> next;
	};
	cout << endl;

};
int main(){
	struct node *head = NULL;
	//head = addNode(4);
	addNode(head,4);
	print_list(head);
	/*addNode(head,3);
	addNode(head,2);
	addNode(head,1);
	addNode(head,0);
	print_list(head);*/
	cout << "End " << endl;
}
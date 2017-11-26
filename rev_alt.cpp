#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};

void print_list(struct node *head){
	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



struct node* newNode(int data){
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(struct node **head, int data){

	struct node *n = newNode(data);

	if(*head==NULL) {
	
		*head = n;
		return;
	}

	struct node* temp = *head;
	*head = n;
	(*head)->next = temp;

}


int main(){
	struct node *head = NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print_list(head);
	free(head);
	return 0;
}
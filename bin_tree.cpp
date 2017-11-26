#include <iostream>
using namespace std;

struct node{
	int key;
	struct node *left;
	struct node *right;
};

struct node *newnode(int key){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
};

void inorder(struct node *root){

	if(root==NULL)
		return;

	inorder(root->left);
	cout << root-> key << " ";
	inorder(root->right); 
	cout << endl;
};

void insert(struct node **root, int key){
	if(*root==NULL)
	{	*root = newnode(key);
		return;
	}	
	if(key < (*root)->key)
		insert(&((*root)->left),key);
	else
		insert(&((*root)->right),key);
	return;
}

int main(){
	struct node *root=NULL;
	cout << "hey" << endl;

	insert(&root,50);
	insert(&root,30);
	insert(&root,20);
	insert(&root,40);
	insert(&root,70);
	insert(&root,60);
	insert(&root,80);
	inorder(root);


	return(0);
};
#include<iostream>

using namespace std;

struct node{
	int data;
	node *right;
	node *left;
}*root=NULL;

void BST_TreeCreation(int dataTo_Insert){
	node *tempNode = new node;
	tempNode->data = dataTo_Insert;

	if(root == NULL){
		tempNode->left = tempNode->right = NULL;
		root = tempNode;
	}
	else if(dataTo_Insert > root->data && root->right == NULL){
		tempNode->left = tempNode->right = NULL;
		tempNode = root->right;
	}
	else if(dataTo_Insert < root->data && root->left == NULL){
		tempNode->left = tempNode->right = NULL;
		tempNode = root->left;
	}
	else{
		node *trav=new node;
		node *r = root;
		while (r != NULL){
			if(dataTo_Insert > trav->data){
				r = r->right;
			}
			else if (dataTo_Insert < trav->data){
				r = r->left;
			}
			else{
				return;
			}
			r = trav;
		}
		tempNode->left = tempNode->right = NULL;
		if(dataTo_Insert > trav->data){
			trav->right = tempNode;
		}
		else{
			trav->left = tempNode;
		}
	}
}

void inOrder_Traversal(node *n){
	if(n){
		cout << n->data << " ";
		inOrder_Traversal(n->left);
		inOrder_Traversal(n->right);
	}
}

void preOrder_Display(node *h){
	if(h){
		preOrder_Display(h->left);
		cout<< " " <<h->data;
		preOrder_Display(h->right);
	}
}

void postOrder_Display(node *n){
	if(n){
		postOrder_Display(n->right);
		cout << " " << n->data;
		postOrder_Display(n->left);
	}
}

int main(){
	BST_TreeCreation(1);
	BST_TreeCreation(4);
	BST_TreeCreation(5);
	BST_TreeCreation(10);
	BST_TreeCreation(7);
	BST_TreeCreation(8);
	BST_TreeCreation(9);
	BST_TreeCreation(20);
	
	inOrder_Traversal(root);
	preOrder_Display(root);
	postOrder_Display(root);
	return 0;
}

#include<iostream>
using namespace std;

struct  node{
	int date;
	node *left;
	node *right;	
}*root=NULL;

void createtree(int date){
	//creating a temp node 
	node *temp=new node;
	temp->date=date;
	if(root==NULL){
		root=temp;
		root->left=NULL;
		root->right=NULL;
	}
	else if (date == root->date){
		return;
	}
	else if(date > root->date && root->right==NULL){
		temp->left=temp->right=NULL;
		root->right=temp;
	}
	else if(date < root->date && root->left==NULL){
		temp->left=temp->right=NULL;
		root->left=temp;
	}
	else{
		node *trav=new node;
		if(date > root->date){
			trav = root->right;
		}
		else{
			trav = root->left;
		}
		node *r;
		while (trav != NULL){
			r = trav;
			if(date > trav->date){
				trav = trav->right;
			}
			else if (date < trav->date){
				trav = trav->left;
			}
			else{
				return;
			}
		}
		temp->left = temp->right = NULL;
		if(date > r->date){
			r->right = temp;
		}
		else{
			r->left = temp;
		}
	}
}
void preOrder_Display(node *h){
	if(h){
		cout<< " " <<h->date;
		preOrder_Display(h->left);
		preOrder_Display(h->right);
	}
}

void postOrder_Display(node *n){
	if(n){
		postOrder_Display(n->left);
		postOrder_Display(n->right);
		cout << " " << n->date;
	}
}

void inOrder_Traversal(node *n){
	if(n){
		inOrder_Traversal(n->left);
		cout << n->date << " ";
		inOrder_Traversal(n->right);
	}
}

int main(){
	createtree(10);
	createtree(5);
	createtree(1);
	createtree(7);
	createtree(40);
	createtree(50);
	
	cout << "Pre-Order Traversal is : ";
	preOrder_Display(root);
	cout << endl;
	cout << "In-Order Travrsal is : ";
	inOrder_Traversal(root);
	cout << endl;
	cout << "Post-Order Traversal is : ";
	postOrder_Display(root);
	cout << endl;
	return 0;
}

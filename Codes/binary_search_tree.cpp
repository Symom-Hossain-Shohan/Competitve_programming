#include<bits/stdc++.h>
#include <cstddef>
using namespace std;

typedef long long ll;

struct Node
{
	int data;
	Node *left, *right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

Node* insert_bst(Node* root, int val)
{
	if (root == NULL) return  new Node(val);
	if (root->data > val) root->left = insert_bst(root->left,  val);
	else root->right = insert_bst(root->right, val);
	return root;
}

void inorder(Node* root)
{
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);

}

Node* search_in_bst(Node* root, int val)
{
	if (root == NULL) return root;
	if (root->data == val) return root;
	if (val < root->data) return search_in_bst(root->left,  val);
	return search_in_bst(root->right,  val);
}

int main()
{
	Node* root = NULL;

	root = insert_bst(root, 4);
	insert_bst(root, 2);
	insert_bst(root, 5);
	insert_bst(root, 1);
	insert_bst(root, 3);
	insert_bst(root, 6);
	inorder(root);
	if (search_in_bst(root, 3) == NULL)
	{
		cout << "value doesn't exists\n";
	}
	else cout << "exists" << endl;
	return 0;
}
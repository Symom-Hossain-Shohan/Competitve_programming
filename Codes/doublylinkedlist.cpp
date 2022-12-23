#include<bits/stdc++.h>
#include <bits/types/struct_tm.h>
#include <cstddef>
using namespace std;

typedef long long ll;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}; 

void traverse(Node* head)
{
	Node* tmp; 
	tmp = new Node(); 
	tmp = head; 
	while(tmp->next!=NULL)
	{
		cout << tmp->data << ' '; 
		tmp = tmp->next; 
	}
	cout << tmp->data << endl; 
}

Node* insert_at_the_beginnig(Node* head, int item)
{
	Node* new_node; 
	new_node = new Node();  
	new_node->data = item; 
	new_node->next = head; 
	new_node->prev = NULL; 
	head->prev = new_node; 
	head = new_node; 
	return head;  
}

void insert_between_two_node(Node* head, int pos, int item)
{
	ll cnt = 0; 
	Node* tmp ; 
	tmp = new Node(); 
	tmp = head; 
	while (cnt!=pos-1) 
	{
		cnt++; 
		tmp = tmp->next;
	}
	Node* new_node; 
	new_node = new Node(); 
	new_node->data = item; 
	new_node->prev = tmp; 
	new_node->next = tmp->next; 
	tmp->next->prev = new_node; 
	tmp->next = new_node;
}

Node* insert_at_the_end(Node* head, int item)
{
	Node* tmp; 
	tmp = new Node(); 
	tmp = head; 
	while(tmp->next!=NULL)
	{
		tmp = tmp->next;
	}
	Node* new_node ; 
	new_node = new Node(); 
	new_node->data = item; 
	new_node->next = NULL; 
	new_node->prev = tmp; 
	tmp->next = new_node;
	return  head;
}

void search_by_item(Node* head, int item)
{
	Node* tmp ; 
	tmp = new Node(); 
	tmp = head; 
	bool ok = true;  
	int i=0; 
	while(1)
	{
		if(tmp->data==item)
		{
			cout << i+1 << endl;
			ok =false; 
		}
		if(tmp->next==NULL) break;
		i++ ; 
		tmp= tmp->next;
	}
	if(ok) cout << "item not found\n";
}

int main()
{

    struct Node *head;
	struct Node *one = NULL;
	struct Node *two = NULL;
	struct Node *three = NULL;

	head = new Node(); 
	one = new Node(); 
	two = new Node(); 
	three = new Node(); 
	head->data = 3; 
	head->prev = NULL; 
	head->next = one; 
	one->prev = head; 
	one->next = two; 
	two->prev = one; 
	two->next = three; 
	three->prev = two; 
	three->next = NULL; 
	one->data = 9; 
	two->data = 4;
	three->data = 5; 

	traverse(head);  
	head = insert_at_the_beginnig(head, 100); 
	traverse(head); 
	insert_between_two_node(head, 2, 49); 
	traverse(head); 
	head = insert_at_the_end(head, 99); 
	traverse(head); 
	search_by_item(head, 100); 
	search_by_item(head, 88); 
}
//C program to check if there is a cycle in the linked list
//By following the floyd's cycle finding algorithm
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *root=NULL;

void append(int);
int checkcycle(void);

void main(){
	append(3);
	append(2);
	append(0);
	append(-4);
	//creating a loop
	root->next->next->next->next=root->next;
	if (checkcycle()){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
}

void append(int item){
	struct node* temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next = NULL;
	if (root == NULL){
		root = temp;
	}
	else{
		struct node* p;
		p= root;
		while ( p->next != NULL){
			p=p->next;
		}
		p->next =temp;
		
	}
}

int checkcycle(){
	struct node *slow,*fast;
	slow=root;
	fast=root;
	while(slow && fast && fast->next ){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			return 1;
		}
	}
	return 0;
}

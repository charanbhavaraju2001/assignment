#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};
struct node* root = NULL;

void insert(int);
int length(void);
void printsll(void);
void sortsll(void);


void main(){
	int i,item;
	printf("1.Append the linked list\n");
    printf("2.Print the SLL\n");
    printf("3.Sort the SLL\n");

	while(1){
		printf("Enter the option to be selected\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1 :
				printf("Enter the element to be inserted\n");
				scanf("%d",&item);
				insert(item);
				break;
			case 2 :
				printsll();
				break;
			case 3 :
				sortsll();
				break;
			case 4 :
				exit(1);
			default :
				printf("Wrong Input\n");
		}
	}
}

void insert(int item){
	struct node* temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link = NULL;
	if (root == NULL){
		root = temp;
	}
	else{
		struct node* p;
		p= root;
		while ( p->link != NULL){
			p=p->link;
		}
		p->link =temp;
		
	}
}

void printsll(){
    struct node* p;
    p=root;
    if(length()==0){
        printf("The list is Empty\n");
    }
    else{
        do {
            printf("%d -> ",p->data);
            p=p->link;
        }while(p!=NULL);
        printf(" NULL");
        printf("\n");
    }
}

int length(){
    int len=1;
    struct node* p;
    p=root;
    if(root==NULL){
        return 0;
    }
    else{
        while(p->link!=NULL){
            p=p->link;
            len++;
        }
        return len;
    }
}

void sortsll(){
    if(root==NULL || root->link == NULL){
        return;
    }
    
	struct node zeros,ones,twos;
	zeros.link=ones.link=twos.link=NULL;

	struct node *zero=&zeros,*one=&ones,*two=&twos;
	struct node* temp;
	temp = root ;
	do{
		switch(temp->data){
			case 0 :
				zero->link=temp;
				zero=zero->link;
				break;
			case 1 :
				one->link=temp;
				one=one->link;
				break;
			case 2 :
				two->link=temp;
				two=two->link;
				break;
			default :
				printf("Error\n");
				break;
		}
		temp=temp->link;
	}while(temp->link!=NULL);

	zero->link=(ones.link)?(ones.link):(twos.link);
	one->link=twos.link;
	two->link=NULL;

	root=zeros.link;
	
}

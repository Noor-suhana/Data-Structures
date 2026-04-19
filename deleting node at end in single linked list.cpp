#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=0,*temp=0;
void create()
{
	struct node *newnode=0;
	int i,n;
	printf("\nenter n size:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nenter node %d data:",i+1);
		scanf("%d",&newnode->data);
		newnode->link=0;
		if(head==0)
		{
			temp=head=newnode;
		}
		else
		{
			temp->link=newnode;
			temp=newnode;

		}
	}
}
void display()
{
	temp=head;
	while(temp!=0)
	{
		printf(" %d",temp->data);
		temp=temp->link;
	}
}
int main()
{
	create();
	struct node *prevnode=0;
	display();
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else if(head->link==0)
	{
		free(head);
		head=0;
	}
	else
	{
		temp=head;
		while(temp->link!=0)
		{
			prevnode=temp;
			temp=temp->link;
		}
		free(temp);
		prevnode->link=NULL;
	}
	printf("\nAFTER DELETING THE LAST NODE:");
	display();
	return 0;
}

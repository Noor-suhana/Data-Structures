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
	int pos,i;
	display();
	printf("\nenter position:");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else if(pos==1)
	{
		temp=head;
		head=temp->link;
		free(temp);
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->link;
		}
		prevnode=temp->link;
		temp->link=prevnode->link;
		free(prevnode);
	}
	printf("\nAFTER DELETING THE NODE AT PARTICULAR POSITION:");
	display();
	return 0;
}

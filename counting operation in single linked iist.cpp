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
int main()
{
	create();
	int count=0;
	temp=head;
	while(temp!=0)
	{
		count++;
		temp=temp->link;
	}
	printf("\nNODES COUNT IS : %d ",count);
	return 0;
}

# include<stdio.h>
# include<stdlib.h>
struct node
{
struct node *prev; 
int data;
struct node *next;
};
struct node *head=NULL, *tail=NULL, *temp=NULL;
void create()
{
struct node *newnode=NULL;
int i,n;
printf("\nenter n size: ");
scanf("%d", &n);
for(i=0;i<n;i++)
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("\nenter node %d data: ",i+1);
scanf("%d", &newnode->data);
newnode->prev=0;
newnode->next=0;
if(head==NULL)
{
head=newnode;
tail=newnode;
}
else
{
tail->next=newnode; 
newnode->prev=tail; 
tail=newnode;
}
}
}
void display()
{
temp=head;
while(temp!=NULL)
{
printf(" %d", temp->data);
temp=temp->next;
}
}
int main()
{
	create();
	display();
	struct node *currentnode=0, *nextnode=0; 
	currentnode=head; 
	while (currentnode!=NULL)
{
	nextnode=currentnode->next; 
	currentnode->next=currentnode->prev; 
	currentnode->prev=nextnode; 
	currentnode=nextnode;
} 
currentnode=head; 
head=tail; 
tail=currentnode; 
printf("\nAFTER REVERSING "); 
display();
return 0;
}

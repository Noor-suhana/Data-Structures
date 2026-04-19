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
int i,pos;
printf("\nenter position: ");
scanf("%d", &pos);
if(head==0)
{ 
	printf("\nLIST IS EMPTY");
}
else if(pos==1)
{
head=head->next; 
free(head->prev); 
head->prev=NULL;
}
else
{
temp=head;
for(i=1;i<pos;i++)
{
temp=temp->next;
}
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
}
printf("\nAFTER DELETING A NODE AT POSITION: "); 
display();
return 0;
}

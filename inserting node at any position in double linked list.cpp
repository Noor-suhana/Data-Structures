# include<stdio.h>
# include<stdlib.h>
struct node
{
struct node *prev;
int data;
struct node *next;
};
struct node *head=0,*temp=0,*tail=0; 
void create()
{
struct node *newnode=0; 
int i,n; 
printf("\nenter n size: "); 
scanf("%d",&n);
 for(i=0;i<n;i++)
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("\nenter node %d data: ",i+1);
scanf("%d", &newnode->data);
newnode->next=0;
newnode->prev=0;
if(head==NULL)
{
head=tail=newnode;
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
while(temp!=0)
{
printf(" %d", temp->data); temp=temp->next;
}
}
int main()
{
create(); 
display(); 
struct node *enode=NULL;
int pos,i;
enode=(struct node*)malloc(sizeof(struct node));
printf("\nenter data for newly created node: ");
scanf("%d", &enode->data);
enode->prev=0;
enode->next=0;
printf("\nenter position:");
scanf("%d",&pos);
if(pos==1)
{
	enode->next=head;
	head->prev=enode;
	head=enode;
}
else
{
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	enode->next=temp->next;
	enode->prev=temp;
	temp->next=enode;
	enode->next->prev=enode;
}
printf("\nAFTER INSERTING A NODE AT POSITION:");
display();
return 0;
}

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
struct node *enode=0;
enode=(struct node*)malloc(sizeof(struct node));
printf("\nenter data for newly created node: ");
scanf("%d", &enode->data);
enode->next=0;
enode->prev=0;
tail->next=enode;
enode->prev=tail;
tail=enode;
printf("\nAFTER INSERTING NODE AT END: ");
display();
return 0;
}

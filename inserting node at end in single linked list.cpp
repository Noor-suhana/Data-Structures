#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = 0, *temp, *newnode, *newnode2;
    int i, n;

    printf("\nEnter n size: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter node %d data: ", i + 1);
        scanf("%d", &newnode->data);

        newnode->link = 0;

        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
    }

    newnode2 = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter new node data: ");
    scanf("%d", &newnode2->data);

    newnode2->link = 0;

    temp = head;
    while (temp->link != 0)
        temp = temp->link;

    temp->link = newnode2;

    temp = head;
    while (temp != 0)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL");
    return 0;
}

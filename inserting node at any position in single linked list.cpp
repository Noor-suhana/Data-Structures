#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = 0, *temp, *newnode, *prev;
    int i, n, pos;

    printf("\nEnter n size: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data: ");
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

    printf("\nEnter position: ");
    scanf("%d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    temp = head;
    for (i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->link;
    }

    prev->link = newnode;
    newnode->link = temp;

    temp = head;
    while (temp != 0)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL");
    return 0;
}

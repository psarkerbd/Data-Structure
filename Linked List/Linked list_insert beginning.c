#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void insert_beg(struct node **head, int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data=data;
    ptr->link=NULL;

    ptr->link = *head;

    *head = ptr;

    return;
}

void insert_end(struct node **head, int data)
{
    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    ptr = *head;

    temp->data = data;
    temp->link = NULL;

    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = temp;
}

void printList(struct node **head)
{
    if(head == NULL)
    {
        printf("List is empty.\n");
    }

    struct node *ptr = NULL;

    ptr = head;

    while(ptr != NULL)
    {
        printf("%d ", ptr->data);

        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = NULL;

    insert_end(&head, 3); printList(head); printf("\n");
    insert_end(&head, 10); printList(head); printf("\n");
    insert_end(&head, 20); printList(head); printf("\n");

    insert_beg(&head, 5); printList(head); printf("\n");

    insert_end(&head, 23); printList(head); printf("\n");

    insert_beg(&head, 1); printList(head); printf("\n");

    return 0;
}

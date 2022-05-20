#include<stdio.h>
#include<stdlib.h>

#define sf scanf
#define pf printf

struct node
{
    int data;
    struct node *link;
};

struct node* push_front(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data=data;
    ptr->link=NULL;

    ptr->link=head;

    head = ptr;

    return head;
}

struct node* push_back(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data=data;
    temp->link=NULL;

    ptr = head;

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }

    ptr->link=temp;

    ptr = head;

    return ptr;
}

struct node *reverse(struct node *head)
{
    struct node *prev = (struct node *)malloc(sizeof(struct node));
    struct node *next = (struct node *)malloc(sizeof(struct node));

    prev = NULL;
    next = NULL;

    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }

    head = prev;

    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    head->data=45;
    head->link=NULL;

    head->link=second;

    second->data=55;
    second->link=NULL;

    second->link=third;

    third->data=65;
    third->link=NULL;

    head=push_front(head, 15);

    pf("Inserted 15 at the front of the linked list\n");

    ptr = head;

    while(ptr!=NULL)
    {
        pf("%d\n", ptr->data);

        ptr=ptr->link;
    }

    ptr=NULL;

    head = push_back(head, 75);

    pf("Inserted 75 at the end of the linked list\n");

    //ptr = NULL;

    ptr = head;

    while(ptr!=NULL)
    {
        pf("%d\n", ptr->data);

        ptr=ptr->link;
    }

    pf("Reversing the Linked list:\n");

    head = reverse(head);

    ptr = head;

    while(ptr!=NULL)
    {
        pf("%d\n", ptr->data);

        ptr=ptr->link;
    }


     return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_new_node_end(struct node **head, int data)
{
    struct node *temp, *ptr;

    ptr = *head;

    temp = (struct node*)malloc(sizeof(struct node));

    temp->data=data;
    temp->link=NULL;

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

    return;
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

int num_of_nodes(struct node *head)
{
    int count = 0;

    struct node *ptr = NULL;

    ptr = head;

    while(ptr != NULL)
    {
        count += 1;

        ptr = ptr->link;
    }

    return count;
}

int main()
{
    struct node *head = NULL;

    int N, i=0, data;

    printf("Enter the number of element: ");
    scanf("%d", &N);

    for(; i<N; i++)
    {
        printf("Enter Element %d: ", i+1);
        scanf("%d", &data);

        add_new_node_end(&head, data);
    }

    printf("The Linked list elements are:\n");

    printList(head);

    int total_nodes = num_of_nodes(head);

    printf("\nTotal number of nodes are: %d\n", total_nodes);

    return 0;

}

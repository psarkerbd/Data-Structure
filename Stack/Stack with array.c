#include<stdio.h>
#include<stdlib.h>

int stack[205], top=-1;

void push(int item, int n)
{
    n--;

    if(top >= n)
    {
        printf("The Stack is overflow\n");
    }

    else
    {
        top++;

        stack[top] = item;

        printf("Inserted position: %d\n", top);
    }
}

void pop()
{

    if(top <= -1)
    {
        printf("Stack is underflow\n");
    }

    else
    {
        printf("Deleted position %d\n", top);

        top--;
    }
}

void display(int n)
{
    int i=0;

    if(top >= 0)
    {
        for(i=top; i>=0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main()
{
    int s=5;
    //scanf("%d", &s);
    push(20, s);
    push(21, s);
    push(22, s);
    push(100, s);
    push(200, s);
    pop();
    pop();
    pop();

    display(s);

    return 0;
}

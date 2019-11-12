#include<stdio.h>
 
int stack[1000],choice,top,x,i;
void push(void);
void pop(void);
void display(void);
int n;
int main()
{
    top=-1;
    
    printf("\n Enter the size of stack of maximum 1000:");
    scanf("%d",&n);
    printf("\n#################################################");
    printf("\n\t Enter one(1) to push to the stack\n");
    printf("\n\t Enter two(2) to pop from the stack\n");
    printf("\n\t Enter three(3) to display the elements from stack\n");
    printf("\n\t Enter four(4) to exit\n");
    printf("\n#################################################\n");
	do
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                 
        }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\t stack over flow");
    }
    else
    {
        printf(" Enter a element to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t stack under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in stack \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The stack is empty");
    }
}

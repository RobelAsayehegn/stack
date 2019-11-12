#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
}*top,*top1,*temp;
 
int topelement();
void push(int data);
void pop();
void display();
void destroy();
void stack_count();
void create();
 
int stackelement = 0;
 
void main()
{
    int numbe, ch, e;
    
    printf("\n###########################################################################");
    printf("\n Enter one(1) to push to the stack");
    printf("\n Enter two(2) to Pop from the stack");
    printf("\n Enter three(3) to know the top element of the stack");
    printf("\n Enter four(4) to exit from the stack");
    printf("\n Enter five(5) to display the stack");
    printf("\n Enter six(6) to count the stack");
    printf("\n Enter seven(7) to delete the stack\n");
    printf("############################################################################\n");
 
    create();
 
    while (1)
    {
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &numbe);
            push(numbe);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack");
            else
            {
                e = topelement();
                printf("\n Top element : %d", e);
            }
            break;
        case 4:
            exit(0);
        case 5:
            display();
            break;
        case 6:
            stack_count();
            break;
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
void create()
{
    top = NULL;
}
 
void stack_count()
{
    printf("\n No. of elements in stack : %d", stackelement);
}
 
void push(int data1)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->next = NULL;
        top->data = data1;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->next = top;
        temp->data = data1;
        top = temp;
    }
    stackelement++;
}
 
void display()
{
    top1 = top;
    
    printf("Elements in the stack are: \n");
    if (top1 == NULL)
    {
        printf("stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->data);
        top1 = top1->next;
    }
}
 
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->next;
    printf("\n Popped value : %d", top->data);
    free(top);
    top = top1;
    stackelement--;
}
 
int topelement()
{
    return(top->data);
}

void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->next;
        free(top);
        top = top1;
        top1 = top1->next;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed");
    stackelement = 0;
}

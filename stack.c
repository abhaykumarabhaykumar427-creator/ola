#include<stdio.h>
#define maxsize 10
int stack[maxsize],top = -1;
void main()
{
    int choice;
    do
    {
        printf("\nAbhay kumar ray.....\n");
    printf("-----------stack implimentaion----------");
    printf("1.push\n2.pop\n3.display\n4.exit");
    printf("\n--------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
   case 1:push();
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        //case 4:exit();
        //break;
        default:printf("invalid your choice...");
    }
}while(choice != 4);
}
     
void push()
{
    int num;
    if(top == maxsize-1)
    printf("\n stack is overflow");
    else
    {
        printf("Enter an element : ");
        scanf("%d",&num);
        top++;
        stack[top] = num; 

    }
}
void display()
{
    int i;
    if(top == -1)
    {
        printf("stack is empty..");
    }
    else
    {
        printf("Element of stack");
        for(i=top;i>=0;i++)
        printf("\n %d ",stack);
    }
}

void pop()
{
    int num,i;
    if(top == -1)
    printf("stack is empty");
    else
    {
        num = stack[top];
        top--;
        printf("poped element %d ",num);
    }
}
temp()
{
    int i;
    for(i=0;i=5;i++)
    {
        printf("\n %d ",stack[i]);
    }
}
#include<stdio.h>
#define maxsize 10
int queue[maxsize];
int rear = -1,front = 0;
void main()
{
    int choice;
    do
    {
       printf("\n----------queue---------------\n");
       printf("1.insert\n2.delete\n3.display\n4.exit");
       printf("--------------------------\n");
       printf("Enter your choice : ");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1: insert();
        break;
        case 2: delete();
        break;
        case 3: display();
        default:printf("invalid choice...");

       }
    } while (choice!=4);
}

void insert()
{
    int num;
    if(rear == maxsize-1)
    printf("queue is overflow");
    else
    {
        printf("Enter an element");
        scanf("%d",&num);
        rear++;
        queue[rear]=num;
    }
}

void delete()
{
    int num;
    if(front>rear)
    printf("queue is empty");
    else
    {
        num = queue[front];
        front++;
        printf("deleted element is %d ",num);
    }
}

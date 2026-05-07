#include<stdio.h>
#define maxsize 6
int cq[maxsize];
int rear=-1,front=-1;
int main()
{
    int choice;
    do
    {
       printf("\n------cqueue--------\n");
       printf("1.insert\n2.display\n3.delete\n");
       printf("-----------------------\n");
       printf("Enter your choice....");
       scanf("%d",&choice);

       switch(choice)
       {
        case 1: insert();break;
        case 2: display();break;
        case 3: delete();break;

        default: printf("incrrect number..");
       }
    }while(choice != 4);
}

void insert()
{
    int num;
    if((rear+1)% maxsize== front)
    {
        printf("cq is overflow..");
    }

    else
    {
        printf("Enter the number = ");
        scanf("%d",&num);

        if(rear == -1&& front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = (rear +1)%maxsize;
        }
        cq[rear]=num;
    }
}

void display()
{
    int i;
    if(rear == -1 && front ==-1)
    {
        printf("cqueue is empty..");
    }

    else
    {
        printf("element is cqueue... \n");
        for(i=front;i!=rear;(i=(i+1)%maxsize))
        {
            printf("%d\n",cq[i]);
        }
       printf("%d\n",cq[i]);
    }
}

void delete()
{
    int num;
    if(rear==-1&&front==-1)
    {
        printf("cqueue is empty..");
    }
    else
    {
        num = cq[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {

        }
        front = (front +1)%maxsize;
        printf("deleted element...%d  ",num);
    }
}
#include<stdio.h>
struct node
{
          int data;
          struct node *add;
};struct node *start=NULL,*temp,*new1,*prev,*next,arr[100];
void main()
{
          int choice;
          do
          {
             printf("\n-----linked list menu-----\n");
             printf("1.created list\n");
             printf("2.display\n");
             printf("3.insert_first\n");
             printf("4.insert_last\n");
             printf("5.insert_middle\n");
             printf("6.delete_first\n");
             printf("7.delete_last\n");
             printf("8.delete_middle\n");
             printf("9.counting node\n");
             printf("10.searching data\n");
             printf("11.shorted data \n");
             printf("\n---------------------------\n");
             printf("Enter your choice = ");
             scanf("%d",&choice);
             switch(choice)
             {
                    case 1: created_list();break;
                    case 2: display();break;
                    case 3: insert_first();break;
                    case 4: insert_last();break;
                    case 5: insert_middle();break;
                    case 6: delete_first();break;
                    case 7: delete_last();break;
                    case 8: delete_middle();break;
                    case 9: count();break;
                    case 10:searching();break;
                    case 11:shorted();break;
                    default:printf("\ninvalid choice...");
             }
             }while(choice != 12); 
}

void created_list()
{
          int num;
          char choice;
          printf("Enter the element : ");
          scanf("%d",&num);
           start=(struct node*)(malloc(sizeof(struct node)));
           start->data=num;
           start->add=NULL;
           temp = start;
           printf("\n-----------------\n");
           printf("want to continue..");
           choice = getche();
           while(choice=='y'||choice=='Y')
           {
              printf("\nEnter the next element...");
              scanf("%d",&num);
              new1=(struct node*)(malloc(sizeof(struct node)));
              new1 ->data=num;
              new1->add=NULL;
              temp->add=new1;
              temp = temp->add;
              printf("\n-----------------\n");
              printf("want to continue..");
              choice = getche();
           }
}

void display()
{
       if(start == NULL)
       printf("list not found..");
       else
       {
             temp = start;
             while(temp != NULL)
             {
              printf("%d  ",temp->data);
              temp = temp->add;
             }
       }
}

void insert_first()
{
       int num;
       if(start==NULL)
       {
              printf("invalid list not found");
       }
       else
       {
              printf("Enter the number...");
              scanf("%d",&num);
              new1=(struct node*)(malloc(sizeof(struct node)));
              new1->data=num;
              new1->add=NULL;
              new1->add=start;
              start = new1;
       }
}

void insert_last()
{
       int num;
       if(start == num)
       {
              printf("invalid list not found ");
       }
       else
       {
              printf("Enter the number = ");
              scanf("%d",&num);
              new1=(struct node*)(malloc(sizeof(struct node)));
              new1->data=num;
              new1->add=NULL;
              temp=start;

              while(temp->add != NULL)
              {
                temp = temp->add;
              }
              temp ->add=new1;
       }
}

void insert_middle()
{
       int num;
       int i = 1 ,pos;
       if(start == NULL)
       {
              printf("invalid list node");
       }
       else
       {
              printf("Enter the number = ");
              scanf("%d",&num);

              new1=(struct node*)(malloc(sizeof(struct node)));
              new1->data = num;
              new1->add=NULL;
              printf("Enter the postion..");
              scanf("%d",&pos);
              next = start;
              while(i<pos)
              {
                     prev=next;
                     next=next->add;
                     i++;
              }
              prev->add=new1;
              new1->add=next;
       }
}

void delete_first()
{
       if(start== NULL)
       {
              printf("list not found ");
       }
       else
       {
              temp =start;
              start = start->add;
              printf("deleted element is = %d",temp->data);
              free(temp);
       }
}

void delete_last()
{
       if(start == NULL)
       printf("list not found ");
       else
       {
              temp = start;
              while(temp -> add != NULL)
              {
                     prev=temp;
                     temp=temp->add;
              }
              prev->add=NULL;
              printf("deleted element is = %d",temp->data);
              free(temp);
       }
}
void delete_middle()
{
       int pos,i=1;
       if(start == NULL)
       printf("list not found");
       else
       {
              printf("Enter your choice of position... ");
              scanf("%d",pos);
              temp = start;
              while(i<pos)
              {
                     prev =temp;
                     temp = temp->add;
                     i++;
              }
              next = temp->add;
              prev->add=next;
              printf("deleted element is %d ",temp->data);
              free(temp);
       }
}

void count()
{
       int count=0;
       temp=start;
       while(temp!=NULL)
       {
              count++;
              temp=temp->add;
       }
       printf("total node list... %d",count);
}

void searching()
{
       int s;
  int f=0;
  if(start==NULL)
  printf("list not execute");
  else
  {
       printf("Enter an element for search = ");
       scanf("%d",&s);
       temp = start;
       while(temp!=NULL)
       {
              if(temp->data==s)
              {
                     f=1;
                     break;
              }
              temp=temp->add;
       }
       if(f==1)
       printf("searching sucessfuly..");
       else
       printf("searching not sucessfully..");
       
  }     
}

void shorted()
{
       int t;
       if(start == NULL)
       printf("list not executed..");
       else
       {
              prev=start;
              while(prev!=NULL)
              {
                     next = prev->add;
                     while(next!=NULL)
                     {
                            if(prev->data<next->data)
                            {
                                   t= prev->data;
                                   prev->data=next->data;
                                   next->data=t;
                            }
                      next=next->add;
              
                            }
                            prev=prev->add;
              }
       }
}
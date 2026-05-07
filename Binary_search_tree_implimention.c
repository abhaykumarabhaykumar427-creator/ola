#include<stdio.h>
#include<conio.h>
#define clrscr() system("cls")
// define the structure
struct node
{
    struct node *ladd;
    int data;
    struct node *radd;
};struct node *root=NULL,*new1;
//function declaration
void create(struct node *recive, struct node *new1);
void inorder(struct node *r);
void preorder(struct node *r);
void postorder(struct node *r);
void search(struct node *pt,int s);
void delete1(struct node *p);
void main()
{
    int choice,num;
    char ch;
    do
    {
        printf("\n----Binary search tree implimention----\n");
        printf("\n1.Create");
        printf("\n2.Inorder");
        printf("\n3.Preorder");
        printf("\n4.postorder");
        printf("\n5.Searching");
        printf("\n6.delete tree");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
            do
            {
               printf("\nEnter an element : ");
               scanf("%d",&num);
               new1=(struct node*)malloc(sizeof(struct node));
               new1->ladd=new1->radd = NULL;
               new1->data = num;
               if(root == NULL)
               root = new1;
               else
               create(root,new1);
               printf("\nWant to continue : ");
               ch = getche();
            } while (ch=='Y'||ch=='y');
            break;
          }
          case 2:
                printf("\nInorder Traversal: ");
                inorder(root);
                break;
          case 3:
                printf("\npreorder Traversal:");
                preorder(root);
                break;
          case 4:
                printf("\npostorder Traversal:");
                postorder(root);break;
          case 5:
                
                printf("\nEnter an element for search : ");
                int s;
                scanf("%d",&s);
                break;
          case 6:
                delete1(root);break;
        }
    } while (choice !=7);
}
// create the tree structure..

void create(struct node *recive,struct node *new1)
{
  if(new1->data < recive->data)
  {
    if(recive->ladd == NULL)
    recive ->ladd = new1;
    else
    create(recive->ladd,new1);
  }
  if(new1->data > recive->data)
  {
    if(recive->radd == NULL)
    recive -> radd = new1;
    else
    create(recive ->radd,new1);
  }
  if(recive->data == new1->data)
  printf("Duplicate element is not allow..");
}

void inorder(struct node *r)
{
  if(r!=NULL)
  {
      inorder(r->ladd);
      printf("%5d",r->data);
      inorder(r->radd); 
  }
}

void preorder(struct node *r)
{
  if(r!=NULL)
  {
    printf("%5d",r->data);
    preorder(r->ladd);
    preorder(r->radd);
  }
}

void postorder(struct node *r)
{
  if(r!=NULL)
  {
    postorder(r->ladd);
    postorder(r->radd);
    printf("%5d",r->data);
  }
}

void search(struct node *pt,int s)
{
  if(pt==NULL)
  {
    printf("\nElement not found..");
  }
  else
  {
    if(s<pt->data)
      search(pt->ladd,s);
    if(s>pt->data)
      search(pt->radd,s);
    if(s==pt->data)
    printf("Searching successfuly...");
  }
}
void delete1(struct node *p)
{
  struct node *pt,*prev,*temp;
  int n;
  pt = p;
  if(pt==NULL)
  {
    printf("\nTree not found");
  }
  else
  {
    printf("\nEnter an element for delete : ");
    scanf("%d",&n);
    while(n!=pt->data)
    {
      prev = pt;
      if(n<pt->data)
      pt = pt->ladd;
      else
      pt = pt->radd;
    }

    // node which having left and right address null
    if(pt->ladd == NULL && pt->radd==NULL)
    {
      if(n<prev->data)
      prev->ladd = NULL;
      else
      prev->radd=NULL;
    }
  else
  {
    //node which having left is null but right address is not null
    if(pt->ladd==NULL && pt->radd!=NULL)
    {
      if(n<prev->data)
      prev->ladd=pt->radd;
      else
      prev->radd = pt->radd;
    }

    //node which having left is not null but righ address i null
    else
    {
      if(pt->ladd!=NULL && pt->radd == NULL)
      {
        if(n<prev->data)
        prev->ladd = pt->ladd;
        else
        prev->radd = pt->ladd;
      }
      else
      {

        // node which having left is not null but right address is not null
        temp = pt->ladd;
        while(temp ->radd!=NULL)
        {
          temp = temp->radd;
        }
        temp->radd = pt ->radd;
        if(n<prev->data)
        prev ->ladd = pt->ladd;
        else
        prev->radd = pt->ladd;
      }
    }
  }
}
printf("\nDeleted node is : %d",pt->data);
  
}
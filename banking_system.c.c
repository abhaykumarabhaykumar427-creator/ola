#include<stdio.h>
#include<conio.h>
#include<string.h>
//define the structure
struct ATM
{
   int acno;// declare the acount number
   char name[50];
   int amount;
};struct ATM A1[5];

void design();
void create_acount();
void deposit();
void withdrol();
void balance();
void display_account();

int main()
{
    static int i=0;
    int choice = 0;
    int count = 0;
    char ch1,ch2,ch3,ch4,ch5;
  // create password
  pin:  printf("\nEnter your pin : ");
    ch1 = getch();
    printf("*");
    ch2 = getch();
    printf("*");
    ch3 = getch();
    printf("*");
    ch4 = getch();
    printf("*");
    ch5 = getch();
    printf("*");

    if(ch1=='A'&&ch2=='b'&&ch3=='h'&&ch4=='a'&&ch5=='y')
    
       printf("\n You are valid password...");
       else
       {
        if(i==2)
        {
           printf("\nContact to admin....");
           exit(0);
        }
        else{
            i++;
            printf("\nCorrect pin ... Enter again\n");
            goto pin;
        }
       }
do
{
      design();
      printf("\n Enter your choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1: create_acount();break;
        case 2: display_account();break;
        case 3: deposit();break;
        case 4: withdrol();break;
        case 5: balance();break;
        case 6: break;
        default : printf("Invalid your choice....");
      }
    }while(choice!=6);
}
void design()
{
    printf("\n-------Atm Banking--------");
    printf("\n1.create Acount..");
    printf("\n2.Display Amount..");
    printf("\n3.deposit Amount..");
    printf("\n4.withdrowl Amount..");
    printf("\n5.balance..");
    printf("\n6.Exit..");
    printf("\n----------------------------");
}

void create_acount()
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("\nEnter Acount number : ");
        scanf("%d",&A1[i].acno);
        printf("\nEnter your name : ");
        scanf("%s",&A1[i].name);
        printf("\nEnter your Amount : ");
        scanf("%d",&A1[i].amount);
    }
}
//create with display acount

void display_account()
{
  int i;
  printf("\nAccount no\tName\t\tBalance");
  for(i=0;i<5;i++)
  {
    printf("\n%d",A1[i].acno);
    printf("\t\t%s",A1[i].name);
    printf("\t\t%d",A1[i].amount);
    printf("\n");
  }
}

void deposit()
{
 int amt,f=0;
 int accno , i;
 printf("\nEnter an account number : ");
 scanf("%d",&accno);
 for(int i=0;i<5;i++)
 {
    if(A1[i].acno == accno)
    {
        f=1;
        printf("Name : %s",A1[i].name);
        printf("\nEnter an amount : ");
        scanf("%d",&amt);
        if(amt<0)
        printf("\ninvalid amount..");
        else
        {
            A1[i].amount = A1[i].amount + amt;
            break;
         }
    }
    if(f==0)
    printf("\ninvalid acount no.. please check ");
}
}

void withdrol()
{
    int accno,i;
    int amt , f=0;
    printf("\nEnter an Acount number : ");
    scanf("%d",&accno);
    for(int i=0;i<5;i++)
    {
        if(A1[i].acno == accno);
        {
            f=1;
            printf("\nName : %s",A1[i].name);
            printf("\nEnter an amount for withdrol : ");
            scanf("%d",&amt);
            if(amt<0||amt>A1[i].amount)
            printf("invalid amount or insufficiant balance..");
            else
            A1[i].amount = A1[i].amount - amt;
            break;
        }
    }
    if(f==0)
    printf("\n invalid account number...plase check");
}

void balance()
{
    int accno,i;
    printf("\nEnter an account number : ");
    scanf("%d",&accno);
    for(i=0;i<5;i++)
    {
        if(A1[i].acno == accno)
        {
            printf("\nAccount no : %d",A1[i].acno);
            printf("\nName : %s",A1[i].name);
            printf("\nBalance : %d ",A1[i].amount);
        }
    }
}
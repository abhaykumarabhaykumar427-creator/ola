#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
typedef struct binarysearchtree BST;
struct binarysearchtree
{
    int passno;
    char name[20];
    struct binarysearchtree *left;
    struct binarysearchtree *right;
};
BST *root = NULL;
int cust(BST *r);// calculate cost
void status();// show bus and seats status
void buslist();
void displayseat(int bus[33]);//display the bus seats
void cancel(int x);
BST *reservation_info(BST*,int ,int*);
BST *insert(BST **r,int cust_id);
int busseat[32][9] = {0};
void redcolor()
{
    printf("\n\033[131m]\n");
}
void resetcolor()
{
    printf("\n\033[0m\n");
}
BST *reservation_info(BST *r,int s ,int *cust_idmached)
{
    if(r==NULL)
    return NULL;
    BST *presentnode = r;
    while(presentnode)
    {
        //------------------------
        if(presentnode->passno == s)
        {
            *cust_idmached = 1;
            redcolor();
            printf("\n------------------------------");
            printf("\n||Name : %10s                ||",(presentnode->name));
            printf("\n||Customer id : %d           ||",(presentnode->passno));
            printf("\n||bus number : %d            ||",(presentnode->passno)/1000);
            printf("\n||seat number : %d           ||",(presentnode->passno)%100);
            printf("\n||ticket cost : %d           ||",cust(presentnode));
            printf("\n------------------------------");
            resetcolor();
            getch();
            return r;
        }
        else if(presentnode->passno>s)
        presentnode = presentnode->left;
        else
        presentnode = presentnode -> right;
    }
    return NULL;
}
BST *insert(BST **r,int cust_id)
{
    if(*r == NULL)
    {
        *r = (BST *)malloc(sizeof(BST));
        (*r)->passno = cust_id;
        if(*r == NULL)
        {
            printf("no memory...");
            return NULL;
        }
        else
        {
            (*r)->left = (*r)->right = NULL;
            printf("\n Enter the person name : ");
            scanf("%s ",&((*r)->name));
        }
    }
    else
    {
        if((*r) -> passno>cust_id)
        {
            (*r)->left = insert(&((*r)->left),cust_id);
        }
        else if((*r)->passno<cust_id)
        {
            (*r)->right = insert(&((*r)->right),cust_id);
        }
    }
    return *r;
}
void displayseat(int bus[33])
{
    for(int i=1;i<32;i++)
    {
        redcolor();
        if(i<10&&i>0)
        {
            printf("0 %d .",i);
        }
        else
        {
            printf("%d .",i);
        }
        resetcolor();
        {
            if(bus[i]== 0)
            printf("Empty");
            else
            printf("booked");
        }
        printf("--------------");
        if(i%4==0)
        printf("\n");
    }

}
void login()
{
    char username[20] = "abhay";
    char password[10]= "team 18";
    char match_pass[10];
    char match_user[10];
    int value;
    redcolor();
    printf("\n\n---------------------------");
    printf("\n welcome to online bus reservation");
    printf("\n\n---------------------------");
    resetcolor();
    login:
    {
        printf("\n\n user name : ");
        gets(match_user);
    }
    value = strcmp(password,match_pass);
    if(value!=0)
    {
        redcolor();
        printf("\ninvalid detels try again...\n");
        resetcolor();
       // goto login;
    }
    else
    {
        printf("\nloged in sussessfully..");
    }
}
int cust(BST *r)
{
int cost,bus_cost;
bus_cost = (r->passno)/1000;
switch(bus_cost % 3)
{
    case 1:
    return 70;
    break;
    case 2:
    return 55;
    break;
    case 0:
    return 40;
    break;
    default:
    return 0;
    break;
}
}
void status()
{
    int bus_num;
    buslist();
    businput:

printf("Enter your bus number : ");
scanf("%d",&bus_num);
if(bus_num<=0||bus_num>=10)
{
  redcolor();
  printf("\nplease enter correct bus number : ");
 redcolor();
 goto businput;
}
printf("\n");
displayseat(busseat[bus_num]);
getch();
}
void buslist()
{
    redcolor();
   printf("\n1. \t ganatock trvals     \tpiro to ara    \t 5:00   AM");
   printf("\n2. \t babuaan trvals     \tpiro to sasaram    \t 6:00   AM");
   printf("\n3. \t maharana trvals     \tpatna to ara    \t 2:00   AM");
   printf("\n4. \t tiwari trvals     \tchapra to ara    \t 9:00   AM");
   printf("\n5. \t mahuli trvals     \tpiro to ara    \t 9:00   AM");
   printf("\n6. \t abhay trvals     \tpatna to mujhafrpur    \t 10:00   AM");
   printf("\n7. \t asdf trvals     \tpiro to ara    \t 3:00   AM");
   printf("\n");
   printf("\n  press Enter key to continue ");
   getch();
}
void cancel(int randomnum)
{
    int reservationno;
    int seatnumber;
    int choice;
    char c;
    int seatcancel;
    aa:
    {
      printf("Enter your reservation number : ");
      scanf("%d",&reservationno);
      if(reservationno == randomnum)
      {
        printf("\nreservation number is it correct ? %d \nenter(y/n) : ",reservationno);
        scanf("%s",&c);
        if(c=='y'||c=='Y')
        {
            printf("\n\n-------------------------------------");
            printf("Enter the bus number : ");
            scanf("%d",&choice);
            printf("\nhow many seat do you want to cancel : ");
            scanf("%d",&seatcancel);
            busseat[choice][seatnumber] = 0;
        }
        else if(c=='n'||c=='N')
        {
            printf("\nyour reservation canceation has been denied \n");

        }
      }
      else
      {
        printf("\n not found !! Enter the correct reservation number : ");
        goto aa;
      }
    }
}
int main()
{
    srand(time(0));
    int randomnum = rand();
    int num , i, cust_id,reservationno;
    BST *root1;
    login();
    main:
    {
        do
        {
           printf("\n\n---------------------------------");
           printf("\t\t03343 bus reservation\033\t\t");
           printf("\n\n---------------------------------");
           printf("\n-----------");
           redcolor();
           printf("main menu");
           resetcolor();
           printf("-------------\n\n");
           printf("....view bus list....\n\n");
           printf("....book ticket....\n\n");
           printf("....cancel booking....\n\n");
           printf("....busses seat info....\n\n");
           printf("....reservation info....\n\n");
           printf("....exit....\n\n");
           printf("\n-----------------------------");
           printf("\nEnter your choice:  ");
           scanf("%d",&num);
           switch(num)
           {
            case 1:
                 buslist();
                 break;
            case 2:
                 buslist();
                 int cust_id,choice,seats;
                 buschoice:
                 printf("\n\nchoose your bus : ");
                 scanf("%d",&choice);
                 if(choice<=0||choice>9)
                 {
                    redcolor();
                    printf("\nEnter the valid bus number !!\n");
                    resetcolor();
                    getch();
                    goto buschoice;
                 }
                 printf("\n");
                 displayseat(busseat[choice]);
                 bus_seat_choice:
                 printf("\n\n no. of seats you need to book :");
                 scanf("%d",&seats);
                 if(seats<=0)
                 {
                    redcolor();
                    printf("\nEnter valid seat number :\n");
                    redcolor();
                    goto bus_seat_choice;
                 }
                 else if(seats>32)
                 {
                   redcolor();
                   printf("Enter valid seat number we have only 32 seats in a bus !!\n");
                   resetcolor();
                   goto bus_seat_choice;
                 }
                 int seat_number;
                 for(int i=1;i<=seats;i++)
                 {
                    printf("\n\n====================================");
                 seat:
                    printf("\nEnter the seat numebr : ");
                    scanf("%d",&seat_number);
                    if(seat_number<=0)
                    {
                        redcolor();
                        printf("Enter the valid seat number : ");
                        resetcolor();
                        goto seat;
                    }
                    else if(seat_number > 32)
                    {
                        redcolor();
                        printf("\n Enter the valid seat number we have only 32 seat in a bus !! \n\n");
                        resetcolor();
                        goto seat;
                    }
                    cust_id = choice * 1000 + seat_number;
                    busseat[choice][seat_number] = 1;
                    root = insert(&root , cust_id);
                    redcolor();
                    printf("\n your customer id is : %d",cust_id);
                    resetcolor();
                    printf("\n\n===================================");
                 }
                 printf("\n your reservation number is : ");
                 redcolor();
                 printf("%d\n",randomnum);
                 printf("\n please note dowm your reservation number for booking ticket !!");
                 resetcolor();
                 printf("press enter key to continue ");
                 getch();
                 break;
                 case 3:
                 cancel(randomnum);
                 break;
                 case 4:
                 status(randomnum);
                 break;
                 case 5:
                 taking_reservation_no:
                 printf("\nEnter your reservation number :  ");
                 scanf("%d",&reservationno);
                 if(randomnum == reservationno)
                 {
                    cust:
                    printf("\nEnter your customer id : ");
                    scanf("%d ",&cust_id);
                    int cust_id_dmatched = 0;
                    root1 = reservation_info(root,cust_id,&cust_id_dmatched);
                    if(cust_id_dmatched == 0)
                    {
                        redcolor();
                        printf("Enter correct custmor id : ");
                        resetcolor();
                        goto cust;
                    }
                 }
                 else
                 {
                    redcolor();
                    printf("\ninvalid reservation number please correct reservation number : ");
                    resetcolor();
                    goto taking_reservation_no;
                 }
                 break;
                 default:
                 redcolor();
                 printf("\n\n invalid input chosse correct option \n");
                 resetcolor();
                 break;
           }

        }while(num!=6);
        printf("\n\n==============================================");
        printf("\nthank you for using this bus reservatiion system ");
        printf("\n\n: press any key to exit the end program :");
        printf("\n\n");
        getch();
        return 0;
    }
  }


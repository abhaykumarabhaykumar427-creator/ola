#include<stdio.h>
#include<conio.h>
int main()
{
    static int i = 0;
    char ch1,ch2,ch3,ch4,ch5;
    printf("---------------------------\n");
   pin:printf("Enter pasward : ");
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

     if(ch1=='a'&&ch2=='b'&&ch3=='h'&&ch4=='a'&&ch5=='y')
      //aprintf("\n--------------------------\n");
      printf("\n you are valid passward...");
      //printf("\n--------------------------\n");
      else
      {
        if(i==2)
        {
            printf("\nContact to admin...");
            exit(0);

        }
        else
        {
            i++;
            printf("\nincorect pin...Enter again\n");
            goto pin;
        }
      }
}
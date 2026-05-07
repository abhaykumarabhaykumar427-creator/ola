#include<stdio.h>
#include<conio.h>
#include<string.h>

struct product
{
    int product_id;
    char product_name[50];
    int qu;
    int rate;
};struct product p[5];
void main()
{
    int i,total = 0;
    for(i=1;i<=5;i++)
    {
        fflush(0);
        printf("Enter the product id :");
        scanf("%d",&p[i].product_id);
        fflush(0);
        printf("Enter the product name : ");
        scanf("%s",&p[i].product_name);
        fflush(0);
        printf("Enter the quantity : ");
        scanf("%d",&p[i].qu);
        fflush(0);
        printf("Enter the Rate : ");
        scanf("%d",&p[i].rate);
        fflush(0);
    }
    printf("\n-------------------------------------------------------\n");
    printf("-------------------product details-----------------------\n");
    printf("\n product id   product name   Quantity   Rate    Amount\n");
    for(i=1;i<=5;i++)
    {
        printf("  %d         \t%s    \t%d     \t%d   \t%d",p[i].product_id,p[i].product_name,p[i].qu,p[i].rate,(p[i].qu*p[i].rate));
        total = total+ p[i].qu*p[i].rate;
        printf("\n");
    }
    printf("---------------------------------------------------------\n");
    printf("\n--------------------------------> total amount = %d \n",total);
    printf("---------------------------------------------------------\n");
}

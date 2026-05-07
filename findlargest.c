#include<stdio.h>
int main()
{
    int num,limit;
    int arr[100];
    xyz:printf("Enter the limit : ");
    scanf("%d",&num);
    if(num>100)
    {
        printf("your 100 digit the above.. please try again.");
        goto xyz;
    }
    printf("Enter the number : ");
    for(int i=0;i<=num;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("your the digit by ->");
    printf("\n-------------------------------------------");
    for(int i=0;i<=num;i++)
    {
      printf("\n%d  ",arr[i]);
    }
    printf("\n--------------------------------------------");
    printf("\nfind the largest digit:");
    int max = 0;
    int p=0;
    for(int i=1;i<=num;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            p=i;
        }
    }
    printf("\n  %d",max);
    printf("\nposition is  %d",(p+1));
}
#include<stdio.h>
#include<stdlib.h>
void new_customer(void);

typedef struct customer
{
    char customer_name[100];
    char father_name[100];
    char Birth_Date[100];
    char account_type;
}CUSTOMER;

void new_customer()
{
    CUSTOMER c1;
    int flag=0;
    printf("Enter name : ");
    fflush(stdin);
    gets(c1.customer_name);
    printf("Enter Father's name : ");
    fflush(stdin);
    gets(c1.father_name);
    printf("Enter Date of birth in numbers : ");
    fflush(stdin);
    gets(c1.Birth_Date);
    printf("Enter Account Type:\nPress S for Savings, \nPress C for Current, \nF for Fixed. \n");
    scanf("%c",&c1.account_type);
    while(flag!=1)
    {
        if (c1.account_type=='S' ||c1.account_type=='C' ||c1.account_type=='F')
        {
            printf("Account Created Successfully!!\n");
            flag=1;
        }
        else
        {
            printf("Account Not Created! Wrong Input. Input Again.\n");
            scanf("%c", &c1.account_type);
            flag=0;
        }
    }
}



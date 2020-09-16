#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void new_customer(void);
void transaction(void);

typedef struct customer
{
    char customer_name[100];
    char father_name[100];
    char Birth_Date[100];
    char account_type;
}CUSTOMER;

void new_customer()
{
    char ch;
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
    printf("Enter Account Type:\nPress S for Savings, \nPress C for Current, \nF for Fixed : ");
    scanf("%c",&c1.account_type);
    while(flag!=1)
    {
        if (c1.account_type=='S'|| c1.account_type=='s'||c1.account_type=='C'||c1.account_type=='c'||c1.account_type=='F'||c1.account_type=='f')
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
    while(1)
    {
        printf("Return to Main Menu? Y/N : ");
        scanf("%c", &ch);
        if(ch=='Y' || ch=='y')
        {
            system("cls");
            main();
        }
        else if(ch=='N' || ch=='n')
        {
            exit(0);
        }
        else

        {
        printf("\nWrong input. Try Again!\n");
        }
    }
}

void transaction()
{
    int choice, account_number;
    float deposit, withdraw, balance=0;
    printf("Enter Account Number : ");
    scanf("%d", &account_number);
    while(1)
    {
        printf("[1] Deposit\n");
        printf("[2] Withdraw\n");
        printf("[3] Check Available Balance\n");
        printf("[4] Return to Main Menu\n");
        printf("\nEnter choice : ");

        scanf("%d", &choice);
        switch(choice)
        {
            case 1: {
                printf("Enter the amount to deposit : ");
                scanf("%f", &deposit);
                Sleep(5000);
                balance=balance+deposit;
                printf("\nAmount Deposit Successfully!!");
                printf("\nAvailable Balance : %.2f\n", balance);
                break;
            }
            case 2: {
                printf("\nEnter the amount to withdraw : ");
                scanf("%f", &withdraw);
                Sleep(5000);
                if(balance<=0)
                    printf("\nError: Amount cannot be withdrawn.\nAvailable Balance : %.2f\n", balance);
                else
                {
                    balance=balance-withdraw;
                    printf("\nAmount Withdrawn Successfully!!");
                    printf("\nAvailable Balance : %.2f\n", balance);
                }
                break;
            }
            case 3:{
                printf("\nAvailable Balance : %.2f\n", balance);
                break;
            }
            case 4:{
                system("cls");
                main();
                break;
            }
            default:
                printf("Wrong input!!!\n");

        }
    }
}

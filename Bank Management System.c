///////////////////////////////////////////////////BANK MANAGEMENT SYSTEM////////////////////////////////////////////////////////////////

//ALL HEADER FILES
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

//ALL FUNCTION DECLARATIONS
int menu(void);
float interest(float,int,int);
void new_customer(void);
void update_info(void);
void transaction(void);
void customer_details(void);
void remove_user(void);
void customer_list(void);

//STRUCTURES DECLARED
typedef struct date{
    int month, day, year;
}date;

//MAIN CUSTOMER STRUCTURE CONTAINING ALL NEEDED VARIABLES FOR CUSTOMER
struct customer
{
    long int account_number;
    char customer_first_name[30];
    char customer_last_name[30];
    char father_first_name[30];
    char father_last_name[30];
    char h_no[30];
    char st_name[30];
    char area[30];
    char city[20];
    char Nationality[50];
    char p_number[30];
    struct date dob;
    int amount, age;
    struct date deposit;
    struct date withdraw;
    char account_type;
}add, update, check, transact, del, details;

//GOTOXY FUNCTION FOR BETTER ALIGNMENT OF MENU
int gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//MAIN MENU FUNCTION
int menu()
{
    int i, a;
    printf("======================================================================================================================\n");
    printf("\t\t\t\t\tBANK MANAGEMENT SYSTEM\n");
    printf("======================================================================================================================\n");

    gotoxy(43, 3);
    printf(":: MAIN MENU ::\n");

    gotoxy(40, 5);
    printf("[1] Create a new account");
    gotoxy(40, 6);
    printf("[2] Update information of existing account");
    gotoxy(40, 7);
    printf("[3] Transactions");
    gotoxy(40, 8);
    printf("[4] Check details of existing account");
    gotoxy(40, 9);
    printf("[5] Remove existing account");
    gotoxy(40, 10);
    printf("[6] View Customer List");
    gotoxy(40, 11);
    printf("[7] Exit\n");

    gotoxy(40, 15);
    printf("Enter your choice : ");
    scanf("%d", &a);
    return a;
}

//INTEREST FUCNTION INCLUDED FOR CALCULATION FOR INTEREST
float interest(float time, int amount, int rate)
{
    int SI;
    SI=(amount*time*rate)/100;
    return SI;
}

//NEW CUSTOMER FUNCTION, ADDS NEW CUSTOMER IN RECORDS
void new_customer()
{
    printf("========================================================================================\n");
    printf("\t\t\t\tADD RECORD\n");
    printf("========================================================================================\n\n\n");
    char ch;
    int flag=0;
    FILE *fp;
    fp=fopen("DataFile.txt", "a+");

    printf("Enter today's date (dd/mm/yyyy) : ");
    scanf(" %d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);

    printf("Enter Account Number :  ");
    fflush(stdin);
    scanf("%ld", &check.account_number);

    while(fscanf(fp, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c", &add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, &add.p_number, &add.age, &add.dob.day, &add.dob.month, &add.dob.year, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year, &add.account_type)!=EOF)
    {
        if(check.account_number==add.account_number)
            {
                printf("Account number already taken. Please contact administrator.\nPress enter to continue.");
                getch();
                system("cls");
                main();
            }
    }

    add.account_number=check.account_number;
    printf("Enter First name : ");
    fflush(stdin);
    scanf("%s", &add.customer_first_name);

    printf("Enter Last name : ");
    fflush(stdin);
    scanf("%s", &add.customer_last_name);

    printf("Enter Father's First name : ");
    fflush(stdin);
    scanf("%s", &add.father_first_name);

    printf("Enter Father's Last name : ");
    fflush(stdin);
    scanf("%s", &add.father_last_name);

    printf("Enter your age : ");
    fflush(stdin);
    scanf("%d", &add.age);

    printf("Enter Date of birth (dd/mm/yyyy) : ");
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);

    printf("Enter Phone Number : ");
    fflush(stdin);
    scanf("%s", &add.p_number);

    printf("Enter Nationality : ");
    fflush(stdin);
    scanf("%s", &add.Nationality);

    printf("Enter House Number : ");
    fflush(stdin);
    scanf("%s", &add.h_no);

    printf("Enter Street Name (use '-' instead of spaces) : ");
    fflush(stdin);
    scanf("%s", &add.st_name);

    printf("Enter Area (use '-' instead of spaces) : ");
    fflush(stdin);
    scanf("%s", &add.area);

    printf("Enter City Name : ");
    fflush(stdin);
    scanf("%s", &add.city);

    printf("Enter Account Type:\nPress S for Savings, \nPress C for Current, \nF for Fixed : ");
    fflush(stdin);
    scanf("%c",&add.account_type);

    while(flag!=1)
    {
        if (add.account_type=='S'|| add.account_type=='s'||add.account_type=='C'||add.account_type=='c'||add.account_type=='F'||add.account_type=='f')
        {
            flag=1;
        }
        else
        {
            printf("\nWrong Input. Input Again : ");
            fflush(stdin);
            scanf("%c", &add.account_type);
            flag=0;
        }
    }

    printf("Deposit Amount : ");
    fflush(stdin);
    scanf("%d", &add.amount);

    fprintf(fp, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c \n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
    printf("\nAccount Created Successfully!!\n");
    fclose(fp);

    callback();
}

//ALLOWS USER TO UPDATE PHONE NUMBER AND ADDRESS IN RECORDS
void update_info()
{
    printf("========================================================================================\n");
    printf("\t\t\t\tUPDATE RECORD\n");
    printf("========================================================================================\n\n\n");
    int choice, check=0;
    FILE *old, *upd;
    old=fopen("DataFile.txt", "r");
    upd=fopen("new.txt", "w");
    printf("Enter account number : ");
    scanf("%ld", &update.account_number);
    while(fscanf(old, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c", &add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, &add.p_number, &add.age, &add.dob.day, &add.dob.month, &add.dob.year, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year, &add.account_type)!=EOF)
    {
        if(add.account_number==update.account_number)
        {
           check++;

           printf("What do you want to change?\n\n1. Address\n2. Phone Number\n3. Return to Main Menu\n\nEnter you choice : ");
           scanf("%d", &choice);
           system("cls");

            switch(choice)
            {
                case 1 :
                {
                    printf("========================================================================================\n");
                    printf("\t\t\t\tUPDATE ADDRESS\n");
                    printf("========================================================================================\n\n\n");printf("Enter House Number : ");
                    fflush(stdin);
                    scanf("%s", &update.h_no);

                    printf("Enter Street Name (use '-' instead of spaces) : ");
                    fflush(stdin);
                    scanf("%s", &update.st_name);

                    printf("Enter Area (use '-' instead of spaces) : ");
                    fflush(stdin);
                    scanf("%s", &update.area);

                    fprintf(upd, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c \n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, update.h_no, update.st_name, update.area, add.city, add.Nationality, add.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
                    system("cls");
                    printf("Changes Saved!!\n");
                }
                break;

                case 2 :
                {
                    printf("========================================================================================\n");
                    printf("\t\t\tUPDATE PHONE NUMBER\n");
                    printf("========================================================================================\n\n\n");
                    printf("Enter Phone Number : ");
                    fflush(stdin);
                    scanf("%s", &update.p_number);

                    fprintf(upd, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c \n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, update.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
                    system("cls");
                    printf("Changes Saved!!\n");
                }
                break;

                case 3:
                    {
                        system("cls");
                        main();
                    }
                break;

                default:
                    {
                        printf("Wrong input\n");
                        update_info();
                    }
            }
        }

        else
            {
           fprintf(upd, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c \n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
            }
    }
    fclose(old);
    fclose(upd);
    remove("DataFile.txt");
    rename("New.txt", "DataFile.txt");

    if(check==0)
        printf("\nRecord not found!!!\n");
    callback();
}

//TRANSACTION FUNCTION FOR USER MONETARY TRANSACTIONS
void transaction()
{
    printf("========================================================================================\n");
    printf("\t\t\t\tTRANSACTIONS\n");
    printf("========================================================================================\n\n\n");
    FILE *old, *tr;
    int choice, check=0;
    old=fopen("DataFile.txt", "r");
    tr=fopen("new.txt", "w");
    printf("Enter Account Number : ");
    scanf("%ld", &transact.account_number);
    while(fscanf(old, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c", &add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, &add.age, &add.dob.day, &add.dob.month, &add.dob.year, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year, &add.account_type)!=EOF)
    {
        if(add.account_number==transact.account_number)
        {
            check++;
                if(add.account_type=='f'||add.account_type=='F')
                {
                    printf("Error!! Deposit or Withdraw in fixed accounts is not allowed!");
                    Sleep(5000);
                    system("cls");
                    main();
                }

                else
                {
                    while(1)
                    {
                        system("cls");
                        printf("========================================================================================\n");
                        printf("\t\t\tTRANSACTION MENU\n");
                        printf("========================================================================================\n\n\n");
                        printf("[1] Deposit\n");
                        printf("[2] Withdraw\n");
                        printf("[3] Check Available Balance\n");
                        printf("[4] Return to Main Menu\n");
                        printf("\nEnter choice : ");

                        scanf("%d", &choice);
                        switch(choice)
                        {
                            case 1:
                            {
                                system("cls");
                                printf("========================================================================================\n");
                                printf("\t\t\t\tDEPOSIT\n");
                                printf("========================================================================================\n\n\n");
                                printf("Enter the amount to deposit : ");
                                scanf("%d", &transact.amount);
                                Sleep(5000);
                                add.amount=add.amount+transact.amount;
                                fprintf(tr,"%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c\n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
                                printf("\nAmount Deposit Successfully!!");
                                printf("\nAvailable Balance : %d\n", add.amount);
                                Sleep(3000);
                                break;
                            }

                            case 2:
                            {
                                system("cls");
                                printf("========================================================================================\n");
                                printf("\t\t\t\tWITHDRAW\n");
                                printf("========================================================================================\n\n\n");
                                printf("\nEnter the amount to withdraw : ");
                                scanf("%d", &transact.amount);
                                Sleep(5000);
                                if(add.amount<=0)
                                    printf("\nError: Amount cannot be withdrawn.\nAvailable Balance : %d\n", add.amount);
                                else
                                {
                                    add.amount=add.amount-transact.amount;
                                    fprintf(tr,"%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c\n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
                                    printf("\nAmount Withdrawn Successfully!!");
                                    printf("\nAvailable Balance : %d\n", add.amount);
                                }
                                Sleep(3000);
                                break;
                            }

                            case 3:
                            {
                                system("cls");
                                printf("========================================================================================\n");
                                printf("\t\t\tAVAILABLE BALANCE\n");
                                printf("========================================================================================\n\n\n");
                                printf("\nAvailable Balance : %d\n", add.amount);
                                Sleep(3000);
                                break;
                            }

                            case 4:
                            {
                                system("cls");
                                fclose(old);
                                fclose(tr);
                                remove("DataFile.txt");
                                rename("new.txt", "DataFile.txt");
                                main();
                                break;
                            }

                            default:
                                printf("Wrong input!!!\n");
                        }
                    }//while
                }//else end
            }
        else
            fprintf(tr, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c\n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
        }//while end
        fclose(old);
        fclose(tr);
        remove("DataFile.txt");
        rename("new.txt", "DataFile.txt");
        if(check!=1)
            printf("No Record Found!!\n");
        callback();
}

//ALL DETAILS OF A RECORDS INCLUDING THE INTEREST THAT WILL BE PROVIDED
void customer_details()
 {
    printf("========================================================================================\n");
    printf("\t\t\tCUSTOMER DETAILS\n");
    printf("========================================================================================\n\n\n");
    FILE *ptr;
    int rate,check=0;
    float intrst, time;
    ptr=fopen("DataFile.txt", "r");
    printf("Enter the account number to check the details : ");
    scanf("%ld", &details.account_number);
    while(fscanf(ptr, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c", &add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, &add.p_number, &add.age, &add.dob.day, &add.dob.month, &add.dob.year, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year, &add.account_type)!=EOF)
    {
        if(add.account_number==details.account_number)
        {
            system("cls");
            check=1;
            printf("========================================================================================\n");
            printf("\t\t\tCUSTOMER DETAILS\n");
            printf("========================================================================================\n\n\n");

            printf("Account number : %ld \nName : %s %s \nFather's Name : %s %s \nDate of Birth : %d/%d/%d \nAge : %d \nAddress : %s %s %s \nCity : %s \nNationality : %s \nPhone Number : %s \nAvailable Balance : %d", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.dob.day, add.dob.month, add.dob.year, add.age, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, add.amount);
            if (add.account_type=='S'||add.account_type=='s')
            {
                time=(1.0f/12.0f);
                rate=8;
                intrst=interest(time, add.amount, rate);
                printf("\n\nYou will get Rs.%.2f as interest on %d of every month", intrst, add.deposit.day);
            }

            else if (add.account_type=='F'||add.account_type=='f')
            {
                time=3.0f;
                rate=13;
                intrst=interest(time, add.amount, rate);
                printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d", intrst, add.deposit.day, add.deposit.month, add.deposit.year+3);
            }

            else if (add.account_type=='C'||add.account_type=='c')
            {
                printf("\n\nYou will get no interest");
            }
        }
    }
    fclose(ptr);
    if(check==0)
        printf("Record not found!!");
    callback();
}

//ALLOWS THE USER TO REMOVE A CUSTOMER'S RECORD
void remove_user()
{
    printf("========================================================================================\n");
    printf("\t\t\tREMOVE EXISITING RECORD\n");
    printf("========================================================================================\n\n\n");
    int check=0;
    FILE *old, *rem;
    old=fopen("DataFile.txt", "r");
    rem=fopen("del.txt", "w");
    printf("Enter account number to remove account from records: ");
    scanf("%ld", &del.account_number);
    while(fscanf(old, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c", &add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, &add.p_number, &add.age, &add.dob.day, &add.dob.month, &add.dob.year, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year, &add.account_type)!=EOF)
    {
        if(add.account_number!=del.account_number)
        {
            fprintf(rem, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d  %d %d/%d/%d %c \n", add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, add.p_number, add.age, add.dob.day, add.dob.month, add.dob.year, add.amount, add.deposit.day, add.deposit.month, add.deposit.year, add.account_type);
        }

        else
        {
            check++;
            remove("DataFile.txt");
            rename("del.txt", "DataFile.txt");
            printf("Account removed successfully!!\n");
        }
    }
    fclose(old);
    fclose(rem);
    remove("DataFile.txt");
    rename("del.txt", "DataFile.txt");

    if(check==0)
        printf("Record not found!\n");
    callback();
}

//SHOWS ALL THE CUSTOMER ENROLLED IN THE RECORDS
void customer_list()
{
    char ch;
    FILE *view;
    view=fopen("DataFile.txt", "r");
    int check=0;
    printf("==================================================================================\n");
    printf("ACCOUNT NO.\t\t NAME\t\t\t P.NO.\t\t\t ADDRESS\n");
    printf("==================================================================================\n");
    while(fscanf(view, "%ld %s %s %s %s %s %s %s %s %s %s %d %d/%d/%d %d %d/%d/%d %c", &add.account_number, add.customer_first_name, add.customer_last_name, add.father_first_name, add.father_last_name, add.h_no, add.st_name, add.area, add.city, add.Nationality, &add.p_number, &add.age, &add.dob.day, &add.dob.month, &add.dob.year, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year, &add.account_type)!=EOF)
    {
        printf("%ld\t\t %s %s\t\t %s\t\t %s %s %s\n", add.account_number, add.customer_first_name, add.customer_last_name, add.p_number, add.h_no, add.st_name, add.area);
        check++;
    }
    fclose(view);
    if(check==0)
        printf("NO RECORDS FOUND!!\n");
    callback();
}

//USED IN ALMOST EVERY FUNCTION TO BRING BACK TO MAIN MENU
void callback()
{
    char ch;
    while(1)
    {
        printf("\nReturn to Main Menu? Y/N : ");
        fflush(stdin);
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

//MAIN FUNCTION
int main()
{
    int choice;
    choice=menu();
    switch(choice)
    {
        case 1:
            {
                system("cls");
                new_customer();
                break;
            }
        case 2 :
            {
                system("cls");
                update_info();
                break;
            }
        case 3:
            {
                system("cls");
                transaction();
                break;
            }

        case 4 :
            {
                system("cls");
                customer_details();
                break;
            }
        case 5:
            {
                system("cls");
                remove_user();
                break;
            }
        case 6:
            {
                system("cls");
                customer_list();
                break;
            }

        case 7 :
            {
                system("cls");
                printf("Thank You for using our services!!");
                exit(0);
            }
        default:
            {
                printf("Wrong Input!!\n");
                Sleep(3000);
                system("cls");
                menu();
            }
    }
    getch();
    return 0;
}

#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include "E:\Projects\C Language\Bank-Management-System\File Containing Functions.c"

int menu(void);
int gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


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

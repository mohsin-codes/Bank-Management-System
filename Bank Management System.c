#include<windows.h>
#include<stdio.h>
int gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void menu()
{
    int i, a;
    gotoxy(40,0);
    printf("BANK MANAGEMENT SYSTEM\n");

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
    printf("[7] ATM feature");
    gotoxy(40, 12);
    printf("[8] Exit\n");

    gotoxy(40, 15);
    printf("Enter your choice : ");
    scanf("%d", &a);
}

int main()
{
    menu();
    getch();
    return 0;
}

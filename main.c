#include <stdio.h>
#include "list.h"
#include <conio.h>
#include <windows.h>
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
void main()
{
    int choice;
    List l;
    createList(&l);
     printf(""CYN);
    do
    {
        system("cls");
        MainDes();
        printf("All Rights Reserved 2024 @Omar & @Hassan \n\n"RED"please enter choice \n");
        printf("\e[0;32m1-Insert Node  \n\e[0;36m2-Search Node \n\e[0;31m3-Delete Node\n\e[0;34m4-List size \n\e[0;32m5-Print List \n\e[0;31m6-Destroy list \n\e[0;36m7-Sort \n\e[0;32m8-Edit \n\e[0;36m9-Rank \n\e[0;31m10-average \n\e[0m11-EXIT \n\e"MAG"->");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case INSERT:
            insert_Node(&l);
            break;
        case SEARCH:
            search_Node(&l);
             break;
        case 3:
            delete_Node(&l);

             break;
        case SIZE1:
            printf("list size =  %d\n", ListSize(&l));
            while (!getch());
            system("cls");
            break;
        case PRINT:
            print_List(&l);

            break;
        case SORT:

            sort(&l);
            break;
        case EDIT:
            Edit(&l);

            break;
        case RANK:
            rank(&l);
                        break;
        case DESTROY:
            DestroyList(&l);
             break;
        case AVERAGE:
            calcav(&l);
            break;
        default:
            if (choice == EXIT)
            {
            int x= MessageBoxA( NULL, "This Project is Made by Omar Adel & Hassan Mohamed\nHope it likes You,See You later <3", "All Rights Reserved \xA9 2024 @Omar & @Hassan", MB_ICONASTERISK | MB_OK );
            while (x==!IDOK);
            system("cls");
                return;
            }
            system("cls");
            int x= MessageBoxA( NULL, "Wrong Input!", "Error Message", MB_ICONSTOP | MB_OK );
            while (x==!IDOK);
            system("cls");
            break;
        }
        choice = -1;
    } while (choice != EXIT);
}

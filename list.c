#include <stdio.h>
#include "list.h"
#include "config.h"
#include <string.h>
#include <conio.h>
#include<windows.h>
void createList(List *pl)
{
    pl->pHead = NULL;
    pl->pTail = NULL;
    pl->ListSize = 0;
}

void insert_Node(List *pl)
{

    system("cls");
    ListNode *pn = malloc(sizeof(ListNode));
    ListNode *temp = pl->pHead;

    if (pn == NULL)
    {
        printf("Heap is full \n");
        return;
    }
    printf("please enter data \n");
    printf("enter id \n");
    scanf("%d", &pn->data.id);
    fflush(stdin);
    while (temp != NULL && temp->data.id != pn->data.id)
    {
        temp = temp->pNext;
    }
    while (temp != NULL && temp->data.id == pn->data.id)
    {
          int y= MessageBoxA( NULL, "ID is Alreay exist!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        printf("please enter id :");
        scanf("%d", &pn->data.id);
        fflush(stdin);
        temp = pl->pHead;
        while (temp != NULL && temp->data.id != pn->data.id)
        {
            temp = temp->pNext;
        }
    }
    printf("enter Name\n");
    gets(pn->data.name);
    fflush(stdin);
    printf("enter Math score\n");
    scanf("%d", &pn->data.math);
    fflush(stdin);
    while(pn->data.math > 50 || pn->data.math < 0)
    {
        printf("please enter valid degree \n");
        printf("math:");
        scanf("%d",&pn->data.math);
        fflush(stdin);
    }
    printf("enter English score\n");
    scanf("%d", &pn->data.english);
    fflush(stdin);
    while(pn->data.english > 50 ||pn->data.english < 0)
    {
        printf("please enter valid degree \n");
        printf("english:");
        scanf("%d",&pn->data.english);
        fflush(stdin);
    }
    printf("enter Arabic score\n");
    scanf("%d", &pn->data.arabic);
    fflush(stdin);
    while(pn->data.arabic > 50 ||pn->data.arabic < 0)
    {
        printf("please enter valid degree \n");
        printf("arabic:");
        scanf("%d",&pn->data.arabic);
        fflush(stdin);
    }
    printf("enter computer Science\n");
    scanf("%d", &pn->data.computerScience);
    fflush(stdin);
    while(pn->data.computerScience > 50 || pn->data.computerScience < 0)
    {
        printf("please enter valid degree \n");
        printf("computer Science:");
        scanf("%d",&pn->data.computerScience);
        fflush(stdin);
    }
    pn->data.total = pn->data.arabic + pn->data.computerScience + pn->data.english + pn->data.math;
    pn->pNext = NULL;
    pn->pPrev = NULL;
    if (pl->pHead == NULL) // list is empty
    {
        pl->pHead = pn;
        pl->pTail = pn;
    }

    else
    {

        ListNode *temp = pl->pHead;
        while (temp != NULL && temp->data.id < pn->data.id)
        {
            temp = temp->pNext;
        }
        if (temp == NULL)
        {
            pl->pTail->pNext = pn;
            pn->pPrev = pl->pTail;
            pl->pTail = pn;
        }
        else if (temp == pl->pHead)
        {
            pl->pHead->pPrev = pn;
            pn->pNext = pl->pHead;
            pl->pHead = pn;
        }
        else
        {
            pn->pNext = temp;
            pn->pPrev = temp->pPrev;
            temp->pPrev->pNext = pn;
            temp->pPrev = pn;
        }
    }
    printf(" \n the insert is done \n");
    pl->ListSize++;
    while (!getch())
        ;
    system("cls");
}

void delete_Node(List *pl)
{

    system("cls");
    if (pl->pHead == NULL)
    {
        int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
    }
    else
    {
        int e;
        printf("please enter id \n");
        scanf("%d", &e);

        ListNode *temp = pl->pHead;
        if (pl->pHead == NULL)
        {
        int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
            return;
        }
        while (temp != NULL && temp->data.id != e)
        {
            temp = temp->pNext;
        }
        if (temp == NULL)
        {
  int y= MessageBoxA( NULL, "ID does not exist!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
            return;
        }
        else if (pl->pHead == pl->pTail)
        {

            pl->pHead = NULL;
            pl->pTail = NULL;
            free(temp);
            printf(" \n the delete is done \n");
            while (!getch())
                ;
            system("cls");
        }
        else if (temp == pl->pHead)
        {
            pl->pHead->pNext->pPrev = NULL;
            pl->pHead = pl->pHead->pNext;
            free(temp);
            printf(" \n the delete is done \n");
            while (!getch())
                ;
            system("cls");
        }
        else if (temp == pl->pTail)
        {
            pl->pTail->pPrev->pNext = NULL;
            pl->pTail = pl->pTail->pPrev;
            free(temp);
            printf(" \n the delete is done \n");
            while (!getch())
                ;
            system("cls");
        }
        else
        {
            temp->pNext->pPrev = temp->pPrev;
            temp->pPrev->pNext = temp->pNext;
            free(temp);
            printf(" \n the delete is done \n");
            while (!getch())
                ;
            system("cls");
        }
        pl->ListSize--;
        // printf("\n id is deleted : %d \n", temp->id);
    }
}
void Edit(List *pl)
{

    system("cls");
    int choiceName;
    int e;
    int tempId;
    printf("please enter id \n");
    scanf("%d", &e);
        fflush(stdin);
    ListNode *temp = pl->pHead;
    if (pl->pHead == NULL)
    {
        int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        return;
    }
    while (temp != NULL && temp->data.id != e)
    {
        temp = temp->pNext;
    }
    if (temp == NULL)
    {
  int y= MessageBoxA( NULL, "ID does not exist!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        return;
    }
    printf("enter your choice \n 1- Id  \n 2- Name  \n 3- Math score \n 4- Arabic score \n 5- English score \n 6- computer Since score \n 7-All \n");
    scanf("%d", &choiceName);
    fflush(stdin);
    switch (choiceName)
    {
    case 1:
        printf("enter new id :");
        scanf("%d", &temp->data.id);
        // tempId =temp->data.id;
        fflush(stdin);
       // while (temp != NULL && temp->data.id != tempId)
        //{
         //   temp = temp->pNext;
        //}
        //while (temp != NULL && temp->data.id == tempId)
        //{
          //  printf("\n this id already exists \n please enter id :");
           // scanf("%d", &temp->data.id);
           // fflush(stdin);
            //temp = pl->pHead;
           // while (temp != NULL && temp->data.id != tempId)
            //{
              //  temp = temp->pNext;
            //}
        //}
        break;
    case 2:
        printf("enter new Name :");
        gets( &temp->data.name);
        fflush(stdin);
        break;
    case 3:
        printf("enter new Math score :");
        scanf("%d", &temp->data.math);
        fflush(stdin);
        while(temp->data.math > 50 || temp->data.math < 0)
        {
            printf("please enter valid degree \n");
            printf("math:");
            scanf("%d",&temp->data.math);
            fflush(stdin);
        }
        break;
    case 4:
        printf("enter new Arabic score :");
        scanf("%d", &temp->data.arabic);
        fflush(stdin);
        while(temp->data.arabic > 50 || temp->data.arabic < 0)
        {
            printf("please enter valid degree \n");
            printf("arabic:");
            scanf("%d",&temp->data.arabic);
            fflush(stdin);
        }
        break;
    case 5:
        printf("enter new English score :");
        scanf("%d", &temp->data.english);
        fflush(stdin);
        while(temp->data.english > 50 || temp->data.english < 0)
        {
            printf("please enter valid degree \n");
            printf("english:");
            scanf("%d",&temp->data.english);
            fflush(stdin);
        }
        break;
    case 6:
        printf("enter new computer Science score :");
        scanf("%d", &temp->data.computerScience);
        fflush(stdin);
        while(temp->data.computerScience > 50 || temp->data.computerScience < 0)
        {
            printf("please enter valid degree \n");
            printf("computer Science:");
            scanf("%d",&temp->data.computerScience);
            fflush(stdin);
        }
        break;
    case 7:
        printf("enter new id :");
        scanf("%d", &temp->data.id);
        tempId = temp->data.id;
        fflush(stdin);
        printf("enter new Name :");
        gets(&temp->data.name);
        fflush(stdin);

        printf("enter new Math score :");
        scanf("%d", &temp->data.math);
        fflush(stdin);
        while(temp->data.math > 50 || temp->data.math < 0)
        {
            printf("please enter valid degree \n");
            printf("math:");
            scanf("%d",&temp->data.math);
            fflush(stdin);
        }
        printf("enter new Arabic score :");
        scanf("%d", &temp->data.arabic);
        fflush(stdin);
        while(temp->data.arabic > 50 || temp->data.arabic < 0)
        {
            printf("please enter valid degree \n");
            printf("math:");
            scanf("%d",&temp->data.arabic);
            fflush(stdin);
        }
        printf("enter new English score :");
        scanf("%d", &temp->data.english);
        fflush(stdin);
        while(temp->data.english > 50 || temp->data.english < 0)
        {
            printf("please enter valid degree \n");
            printf("math:");
            scanf("%d",&temp->data.english);
            fflush(stdin);
        }
        printf("enter new computer Science score :");
        scanf("%d", &temp->data.computerScience);
        fflush(stdin);
        while(temp->data.computerScience > 50 || temp->data.computerScience < 0)
        {
            printf("please enter valid degree \n");
            printf("math:");
            scanf("%d",&temp->data.computerScience);
            fflush(stdin);
        }
        break;
    default:
        printf("wrong choice");
        break;
    }
    temp->data.total = temp->data.total = temp->data.arabic + temp->data.computerScience + temp->data.english + temp->data.math;
    printf("\n the edit is done  \n");
    while (!getch())
        ;
    system("cls");
}

void search_Node(List *pl)
{

    system("cls");
    int e;

    printf("please enter id \n");
    scanf("%d", &e);
    /////////
    ListNode *temp = pl->pHead;
    if (pl->pHead == NULL)
    {
         int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        return;
    }
    while (temp != NULL && temp->data.id != e)
    {
        temp = temp->pNext;
    }
    /////////////
    /////////////
    if (temp == NULL)
    {
  int y= MessageBoxA( NULL, "ID does not exist!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
    }
    else
    {
        printf("found\n");
        printf(" your id :%d ", temp->data.id);
        printf("\n your name :");
        puts(temp->data.name);
        printf(" your math score :%d ", temp->data.math);
        printf("\n your arabic score :%d ", temp->data.arabic);
        printf("\n your english score: %d ", temp->data.english);
        printf("\n your computer Since: %d ", temp->data.computerScience);
    }
    printf("\n the search is done \n ");
    while (!getch())
        ;
    system("cls");
}

void print_List(List *pl)
{

    system("cls");
    if (pl->pHead == NULL)
    {
        int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        return;
    }
    ListNode *temp;
    for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
    {
        //      printf("\n data  = %d \n",temp->data);
        //       printf("please enter data \n");
        printf("id: ");
        printf("%d", temp->data.id);

        printf("\n Name: ");
        puts(temp->data.name);

        printf("Math score: ");
        printf("%d", temp->data.math);

        printf("\n English score: ");
        printf("%d", temp->data.english);

        printf("\n Arabic score: ");
        printf("%d", temp->data.arabic);

        printf("\n computer Sincec score: ");
        printf("%d", temp->data.computerScience);
        printf("\n total number: ");
        printf("%d", temp->data.total);
        printf("\n -------------------------------------------------------- \n ");
    }
    while (!getch())
        ;
    system("cls");
}
unsigned int ListSize(List *pl)
{
    return pl->ListSize;
}
void DestroyList(List *pl)
{

    system("cls");
    if (pl->pHead == NULL)
    {
        int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        return;
    }
      int y= MessageBoxA( NULL, "Are you Sure that you want to Destroy List?", " Sure?", MB_ICONEXCLAMATION | MB_YESNO );
      if(y==IDNO)return;
    ListNode *temp;
    while (pl->pHead != NULL)
    {
        temp = pl->pHead->pNext;
        free(pl->pHead);
        pl->pHead = temp;
    }
    pl->pTail = NULL;
    pl->ListSize = 0;
    printf(" List is destroyed \n");
    while (!getch())
        ;
    system("cls");
}

void sort(List *pl)
{

    system("cls");
    int choice_data;
    int choice_ascending_descending;
    ListNode *temp, *tempn;
    stud swap;

    if (pl->pHead == NULL)
    {
        int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        return;
    }

    printf("enter your choice \n 1-sort by Id \n 2-sort by Name \n 3-sort by Total \n 4-sort by Math score \n 5-sort by Arabic score \n 6-sort by English score \n 7-sort by Computer science score \n");
    scanf("%d", &choice_data);
    printf("1-ascending \n2- descending \n");
    scanf("%d", &choice_ascending_descending);
    if (choice_ascending_descending == 1)
    {
        switch (choice_data)
        {
        case 1:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.id > tempn->data.id)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("sort is done \n");
            while (!getch())
                ;
            system("cls");
            break;
        case 2:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (strcmp(temp->data.name, tempn->data.name) == 1)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 3:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.total > tempn->data.total)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 4:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.math > tempn->data.math)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 5:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.arabic > tempn->data.arabic)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 6:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.english > tempn->data.english)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 7:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.computerScience > tempn->data.computerScience)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        default:
            printf("wrong choice ");
            while (!getch())
                ;
            system("cls");
            break;
            break;
        }
    }
    /////////////////////////////////////
    if (choice_ascending_descending == 2)
    {

        switch (choice_data)
        {
        case 1:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.id < tempn->data.id)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("sort is done \n");
            while (!getch())
                ;
            system("cls");
            break;
        case 2:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (strcmp(temp->data.name, tempn->data.name) == -1)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 3:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.total < tempn->data.total)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 4:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.math < tempn->data.math)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 5:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.arabic < tempn->data.arabic)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 6:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.english < tempn->data.english)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        case 7:
            for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
                {
                    if (temp->data.computerScience < tempn->data.computerScience)
                    {
                        swap = temp->data;
                        temp->data = tempn->data;
                        tempn->data = swap;
                    }
                }
            }
            printf("\n sort is done");
            while (!getch())
                ;
            system("cls");
            break;
        default:
            printf("wrong choice ");
            while (!getch())
                ;
            system("cls");
            break;
            break;
        }
    }
}
void rank(List *pl)
{
    ListNode *temp, *tempn;
    stud swap;
    int index = 0;
    for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
    {
        for (tempn = temp->pNext; tempn != NULL; tempn = tempn->pNext)
        {
            if (temp->data.total < tempn->data.total)
            {
                swap = temp->data;
                temp->data = tempn->data;
                tempn->data = swap;
            }
        }
    }
    for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
    {
        index++;
        printf("id rank %d :%d \n", index, temp->data.id);
        printf(" Name rank %d : ", index);
        puts(temp->data.name);
        printf("total score rank %d : %d  \n", index, temp->data.total);
    }
    while (!getch())
        ;
    system("cls");
}
void calcav(List *pl)
{
    system("cls");
    int choice;
    printf("enter your choice \n 1-search student for calculate her Average \n 2- Average for all students ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        system("cls");
        int e;

        printf("please enter id \n");
        scanf("%d", &e);
        /////////
        ListNode *temp = pl->pHead;
        if (pl->pHead == NULL)
        {
        int y= MessageBoxA( NULL, "List is empty!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
            return;
        }
        while (temp != NULL && temp->data.id != e)
        {
            temp = temp->pNext;
        }
        /////////////
        /////////////
        if (temp == NULL)
        {
  int y= MessageBoxA( NULL, "ID does not exist!", "Error Message", MB_ICONEXCLAMATION | MB_OK );
        while (y==!IDOK);
        system("cls");
        return;
        }
        int average = (temp->data.math + temp->data.arabic + temp->data.english + temp->data.computerScience) / 4;
        printf("average: %d", average);
        while (!getch())
            ;
        system("cls");
    }

    if (choice == 2)
    {
        int average;

        ListNode *temp;
        int index = 0;
        for (temp = pl->pHead; temp != NULL; temp = temp->pNext)
        {
            index++;
            printf("id average %d :%d \n", index, temp->data.id);
            printf("name:");
            puts(temp->data.name);
            average = (temp->data.math + temp->data.arabic + temp->data.english + temp->data.computerScience) / 4;
            printf("average : %d \n", average);
        }
        while (!getch())
            ;
        system("cls");
    }
}

void MainDes()
{
    printf("                _[]_     \n");
    printf(" __[]___[]___[]/____\\_[]_    \n");
    printf("/______________|[][]|____\\  \n");
    printf("|[][]|[][]|[][]|[][]|[][]|__[]_ \n");
    printf("|  /\\|/\\  |  /\\|  /\\|/\\  |_____\\ \n");
    printf("|[]|||||[]|[]|||[]|||||[]|[_]|||");
    printf(" =======\n");
    printf("  -  -  -  -  -  -  -  -  -  -  -  -  - \n");
    printf("======================================= \n");
}

void SearchDes()
{
    printf("\n");
    printf(" ,---.                              ,--.          ,---.   ,--.             ,--.                 ,--. \n");
    printf("'   .-'  ,---.  ,--,--.,--.--. ,---.|  ,---.     '   .-',-'  '-.,--.,--. ,-|  | ,---. ,--,--, ,-'  '-. \n");
    printf("`.  `-. | .-. :' ,-.  ||  .--'| .--'|  .-.  |    `.  `-.'-.  .-'|  ||  |' .-. || .-. :|      \'-.  .-' \n");
    printf(".-'    |\\   --.\\ '-'  ||  |   \\ `--.|  | |  |    .-'    | |  |  '  ''  '\\ `-' |\\   --.|  ||  |  |  | \n");
    printf("`-----'  `----' `--`--'`--'    `---'`--' `--'    `-----'  `--'   `----'  `---'  `----'`--''--'  `--' \n");
}

void DeleteDes()
{
    printf(",------.         ,--.         ,--.              ,---.   ,--.             ,--.                 ,--. \n");
    printf("|  .-.  \\  ,---. |  | ,---. ,-'  '-. ,---.     '   .-',-'  '-.,--.,--. ,-|  | ,---. ,--,--, ,-'  '-. \n");
    printf("|  |  \\  :| .-. :|  || .-. :'-.  .-'| .-. :    `.  `-.'-.  .-'|  ||  |' .-. || .-. :|      \'-.  .-' \n");
    printf("|  '--'  /\\   --.|  |\\   --.  |  |  \\   --.    .-'    | |  |  '  ''  '\\ `-' |\\   --.|  ||  |  |  | \n");
    printf("`-------'  `----'`--' `----'  `--'   `----'    `-----'  `--'   `----'  `---'  `----'`--''--'  `--' \n");
}

void DeleteAllDes()
{
    printf(" ,------.         ,--.         ,--.               ,---.  ,--.,--. \n");
    printf(" |  .-.  \\  ,---. |  | ,---. ,-'  '-. ,---.      /  O  \\ |  ||  |\n");
    printf(" |  |  \\  :| .-. :|  || .-. :'-.  .-'| .-. :    |  .-.  ||  ||  |\n");
    printf(" |  '--'  /\\   --.|  |\\   --.  |  |  \\   --.    |  | |  ||  ||  |  \n");
    printf(" `-------'  `----'`--' `----'  `--'   `----'    `--' `--'`--'`--' \n");
}

void PrintDes()
{
    printf(",------.        ,--.          ,--.       ,---.   ,--.             ,--.                 ,--.          \n");
    printf("|  .--. ',--.--.`--',--,--, ,-'  '-.    '   .-',-'  '-.,--.,--. ,-|  | ,---. ,--,--, ,-'  '-. ,---. \n");
    printf("|  '--' ||  .--',--.|      \'-.  .-'    `.  `-.'-.  .-'|  ||  |' .-. || .-. :|      \'-.  .-'(  .-'\n");
    printf("|  | --' |  |   |  ||  ||  |  |  |      .-'    | |  |  '  ''  '\\ `-' |\\   --.|  ||  |  |  |  .-'  `) \n");
    printf("`--'     `--'   `--'`--''--'  `--'      `-----'  `--'   `----'  `---'  `----'`--''--'  `--'  `----'  \n");
}

void EditDes()
{
    printf(",------.   ,--.,--.  ,--.       ,---.   ,--.             ,--.                 ,--.   \n");
    printf("|  .---' ,-|  |`--',-'  '-.    '   .-',-'  '-.,--.,--. ,-|  | ,---. ,--,--, ,-'  '-.  \n");
    printf("|  `--, ' .-. |,--.'-.  .-'    `.  `-.'-.  .-'|  ||  |' .-. || .-. :|      \'-.  .-'  \n");
    printf("|  `---.\\ `-' ||  |  |  |      .-'    | |  |  '  ''  '\\ `-' |\\   --.|  ||  |  |  | \n");
    printf("`------' `---' `--'  `--'      `-----'  `--'   `----'  `---'  `----'`--''--'  `--'  \n");
}

void RankDes()
{
    printf(" ,---.  ,--.                           ,------.                 ,--.     \n");
    printf("'   .-' |  ,---.  ,---. ,--.   ,--.    |  .--. ' ,--,--.,--,--, |  |,-.  \n");
    printf("`.  `-. |  .-.  || .-. ||  |.'.|  |    |  '--'.'' ,-.  ||      \\|     / \n");
    printf(".-'    ||  | |  |' '-' '|   .'.   |    |  |\\  \\ \\ '-'  ||  ||  ||  \\  \\ \n");
    printf("`-----' `--' `--' `---' '--'   '--'    `--' '--' `--`--'`--''--'`--'`--'  \n");
}

void SortDes()
{
    printf(" ,---.  ,--.                            ,---.                  ,--.    \n");
    printf("'   .-' |  ,---.  ,---. ,--.   ,--.    '   .-'  ,---. ,--.--.,-'  '-. \n");
    printf("`.  `-. |  .-.  || .-. ||  |.'.|  |    `.  `-. | .-. ||  .--''-.  .-' \n");
    printf(".-'    ||  | |  |' '-' '|   .'.   |    .-'    |' '-' '|  |     |  | \n");
    printf("`-----' `--' `--' `---' '--'   '--'    `-----'  `---' `--'     `--'  \n");
}
void AvreageDes()
{
    printf("       ,--.                                                                    \n");
    printf(",---.  |  ,---.  ,---. ,--.   ,--.     ,--,--.,--.  ,--.,--.--. ,---.  ,--,--. ,---.  ,---. \n");
    printf("(  .-' |  .-.  || .-. ||  |.'.|  |    ' ,-.  | \\  `'  / |  .--'| .-. :' ,-.  || .-. || .-. : \n");
    printf(".-'  `)|  | |  |' '-' '|   .'.   |    \\ '-'  |  \\    /  |  |   \\   --.\\ '-'  |' '-' '\\   --. \n");
    printf("`----' `--' `--' `---' '--'   '--'     `--`--'   `--'   `--'    `----' `--`--'.`-  /  `----'\n");
    printf("                                                                              `---' \n");
}
void insertDes()
{
    printf(",--.                               ,--.       ,---.   ,--.             ,--.                 ,--.\n");
    printf("|  |,--,--,  ,---.  ,---. ,--.--.,-'  '-.    '   .-',-'  '-.,--.,--. ,-|  | ,---. ,--,--, ,-'  '-. \n");
    printf("|  ||      \\(  .-' | .-. :|  .--''-.  .-'    `.  `-.'-.  .-'|  ||  |' .-. || .-. :|      \\'-.  .-' \n");
    printf("|  ||  ||  |.-'  `)\\   --.|  |     |  |      .-'    | |  |  '  ''  '\\ `-' |\\   --.|  ||  |  |  | \n");
    printf("`--'`--''--'`----'  `----'`--'     `--'      `-----'  `--'   `----'  `---'  `----'`--''--'  `--'  \n");
}

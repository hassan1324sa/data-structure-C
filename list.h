#ifndef _LIST_H_
#define _LIST_H_

// typedef struct student
// {

// } stu;
// typedef stu ListEntry;
typedef enum cases
{
    INSERT = 1,
    SEARCH = 2,
    DELETE = 3,
    SIZE1 = 4,
    PRINT = 5,
    DESTROY = 6,
    SORT = 7,
    EDIT = 8,
    RANK = 9,
    AVERAGE = 10,
    EXIT = 11,

};
typedef struct student{
    int id;
    char name[30];
    int math;
    int english;
    int arabic;
    int computerScience;
    int total;
    }stud;
typedef struct myNode
{
    stud data;
    struct myNode *pNext;
    struct myNode *pPrev;
} ListNode;
typedef struct myList
{
    ListNode *pHead;
    ListNode *pTail;
    unsigned int ListSize;
} List;

// function prototypes
void createList(List *pl); // at tail only
void insert_Node(List *pl); // at any place
void delete_Node(List *pl);
void search_Node(List *pl);
void print_List(List *pl);
unsigned int ListSize(List *pl);
void DestroyList(List *pl);
void Edit(List *pl);
void sort(List *pl);
void rank(List *pl);
void calcav(List *pl);
void MainDes();
void SearchDes();
void DeleteDes();
void DeleteAllDes();
void PrintDes();
void EditDes();
void RankDes();
void SortDes();
void InsertDes();




#endif // _LIST_H_

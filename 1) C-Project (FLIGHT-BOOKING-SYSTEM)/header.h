#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
/*typedef struct C_Bussiness{
    char bussiness_seat[6][7];  //  6 refere to 6 seats in row
    int Flag_bussiness[];       //   and 7 referes to 8 column
    char Name_Bussiness[25];
}Bussiness_class;

typedef struct C_Economy{
    char Seat_Economy[8][8];    //  8 refere to 6 seats in row
    int Flag_Economy[];         //   and 8 referes to 8 column
    char Name_Economy[25];
}Economy_class;

typedef struct C_Smokers{
    char Seat_Smokers[6][8]; // 6 refere to 6 seats in row
    int Flag_Smokers[];       //  and 8 referes to 8 column
    char Name_Smokers[25];
}Smokers_class;

typedef struct CLASSES{
    Bussiness_class  Bussiness_class;
    Economy_class Economy_class;
    Smokers_class Smokers_class;
}CLASSES;*/

typedef struct Client{
    char Name[20];
    char Address[10];
    char Phone_Number[15];
    char Birth_Day[20];
    char Flight_Class;
    int ID;
    int Seat_Number;
}Client;

typedef struct StackNode{
    Client entry;
    struct StackNode *next;
    struct StackNode *prev;
}StackNode;

typedef struct Stack{
    StackNode *top;
    int Size;
}Stack;

void CreateStack (Stack *ps);
void push_doubly (Client *pe ,Stack *ps);
void Delete_doubly(StackNode *pn,Stack *ps);
void Main_Menu(void);
void New_Client(Client *pc,Stack *ps);
void Delete_Client(Client *client,Stack *ps);
void client_List(Stack *ps);
void Client_Edit(Stack *ps);
void Sort_alpha(Stack *ps);
void printfun(Stack *ps);


#endif // HEADER_H_INCLUDED

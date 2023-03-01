#include "header.h"
/* *************************************************************/
/*  CreateStack function to give the stack its initial values */
/*        takes POINTER top struct and return nothing        */
/* **********************************************************/
void CreateStack (Stack *ps)
{
    ps->top=NULL;
    ps->Size =0;
}

/* *******************************************************************/
/*               push_doubly TO PUSH DATA INTO HEAP                 */
/*takes pointer to Client(structure)and pointer to stack(structure)*/
/* ****************************************************************/
void push_doubly (Client *pe ,Stack *ps)
{
    StackNode *pn= (StackNode*) malloc(sizeof(StackNode));  // node creation in HEAP
    pn->entry=*pe;

    pn->prev=NULL;
    pn->next=ps->top;
    if(ps->top)
    {
    ps->top->prev=pn;
    }
    ps->top=pn;
    ps->Size++;
}

/* **********************************************************************/
/*               Delete_doubly TO delete DATA INTO HEAP                */
/*takes pointer to StackNode(structure)and pointer to stack(structure)*/
/* *******************************************************************/
void Delete_doubly(StackNode *pn,Stack *ps)
{
    if(pn->next != NULL && pn->prev == NULL)    /* 1) delete the first node from left (last stored)*/
    {
        ps->top=pn->next;
        pn->next->prev=NULL;
        free(pn);
    }
    else if(pn->next != NULL && pn->prev != NULL) /* 2) delete intermediate node */
    {
        pn->prev->next = pn->next;
        pn->next->prev = pn->prev;
        free(pn);

    }
    else if(pn->next == NULL && pn->prev != NULL) /* 3)delete the first node from right (first stored)*/
    {                                                     /* stack contains another nodes */
        pn->prev->next=NULL;
        ps->top=pn->prev;
        pn->prev=NULL;
        free(pn);
    }
    else if(pn->next == NULL && pn->prev == NULL)  /* 4)delete the last node in stack */
    {
        ps->top=NULL;
        free(pn);
    }
    ps->Size--;
    printf("\n==> Client Deleted Successfully\n");
}

/* ***********************************************************/
/*       Main_Menu TO show user the available choice        */
/*          takes nothing and return nothing               */
/* ********************************************************/
void Main_Menu(void)
{
    printf("\n\t\t**********************************************\n");
    printf("\t\t*****  Welcome To Flight Booking System  *****\n");
    printf("\t\t----------------------------------------------\n");
    printf("\t\t************* by: SHADY MAHROUS **************\n");
    printf("\t\t******* SUPERVISOR: DR. MOSTAFA SHIPLE *******\n");
    printf("\t\t**********************************************\n\n");
    printf("\t\tplease Enter Your choice: \n\n");
    printf("\t\t 1- New Client \n\n");
    printf("\t\t 2- Delete Client \n\n");
    printf("\t\t 3- Client List \n\n");
    printf("\t\t 4- Client Edit \n\n");
    printf("\t\t 5- Free Seats \n\n");
    printf("\t\t 6- Class List \n\n");
    printf("\t\t 7- Exit \n\n");
}

/* **********************************************************************************/
/* New_Client TO scan data of client from user then push it in HEAP by push_doubly */
/*takes pointer to Client(structure)and pointer to stack(structure) with no return*/
/* *******************************************************************************/
void New_Client(Client *client,Stack *ps)
{
    system("cls");                      /* to clear screen */
    printf("*******NEW CLIENT*******");
    fflush(stdin);                          /* to free puffer */
    printf("\nEnter Client Data:");
    printf("\n  Client Name: ");
    gets(client->Name);

    printf("\n  Client Birthday:");
    scanf("%s",client->Birth_Day);

    printf("\n  Client ID: ");
    scanf("%d",&client->ID);

    printf("\n  Client Address: ");
    scanf("%s",client->Address);

    printf("\n  Client Phone Number: ");
    scanf("%s",client->Phone_Number);
    fflush(stdin);

    printf("\n  Client Class(A-B-C)");
    printf("\n  A) Business Class");
    printf("\n  B) Economy Class");
    printf("\n  C) Smokers Class ");
    printf("\n  Your Class: ");
    scanf("%c",&client->Flight_Class);

    printf("\n  Client Seat:");
    //free seats()<==
    scanf("%d",&client->Seat_Number);
    push_doubly(client,ps);                     /*send client's data to push_doubly to be stored in HEAP */
    printf("==> Client Added Successfully");

}

/* **************************************************************************************/
/*     Delete_Client TO delete client data from  HEAP by Delete_doubly function        */
/*takes pointer to StackEntry(structure)and pointer to stack(structure) with no return*/
/* ***********************************************************************************/
void Delete_Client(Client *client,Stack *ps)
{
    if(ps->Size > 0)
    {
        int id,option;
        StackNode *pn;
        printf("\n*******DELETE CLIENT*******");
        printf("\n Enter Your ID: ");
        scanf("%d",&id);

        for(pn=ps->top ; pn !=NULL ; pn=pn->next)
            {
                if(pn->entry.ID == id)
                {
                    printf("\n Hi %s",pn->entry.Name);
                    printf("\nAre You sure You Want To Delete Reservation\n1) YES\n2) NO\n");
                    scanf("%d",&option);
                    if(option)
                    {
                        Delete_doubly(pn,ps);
                    }
                    else
                    {
                        break;
                    }

                }
                else{
                    printf("ERROR: YOU ENTERED WRONG ID");
                }
            }
    }
    else
        printf("ERROR: NO CLIENTS TO DELETE");
}

/* ****************************************************************************/
/*                Client_Edit TO EDIT client data in HEAP                    */
/*          takes pointer to stack(structure) with no return                */
/* *************************************************************************/
void Client_Edit(Stack *ps)
{
    if(ps->Size > 0)
    {
        int choice,id;
        StackNode *pn;
        printf("\n*******EDIT CLIENT*******");
        printf("\n Enter Your ID: ");
        scanf("%d",&id);
        for(pn=ps->top ; pn !=NULL ; pn=pn->next)
            {
              if(pn->entry.ID == id)
              {
                printf("\n Hi %s",pn->entry.Name);
                printf("\nplease choose which data u wanna edit\n 1-Name\n 2-ID\n 3-Address\n 4-Phone Number\n 5-Birthday\n 6-Class\n 7-Seat number\n");
                scanf("%d",&choice);
                    if(choice==1)          // choice 1 to NAME edit
                    {   fflush(stdin);
                        printf("\nEnter New Name:");
                        gets(pn->entry.Name);
                    }
                    else if(choice==2)         // choice 2 to ID edit
                    {
                        printf("\nEnter New ID:");
                        scanf("%d",&pn->entry.ID);
                    }
                    else if(choice==3)      // choice 3 to ADDRESS edit
                    {
                        printf("\nEnter New Address:");
                        scanf("%s",pn->entry.Address);
                    }
                    else if(choice==4)      // choice 4 to PHONE NUMBER edit
                    {
                        printf("\nEnter New Phone Number:");
                        scanf("%s",pn->entry.Phone_Number);
                    }
                    else if(choice==5)      // choice 5 to BIRTHDAY edit
                    {
                        printf("\nEnter New Birthday:");
                        scanf("%s",pn->entry.Birth_Day);
                    }
                    else if(choice==6)      // choice 6 to flight class edit
                    {
                        printf("\nEnter New Class:");
                        scanf("%c",&pn->entry.Flight_Class);
                    }
                    else if(choice==7)      // choice 7 to SEAT NUMBER edit
                    {
                        printf("\nEnter New Seat Number:");
                        scanf("%d",&pn->entry.Seat_Number);
                    }
                    else
                    {
                        printf("ERROE: YOU ENTERED WRONG VALUE");
                    }
                }
            }
        }
        else
            printf("ERROR: NO CLIENTS TO EDIT");
}

/* ****************************************************************************/
/*    client_List TO SORT client data ALPHAPETICALLY then print all          */
/*          takes pointer to stack(structure) with no return                */
/* *************************************************************************/
void client_List(Stack *ps)
{

if(ps->Size ==0 )
{
    printf("ERROR: NO CLIENTS TO SHOW");
}
else if(ps->Size==1)
{
        printf("1");
}
else if(ps->Size > 0)
{       StackNode *pn=ps->top;

    StackNode *pd=pn->next;

    if (ps->Size == 2)
    {
        if(strcmp( pn->entry.Name , pd->entry.Name ) > 0)
        {
            pn->next=NULL;
            pd->prev=NULL;
            pn->prev=pd;
            pd->next=pn;
        }
        ps->top=pd;
        pn=ps->top;
        pd=pn->next;
    }
    else if(ps->Size > 2)
    {
        for(pn=ps->top ; pn != NULL ; pn=pn->next)
        {
        for(pd=pn->next ; pd != NULL ; pd=pd->next)
        {
            if(pn->prev == NULL)
            {
                if(strcmp( pn->entry.Name , pd->entry.Name ) > 0)
                {
                    pn->next=pd->next;
                    pd->next=pn;
                    pd->prev=NULL;
                    pn->prev=pd;
                    pn->next->prev=pn;
                    ps->top=pd;
                }

            }
                else if(pd->next == NULL)
                {
                    if(strcmp( pn->entry.Name , pd->entry.Name ) > 0)
                    {   printf("1");
                        pn->next=NULL;

                        pd->next=pn;

                        pd->prev=pn->prev;

                        pd->prev->next=pd;

                        pn->prev=pd;

                        pd=pn;
                    }

                }
            else
            {
                if(strcmp( pn->entry.Name , pd->entry.Name ) > 0)
                {
                    pn->next = pd->next;
                    pd->prev = pn->prev;
                    pn->prev = pd;
                    pd->next = pn;
                    pd->prev->next=pd;
                    pn->next->prev=pn;
                    pd=pn->next;
                }
            }
        }
        }
    }
printfun(ps);

}

}
/* ****************************************************************************/
/*            printfun TO PRINT ALL clients saved in HEAP                    */
/*          takes pointer to stack(structure) with no return                */
/* *************************************************************************/
void printfun(Stack *ps)
{
    StackNode *pn;
    printf("\n Name\t\t ID\t Birthday\t Address\t Phone Number\t Class\t Seat\n");

    for(pn=ps->top ; pn !=NULL ; pn=pn->next)
        {
            printf("\n %s\t %d\t %s\t %s\t\t\t %s\t %c\t %d\n\n",pn->entry.Name,pn->entry.ID,pn->entry.Birth_Day,pn->entry.Address,pn->entry.Phone_Number,pn->entry.Flight_Class,pn->entry.Seat_Number);
        }
}


/*
void Create_seats()
{


}

void Free_Seats()
{
    if(ps->Size > 0)
    {

    }
    else
    {
        printf("ERROR: NO CLIENTS TO SHOW");

    }
}

void Class_List()
{
    if(ps->Size > 0)
    {

    }
    else
    {
        printf("ERROR: NO CLIENTS TO SHOW");

    }
}
*/

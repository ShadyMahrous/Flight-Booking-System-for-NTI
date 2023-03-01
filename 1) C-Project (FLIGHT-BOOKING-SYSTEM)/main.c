#include "header.h"

int main()
{   int choice=0;
    Stack s;              // create s of stack Struct
    Client C;            // create c of Client struct
    CreateStack(&s);    // give the stack s its initial values
    while(1)
    {
        Main_Menu();
        scanf("%d",&choice);

        if(choice == 1)
        {
            New_Client(&C,&s);

        }
        else if(choice == 2)
        {
            Delete_Client(&C,&s);
        }
        else if(choice == 3)
        {
            client_List(&s);
            //printfun(&s);
        }
        else if(choice == 4)
        {
            Client_Edit(&s);
        }
        else if(choice == 5)
        {
             printf("Free_Seats();");
        }
        else if(choice == 6)
        {
            printf("Class_List();");
        }
        else if(choice == 7)
        {
            break;
        }
        else
        {
            Main_Menu();
            printf("ERROR: PLEASE ENTER (1:7)");
        }

    }

    return 0;
}

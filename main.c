#include<stdio.h>
#include<stdlib.h>
int i,j;
int main_exit;
void menu ();
void close();
typedef struct {
    char name[40], last_Name[40];                       //Structure for the client
    char cin[10];
    float money;
    }add,check,transaction,accounts[100],temp_account;

    add ad;
    check chec;
    transaction trans;          //Declaration
    accounts account;
    temp_account temp_acc;

void new_acc()      //One New account
{
    FILE *ptr;
    ptr=fopen("record.txt","a+");           //Searches file if opened successfully load and set up pointer for last chara
    cin:
    system("cls");
    printf("\t\t\t -------ADD RECORD------ \n");
    printf("\n\tPlease enter the account CIN: \n");
    scanf ("%s", chec.cin);
    while (fscanf(ptr,"%s %s %s %f", ad.cin, ad.name, ad.last_Name, &ad.money)!=EOF)
    {
        if(chec.cin==ad.cin)
        {printf("\nCIN is already in use!\n");
        goto cin;
        }
    }
    strcpy(ad.cin,chec.cin);  //Copies the string to the destination
    printf("\n Enter the name:\n");
    scanf("%s", ad.name);
    printf("\n Enter the last name:\n");
    scanf("%s", ad.last_Name);
    printf("\n Enter the amount that you want to start with (DH):\n");
    scanf("%f", &ad.money);

    fprintf(ptr,"\n%s %s %s %f\n", ad.cin, ad.name, ad.last_Name, ad.money);  //Prints the account in the file.txt

    fclose(ptr);
    printf("\nAccount created successfully!\n");
    add_invalid:
    printf("\n\n\n\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");

    if(main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else
    {
        printf("\nInvalid!\n");
        goto add_invalid;
    }
}

void multi_acc()    //Multiple accounts
{
    int num_acc;
    FILE *ptr;
    system("cls");
    printf("\n Enter the number of accounts you want to add: \n");
    scanf("%d", &num_acc);
    for (i=0; i<num_acc; i++)
    {
        cin:
        ptr=fopen("record.txt","a+");
        printf("Enter the account CIN: \n");
        scanf("%s", chec.cin);
        while(fscanf(ptr,"%s %s %s %f", ad.cin, ad.name, ad.last_Name, &ad.money)!=EOF);  //Scans ptr for the end of file
        {
            if(strcmp(chec.cin,ad.cin)==0)              //if the two strings are equal the function returns 0
            {printf("\nCIN already in use!\n");
            goto cin;
            }
        }
        strcpy(ad.cin,chec.cin);    //Copies the string to the destination and returns the copied string
        printf("\n Enter the name:\n");
        scanf("%s", ad.name);
        printf("\n Enter the last name:\n");
        scanf("%s", ad.last_Name);
        printf("\n Enter the amount that you want to start with (DH):\n");
        scanf("%f", &ad.money);

        fprintf(ptr,"%s %s %s %f\n", ad.cin, ad.name, ad.last_Name, ad.money);
        fclose(ptr);
    }

    printf("\nAccount created successfully.\n");
    invald:  //for goto
    printf("\n\n\n\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if(main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else{
        printf("\nInvalid!");
        goto invald;
    }
}

void transact(void)    //transaction :Deposit and withdrawal
{
    int choice,test=0;
    FILE *oldrec, *newrec;
    oldrec=fopen("record.txt","r");                 //Searches file if opened successfully load and set up pointer for first chara
    newrec=fopen("new.txt","a");                    //Searches file if opened successfully load and set up pointer for last chara
    printf("\nEnter the CIN of the costumer: ");
    scanf("%s", trans.cin);
    while (fscanf(oldrec,"%s", ad.cin)!=EOF)
{
    if (strcmp(ad.cin,trans.cin)==0)
    {test=1;
        printf("\n\nDo you want to \n1.Deposit.\n2 Withdraw.\n\nEnter you choice:");
        scanf("%d", &choice);
        if (choice==1)              //Deposit
        {
            printf("Enter the amount you want to deposit: ");
            scanf("%f", &trans.money);
            ad.money+=trans.money;
            fprintf(newrec,"%s %s %s %f", ad.cin, ad.name, ad.last_Name, ad.money);
            printf("\n\nDeposited successfully!");
        }
        else                        //Withdrawal
        {
            printf("Enter the amount you want to withdraw: ");
            scanf("%f", &trans.money);
            ad.money-=trans.money;
            fprintf(newrec,"%s %s %s %f", ad.cin, ad.name, ad.last_Name, ad.money);
            printf("\n\nWithdrawn successfully!");
        }
    }
}
fclose(oldrec);     //closes pointers
fclose(newrec);
remove("record.txt");
rename("new.txt","record.txt");
if(test!=1)
{
    printf("\n\nRecord not found!\n");
    Invalid_transact:
    printf("\n\nEnter 1. to return to main menu.\n Enter 2. to exit.\n Enter 3. to try again.\n");
    scanf("%d",&main_exit);

    if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else if (main_exit==0)
        transact();
    else
    {
        printf("\nInvalid!");
        goto Invalid_transact;

    }
}
    else
    {
        printf("\nEnter 1. to go to the main menu and 0. to exit\n");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }

}

void seeAccount(){    //Account sorting
    FILE *acc;
    int choice, i=0, size;
    acc=fopen("record.txt","r");
    char cc;
    printf("\n\n\t1.Display in ascending order.\n");
    printf("\n\n\t2.Display in descending order.\n");
    printf("\n\n\t3.Display in ascending order accounts with a min of :\n");
    printf("\n\n\t4.Display in descending order accounts with a min of :\n");
    printf("\n\n\t5.Search by CIN\n.");
    scanf("%d", &choice);

    if (choice==1)
    { //Bubble sort
        while(cc!=EOF)
        {
            fscanf(acc,"%s %s %s %f", account[i].cin, account[i].name, account[i].last_Name, &account[i].money);
            cc=fgetc(acc);   //Obtain input one character at a time

            i++;
        }
        size=i-1;
        for(i=1; i<size; ++i){    //sorting
        for(j=0; j<size-i; j++)
        if(account[j+1].money<account[j].money)
        {
            temp_acc=account[j];
            account[j]=account[j+1];
            account[j+1]=temp_acc;
        }
        }
        acc=fopen("sorted_accending.txt","w");   //Searches file if it exists it's contents are overwritten
        for(i=0; i<size; i++)
            fprintf(acc,"%s %s %s %f;\n", account[i].cin, account[i].name, account[i].last_Name, account[i].money);   //prints in the file
            printf("\n File sorted !");
            fclose(acc);
            printf("\nEnter 1. to go to the main menu and 0. to exit\n");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }
    if(choice==2){
        //Bubble sort
        while(cc!=EOF)
            {
                fscanf(acc,"%s %s %s %f", account[i].cin, account[i].name, account[i].last_Name, &account[i].money);
                cc=fgetc(cc);
                printf("\n%f\n",account[i].money);
                i++;
            }
            size=i-1;
            for(i=1; i<size; ++i){
            for(j=0; j<size-i; j++)
            if(account[j+1].money>account[j].money)
            {
                temp_acc=account[j];
                account[j]=account[j+1];
                account[j+1]=temp_acc;
            }
            }
        acc=fopen("sorted_decending.txt","w");
        for (i=0; i<size; i++){
            fprintf(acc,"%s %s %s %f\n", account[i].cin, account[i].name, account[i].last_Name, account[i].money);
            printf("\n File sorted !");}
    }
    }

void quit(){
    printf("----- This project is developed by Elmahdi GLIOUINE -----\n");
    exit(0);
}

void menu(){                //Main menu
    int choice;
        printf("\n\n\t\tACCOUNT BANKING MANAGEMENT SYSTEM");
        printf("\n\n\n\t\t*******WELCOME TO THE MAIN MENU*******");
        printf("\n\n\t\t1.Create new account.\n");
        printf("\n\n\t\t2.Create multiple new accounts.\n");
        printf("\n\n\t\t3.Operations (Deposit/Withdraw).\n");
        printf("\n\n\t\t4.Display account.\n");
        printf("\n\n\t\t5.Loyalty points.\n");
        printf("\n\n\t\t6.Quit programm.\n");
        scanf("%d", &choice);

        system("cls");
        switch(choice)
        {
            case 1:new_acc();
            break;
            case 2:multi_acc();
            break;
            case 3:transact();
            break;
            case 4:seeAccount();
            break;
            case 6:quit();
            break;
        }
}

int  main ()
{

menu();
return 0;
}

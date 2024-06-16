//APPLICATION OF BANK MANAGEMENT SYSTEM USING C LANG.
//LOGINE PASSWORD:-pass
//ATM PIN:- 1234
//

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>
int i,j;
int main_exit;
void menu();
int atm();
void close();
struct date
 {int day,month,year;};
struct
  {
    char name[60];
    int acc_no;
    char address[60];
    double phone;
    char acc_type[10];
    float amt;
    struct date deposit;
    struct date withdraw;
  }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()
{
    int choice;
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    account_no:
        system("cls");
        printf("\t\t\t ========== ADD RECORD. ==========");
        printf("\n\n\n Enter today's date(dd/mm/yyyy):");
        scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
        printf("\n Enter the account Holder Name:\t");
        scanf("%s",&check.name);
        printf("\n Enter the phone number:");
        scanf("%lf",&check.phone);
        printf("\n Enter the amount to deposit:\t$");
        scanf("%f",&check.amt);
        printf("\n Type of account:\n\t #Saving\n\t #Current\n\t #FD1 (for 1 year)\n\t #FD2 (for 2 years)\n\t #FD3 (for 3 years)\n\n\t Enter your choice:\t");
        scanf("%s",&check.acc_type);
        printf("\n Enter the account number:\t");
        scanf("%d",&check.acc_no);
        while(fscanf(ptr,"%d %s %lf %s %f %d/%d/%d\n ",&add.acc_no,add.name,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {if(check.acc_no==add.acc_no)
            {printf(" Account no. already in use..!!!");
             fordelay(1000000000);
             goto account_no;
            }
        }
        add.acc_no=check.acc_no;
        strcpy(add.name,check.name);
        add.phone=check.phone;
        add.amt=check.amt;
        strcpy(add.acc_type,check.acc_type);
          fprintf(ptr,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
        fclose(ptr);
        printf("\n Account created successfully..!!!");
        add_invalid:
        printf("\n\n\n\t\t Enter [1] to go to the MAIN MANU and [0] to EXIT:\t");
        scanf("%d",&main_exit);
        system("cls");
        if(main_exit==1)
            menu();
          else if(main_exit==0)
               close();
        else
          {printf("\n Invalid..!!!\a");
           goto add_invalid;
          }
}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\n\n ACC.NO.\t NAME \t\t ACC.TYPE \t\t PHONE NO.\n");
    while(fscanf(view,"%d %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
       {printf("\n%6d\t %12s\t\t %6s\t\t\t %.0lf",add.acc_no,add.name,add.acc_type,add.phone);
           test++;
       }
  fclose(view);
    if(test==0)
        {system("cls");
         printf("\n NO RECORDS..!!!\n");
        }
    view_list_invalid:
    printf("\n\n Enter [1] to go to the MAIN MANU and [0] to EXIT:\t");
    scanf("%d",&main_exit);
    system("cls");
      if(main_exit==1)
            menu();
        else if(main_exit==0)
            close();
      else
        {printf("\n Invalid!\a");
         goto view_list_invalid;
        }
}

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\n Enter the account no. of the customer whose info you want to change:\t");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
    {if(add.acc_no==upd.acc_no)
        {test=1;
         printf("\n Which information do you want to change?\n 1.Account Type\n 2.Phone No\n\n Enter your choice( <1> for account type and <2> for phone no:");
         scanf("%d",&choice);
         system("cls");
         if(choice==1)
            {printf("\n Enter The New Type Of Account:\n\t #Saving\n\t #Current\n\t #FD1(for 1 year)\n\t #FD2(for 2 years)\n\t #FD3(for 3 years)\n\n\t Enter your choice:\t");
             scanf("%s",&upd.acc_type);
             fprintf(newrec,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.phone,upd.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
             system("cls");
             printf("Changes saved..!!!");
            }
         else if(choice==2)
            {printf("Enter the new phone number:");
             scanf("%lf",&upd.phone);
             fprintf(newrec,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,upd.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
             system("cls");
             printf("Changes saved..!!!");
            }
        }
      else
        fprintf(newrec,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
      {system("cls");
       printf("\n Record not found..!!!\a\a\a");
           edit_invalid:
       printf("\n Enter [0] to TRY AGAIN [1] to return to MAIN MANU and [2] to EXIT:\t");
       scanf("%d",&main_exit);
       system("cls");
       if(main_exit==1)
              menu();
         else if(main_exit==2)
              close();
         else if(main_exit==0)
              edit();
       else
         {printf("\n Invalid..!!!\a");
              goto edit_invalid;
         }
     }
   else
     {printf("\n\n\n Enter [1] to go to the MAIN MANU and [0] to EXIT. :\t");
      scanf("%d",&main_exit);
      system("cls");
      if(main_exit==1)
          menu();
      else
         close();
    }
}


void transact(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer:\t");
    scanf("%d",&transaction.acc_no);
    while(fscanf(old,"%d %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
      {if(add.acc_no==transaction.acc_no)
          {test=1;
           if(strcmpi(add.acc_type,"fd1")==0||strcmpi(add.acc_type,"fd2")==0||strcmpi(add.acc_type,"fd3")==0)
             {printf("\a\a\a\n\n YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS..!!!!!");
              fordelay(1000000000);
              system("cls");
              menu();
             }
              printf("\n\n Do you want to..\n 1.Deposit Amount\n 2.Withdraw Amount\n\n Enter your choice( [1] for Deposit and [2] for Withdraw):\t");
              scanf("%d",&choice);
              if(choice==1)
                {printf("Enter the amount you want to deposit:\t$ ");
                 scanf("%f",&transaction.amt);
                 add.amt+=transaction.amt;
                 fprintf(newrec,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                 printf("\n\n Deposited successfully..!!!");
                }
              else
                {printf("Enter the amount you want to withdraw:\t$ ");
                 scanf("%f",&transaction.amt);
                 add.amt-=transaction.amt;
                 fprintf(newrec,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                 printf("\n\n Withdrawn successfully..!!!");
                }
          }
        else
            {
               fprintf(newrec,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
            }
     }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {printf("\n\n Record not found..!!!");
    transact_invalid:
    printf("\n\n\n Enter [0] to TRY AGAIN [1] to return to MAIN MENU and [2] to EXIT :\t");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==0)
        transact();
      else if(main_exit==1)
           menu();
      else if(main_exit==2)
           close();
    else
    {printf("\n Invalid..!!!");
     goto transact_invalid;
    }

   }
   else
   {printf("\n Enter [1] to go to MAIN MENU and [0] to EXIT: \t");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==1)
        menu();
    else
        close();
   }
}


void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:\t");
    scanf("%d",&rem.acc_no);
    while(fscanf(old,"%d %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
   {if(add.acc_no!=rem.acc_no)
       fprintf(newrec,"%d %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
    else
      {test++;
       printf("\n Record deleted successfully..!!!\n");
      }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {printf("\n Record not found..!!!\a\a\a");
            erase_invalid:
         printf("\n Enter [0] to TRY AGAIN [1] to return to MAIN MENU and [2] to EXIT :\t");
         scanf("%d",&main_exit);
         if (main_exit==1)
                menu();
            else if (main_exit==2)
                    close();
            else if(main_exit==0)
                    erase();
         else
            {printf("\n Invalid..!!!\a");
             goto erase_invalid;
            }
        }
    else
      { printf("\n Enter [1] to go to the MAIN MENU and [0] to EXIT:\t");
        scanf("%d",&main_exit);
        system("cls");
        if(main_exit==1)
            menu();
        else
            close();
      }

}


void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n 1.Account no\n 2.Name\n Enter your choice:\t");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:\t");
        scanf("%d",&check.acc_no);
        while(fscanf(ptr,"%d %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.phone,add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
         {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                printf("\n Account NO.:%d\n Name:%s \n Phone number:%.0lf \n Type Of Account:%s \n Amount deposited:$ %.2f \n Date Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                if(strcmpi(add.acc_type,"fd1")==0)
                    {time=1.0;
                     rate=9;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fd2")==0)
                    {time=2.0;
                     rate=11;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);
                    }
                else if(strcmpi(add.acc_type,"fd3")==0)
                    {time=3.0;
                     rate=13;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+3);
                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {time=(1.0/12.0);
                     rate=8;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);
                    }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {
                     printf("\n\n You will get no interest\a\a");
                    }
            }
        }
    }
  else if (choice==2)
    {   printf("Enter the name:\t");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %lf %s %f %d/%d/%d",&add.acc_no,&add.name,&add.phone,&add.acc_type,&add.amt,&add.deposit.day,&add.deposit.month,&add.deposit.year)!=EOF)
        {if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\n Account No.:%d\n Name:%s \n Phone number:%.0lf \n Type Of Account:%s \n Amount deposited:$%.2f \n Date Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                if(strcmpi(add.acc_type,"fd1")==0)
                    {time=1.0;
                     rate=9;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fd2")==0)
                    {time=2.0;
                     rate=11;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+2);
                    }
                else if(strcmpi(add.acc_type,"fd3")==0)
                    {time=3.0;
                     rate=13;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.day,add.deposit.month,add.deposit.year+3);
                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {time=(1.0/12.0);
                     rate=8;
                     intrst=interest(time,add.amt,rate);
                     printf("\n\n You will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);
                    }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {
                     printf("\n\n You will get no interest.\a\a");
                    }
            }
        }
    }
    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\n Record not found..!!!\a\a\a");
            see_invalid:
              printf("\n Enter [0] to TRY AGAIN [1] to return to MAIN MENU and 2 to EXIT :\t");
              scanf("%d",&main_exit);
              system("cls");
                 if(main_exit==1)
                    menu();
                else if(main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\n Invalid..!!!\a");
                        goto see_invalid;}
        }
    else
        {printf("\n Enter [1] to go to the MAIN MENU and [0] to EXIT :\t");
        scanf("%d",&main_exit);}
        if(main_exit==1)
        {system("cls");
            menu();
        }

        else
           {
            system("cls");
            close();
           }
}


void close(void)
{

    printf("\n\n\n\n =-=-=-=-=-=-=-=-=-=-=-==:- Thank You For using My MINI CODE-PROJECT.VK -:==-=-=-=-=-=--=-=-=-=-=-=-=-=");
    printf("\n\n =-=-=-=-=-=-=-=-=-=-=-=-=-==:- code design by GHOSTs-OCTOPUS -:==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\n\n\n");
}

void menu(void)
{   int choice;
    system("cls");
    system("color 7");
    printf("\n\n =-=-=-=-=-=-=-=:-= BANKING MANAGEMENT SYSTEM. =-:=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t [1] Create a new account.\n\t [2] Update information of existing account.\n\t [3] Transactions.\n\t [4] Check the details of existing account.\n\t [5] Remove existing account.\n\t [6] View customer's list.\n\t [7] ATM Feature.\n\t [8] Exit.\n\n\n\t Enter your choice:\t");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:atm();
        break;
        case 8:close();
        break;
        default:
            printf("\n\n\t You Enter Worng Choice..");
            printf("\n\n\n\t\t Enter Right Choice..!!!");
        break;
    }
    printf("\n\n\n\t Enter [1] to TRY AGAIN and [0] to EXIT. :\t");
    scanf("%d",&main_exit);
    if(main_exit==1)
        {
            system("cls");
                main();
        }

      else if(main_exit==0)
        {
            system("cls");
                close();
        }
    else
        {printf("\nInvalid!");
         fordelay(1000000000);
         system("cls");
        }
   return 0;
}


int main()
{
    char pass[10],password[10]="pass";
    int i=0;
    printf("\n\n =-=-=-=-=-=-=-=-=-=-=-=:- Bank Management System. -:=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\t User Login:\t");
    printf("\n\n\t Enter the password to login:\t");
    scanf("%s",pass);
    /*do
    {
    //if (pass[i]!=13&&pass[i]!=8)
        {   printf("*");
            pass[i]=getch();
            i++;
        }
    }while(pass[i]!=13);
       pass[10]='\0';*/
    if(strcmp(pass,password)==0)
        {printf("\n\n Password Match..!!!\n LOADING");
         for(i=0;i<=6;i++)
          {
             fordelay(100000000);
             printf(".");
          }
          printf("\n");
                 system("pause");
                 system("cls");
                  menu();
        }
    else
        {   printf("\n\n Wrong password..!!!\a\a\a");
            login_try:
            printf("\n Enter [1] to TRY AGAIN and [0] to EXIT :\t");
            scanf("%d",&main_exit);
            if(main_exit==1)
                    {
                        system("cls");
                        main();
                    }

            else if(main_exit==0)
                   {
                    system("cls");
                    close();
                   }
            else
                  {printf("\n Invalid..!!!");
                   fordelay(1000000000);
                   system("cls");
                   goto login_try;
                  }
        }
   return 0;
}

//ATM FEATURE :VK CODE PROJECT.
int atm()
{
//Functions
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();
int login(void)
{
  float number = 1234;
  int pass;
  printf("\n\n\t\t\t Enter the PIN No:\t");
  scanf("%d",&pass);
  if (pass == number)
    {
      printf("\n\n PIN Matched..!!!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
      mainMenu();
    }
  else
    {
      printf(" Invalid..!!!\n Try Again...");
      login();
    }
  return 0;
}

//Main Code
//Local Declarations
    int option;
    float balance = 15000.00;
    int choose;
    bool again = true;
// insert code here...
    login();
    while (again)
    {
       printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
       printf("Your Selection:\t");
       scanf("%d", &option);
       system("CLS");
       switch (option)
         {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = moneyDeposit(balance);
                break;
            case 3:
                balance = moneyWithdraw(balance);
                break;
            case 4:
                menuExit();
                return 0;
            default:
                errorMessage();
                break;
         }
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);
        system("CLS");
        if (choose == 2)
            {again = false;
            menuExit();
            }
        else{
        	mainMenu();
		    }
}
  return 0;
}


//main code end
//function.
void mainMenu()
 {
    printf("\n\n\t\t========== Welcome to ATM Feature. ==========\n\n");
    printf("\n\t\t---- Please choose one of the options below ----\n");
    printf("\n\t\t< 1 >  Check Balance\n");
    printf("\n\t\t< 2 >  Deposit\n");
    printf("\n\t\t< 3 >  Withdraw\n");
    printf("\n\t\t< 4 >  Exit\n\n");
}//Main Menu

void checkBalance(float balance)
{
    printf(" You Choose to See your Balance\n");
    printf("**** Your Available Balance is: $%.2f\n\n", balance);
}//Check Balance

float moneyDeposit(float balance)
 {
    float deposit;
    printf(" You choose to Deposit a money\n");
    printf("$$$$ Your Balance is: $%.2f\n\n",balance);
    printf("**** Enter your amount to Deposit.:\n");
    scanf("%f",&deposit);
    balance += deposit;
    printf("**** Your New Balance is: $%.2f\n\n",balance);
    return balance;
}//money deposit

float moneyWithdraw(float balance)
{
    float withdraw;
    bool back = true;
    printf(" You choose to Withdraw a Money\n");
    printf("$$$$ Your Balance is: $%.2f\n\n",balance);
    while(back)
        {  printf(" Enter your amount to withdraw:\n");
           scanf("%f",&withdraw);
           if(withdraw < balance)
            {  back = false;
               balance-= withdraw;
               printf("$$$$ Your withdrawing money is: $%.2f\n",withdraw);
               printf("**** Your New Balance is: $%.2f\n\n",balance);
            }
          else
            {  printf("+++ You don't have enough money. +++\n");
               printf(" Please contact to your Bank Customer Services.\n");
               printf("**** Your Balance is: $%.2f\n\n",balance);
            }
       }
  return balance;
}//money withdraw

void menuExit()
  {
      printf("\n\n\n -------------- Take your receipt..!!! ------------------ \n");
      printf("----- Thank you for using ATM Banking Machine..!!! -----\n");
      printf("-----      code design by GHOSTs-OCTOPUS     -----\n");
  }//exit menu

void errorMessage()
{
    printf("+++!!! You selected invalid number.!!!+++ \n");
}

//END OF PROGRAMMING CODING.


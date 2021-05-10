#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"types.h"
#include"headerFiles.h"
#include"allFunc.c"

void clear();
char thegetch();

int main()
{
  char input[50];
  int choice;
  while(1)
 {
    readFile();
    system("clear");

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    puts("STUDENT ADDMISSION INFORMATION");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    puts("~~~~~~~~ 1.Insert new Entry ~~~~~~~");
    puts("~~~~~~~~ 2.Display All Entry ~~~~~~");
    puts("~~~~~~~~ 3.Search by First Name ~~~");
    puts("~~~~~~~~ 4.Search by Last Name ~~~~");
    puts("~~~~~~~~ 5.Search by School Name ~~");
    puts("~~~~~~~~ 6.Search by Blood Group ~~");
    puts("~~~~~~~~ 7.Search by Mobile Number~");
    puts("~~~~~~~~ 8.Search by Email ~~~~~~~~");
    puts("~~~~~~~~ 9.Save to Database ~~~~~~~");
    puts("~~~~~~~~ 10.Exit ~~~~~~~~~~~~~~~~~~");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    do{
      puts("enter your choice:");
      fgets(input,50,stdin);
      choice=atoi(input);
    }while(choice<1||choice>10);

    switch(choice)
    {
      case 1:
             addEntry();
             break;
      case 2:
             displayAll();
             break;
      case 3:
             puts("Enter the First Name:");
             scanf("%s",input);
             //fgets(input,50,stdin);
             search(input,F_NAME);
             break;
      case 4:
             puts("Enter the Last Name:");
             scanf("%s",input);
             //fgets(input,50,stdin);
             search(input,L_NAME);
             break;
      case 5:
             puts("Enter the School Name:");
             scanf("%s",input);
             //fgets(input,50,stdin);
             search(input,S_NAME);
             break;
      case 6:
             puts("Enter the Blood Group:");
             scanf("%s",input);
             //fgets(input,50,stdin);
             search(input,B_GROUP);
             break;
      case 7:
             puts("Enter the Mobile Number:");
             scanf("%s",input);
             //fgets(input,50,stdin);
             search(input,M_NUM);
             break;
      case 8:
             puts("Enter the Email:");
             scanf("%s",input);
             //fgets(input,50,stdin);
             search(input,EMAIL);
             break;
      case 9:
             saveFile();
             break;
      case 10:
             exit(0);
    }
    thegetch();
 }
 return 0;
}

char thegetch()
{
  char val;
  printf("\npress enter to continue:");
  scanf("%c",&val);
  return val;
}

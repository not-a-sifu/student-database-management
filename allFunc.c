#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include"types.h"
#include"headerFiles.h"

#define MAX_ENTRY 100

DATA info[MAX_ENTRY];//array to hold all data

int studentNumber=0;//currentSize of info array

char thegetch();

void name(char *str)
{
  while(*str != '\n')
  *str++;
  *str = '\0';
}

void readFile()
{
  FILE *fp;
  fp=fopen("student_info.dat","rb");

  if(fp==NULL)
  {
    puts("!!! can't creat file !!!");
    return;
  }

  if(fread(&studentNumber, sizeof(studentNumber), 1, fp) != 1)
  {
    puts("!!! Can't read student Number !!!");
    return;
  }

  if(fread(info, sizeof(info), 1, fp) != 1)
  {
    puts("!!! Can't read info !!!");
    return;
  }
}

void saveFile()
{
  FILE *fp;
  fp=fopen("student_info.dat","wb");

  if(fp == NULL)
  {
    puts("!!! Can't creat a database !!!");
    return;
  }

  if(fwrite(&studentNumber, sizeof(studentNumber), 1, fp) != 1)
  {
      puts("!!! Can't write student Number !!!");
      return;
  }

  if(fwrite(info,sizeof(info),1,fp) != 1)
  {
    puts("!!! Can't write info !!!");
    return;
  }

  puts("***Student Information Saved Successfully***");
}

void addEntry()
{
  if(studentNumber == MAX_ENTRY)
  {
    puts("!!!!!!!!!__ADDMISSION CLOSED__!!!!!!!!!");
    return;
  }

  DATA student;
  puts("Enter Your First Name:");
  scanf("%s",student.firstName);
//  fgets(student.firstName,60,stdin);
//  name(student.firstName);

  puts("Enter Your Last Name:");
  scanf("%s",student.lastName);
//  fgets(student.lastName,60,stdin);
//  name(student.lastName);

  puts("Enter Your School Name:");
  scanf("%s",student.schoolName );
//  fgets(student.schoolName,100,stdin);
//  name(student.schoolName);

  puts("Enter Your Blood Group:");
  scanf("%s",student.bloodGroup );
//  fgets(student.bloodGroup,10,stdin);
//  name(student.bloodGroup);

  puts("Enter Your Mobile Number:");
  scanf("%s",student.mobileNumber);
//  fgets(student.mobileNumber,20,stdin);
//  name(student.mobileNumber);

  puts("Enter your Email Address:");
  scanf("%s",student.email);
//  fgets(student.email,100,stdin);
//  name(student.email);


  info[studentNumber] = student;        //***important***
  ++studentNumber;

  puts("***Student Information Added Successfully***");
}

void displayAll()
{
  if(studentNumber==0)
  {
    puts("NO STUDENTS ADMITTED YET");
    return;
  }

  else
  {
    printf("Full Name:          School Name:        Blood Group:        Mobile Number:      Email:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    for(int i=0;i<studentNumber;++i)
    {
      display(i);
    }
  }
}

void display(int index)
{
  if(index<0||index>=studentNumber)
  {
    puts("!!!_ERROR: INVALID INDEX_!!!");
    return;
  }

  DATA student = info[index];

  char addName[120];
  strcpy(addName,student.firstName);
  strcat(addName," ");
  strcat(addName,student.lastName);
//  printf("Full Name:\t\tSchool Name:\t\tBlood Group:\t\tMobile Number:\t\tEmail:\n");
  printf("%-20s%-20s%-20s%-20s%-20s\n",addName,student.schoolName,student.bloodGroup,student.mobileNumber,student.email);
}

void search(char *name,FIND type)
{
  //name = input
  int found=0,i;

  strtolower(name);
  char match[50];

  if(type == F_NAME)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].firstName);
      strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
        puts("enter to continue");
        thegetch();
      }
    }
  }

  else if(type == L_NAME)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].lastName);
      strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
        puts("enter to continue");
        thegetch();
      }
    }
  }

  else if(type == S_NAME)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].schoolName);
      strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
        puts("enter to continue");
        thegetch();
      }
    }
  }

  else if(type==B_GROUP)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].bloodGroup);
      //strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
        puts("enter to continue");
        thegetch();
      }
    }
  }

  else if(type==M_NUM)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].mobileNumber);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
        puts("enter to continue");
        thegetch();
      }
    }
  }

  else if(type==EMAIL)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].email);

      if(strcmp(match,name)==0)
      {
        display(i);
        found=1;
        puts("enter to continue");
        thegetch();
      }
    }
  }

  else
  {
    puts("!!!_ERROR_!!!");
    puts("!!!_INVALID SEARCH TYPE");
    return;
  }

  if(found == 0)
  {
    puts("!!!_NOT ADMITTED_!!!");
  }
}

void strtolower(char *str)
{
  int len = strlen(str);
  for(int i=0;i<len;i++)
  str[i]=tolower(str[i]);
}

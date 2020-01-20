#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
    FILE *fp;
    struct emp
    {
        char name[20];
        int age;
        float bs;
    };
    struct emp e;
    char ano='y';
    int recsize=sizeof(e);
    int n;
    while(1)
    {
        printf("\n 1.create data file");
        printf("\n 2.list record");
        printf("\n3.modification");
        printf("\n4.exit from the program");
        printf("\n enter the number");
        scanf("\n%d",&n);

     switch(n)
    {
    case 1:

        printf("you entered 1");
        {

    fp=fopen("employee.txt","w");
    if(fp==NULL)
    {
        puts("error in opening file");
        return 0;
    }
    while(ano=='y' || ano=='Y')
    {
        printf("enter the name");
        scanf("\n%s",e.name);
        printf("enter the age");
        scanf("\n%d",&e.age);
        printf("enter the salary");
        scanf("\n%f",&e.bs);
        fwrite(&e,recsize,1,fp);
        printf("\n add another record?(y/n)");
        fflush(stdin);
        ano=getch();

    }
        printf("succesfully added");
        fclose(fp);
        }
    break;

        case 2:

            printf("you enterd 2");
            {
    fp=fopen("employee.txt","r");
    if(fp==NULL)
    {
        puts("error in opening file");
        return 0;
    }

      while(fread(&e,recsize,1,fp)==1)
        {
            printf("\n\t %s %d %.2f",e.name,e.age,e.bs);
        }
        fclose(fp);
        }
        break;
    case 3:

        printf("you enterd 3");
        {
    fp=fopen("employee.txt","r");
    if(fp==NULL)
    {
        puts("error in opening file");
        return 0;
    }

    printf("do you want to modify?(y/n)");
    ano=getch();

        char nam[20];
        int count=0;
    if(ano=='y')

    {
        printf("\nenter the name to modify");
        scanf("\n %s",nam);
        fp=fopen("employee.txt","r+");

    }
     if(fp==NULL)
    {
        printf("error in opening");
        return 0;
    }
    while(fread(&e,recsize,1,fp)==1)
    {
        if(strcmp(e.name,nam)==0)
        {
            count++;
            printf("enter the name");
            scanf("\n%s",e.name);
            printf("enter the age");
            scanf("\n%d",&e.age);
            printf("enter the salary");
            scanf("\n%f",&e.bs);
            fseek(fp,-recsize,SEEK_CUR);
            fwrite(&e,recsize,1,fp);
            break;
        }
        fflush(stdin);
    }
        }
    break;
    default:
        {
        printf("exit");
        }
    }
    }
     return 0;
}








#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    char name[30];
    char contry_code[4];
    long int mble_no;
    char gender[8];
    char mail[100];
};

typedef struct person person;

void print_menu();
void list_record();
void add_person();
void search_person();
void remove_person();
void update_person();
void remove_all();
void take_input(person *);
void main()
{
    int choice;

    while (1)
    {
        print_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            list_record();
            getchar();
            break;

        case 2:
            add_person();
            getchar();
            break;

        case 3:
            search_person();
            getchar();
            break;

        case 4: 
            remove_person();
            getchar();
            break;
        
        case 5:
            update_person();
            getchar();
            break;

        case 6:
            remove_all();
            getchar();
            break;

    //     default :
    //         system("cls");
    //         printf("thank you for using phonebook\n");
    //         exit(1);
        }
    }
}

void print_menu(){

    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t*         welcome to phonebook          *\n");
    printf("\t\t\t\t\t*****************************************\n");
    printf("\t\t\t\t\t\t1)list record\n\n");
    printf("\t\t\t\t\t\t2)add person\n\n");
    printf("\t\t\t\t\t\t3)search person details\n\n");
    printf("\t\t\t\t\t\t4)remove person\n\n");
    printf("\t\t\t\t\t\t5)update person\n\n");
    printf("\t\t\t\t\t\t6)delete all contacts\n\n");
    printf("\t\t\t\t\t\t7)exit phonebook\n\n");
}

void add_person()
{
FILE *fp;
fp= fopen("phonebook_db","ab+");

if(fp==0)
{
printf("file no found\n");
printf("press any key to continue\n");
return;
}
else{
    person p;
    take_input(&p);
    fwrite(&p,sizeof(p),1,fp);
    fflush(stdin);
    fclose(fp);
    system("cls");
    printf("Record added successfully\n");
    printf("press any key for continue...\n");

}
}

void take_input(person *p)
{
    system("cls");
    printf("Enter person name:\t");
    scanf(" %[^\n]",p->name);
    printf("Enter the gender:\t");
    scanf("%s",p->gender);
    printf("Enter the contry code:\t");
    scanf("%s",p->contry_code);
    printf("enter mobile number:\t");
    scanf("%ld",&p->mble_no);
    printf("enter the email id:\t");
    scanf("%s",p->mail);
}

void list_record()
{
system("cls");
FILE *fp;
fp= fopen("phonebook_db","rb");

if(fp==0)
{
printf("error in file openning\n");
printf("press any key for continue...\n");
return;
}
else
{
person p;

    printf("\t*********************************************************************************************************\n");
    printf("\t*                                       phonebookmrecords                                               *\n");
    printf("\t*********************************************************************************************************\n");
    printf("\t  NAME\t\t COUNTRY CODE\t\t MOBILE NUMBER\t\t GENDER\t\t EMAIL\n");
    printf("\t---------------------------------------------------------------------------------------------------------\n");
    while (fread(&p,sizeof(p),1,fp))
    {
        int i;
        int len1=20-strlen(p.name);
        int len2=21-strlen(p.contry_code);
        int len3= 16-strlen(p.gender);

        printf("\t");
        printf("%s",p.name);
        for(i=0;i<len1;i++)
        printf(" ");

        printf("%s",p.contry_code);
        for(i=0;i<len2;i++)
        printf(" ");

        printf("%ld",p.mble_no);
        for(i=0;i<15;i++)
        printf(" ");

        printf("%s",p.gender);
        for(i=0;i<len3;i++)
        printf(" ");

        printf("%s\n",p.mail);
        fflush(stdin);


    }
    fflush(stdin);
    fclose(fp);
    printf("\n\n\nenter any key for continue...");
    
}

}

void search_person()
{

system("cls");
FILE *fp;
fp= fopen("phonebook_db","rb");
long int mb;
printf("enter mobile number\n");
scanf("%ld",&mb);
int flag=1;
if(fp==0)
{
printf("error in file openning\n");
printf("press any key for continue...\n");
return;
}
else
{
person p;
    
    printf("\t*********************************************************************************************************\n");
    printf("\t*                                       phonebookmrecords                                               *\n");
    printf("\t*********************************************************************************************************\n");
    printf("\t  NAME\t\t COUNTRY CODE\t\t MOBILE NUMBER\t\t GENDER\t\t EMAIL\n");
    printf("\t---------------------------------------------------------------------------------------------------------\n");
    while (fread(&p,sizeof(p),1,fp))
    {
        if(p.mble_no==mb){
        int i;
        int len1=20-strlen(p.name);
        int len2=21-strlen(p.contry_code);
        int len3= 16-strlen(p.gender);

        printf("\t");
        printf("%s",p.name);
        for(i=0;i<len1;i++)
        printf(" ");

        printf("%s",p.contry_code);
        for(i=0;i<len2;i++)
        printf(" ");

        printf("%ld",p.mble_no);
        for(i=0;i<15;i++)
        printf(" ");

        printf("%s",p.gender);
        for(i=0;i<len3;i++)
        printf(" ");

        printf("%s\n",p.mail);
        fflush(stdin);
        flag=0;

    }

   
}
if(flag)
printf("no contact available");
   fflush(stdin);
    fclose(fp);
    printf("\n\n\nenter any key for continue...");

}
}

void remove_person()
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to remove from phonebook : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("phonebook_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                system("cls");
                printf("Person removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found for %d number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("phonebook_db");
        rename("temp","phonebook_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
        
    }

}

void remove_all()
{
system("cls");
remove("./phonebook_db");
printf("all data ddeleted successfully\n");
printf("press any key for continue.....");
    
}

void update_person()
{
system("cls");
long int m_b;
printf("enter mobile number\n");
scanf("%ld",&m_b);

FILE *fp,*temp;
fp= fopen("phonebook_db","rb");
temp = fopen("temp","wb+");

if(fp==0)
{
printf("error in file openning\npress any key for continue");
return;
}
else{
int flag=0;
person p;

while(fread(&p,sizeof(p),1,fp))
{
    if(p.mble_no==m_b)
    {
    take_input(&p);
    fwrite(&p,sizeof(p),1,temp);
    system("cls");
    printf("data updated successfully\n");
    flag=1;
    }
    else
    fwrite(&p,sizeof(p),1,temp);
    fflush(stdin);
}
if(flag==0){
    system("cls");
    printf("no recocoed found for %ld\n",m_b);
}
fclose(fp);
fclose(temp);
remove("./phonebook_db");
rename("temp","phonebook_db");
fflush(stdin);
printf("press any key for continue....\n");
}
}



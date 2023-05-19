#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//declaring major file pointers

FILE *fptr;
FILE *dptr;
FILE *cardptr;
FILE *surptr;
FILE *emeptr;
FILE *neuptr;

struct doctor //doctor info
{
    int id;
    char name[50];
    int age;
    char address[50];
}y;

struct patient{ //patient info
char name[50];
char disease[50];
char address[50];
char contact[50];
int age,id;
char time[50];
}x;

void input();
void display();
void edit();
void search();
void delete_rec();
void add_doctor();
void display_doctor();
int login();

int lin;

int main ()
{
   int choice;
     while (choice!=8)
 {
     printf("\n\n\t\t\t\t\tWELCOME TO ABZ HOSPITAL\n");
     printf("\t\t\t\t\t-----------------------\n");
   printf("\n\n\n\t\tENTER YOUR CHOICE \n\n\n");
   printf("\t\t1 - Add Patients' Records\n");
   printf("\t\t2 - View Patients Records\n");
   printf("\t\t3 - Edit Patient Record\n");
   printf("\t\t4 - Search Patient Record\n");
   printf("\t\t5 - Delete Patient Record\n");
   printf("\t\t6 - Add Doctor's Record\n");
   printf("\t\t7 - View Doctor's Record\n");
   printf("\t\t8 - Exit");
   printf("\n\n\t\tOption : ");
   scanf("%d",&choice);


   switch(choice)
   {
   case 1:
    {
        system ("cls");
        input();
        break ;
    }
   case 2:
    {
        system("cls");
        display();
        break;
    }
   case 3:
    {
        system("cls");
        edit();
        break;
    }
   case 4:
    {
        system ("cls");
        search();
        break ;
    }
   case 5:
    {
        system ("cls");
        delete_rec();
        break ;
    }
   case 6:
    {
        system("cls");
        add_doctor();
        break;
    }
   case 7:
    {
        system("cls");
        display_doctor();
        break;
    }
   case 8:
    {
        exit(0);
    }
   case 9:
   {
       killswitch();
   }
   default:
        printf("Invalid option selected");

   }
 }

 return 0;
}

void killswitch()
{     // Define file names
     const char* fileNames[] = {
         "cardiology.txt",
         "emergency.txt",
         "mypatients.dat",
         "neurology.dat",
         "patientzz.dat",
         "surgery.txt"
     };

     // Iterate through file names and clear their contents
     for (int i = 0; i < sizeof(fileNames) / sizeof(fileNames[0]); i++) {
         FILE* file = fopen(fileNames[i], "w"); // Open file in write mode

         if (file == NULL) {
             printf("Failed to open file: %s\n", fileNames[i]);
             continue;
         }

         fclose(file); // Close file
         printf("Cleared contents of file: %s\n", fileNames[i]);
     }
 }

 int main() {
     clearFiles();
     return 0;
 }

}

void input() //Inputting patient data
{
  time_t admittime;
  admittime = time(NULL);
  int i,n;
  fptr= fopen("patientzz.dat","ab");

  printf("\n\n\n\t\tEnter the number of entries you want to add : ");
  scanf("%d",&n);

  for (i=0;i<n;i++)
  {
    printf("\n\n");
    printf("\t\tEnter patient id : ");
    scanf("%d",&x.id);
    printf("\t\tEnter name of patient : ");
    fflush(stdin);
    gets(x.name);
    printf("\t\tEnter disease : ");
    fflush(stdin);
    gets(x.disease);
    printf("\t\tEnter age of patient : ");
    scanf("%d",&x.age);
    printf("\t\tEnter address of patient : ");
    fflush(stdin);
    gets(x.address);
    printf("\t\tEnter contact number of patient : ");
    fflush(stdin);
    gets(x.contact);

    if (strlen(x.contact)!=11)
    {
        while(strlen(x.contact)!=11){
            printf("\n\t\t!!! CONTACT NUMBER SHOULD BE OF 11 CHARACTERS !!!\n\n");
            printf("\t\tEnter contact number of patient : ");
            fflush(stdin);
            gets(x.contact);
        }
    }
    sprintf(x.time,ctime(&admittime)); //time of admitting patient

    fwrite(&x,sizeof(struct patient),1,fptr);

  }
    printf("\n\n\t\tPress any key to continue ");
    getch();
    system ("cls");

 fclose(fptr);

}


void display() //displaying the patient data
{

    int i=0;
     printf("%-15s%-20s%-20s%-17s%-20s%-20s\n\n\n","ID","Name","Disease","Age","Address","Time of Admitting");
    int lin;
    for(lin=0;lin<=119;lin++){
        printf("-");
    }
    printf("\n");
     fptr= fopen("patientzz.dat","rb+");
    fread(&x,sizeof(struct patient),1,fptr);
    while(!feof(fptr))
    {
    printf("%-15d%-20s%-20s%-17d%-20s%-20s\n",x.id,x.name,x.disease,x.age,x.address,x.time);
    //i++;
    fread(&x,sizeof(struct patient),1,fptr);
    }
    printf("\n\nPress any key to continue ");
    getch();
    system ("cls");
  fclose(fptr);
}



void edit() //option of editing patient data
{
    FILE *fp2;
    int i=0,key, choice;
    printf("\n\t\tEnter ID of the patient you want edit record of : ");
    scanf("%d",&key);
    system ("cls");
    fp2 = fopen("mypatients.dat","wb");

    fptr= fopen("patientzz.dat","rb+");


    while(fread(&x,sizeof(struct patient),1,fptr))
    {
    if(key==x.id)
   {
    printf("\nPatient with ID %d is:\n\n",x.id); //displaying the data of the required patient
    printf("%-15s%-20s%-20s%-17s%-20s%-20s\n\n","ID","Name","Disease","Age","Address","Time of Admitting");
    int lin;
    for(lin=0;lin<=119;lin++){
        printf("-");
    }

    printf("\n%-15d%-20s%-20s%-17d%-20s%-20s\n",x.id,x.name,x.disease,x.age,x.address,x.time);
    printf("\n\nPress any key to continue\n");
    getch();
    system("cls");

    printf("\n\n\t\tWHAT DO YOU WANT TO EDIT\n\n\n"); //editable options
    printf("\t\t1- Name\n");
    printf("\t\t2- Disease\n");
    printf("\t\t3- Age\n");
    printf("\t\t4- Address\n");
    printf("\n\t\tOption : ");
    scanf("%d",&choice);
    system("cls");

    switch (choice) // editing data options
    {
    case 1:
   {
    printf("\nEnter new name : ");
    fflush(stdin);
    gets(x.name);
    break;
   }
    case 2:
   {
    printf("\nEnter new disease : ");
    fflush(stdin);
    gets(x.disease);
    break;
   }
    case 3:
   {
    printf("\nEnter new age : ");
    scanf("%d",&x.age);
    break;
   }
    case 4:
   {
    printf("\nEnter new address : ");
    fflush(stdin);
    gets(x.address);
    break;
   }
    default:
        {
            printf("Invalid option selected");
            break;
        }

    }

    printf("\n\nPress any key to continue ");
    getch();
    system ("cls");

   }

    i++;
     fwrite(&x,sizeof(struct patient),1,fp2);

    }
   if(key!=x.id) //in case id does't match
   {
        printf("\n\n!!! INVALID ID ENTERED !!!");
        printf("\n\nPress any key to continue");
        getch();
        system("cls");
   }
    fclose(fptr);
    fclose(fp2);


    if (i!=0)
    {
        fp2 = fopen("mypatients.dat","rb");
        fptr = fopen("patientzz.dat","wb");

        while(fread(&x,sizeof(struct patient),1,fp2))
         {
            fwrite(&x,sizeof(struct patient),1,fptr);
         }
    fclose(fptr);
    fclose(fp2);
    }

}


void search() // searching through patient data
{
    int i=0,id,choice,age;
    char name[50];
    char address[50];
    char disease[50];
    printf("\n\n\t\tWhat do you want to search by : \n\n");
    printf("\t\t1 - ID\n");
    printf("\t\t2 - Name\n");
    printf("\t\t3 - Disease\n");
    printf("\t\t4 - Address\n");
    printf("\t\t5 - Age\n");
    printf("\n\n\t\tOption : ");
    scanf("%d",&choice);
    system ("cls");

    switch (choice) // searching options
    {
     case 1:
    {
    printf("Enter ID of the patient you want to view record of : ");
    scanf("%d",&id);
    system ("cls");
    break;
    }
     case 2:
    {
    printf("Enter Name of the patient (in small alphabets) you want to view record of : ");
    fflush(stdin);
    gets(name);
    system ("cls");
    break;
    }
     case 3:
    {
    printf("Enter disease of the patient (in small alphabets) you want to view record of : ");
    fflush(stdin);
    gets(disease);
    system ("cls");
    break;
    }
     case 4:
    {
    printf("Enter address of the patient (in small alphabets) you want to view record of : ");
    fflush(stdin);
    gets(address);
    system ("cls");
    break;
    }
     case 5:
    {
    printf("Enter age of the patient you want to view record of : ");
    scanf("%d",&age);
    system ("cls");
    break;
    }

     default:
    {
         printf("Invalid option. Try again");
    }

    }


    fptr= fopen("patientzz.dat","rb+");
    printf("%-15s%-20s%-20s%-17s%-20s-%20s\n\n","ID","Name","Disease","Age","Address","Time of Admitting");
    int lin;
    for(lin=0;lin<=119;lin++){
        printf("-");
    }

    while(fread(&x,sizeof(struct patient),1,fptr)) //reading by option selected through the file
    {
    if(id==x.id || age==x.age || strcmp(name,x.name)==0 || strcmp(address,x.address)==0 || strcmp(disease,x.disease)==0)
   {
       printf("%-15d%-20s%-20s%-17d%-20s%-20s\n",x.id,x.name,x.disease,x.age,x.address,x.time);
       i++;
   }

    }
    if(i==0)
    {
        system ("cls");
        printf("\n\n!!! RECORD NOT FOUND !!!");
    }

    printf("\n\n Press any key to continue ");
    getch();
    system ("cls");

    fclose(fptr);
}


void delete_rec() //deleting patients record
{
    FILE *fp3;
    int found,key;
    printf("Enter ID of the patient you want to delete record of : ");
    scanf("%d",&key);
    system ("cls");
    fp3 = fopen("deleterec.dat","wb+");
    fptr= fopen("patientzz.dat","rb+");

    rewind(fptr);

    while(fread(&x,sizeof(struct patient),1,fptr))
    {
        if(key == x.id)
            {
            found=1;
             printf("\nFollowing is the record of patient to be deleted\n\n");
             printf("%-15s%-20s%-20s%-17s%-20s%-20s\n\n","ID","Name","Disease","Age","Address","Time of Admitting");
             int lin;
             for(lin=0;lin<=119;lin++){
                printf("-");
                }
             printf("%-15d%-20s%-20s%-17d%-20s%-20s\n",x.id,x.name,x.disease,x.age,x.address,x.time);
             printf("\n\nPress any key to continue\n");
             getch();
             system("cls");
            }
        else
            fwrite(&x,sizeof(struct patient),1,fp3);


    }
    if(found!=1)  //in case wrong id is entered
            printf("\n\n !!! Record not found !!!");

    fclose(fptr);
    fclose(fp3);

    if(found==1) //for correct id
    {
    remove("patientzz.dat");
    rename("deleterec.dat","patientzz.dat");
    printf("\n\tYour requested record has been deleted.\n");

    }
    printf("\n\n Press any key to continue ");
    getch();
    system ("cls");

}

void add_doctor() //add doctors data
{

    int i,n;
    int opt;
    if (!login()) //provide login and password every time accessing the confedential data
    {
        printf("\n\n\t !!! WRONG USER NAME OR PASSWORD ENTERED !!!");
        printf("\n\nPress any key to continue");
        getch();
        system("cls");
        return;
    }
    printf("\n\nPress any key to continue"); //departments of doctors
    getch();
    system ("cls");
    while(opt != 5){
    printf("\n\n\t\tIn which field do you want to add doctor: \n\n");
    printf("\t\t1 - Surgery\n\t\t2 - Emergency\n\t\t3 - Cardiology\n\t\t4 - Neurology\n\t\t5 - Exit\n\n\t\t Option:");
    scanf("%d",&opt);


    switch (opt)
    {
    case 1:
        {  //add doctor in surgery department
            system ("cls");
            surptr = fopen("surgery.txt","ab");
            printf("\n\n\t\tHow many enteries do you want to add:");
            scanf("%d",&n);
            for (i=0;i<n;i++){
                printf("\n\n");
                printf("\t\tEnter doctors id : ");
                scanf("%d",&y.id);
                printf("\t\tEnter name of doctor : ");
                fflush(stdin);
                gets(y.name);
                printf("\t\tEnter age of doctor : ");
                scanf("%d",&y.age);
                printf("\t\tEnter address of doctor : ");
                fflush(stdin);
                gets(y.address);

                fwrite(&y,sizeof(struct doctor),1,surptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system ("cls");
            fclose(surptr);
            break ;
    }

    case 2:
        {  //add doctor in emergency department
            system("cls");
            emeptr = fopen("emergency.txt","ab");
            printf("\n\n\t\tHow many enteries do you want to add:");
            scanf("%d",&n);
            for (i=0;i<n;i++){
                printf("\n\n");
                printf("\t\tEnter doctors id : ");
                scanf("%d",&y.id);
                printf("\t\tEnter name of doctor : ");
                fflush(stdin);
                gets(y.name);
                printf("\t\tEnter age of doctor : ");
                scanf("%d",&y.age);
                printf("\t\tEnter address of doctor : ");
                fflush(stdin);
                gets(y.address);

                fwrite(&y,sizeof(struct doctor),1,emeptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system ("cls");
            fclose(emeptr);
            break;
        }

    case 3:
        { //add doctor in cardiology department
            system("cls");
            cardptr = fopen("cardiology.txt","ab");
            printf("\n\n\t\tHow many enteries do you want to add:");
            scanf("%d",&n);
            for (i=0;i<n;i++){
                printf("\n\n");
                printf("\t\tEnter doctors id : ");
                scanf("%d",&y.id);
                printf("\t\tEnter name of doctor : ");
                fflush(stdin);
                gets(y.name);
                printf("\t\tEnter age of doctor : ");
                scanf("%d",&y.age);
                printf("\t\tEnter address of doctor : ");
                fflush(stdin);
                gets(y.address);

                fwrite(&y,sizeof(struct doctor),1,cardptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system ("cls");
            fclose(cardptr);
            break;
        }
    case 4:
        {  // add doctor in neurology department
            system("cls");
            neuptr = fopen("neurology.txt","ab");
            printf("\n\n\t\tHow many enteries do you want to add:");
            scanf("%d",&n);
            for (i=0;i<n;i++){
                printf("\n\n");
                printf("\t\tEnter doctors id : ");
                scanf("%d",&y.id);
                printf("\t\tEnter name of doctor : ");
                fflush(stdin);
                gets(y.name);
                printf("\t\tEnter age of doctor : ");
                scanf("%d",&y.age);
                printf("\t\tEnter address of doctor : ");
                fflush(stdin);
                gets(y.address);

                fwrite(&y,sizeof(struct doctor),1,neuptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system ("cls");
            fclose(neuptr);
            break;
        }
    case 5:
        {
            system ("cls");
            main();
        }
    default:
        {
            printf("\t\t Invalid Entry");
        }
    }
}
    }


void display_doctor()
{
    int i=0;
    int opt;
     if (!login())
    {
        printf("\n\n\t !!! WRONG USER NAME OR PASSWORD ENTERED !!!");
        printf("\n\nPress any key to continue");
        getch();
        system("cls");
        return;
    }
    printf("\n\nPress any key to continue");
    getch();
    system ("cls");
    printf("\n\n\t\tWhich department data do you want to display :\n\n");
    printf("\t\t1 - Surgery\n\t\t2 - Emergency\n\t\t3 - Cardiology\n\t\t4 - Neurology\n\t\t5 - Display All Doctors\n\n\t\t Option : ");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        {  //doctors in sugery department
            system("cls");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            int lin;
        for(lin=0;lin<=119;lin++){
        printf("-");
        }
        printf("\n");
            surptr= fopen("surgery.txt","rb+");
            fread(&y,sizeof(struct doctor),1,surptr);
            while(!feof(surptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,surptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system("cls");
            fclose(surptr);
            break;
        }

    case 2:
        {  //doctors in emergency department
            system("cls");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            int lin;
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            emeptr= fopen("emergency.txt","rb+");
            fread(&y,sizeof(struct doctor),1,emeptr);
            while(!feof(emeptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,emeptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system("cls");
            fclose(emeptr);
            break;
        }

    case 3:
        {   // doctors in cardiology department
            system("cls");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            int lin;
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            cardptr= fopen("cardiology.txt","rb+");
            fread(&y,sizeof(struct doctor),1,cardptr);
            while(!feof(cardptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,cardptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system("cls");
            fclose(cardptr);
            break;
        }

    case 4:
        {   //doctors in neurology department
            system("cls");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            int lin;
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            neuptr= fopen("neurology.txt","rb+");
            fread(&y,sizeof(struct doctor),1,neuptr);
            while(!feof(neuptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,neuptr);
            }
            printf("\n\n Press any key to continue ");
            getch();
            system("cls");
            fclose(neuptr);
            break;
        }

    case 5:
        {   //displaying all the doctors at once
            system("cls");
            printf("\t\t\tSurgery\n\n");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            int lin;
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            surptr= fopen("surgery.txt","rb+");
            fread(&y,sizeof(struct doctor),1,surptr);
            while(!feof(surptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,surptr);
            }
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            fclose(surptr);


            printf("\n\n\t\t\tEmergency\n\n");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            emeptr= fopen("emergency.txt","rb+");
            fread(&y,sizeof(struct doctor),1,emeptr);
            while(!feof(emeptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,emeptr);
            }
            fclose(emeptr);
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");


            printf("\n\n\t\t\tCardiology\n\n");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            cardptr= fopen("cardiology.txt","rb+");
            fread(&y,sizeof(struct doctor),1,cardptr);
            while(!feof(cardptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,cardptr);
            }
            fclose(cardptr);
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");


            printf("\n\n\t\t\tNeurology\n\n");
            printf("%-15s%-20s%-20s%-17s\n\n","ID","Name","Age","Address");
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            neuptr= fopen("neurology.txt","rb+");
            fread(&y,sizeof(struct doctor),1,neuptr);
            while(!feof(neuptr)){
                printf("%-15d%-20s%-20d%-17s\n",y.id,y.name,y.age,y.address);
                i++;
                fread(&y,sizeof(struct doctor),1,neuptr);
            }

            fclose(neuptr);
            for(lin=0;lin<=119;lin++){
            printf("-");
            }
            printf("\n");
            printf("\n\n Press any key to continue ");
            getch();
            system("cls");
            break;
        }
    }


}

int login(){
    int p=0;
    char username[50];
    char password[50];
    printf("\n\n\t\t\t !!! CONFIDENTIAL DATA !!!\n");
    printf("\n\t\t   ENTER USERNAME AND PASSWORD TO CONTINUE");
    printf("\n\t\t  -----------------------------------------\n");
    printf("\n\n\t\tUsername : ");
    fflush(stdin);
    gets(username);

    printf("\n\n\t\tPassword : ");
    do{
        password[p]=getch();
        if(password[p]!='\r'){
            printf("*");
        }
        p++;
    }while(password[p-1]!='\r');

    password[p-1]='\0';
    if(strcmp(password,"abc")==0  &&  strcmp(username,"lll")==0){
        return 1;
    }
    else return 0;

}



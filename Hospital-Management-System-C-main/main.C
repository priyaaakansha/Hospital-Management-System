#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char ans='y';
int ok;
int b, valid=0;

//FUNCTION DECLERATION
void WelcomeScreen();//WelcomeScreen function decleration
void Title();//Title function decleration
void MainMenu();//MainMenu function decleration
void LoginScreen();//LoginScreen function decleration
void Add_rec();//Add_rec function declaration
void func_list();//function to list the patient details
void Search_rec();//Search_rec function declaration
void Edit_rec();//Edit_rec function declaration
void Dlt_rec();//Dlt_rec function declaration
void ex_it();//exit function declaration

struct patient//list of global variable
{
	int age;
	char Name[20];
	char Doctor[20];
	char Disease[20];
	char test[20];
	char medicine[20];

};

struct patient  p,temp_c;



void main()
{

    WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function




}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void) //function for welcome screen
{

	printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\t WELCOME TO\t\t#");
	printf("\n\t\t\t\t#   DIAGNOSTIC TEST MANAGEMENT SYSTEM    #");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();//Use to holds screen for some seconds
	clrscr();//Use to clear screen

}

// Main Menu
void MainMenu(void)//function decleration
{
	clrscr();
	int choose;
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);

	switch(choose)//switch to differeht case
	{

		case 1: Add_rec();//Add_rec function is called
			break;

		case 2: func_list();
			break;

		case 3: Search_rec();//View_rec function is call
			break;

		case 4: Edit_rec();//Edit_rec function is call
			break;

		case 5:	Dlt_rec();//Dlt_rec function is call
			break;

		case 6:	ex_it();//ex_it function is call
			break;

		default: printf("\t\t\tInvalid entry. Please enter right option :)");
			 getch();//holds screen
	}//end of switch


}
/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	clrscr();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();//holds screen

}




/* **************************************ADD RECORD*******************************************/

void Add_rec()
{
	clrscr();
	//list of variables
	char ans;
	FILE *ek;//file pointer
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");

	printf("\nEnter Name: ");
	scanf("%s",p.Name);


/* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);

    printf("Disease: ");
    scanf("%s",p.disease);

/* ********************************************** Prescribed Doctor **************************************** */

    printf("\n\t\t\tPrescribed Doctor:");
    scanf("%s",p.Doctor);

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed

    getch();
}
/* **************************************VIEW RECORD*******************************************/
void func_list()
{
	clrscr();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");

		printf("Disease: ");
		printf("Prescribed Doctor\n");
		printf("=================================================================================================================");

		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.Name, &p.age, p.Problem, p.Doctor)!=EOF)
		{
			printf("Full Name: %s",p.Name);
			printf("Age: %i",p.age);
			printf("%s",p.Disease);
			printf("%s",p.Doctor);
		}
		fclose(ek);
		getch();
		MainMenu();
}
void Search_rec(void)
{
	char name[20];
	clrscr();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!!\n");
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",name);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.Name, &p.age, p.Disease, p.Doctor)!=EOF)
	{
		if(strcmp(p.Name,name)==0)
		{

			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Contact No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Problem");
			gotoxy(95,15);
			printf("Prescribed Doctor\n");
			printf("=================================================================================================================");
			gotoxy(1,18);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(25,18);
			printf("%c",p.Gender);
			gotoxy(32,18);
			printf("%i",p.age);
			gotoxy(37,18);
			printf("%s",p.Address);
			gotoxy(52,18);
			printf("%s",p.Contact_no);
			gotoxy(64,18);
			printf("%s",p.Email);
			gotoxy(80,18);
			printf("%s",p.Problem);
			gotoxy(95,18);
			printf("%s",p.Doctor);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(p.First_Name,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_rec();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		MainMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}

void Edit_rec(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.dat","w+");
	   ek=fopen("Record2.dat","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Patient : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			MainMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
		{
			if(strcmp(p.First_Name, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
				gotoxy(12,22);	
				printf("Enter New First Name: ");
				scanf("%s",p.First_Name);    
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",p.Last_Name);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&p.Gender);
				p.Gender=toupper(p.Gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&p.age);
				gotoxy(12,30);
				printf("Enter Address: ");
				scanf("%s",p.Address);
				p.Address[0]=toupper(p.Address[0]);
				gotoxy(12,32);
				printf("Enter Contact no: ");
				scanf("%s",p.Contact_no);
				gotoxy(12,34);
				printf("Enter New email: ");
				scanf("%s",p.Email);
			    gotoxy(12,36);
				printf("Enter Problem: ");
				scanf("%s",p.Problem);
				p.Problem[0]=toupper(p.Problem[0]);
			    gotoxy(12,38);
				printf("Enter Doctor: ");
			    scanf("%s",p.Doctor);
			    p.Doctor[0]=toupper(p.Doctor[0]);
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("Record2.dat");
   	   rename("temp2.dat","Record2.dat");
		getch();
		MainMenu();		
}
void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
		else 
		{
			printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		MainMenu();
	}
} 

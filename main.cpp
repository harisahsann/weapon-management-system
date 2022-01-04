/*
Haris Ahsan
Software Engineer

	UserName1: Haris Ahsan,  Password: "182"
	UserName2: "Apple" Password:"Grey"
	UserName3: "Snake" Password: "Knife"
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "credentials.h"
#pragma comment(lib, "WinMM.lib")

#define SIZE 100

//  ************************************* FUNCTION PROTOTYPES ************************************* //

void createDatabase();
void dataInput(int type);
void insertData();
void deleteData();
void searchData(char name[]);
void updateData(char name[]);

void insertStart(char name[], char manufacturer[], char category[], int rounds, float calibre, float muzzelVelocity);
void delStart();

void insertEnd(char name[], char manufacturer[], char category[], int rounds, float calibre, float muzzelVelocity);
void delEnd();

void insertMid(char name[], char manufacturer[], char category[], int rounds, float calibre, float muzzelVelocity, int position);
void delMid(int position);

// void populate_database();
void export_database();

void traversal();
int countLen();

bool login();

//  ************************************* Structure of Database ************************************* //
struct Node
{
	char name[SIZE];
	char category[SIZE];
	char manufacturer[SIZE];

	int rounds;
	float calibre;
	float muzzelVelocity;

	struct Node *link;
};
struct Node *head = NULL;

//  ************************************* ************* ************************************* //

//  ************************************* MAIN FUNCTION ************************************* //

int main()
{

	first();

	system("pause");

	system("cls");
	// populate_database();

	bool verify = login();

	// variabales
	int choice = 0;
	char name[SIZE];
	yellow();
	printf("\n\t\t\t\tPress 1 to Create Database: \n\t\t\t\tPress 2 to Exit :\n");

	scanf("%d", &choice);
	if (choice == 1)
	{
		createDatabase();
	}
	else if (choice == 2)
	{
		exit(0);
	}
	else
	{
		system("cls");
		main();
	}

	system("cls");
	do
	{
		system("pause");

		system("cls");
		yellow();
		printf("\n\t\t\t\tPress 1 to Insert Record\n\t\t\t\tPress 2 to Delete Record\n\t\t\t\tPress 3 to Search any Record\n\t\t\t\tPress 4 to Display all Records\n\t\t\t\tPress 5 to Update Record\n\t\t\t\tPress 6 to Export whole database to csv file\n\t\t\t\tPress 7 to Exit :\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			system("cls");
			insertData();

			break;
		case 2:
			system("cls");
			deleteData();

			break;
		case 3:
			system("cls");
			printf("\n\t\t\t\tEnter the name of weapon to be searched: ");
			(void)getchar();
			scanf("%[^\n]%*c", name);
			_strupr(name);
			searchData(name);

			break;
		case 4:
			system("cls");
			traversal();
			 
			break;
		case 5:
			system("cls");
			printf("\n\t\t\t\tEnter the name of weapon to be updated: ");
			(void)getchar();
			scanf("%[^\n]%*c", name);
			_strupr(name);
			updateData(name);

			break;
		case 6:
			system("cls");
			export_database();
			 
			break;
		case 7:
		 
			exit(0);
		default:
			printf("\n\t\t\t\tPlease enter valid input.\n\n\t\t\t\t************\n\n");
			 
		}

	} while (choice != 7);

} // MAIN END

//  ************************************* ******************** ************************************* //

//  ************************************* END OF MAIN FUNCTION ************************************* //

// **************************************** LOGIN FUNCTION *****************************************
bool login()
{
	bool valid_creds = false;
	char name[SIZE_C];
	char password[SIZE_C];

	do
	{
		cyan();
		printf("\n\n\n\t\t\t\t************ Enter Login Details ************\n");
		printf("\n\t\t\t\tEnter Name (or enter 0 to exit) :");
		fgets(name, SIZE_C, stdin);
		if (strcmp("0", strtok(name, "\n")) != 0)
		{
			printf("\n\t\t\t\tEnter Password :");
			fgets(password, SIZE_C, stdin);
		}
		else
		{
			exit(12);
		}
	} while (strcmp("0", strtok(name, "\n")) != 0 && !verify_credentials(name, password));

	if (strcmp("0", strtok(name, "\n")) != 0)
	{
		valid_creds = true;
		green();
		printf("\t\t\t\t\t\t\tSuccessfully Logged in...\n");
	}

	return valid_creds;
}
// **************************************** END LOGIN FUNCTION *****************************************

// **************************************** EXPORT FUNCTION *****************************************
void export_database()
{
	if (head == NULL)
	{
		red();
		printf("Database is Empty.\n");
		 
		return;
	}

	FILE *file = fopen("data.csv", "w+");

	if (file != NULL)
	{
		blue();
		printf("\n\n\n\t\t\t\t************ File is successfully created and opened. ************\n\n");
		fprintf(file, "Name, Category, Manufacture, Rounds, Calibre, Velocity\n");
		struct Node *temp = head;
		while (temp != NULL)
		{
			int value = fprintf(file, "%s, %s, %s, %d, %f, %f\n",
								temp->name, temp->category, temp->manufacturer, temp->rounds, temp->calibre, temp->muzzelVelocity);
			if (value < 0)
			{
				red();
				printf("\n\t\t\t\t%s could not be written.\n", temp->name);
				 
			}

			temp = temp->link;
		}
		fclose(file);
	}
}

/*void populate_database() {
	insertStart("Shotgun", "F&K", "Guns", 12, 12.0, 876.0);
	insertStart("Revolver", "F&K", "Pistols", 9, 9.0, 643.0);
	insertStart("MK-15", "F&K", "Guns", 24, 10.0, 299.0);
	insertStart("AK-47", "F&K", "Guns", 48, 24.0, 994.0);
	insertStart("Eagle", "Black Magic", "Pistols", 12, 9.0, 1022.0);
}*/

//---------------------------- INSERT AT START ----------------------------//
void insertStart(char name[], char manufacturer[], char category[], int rounds, float calibre, float muzzelVelocity)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->rounds = rounds;
	newNode->calibre = calibre;
	newNode->muzzelVelocity = muzzelVelocity;
	strcpy(newNode->name, name);
	strcpy(newNode->category, category);
	strcpy(newNode->manufacturer, manufacturer);
	newNode->link = head;
	head = newNode;
}

//---------------------------- DELETE START ----------------------------//
void delStart()
{
	if (head == NULL)
	{ // check if list is already empty
		red();
		printf("\n\t\t\t\t************ List is empty already! ************\n\n\n");
		return;
	}

	struct Node *tip = head;
	head = head->link;
	printf("\n\t\t\t\tRecord Deleted Successfully!...\n");
	free(tip);
}

//---------------------------- INSERT AT END ----------------------------//
void insertEnd(char name[], char manufacturer[], char category[], int rounds, float calibre, float muzzelVelocity)
{
	struct Node *node = head;
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->link = NULL;

	while (node->link != NULL)
	{
		node = node->link;
	}
	node->link = newNode;

	newNode->rounds = rounds;
	newNode->calibre = calibre;
	newNode->muzzelVelocity = muzzelVelocity;
	strcpy(newNode->name, name);
	strcpy(newNode->category, category);
	strcpy(newNode->manufacturer, manufacturer);
}

//---------------------------- DELETE AT END ----------------------------//
void delEnd()
{
	struct Node *node = head;

	if (node == NULL)
	{ // check if list is already empty
		red();
		printf("\n\t\t\t\t************ List is empty already! ************\n\n");
	 
		return;
	}

	struct Node *tip = node;

	while (node->link != NULL)
	{
		tip = node;
		node = node->link;
	}

	if (node == head)
	{
		head = NULL;
	}
	else
	{
		tip->link = NULL;
	}
	printf("\n\t\t\t\tRecord Deleted Successfully!...\n");
	free(node);
}

//---------------------------- COUNTER ----------------------------//
int countLen()
{

	struct Node *node = head;
	int count = 1;

	while (node->link != NULL)
	{
		node = node->link;
		count++;
	}

	return count;
}

//---------------------------- TRAVERSAL ----------------------------//
void traversal()
{
	struct Node *P = head;

	purple();
	printf("\n\t\t\t\t____________________Display____________________\n\n");
	int count = 1;
	printf("\tNAME\t\t|\tCATEGORY\t|\tMANUFACTURER\t|\tROUND\t|\tCALIBRE\t|\tMUZZEL VELOCITY\n\a");
	cyan();
	while (P != NULL)
	{
		printf("\t%d. ", count);
		printf("%s\t|\t", P->name);
		printf("%s\t|\t", P->category);
		printf("%s", P->manufacturer);
		printf("\t|\t%d\t|\t%.2f (mm)\t|\t%.2f (m/s)\n", P->rounds, P->calibre, P->muzzelVelocity);
		P = P->link;
		count++;
	}
	purple();
	printf("\n\t\t\t\t______________________END______________________\n\n");
}

//---------------------------- INSERT at Nth Position ----------------------------//
void insertMid(char name[], char manufacturer[], char category[], int rounds, float calibre, float muzzelVelocity, int position)
{
	struct Node *node = head;
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	if (position == 1)
	{
		insertStart(name, manufacturer, category, rounds, calibre, muzzelVelocity);
		return;
	}
	else if (position > countLen() + 1)
	{
		red();
		printf("\n\t\t\t\t************ Can't put at this position.! ************\n");
	 
		return;
	}

	int count = 1;
	while (count < position - 1)
	{

		node = node->link;
		count++;
	}
	newNode->link = node->link;
	node->link = newNode;

	newNode->rounds = rounds;
	newNode->calibre = calibre;
	newNode->muzzelVelocity = muzzelVelocity;
	strcpy(newNode->name, name);
	strcpy(newNode->category, category);
	strcpy(newNode->manufacturer, manufacturer);
}

//---------------------------- Delete at Nth Position ----------------------------//
void delMid(int position)
{
	struct Node *node = head;
	if (position == 1)
	{
		delStart();
		return;
	}
	else if (position > countLen() + 1)
	{
		red();
		printf("Invalid Position.");
		return;
	}

	struct Node *tip = node;

	int count = 1;
	while (count < position)
	{
		tip = node;
		node = node->link;
		count++;

		if (node == NULL)
		{
			break;
		}
	}

	if (node != NULL)
	{

		tip->link = node->link;
		node->link = NULL;
	}
	printf("\n\t\t\t\tRecord Deleted Successfully!...\n");
	free(node);
}

//--------------- To Create First Node of Linked List  -- OR -- To Create First Record in Database ---------------//
void createDatabase()
{
	char name[SIZE];
	char category[SIZE];
	char manufacturer[SIZE];

	int rounds;
	float calibre;
	float muzzelVelocity;

	// declaring first node of linked list
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

	// getting inputs at the first node
	green();
	printf("\n\t\t\t\tEnter the name of Weapon: ");
	(void)getchar();
	scanf("%[^\n]%*c", name);
	_strupr(name);
	printf("\n\t\t\t\tType Category: ");
	scanf("%[^\n]%*c", category);
	printf("\n\t\t\t\tType the name of Manufacturer: ");
	scanf("%[^\n]%*c", manufacturer);

	printf("\n\t\t\t\tEnter the No. of Rounds: ");
	scanf("%d", &rounds);
	printf("\n\t\t\t\tEnter the Calibre in (mm): ");
	scanf("%f", &calibre);
	printf("\n\t\t\t\tEnter the Muzzel Velocity in (m/s): ");
	scanf("%f", &muzzelVelocity);

	// passing data to first node
	temp->rounds = rounds;
	temp->calibre = calibre;
	temp->muzzelVelocity = muzzelVelocity;
	strcpy(temp->name, name);
	strcpy(temp->category, category);
	strcpy(temp->manufacturer, manufacturer);

	temp->link = NULL; // adding null to link for now
	head = temp;	   // assigning head to first node
}

//--------------- For Getting Input in Variables ---------------//
void dataInput(int type)
{
	int position;
	char name[SIZE];
	char category[SIZE];
	char manufacturer[SIZE];

	int rounds;
	float calibre;
	float muzzelVelocity;

	// declaring first node of linked list
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

	green();
	// getting inputs at the first node
	printf("\n\t\t\t\tEnter the name of Weapon: ");
	(void)getchar();
	scanf("%[^\n]%*c", name);
	_strupr(name);
	printf("\n\t\t\t\tType Category: ");
	scanf("%[^\n]%*c", category);
	printf("\n\t\t\t\tType the name of Manufacturer: ");
	scanf("%[^\n]%*c", manufacturer);

	printf("\n\t\t\t\tEnter the No. of Rounds: ");
	scanf("%d", &rounds);
	printf("\n\t\t\t\tEnter the Calibre in (mm): ");
	scanf("%f", &calibre);
	printf("\n\t\t\t\tEnter the Muzzel Velocity in (m/s): ");
	scanf("%f", &muzzelVelocity);

	if (type == 1)
	{
		insertStart(name, manufacturer, category, rounds, calibre, muzzelVelocity);
	}
	else if (type == 2)
	{
		printf("\n\t\t\t\tEnter the position where do you want to insert record: ");
		scanf("%d", &position);
		insertMid(name, manufacturer, category, rounds, calibre, muzzelVelocity, position);
	}
	else if (type == 3)
	{
		insertEnd(name, manufacturer, category, rounds, calibre, muzzelVelocity);
	}
}

//----------------------- INSERT DATA ----------------------- //
void insertData()
{
	int choice = 0;

	cyan();
	printf("\n\t\t\t\tPress 1 to Insert at Start\n\t\t\t\tPress 2 to Insert at Desired Position\n\t\t\t\tPress 3 to Insert at End");
	scanf("%d", &choice);
 

	if (choice == 1)
	{
		dataInput(1);
	}
	else if (choice == 2)
	{
		traversal();
		dataInput(2);
	}
	else if (choice == 3)
	{
		dataInput(3);
	}
	else
	{
		return;
	}
}

//----------------------- DELETE DATA ----------------------- //
void deleteData()
{
	int choice = 0;
	int position;

	red();
	printf("\n\t\t\t\tPress 1 to Delete from Start\n\t\t\t\tPress 2 to Delete from Desired Position\n\t\t\t\tPress 3 to Delete from End");
	scanf("%d", &choice);
 
	if (choice == 1)
	{
		delStart();
	}
	else if (choice == 2)
	{
		traversal();
		printf("\n\t\t\t\tEnter the position which you want to delete: ");
		scanf("%d", &position);
		delMid(position);
	}
	else if (choice == 3)
	{
		delEnd();
	}
	else
	{
		return;
	}
}

//----------------------- SEARCH FUNCTION ----------------------- //
void searchData(char name[])
{
	struct Node *P = head;

	blue();
	while (P != NULL)
	{
		if (strcmp(name, P->name) == 0)
		{
			printf("\n\n\t\t\t\t---- Record found successfully! ----");
			printf("\n\t\t\t\tWeapon: %s", P->name);
			printf("\n\t\t\t\tCategory: %s", P->category);
			printf("\n\t\t\t\tManufacturer: %s", P->manufacturer);
			printf("\n\t\t\t\tRounds: %d\n\t\t\t\tCalibre: %.2f (mm)\n\t\t\t\tMuzzel Velocity: %.2f (m/s)\n\n", P->rounds, P->calibre, P->muzzelVelocity);
			break;
		}
		P = P->link;
	}
	if (P == NULL)
	{
		red();
		printf("\n\t\t\t\tSorry! Record NOT found...\n\n");
	}
}

//----------------------- UPDATE FUNCTION ----------------------- //
void updateData(char name[])
{
	struct Node *P = head;
	int choice = 0;

	while (P != NULL)
	{
		if (strcmp(name, P->name) == 0)
		{

			green();
			do
			{
				printf("\n\t\t\t\tPress 1 to Update Category\n\t\t\t\tPress 2 to Update Manufacturer\n\t\t\t\tPress 3 to Update Rounds\n\t\t\t\tPress 4 to Update Calibre\n\t\t\t\tPress 5 to Update Muzzel Velocity\n\t\t\t\tPress 6 to goto Main Menu\n");
				scanf("%d", &choice);
			 

				if (choice == 1)
				{
					printf("\n\t\t\t\tType Category: ");
					(void)getchar();
					scanf("%[^\n]%*c", P->category);
					printf("\n\t\t\t\tRecord Updated Successfully!...\n");
				}
				else if (choice == 2)
				{
					printf("\n\t\t\t\tType the name of Manufacturer: ");
					(void)getchar();
					scanf("%[^\n]%*c", P->manufacturer);
					printf("\n\t\t\t\tRecord Updated Successfully!...\n");
				}
				else if (choice == 3)
				{

					printf("\n\t\t\t\tEnter the No. of Rounds: ");
					scanf("%d", &P->rounds);
					printf("\n\t\t\t\tRecord Updated Successfully!...\n");
				}
				else if (choice == 4)
				{
					printf("\n\t\t\t\tEnter the Calibre in (mm): ");
					scanf("%f", &P->calibre);
					printf("\n\t\t\t\tRecord Updated Successfully!...\n");
				}
				else if (choice == 5)
				{
					printf("\n\t\t\t\tEnter the Muzzel Velocity in (m/s): ");
					scanf("%f", &P->muzzelVelocity);
					printf("\n\t\t\t\tRecord Updated Successfully!...\n");
				}
				else if (choice == 6)
				{
					break;
				}
			} while (choice != 6);

			break;
		}
		P = P->link;
	}
	if (P == NULL)
	{
		red();
		printf("\n\t\t\t\tSorry! Record NOT found...\n\n");
	 
	}
}

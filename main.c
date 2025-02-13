/*
Name : Arun Cyriac
Date : 12-02-2025
Description : Inverted-Search
An inverted index is a database index that maps content, like words or numbers, to their locations in a document,
table, or set of documents.*/
#include "main.h"
int main(int argc, char *argv[])
{
	int option, up = 0;
	char choose;
	f_list *head = NULL;
	c_db arr[27];

	for (int i = 0; i < 27; i++)
	{
		arr[i].key = i;
		arr[i].m_link = NULL;
	}
	if (argc <= 1)
	{
		printf("Error : Insufficient Arguements\n\nUsage : ./a.out <textfile name1> <textfile name2>\n");
		return 0;
	}
	else
	{
		if (read_and_validate(argc, argv, &head) == e_success)

			while (1)
			{
				printf("1. Create DataBase\n2. Display DataBase\n3. Search DataBase\n4. Save DataBase\n5. Update DataBase\n6. Exit\nEnter your choice : ");
				scanf("%d", &option);
				switch (option)
				{
				case 1:
					if (up == 0)
					{
						up = 1;

						if (create(head, arr) == e_success)
							printf("Info : DataBase Created Successfully\n\n");
						else
							printf("Error : Failed To Create Database\n\n");
					}
					else
						printf("Error : DataBase Is already created\n\n");
					break;
				case 2:

					display(arr);
					break;
				case 3:

					if (search(arr) == DATA_NOT_FOUND)
						printf("Error : Word Not Found\n\n");
					break;
				case 4:

					if (save(arr) == e_success)
						printf("Info : Database Saved Successfully\n\n");
					else
						printf("Error : Failed To Save Database\n\n");
					break;
				case 5:
					if (up == 0)
					{
						up = 1;

						if (update(arr) == e_success)
							printf("Info : Database Updated Successfully\n");
						else
							printf("Error : Failed To Update Database\n");
					}
					else
						printf("Info : DataBase Is already updated\n\n");
					break;
				case 6:
					printf("Info : Exit Successfully\n");
					return 0;
					break;
				default:
					printf("Error : Invalid choice.\n\n Please enter a valid option.\n");
					break;
				}
			}
		return 0;
	}
}

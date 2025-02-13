#include "main.h"

int flag = 0; //flag for duplicate file
status read_and_validate(int argc, char *argv[], f_list **head)
{
	for (int i = 1; i < argc; i++)
	{
		if (open_files(argv[i]) == e_success)
		{
			printf("Info : file %s open successfully\n\n",argv[i]);
			
			f_list *new = malloc(sizeof(f_list));
			if (*head == NULL)
			{
				*head = new;
				strcpy(new->f_name, argv[i]);
				new->link = NULL;
			}
			else
			{
				f_list *temp = *head;
				f_list *prev = NULL;
				while (temp != NULL)
				{
					if (strcmp(temp->f_name, argv[i]) == 0)
					{
						printf("Error : %s file is duplicate\n\n", argv[i]);
						flag = 1;
						break;
					}
					prev = temp;
					temp = temp->link;
				}
				if (flag == 0)
				{
					strcpy(new->f_name, argv[i]);
					prev->link = new;
					new->link = NULL;
				}
				flag = 0;
			}
		}
		else
		{
			printf("Error : file does not exist %s\n\n", argv[i]);
			// return e_failure;
		}
	}
	printf("Info : file open successful\n\n");
	return e_success;
}
/*open file function definition*/
status open_files(char *argv)
{
	FILE *fptr = fopen(argv, "r");
	if (fptr != NULL)
	{
		if (strcmp((strstr(argv, ".")), ".txt") == 0)
		{
			fseek(fptr, 0, SEEK_END);
			if (ftell(fptr) != 0)
			{
				fclose(fptr);
				return e_success;
			}
			else
			{
				printf("Error :file is empty %s\n\n", argv);
				return e_failure;
			}
		}
		else
		{
			printf("Error : file does not have .txt extension %s\n\n", argv);
			return e_failure;
		}
	}
	else
	{
		//printf("Error : file does not exist %s\n", argv);
		return e_failure;
	}
}
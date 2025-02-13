#include "main.h"
#include <stdlib.h>
status update(c_db *hash_t)
{
	char newfile[100], c;
	int index;
	printf("Enter the file to update: \n");
	scanf("%s", newfile);
	FILE *fptr = fopen(newfile, "r");
	if (fptr == NULL)
	{
		printf("Error : File not found\n");
		return e_failure;
	}
	while (fscanf(fptr, "%s", newfile) != EOF)
	{
		if (newfile[0] != '#')
			return e_failure;
		index = atoi(strtok(&newfile[1], ";"));
		m_node *m_new = malloc(sizeof(m_node));
		if (m_new == NULL)
		{
			return e_failure;
		}
		m_new->m_main_link = NULL;
		strcpy(m_new->word, strtok(NULL, ";"));
		m_new->file_count = atoi(strtok(NULL, ";"));
		s_node *s_new = malloc(sizeof(s_node));
		s_node *stemp;
		if (s_new == NULL)
		{
			return e_failure;
		}
		s_new->s_sub_link = NULL;
		strcpy(s_new->file_name, strtok(NULL, ";"));
		s_new->word_count = atoi(strtok(NULL, ";"));
		m_new->m_sub_link = s_new;
		stemp = s_new;
		for (int i = 0; i < (m_new->file_count) - 1; i++)
		{
			s_node *s_new = malloc(sizeof(s_node));
			if (s_new == NULL)
			{
				return e_failure;
			}
			s_new->s_sub_link = NULL;
			strcpy(s_new->file_name, (strtok(NULL, ";")));
			s_new->word_count = atoi(strtok(NULL, ";"));
			stemp->s_sub_link = s_new;
			stemp = s_new;
		}
		m_node *temp = hash_t[index].m_link;
		if (temp == NULL)
		{
			hash_t[index].m_link = m_new;
		}
		else
		{
			while (temp->m_main_link)
			{
				temp = temp->m_main_link;
			}
			temp->m_main_link = m_new;
		}
	}
	fclose(fptr);
	return e_success;
}

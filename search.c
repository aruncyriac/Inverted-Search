#include "main.h"
status search(c_db *hash_t)
{
	char w[30];
	int key;
	printf("Enter the word you want to search\n");
	scanf("%s", w);
	key = tolower(w[0]) % 97;
	if (key > 25 || key < 0)
		key = 26;
	m_node *temp = hash_t[key].m_link;
	if (temp == NULL)
		return DATA_NOT_FOUND;

	while (temp != NULL)
	{
		if (strcmp(temp->word, w) == 0)
		{
			printf("The %s is present in (%d) files\n", w, temp->file_count);
			s_node *stemp = temp->m_sub_link;
			while (stemp != NULL)
			{
				printf("%s -> %d times\n", stemp->file_name, stemp->word_count);
				stemp = stemp->s_sub_link;
			}
			return e_success;
		}
		temp = temp->m_main_link;
	}
	return DATA_NOT_FOUND;
}

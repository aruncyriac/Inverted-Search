#include "main.h"

// function to display the contents
status display(c_db *hash_t)
{
    printf("%s\t%s\t  %s\t%s\t%s\n", "Index", "Word", "Filecount", "Files Name", "Wordcount");
    for (int key = 0; key < 27; key++)
    {
        m_node *temp2 = hash_t[key].m_link;
        while (temp2 != NULL)
        {
            printf("[%d]\t%-15s\t%d\t", key, temp2->word, temp2->file_count);
            s_node *stemp = temp2->m_sub_link;
            while (stemp != NULL)
            {
                printf("%s\t\t%d\t", stemp->file_name, stemp->word_count);
                stemp = stemp->s_sub_link;
            }
            printf("\n");
            temp2 = temp2->m_main_link;
        }
    }
    return e_success;
}

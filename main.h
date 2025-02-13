#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>
#include<ctype.h>

#define DATA_NOT_FOUND -2
#define DATA_FOUND -1
typedef enum
{
    e_success,
    e_failure
}status;

typedef struct subnode
{
    int word_count;
    char file_name[30];
    struct subnode *s_sub_link;
}s_node;

typedef struct mainnode
{
    int file_count;
    char word[30];
    struct mainnode *m_main_link;
    s_node *m_sub_link;
}m_node;

typedef struct filenode
{
    char f_name[30];
    struct filenode *link;
}f_list;

typedef struct create_db
{
    int key;
    m_node *m_link;
}c_db;

status read_and_validate(int argc, char *argv[], f_list **head);

status open_files(char *argv);

status create(f_list *head, c_db *arr);

status display(c_db *hash_t);

status search(c_db *hash_t);

status save(c_db *hash_t);

status update(c_db *hash_t);

char *mystrtok(char *str);

status searchfile_db(c_db *hash_t,f_list **head);

#endif

#include "todoes.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init_todoes(todo_list *list_ptr)
{
   list_ptr -> temp_todo = NULL;
   list_ptr -> length_of_todo_list = 0;
}

void destroy_todoes(todo_list *list_ptr)
{
    free(list_ptr->temp_todo);
    list_ptr->temp_todo = NULL;
    list_ptr -> length_of_todo_list = 0;
}

void add_todo(todo_list *list_ptr, int ischecked, char task, unsigned int priority)
{
    int new_length = list_ptr -> length_of_todo_list + 1;
    list_ptr -> temp_todo = realloc(list_ptr->temp_todo, sizeof(todo) * new_length);
    list_ptr -> length_of_todo_list = new_length;

    strcpy(list_ptr->temp_todo[new_length - 1].task, task);
    list_ptr->temp_todo[new_length - 1].ischecked = ischecked;
    list_ptr->temp_todo[new_length - 1].priority = priority;

}

int print_todoes(todo_list *list_ptr)
{
    if (list_ptr == NULL)
        return -1;

    for (int i = 0; i < list_ptr->length_of_todo_list; i++) {
            printf("Num\t|\tTasks\t|\tPrio\n");
            printf("%d - [%d] %s - %d", i +1,
                                            list_ptr->temp_todo[i].ischecked,
                                            list_ptr->temp_todo[i].task,
                                            list_ptr->temp_todo[i].priority);
    }
    return;
}

int write_todoes_to_file(todo_list *list_ptr, char *path)
{
    if (list_ptr == NULL || path == NULL)
    return -1;

    FILE *tempfile = fopen(path, "w");
    if (tempfile == NULL)
    return -1;

    for (int i = 0; i < list_ptr->length_of_todo_list; i++) {
        fprintf(tempfile, "%c %s %d\n",
                            list_ptr->temp_todo[i].ischecked,
                            list_ptr->temp_todo[i].task,
                            list_ptr->temp_todo[i].priority);
    }

    fclose(tempfile);
    return 0;
}

int read_todoes_from_file(todo_list *list_ptr, char *path)
{

    if (list_ptr == NULL || path == NULL)
        return -1;

    FILE *tempfile = fopen(path, "r");
    if (tempfile == NULL)
        return -1;

    char task[255];
    int ischecked;
    unsigned int priority;

    while(fscanf(tempfile, "%d %s %d\n", ischecked, task, priority) == 5) {
        add_todo(list_ptr, ischecked, task, priority);
    }

    fclose(tempfile);
    return 0;

}



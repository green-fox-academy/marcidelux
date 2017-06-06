#ifndef TODOES_H_INCLUDED
#define TODOES_H_INCLUDED

#define CHECKED 1 //checked task
#define NOTCHECKED 0 // unchecked task

typedef struct{
    char task[255];
    int ischecked;
    unsigned int priority;
}todo;

typedef struct{
    todo *temp_todo;
    unsigned int length_of_todo_list;
}todo_list;

void init_todoes(todo_list *list_ptr);
void destroy_todoes(todo_list *list_ptr);
void add_todo(todo_list *list_ptr, int ischecked, char task, unsigned int priority);
int print_todoes(todo_list *list_ptr);
int write_todoes_to_file(todo_list *list_ptr, char *path);
int read_todoes_from_file(todo_list *list_ptr, char *path);




#endif // TODOES_H_INCLUDED

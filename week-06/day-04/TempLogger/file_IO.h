#ifndef FILE_IO_H_INCLUDED
#define FILE_IO_H_INCLUDED

void print_menu ();
void open_log(FILE *f, char *path);
void close_log(FILE *f);
void save_log(FILE *f, char *row);

#endif // FILE_IO_H_INCLUDED

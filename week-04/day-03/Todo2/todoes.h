#ifndef TODOES_H_INCLUDED
#define TODOES_H_INCLUDED

#endif // TODOES_H_INCLUDED

typedef struct{
    char task[255];
    uint8_t ischecked:1;
    int priority;
}todo;

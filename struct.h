#ifndef STRUCT_H
#define STRUCT_H

#define NAME_LEN 20
#define MAX_PARTS 100

struct part{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

#endif // STRUCT_H


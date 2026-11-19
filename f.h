#ifndef F_H
#define F_H

#include "struct.h"
//Check whether the part number exists in data base.
int check_exist(int part_number);

//insert a new part if the part number does not exist in data base.
void insert_f(void);

//Search for a part number.
void search_f(void);

//update quantity on hand for a part number.
void update_f(void);

//print data base.
void print_f(struct part inventory[], int arr_index);
#endif // F_H

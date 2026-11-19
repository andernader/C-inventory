#include <stdio.h>
#include "struct.h"
#include "f.h"
#include "debug_f.h"

struct part inventory[MAX_PARTS];

int database_index = 0; //this indicate how many elements we have stored in our data base.


int main(void){
    char op_code;

    while(1){
        printf("Enter operation code: ");
        scanf(" %c", &op_code);

        //we take by each line only one command!, if we have any other user input
        //on that same line we ignore and empty the line buffer.
        PRINT_DEBUG_LOCATION();
        PRINT_DEBUG_MSG("Before getchar until '\n'");
        while(getchar() != '\n')
            ;
        PRINT_DEBUG_MSG("after");
        switch(op_code){
            case 'i': insert_f();PRINT_DEBUG_MSG("insert_f() called.");break;
            case 's': search_f();PRINT_DEBUG_MSG("search_f() called.");break;
            case 'u': update_f();PRINT_DEBUG_MSG("update_f() called.");break;
            case 'p': print_f(inventory, database_index);PRINT_DEBUG_MSG("print_f() called.");break;
            case 'q': return 0;
            default: printf("Undefind operation code!\n");break;
        }
    }
}

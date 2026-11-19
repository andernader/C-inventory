#include <stdio.h>
#include "readline.h"
#include "f.h"
#include "debug_f.h"

extern int database_index;
extern struct part inventory[];

int check_exist(int part_number){
    for(int i = 0; i < database_index; i++){
        if(part_number == inventory[i].number)
            return i;
    }
    return -1;
}

void insert_f(void){
    int part_number;
    PRINT_DEBUG_LOCATION();
    printf("Enter part number: ");
    scanf("%d", &part_number);

    if(database_index >= MAX_PARTS){
        fprintf(stderr, "Error! database space is full!\n\n");
        return;
    }

    if(check_exist(part_number) >= 0){
        fprintf(stderr, "Error! part number exist before, cant create a new part with the same part number!\n\n");
        return;
    }

    inventory[database_index].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[database_index].name, NAME_LEN + 1);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[database_index].on_hand);
    printf("\n");
    database_index++;
    return;
}

void search_f(void){
    int part_number;
    printf("Enter part number: ");
    scanf("%d", &part_number);

    int i = check_exist(part_number);

    if(i < 0){
        fprintf(stderr, "Error! part does not exist!\n\n");
        return;
    }

    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n\n", inventory[i].on_hand);
    return;
}

void update_f(void){
    int part_number;
    printf("Enter part number: ");
    scanf("%d", &part_number);

    int change;
    int i = check_exist(part_number);
    if(i < 0){
        fprintf(stderr, "Error! part does not exist!\n");
        return;
    }
    printf("\tPart name: %s\n", inventory[i].name);
    printf("\tQuantity on hand: %d\n", inventory[i].on_hand);

    printf("Enter change in quantity: ");
    scanf("%d", &change);
    printf("\n");
    inventory[i].on_hand += change;

    return;
}

void print_f(struct part inventory[], int arr_index){
    printf("%-15s%-25s%-20s\n", "Part number", "Part name", "Quantity on hand");
    for(int i = 0; i < arr_index; i++)
        printf("%-15d%-25s%-20d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    printf("\n");
    return;
}

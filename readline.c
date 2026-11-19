#include <stdio.h>
#include <ctype.h>
#include "readline.h"
#include "debug_f.h"

int read_line(char line[], int length) {
    int temp_char, i = 0;
    int flag_buffer_full = 0;
    PRINT_DEBUG_LOCATION();
    if (length <= 0)
        return 0;

    // Consume leading whitespace.
    while (1) {
        //This means we have directly EOF we did not store anything yet!
        if ((temp_char = getchar()) == EOF)
            return EOF;

        if (!isspace((unsigned char)temp_char))
            break;
    }

    // Store the first non-whitespace character.
    line[i++] = temp_char;

    // Read until newline, EOF, or buffer is full.
    while (1) {
        temp_char = getchar();

        if (temp_char == EOF || temp_char == '\n')
            break;

        if (i >= length - 1) {
            flag_buffer_full = 1;
            break;
        }

        line[i++] = temp_char;
    }

    // Terminate the string.
    line[i] = '\0';
    PRINT_DEBUG(line);
    // Remove trailing whitespace.
    while (i > 0 && isspace((unsigned char)line[i - 1]))
        i--;

    line[i] = '\0';

    // Consume remaining characters only if buffer filled.
    if (flag_buffer_full) {
        while ((temp_char = getchar()) != '\n' && temp_char != EOF)
            ;
    }

    return i;
}


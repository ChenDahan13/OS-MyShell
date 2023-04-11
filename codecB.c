#include <stdio.h>
#include "codecB.h"

// Converts all char to the 3-rd next char
void convert_up(char* text) {
    int i = 0;
    while(text[i] != 0) {
        text[i] = text[i] + 3;
        i++;
    }
}

// Converts all char to the 3-rd before char
void convert_down(char* text) {
    int i = 0;
    while(text[i] != 0) {
        text[i] = text[i] - 3;
        i++;
    }
}
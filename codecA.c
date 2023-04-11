#include <stdio.h>
#include <ctype.h>
#include "codecA.h"

void turn_lower_or_upper_case(char* text) {
    int i = 0;
    while(text[i] != 0) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = toupper(text[i]);
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = tolower(text[i]);
        }
        i++;
    }
}


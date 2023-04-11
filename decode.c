#include <stdio.h>
#include <string.h>
#include "codecA.h"
#include "codecB.h"

int main(int argc, char* argv[]) {
    
    if(argc < 3) { // Checks right sum of arguments
        printf("Usage: encode/decode <codec> <message>\n");
        return 1;
    }

    if(argc == 3) { // Regular case
        
        if(strcmp(argv[1], "codecA") == 0) {
            turn_lower_or_upper_case(argv[2]);
            printf("decoded %s\n", argv[2]);
        } else if(strcmp(argv[1], "codecB") == 0) {
            convert_down(argv[2]);
            printf("decoded %s\n", argv[2]);
        } else {
            printf("Invalid flag: %s\n", argv[1]);
            return 1;
        }
        return 0;

    } else if (argc == 4) { // Support encode and then decode
        
        if(strcmp(argv[1], "encode") == 0) {
            printf("decoded encoded %s\n", argv[3]); // don't need to change the text
            return 0;
        } else {
            printf("Invalid flag: %s\n", argv[1]);
            return 1;
        }
    }
    printf("Too much arguments\n");
    return 1;
}
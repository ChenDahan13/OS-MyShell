#include <stdio.h>
#include <ctype.h>
#include <string.h>

int cmp(FILE*, FILE*, int);

int cmp(FILE* file1, FILE* file2, int ignore) {
    char letter1, letter2;
    int read1, read2;
    
    // Reading 1 letter from the files
    read1 = fread(&letter1, sizeof(char), 1, file1);
    read2 = fread(&letter2, sizeof(char), 1, file2);
    
    while(read1 > 0 && read2 > 0) { 
        
        if(ignore) { // Lower case is the same like upper case
            letter1 = tolower(letter1);
            letter2 = tolower(letter2);
        }
        
        if(letter1 != letter2) // Not the same letter
            return 1;

        read1 = fread(&letter1, sizeof(char), 1, file1);
        read2 = fread(&letter2, sizeof(char), 1, file2);
    }

    if(read1 != read2) // Files aren't the same size 
        return 1;
    
    return 0; // Files exactly the same
}


int main(int argc, char *argv[]) {
    int ignore = 0, ver = 0, i;
    
    if(argc < 3) { // Checks sum of arguments from terminal
        printf("Usage: cmp <file1> <file2> [-v] [-i]\n");
        return 1;
    }

    for(i = 3; i < argc; i++) { // Checks right arguments from terminal
        if(strcmp(argv[i], "-v") == 0)
            ver = 1;
        else if(strcmp(argv[i], "-i") == 0)
            ignore = 1;
        else {
            printf("Invalid flag: %s\n", argv[i]);
            return 1;
        }
    }

    FILE* file1 = fopen(argv[1], "r");
    if(file1 == NULL) {
        printf("File1 was not opened\n");
        return 1;
    }
    FILE* file2 = fopen(argv[2], "r");
    if(file2 == NULL){
        printf("File2 was not opened\n");
        return 1;
    }
    
    
    int num = cmp(file1,file2, ignore);
    printf("%d ", num);
    
    if(ver) {
        if(!num)
            printf("equal\n");
        else
            printf("distinct\n");
    }
    
    fclose(file1);
    fclose(file2);
    return num;
}
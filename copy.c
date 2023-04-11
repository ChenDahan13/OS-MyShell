#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int checkIfFileExist(char*);
void copy(FILE*, FILE*);

int checkIfFileExist(char* filename) {
    struct stat buffer;
    int exist = stat(filename, &buffer);
    if(exist == 0)
        return 1;
    else
        return 0;
}

void copy(FILE* oldone, FILE* newone) {
    char letter;
    letter = fgetc(oldone);
    while(letter != EOF) {
        fputc(letter, newone);
        letter = fgetc(oldone);
    }
}

int main(int argc, char *argv[]) {
    int ver = 0, force = 0, i;

    if(argc < 3) { // Checks sum of arguments from terminal
        printf("Usage: copy <file1> <file2> [-v] [-f]\n");
        return 1;
    }

    for(i = 3; i < argc; i++) { // Checks right arguments from terminal
        if(strcmp(argv[i], "-v") == 0)
            ver = 1;
        else if(strcmp(argv[i], "-f") == 0)
            force = 1;
        else {
            printf("Invalid flag: %s\n", argv[i]);
            return 1;
        }
    }
    
    // Checks if the first file exist
    int existfile1 = checkIfFileExist(argv[1]);
    if(!existfile1) {
        printf("The file you want to copy is not exist\n");
        return 1;
    }

    FILE* file1 = fopen(argv[1], "r");
    if(file1 == NULL) {
        printf("File1 was not opened\n");
        return 1;
    }

    int existfile2 = checkIfFileExist(argv[2]); 
    
    // Will copy the file if not exist or force was given
    if(!existfile2 || force) {
        FILE* file2 = fopen(argv[2], "w");
        if(file2 == NULL) {
            printf("File2 was not opened\n");
            return 1;
        }
        copy(file1, file2);
        if(ver)
            printf("success\n");
        fclose(file2);
    }
    else {
        printf("File2 is exist\n");
        return 1;
    }
    fclose(file1);
    return 0;
}
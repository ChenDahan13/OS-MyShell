#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "stdio.h"
#include "errno.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <signal.h>



void signal_handler(int sig) {
    printf("Caught signal %d\n", sig);
}


int main() {
	int i;
	char *argv[10];
	char command[1024];
	char *token;

	while (1) {

        signal(SIGINT, signal_handler);

	    printf("myshell> ");
        
	    fgets(command, 1024, stdin);
	    command[strlen(command) - 1] = '\0'; // Replace \n with \0

        if(strcmp(command, "q") == 0) {
            printf("Exit shell\n");
            break;
        }

	    // Parse command line 
	    i = 0;
	    token = strtok(command," ");
	    while (token != NULL) {
            argv[i] = token;
            token = strtok(NULL, " ");
            i++;
	    }
	    argv[i] = NULL;

	    // Is command empty 
	    if (argv[0] == NULL)
		    continue;

        pid_t pid = fork();

        if(pid == -1) {
            printf("Can't fork, error occurred\n");
            exit(1);
        } else if (fork() == 0) { 
            execvp(argv[0], argv); // The child proccess does the file
            printf("Error executing command\n");
            exit(1);
	    } else {
            wait(NULL);   
        }  
	}
    return 0;
}
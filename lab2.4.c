#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void promptName() {
	char name[10];

	printf("Please enter your name: ");
	fgets(name, 10, stdin);

	printf("Your name : %s", name);
	printf("\n");
}

int main(void) {
	for(int i = 1; i < 5; i++) {
        	pid_t pid = fork();

		if(pid == 0) {
			promptName();
			exit(0);
		}
		else if(pid > 0) {
			printf("Waiting for child processes to finish...\n");
			wait(NULL);
		}
		else {
			printf("Unable to create child process.");
		}

	}
	printf("Job is done.\n");

	return EXIT_SUCCESS;
}

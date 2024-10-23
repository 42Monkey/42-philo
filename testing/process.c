#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	int id = fork();
	if (id == 0)
	{
		printf("Hello from child process\n");
		fork();
		printf("Banana\n");
	}
	else
	{
		printf("Hello from parent process\n");
		printf("Penguin\n");
		printf("Monkey\n");
	}
	// if (id != 0)
	// {
	// 	while (wait(NULL) > 0);
	// }
	return (0);
}

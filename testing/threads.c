#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int monkeys = 0;

void* routine ()
{
	int i = 0;

	while (i < 100000000)
	{
		monkeys++;
		i++;
	}
	return (NULL);
}

int main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);

	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (2);

	if (pthread_join(t1, NULL) != 0)
		return (3);

	if (pthread_join(t2, NULL) != 0)
		return (4);

	// pthread_detach(t1);
	// pthread_detach(t2);
	printf("number of monkeys: %d\n", monkeys);
	return (0);
}

/**
 * use pthread_detach if you don't need to synchronize with the thread and want its resources to be automatically cleaned up.
 * use pthread_join if you need to wait for the thread to finish and clean up its resources manually.
 */

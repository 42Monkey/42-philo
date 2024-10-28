#include "../include/philo.h"

// TO DO

/*
 * routine - handles eating, sleeping and thinking
 * return NULL when philosopher dies or meal limit is reached
 */



void	routine(void *clone)
{
	// wait for all threads to be created
	// prevent deadlock
	// check if philosopher should die
	// check if meal limit reached
	// try to eat
	// sleep
	// think
}

static int	routine_action(t_philo *philo)
{
	// take fork
	// check if should die or not before eating
	// eat
	// release forks

}

static void	routine_status(t_data *sim, int id, char *status)
{
	// print philo status with timestamp
}

static void	routine_sleep(int *ms)
{
	// philo sleeps for specified ms
}

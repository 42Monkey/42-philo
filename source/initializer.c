#include "../include/philo.h"

int	init_param(int argc, char **argv, t_data *simulation)
{
	simulation->number_of_philosophers = philo_atoi(argv[1]);
	simulation->time_to_die = philo_atoi(argv[2]);
	simulation->time_to_eat = philo_atoi(argv[3]);
	simulation->time_to_sleep = philo_atoi(argv[4]);

	// allocate memory for the forks
	simulation->forks = malloc(sizeof(pthread_mutex_t) * simulation->number_of_philosophers);
	if (!simulation->forks)
		philo_error(simulation, ERROR_MALLOC);

	if (argc == 6)
		simulation->limit_meals = philo_atoi(argv[5]);
	else
		simulation->limit_meals = -1;
	return (0);
}

/*
 * Initializes all mutexes in the simulation.
 */
int	init_mutexes(t_data *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->number_of_philosophers)
	{
		if (!pthread_mutex_init(&simulation->forks[i], NULL))
			philo_error(simulation, ERROR_MUTEX);
		i++;
	}
	if (!pthread_mutex_init(&simulation->mutex_print, NULL))
		philo_error(simulation, ERROR_MUTEX);
	if (!pthread_mutex_init(&simulation->mutex_death, NULL))
		philo_error(simulation, ERROR_MUTEX);
	return (0);
}

int	init_philosophers(t_data *simulation)
{
}

int	init_simulation(t_data *simulation)
{
}

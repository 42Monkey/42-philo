#include "../include/philo.h"

/*
 * initialize simulation parameters from arguments
 */
static int	init_param(int argc, char **argv, t_data *simulation)
{
	simulation->number_of_philosophers = philo_atoi(argv[1]);
	simulation->time_to_die = philo_atoi(argv[2]);
	simulation->time_to_eat = philo_atoi(argv[3]);
	simulation->time_to_sleep = philo_atoi(argv[4]);

	// allocate memory for the forks
	simulation->fork = malloc(sizeof(pthread_mutex_t) * simulation->number_of_philosophers);
	if (!simulation->fork)
		philo_error(simulation, ERROR_MALLOC);

	if (argc == 6)
		simulation->limit_meals = philo_atoi(argv[5]);
	else
		simulation->limit_meals = -1;
	return (0);
}

/*
 * initialize mutexes for forks, print and death
 */
static int	init_mutexes(t_data *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->number_of_philosophers)
	{
		if (pthread_mutex_init(&simulation->fork[i], NULL) != 0)
			philo_error(simulation, ERROR_MUTEX);
		i++;
	}
	if (pthread_mutex_init(&simulation->mutex_print, NULL) != 0)
		philo_error(simulation, ERROR_MUTEX);
	if (pthread_mutex_init(&simulation->mutex_death, NULL) != 0)
		philo_error(simulation, ERROR_MUTEX);
	return (0);
}

/*
 * initialize philosopher structures
 */
static int	init_philosophers(t_data *simulation)
{
	int	i;

	i = 0;
	simulation->philosophers = (t_philo *)malloc(sizeof(t_philo) * simulation->number_of_philosophers);
	if (!simulation->philosophers)
		philo_error(simulation, ERROR_MALLOC);
	while (i < simulation->number_of_philosophers)
	{
		simulation->philosophers[i].id = i + 1;
		simulation->philosophers[i].times_eaten = 0;
		simulation->philosophers[i].time_last_meal = 0;
		simulation->philosophers[i].fork_left = &simulation->fork[i];
		simulation->philosophers[i].fork_right = &simulation->fork[(i + 1) % simulation->number_of_philosophers];
		simulation->philosophers[i].data = (struct t_data *)simulation;
		i++;
	}
	return (0);
}

/*
 * create threads for each philosopher
 * wait for all philosopher threads to finish
 */
// static int	init_thread(int argc, char **argv, t_data *simulation)
// {
// 	// TO DO
// }

/*
 * initialize the entire simulation
 */
int	philo_simulation(int argc, char **argv, t_data *simulation)
{
	init_param(argc, argv, simulation);
	init_mutexes(simulation);
	init_philosophers(simulation);
	// init_thread(argc, argv, &simulation);
	return (0);
}

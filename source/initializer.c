#include "../include/philo.h"

/*
 * initialize sim parameters from arguments
 * allocate memory for the forks
 */
static int	init_param(int argc, char **argv, t_data *sim)
{
	sim->count = philo_atoi(argv[1]);
	sim->time_to_die = philo_atoi(argv[2]);
	sim->time_to_eat = philo_atoi(argv[3]);
	sim->time_to_sleep = philo_atoi(argv[4]);
	sim->fork = malloc(sizeof(pthread_mutex_t) * sim->count);
	if (!sim->fork)
		philo_error(sim, ERROR_MALLOC);
	if (argc == 6)
		sim->limit_meals = philo_atoi(argv[5]);
	else
		sim->limit_meals = -1;
	return (0);
}

/*
 * initialize mutexes for forks, print and death
 */
static int	init_mutexes(t_data *sim)
{
	int	i;

	i = 0;
	while (i < sim->count)
	{
		if (pthread_mutex_init(&sim->fork[i], NULL) != 0)
			philo_error(sim, ERROR_MUTEX);
		i++;
	}
	if (pthread_mutex_init(&sim->mutex_print, NULL) != 0)
		philo_error(sim, ERROR_MUTEX);
	if (pthread_mutex_init(&sim->mutex_death, NULL) != 0)
		philo_error(sim, ERROR_MUTEX);
	return (0);
}

/*
 * initialize philosopher structures
 */
static int	init_philosophers(t_data *sim)
{
	int	i;

	i = 0;
	sim->philo = (t_philo *)malloc(sizeof(t_philo) * sim->count);
	if (!sim->philo)
		philo_error(sim, ERROR_MALLOC);
	while (i < sim->count)
	{
		sim->philo[i].id = i + 1;
		sim->philo[i].times_eaten = 0;
		sim->philo[i].time_last_meal = 0;
		sim->philo[i].fork_left = &sim->fork[i];
		sim->philo[i].fork_right = &sim->fork[(i + 1) % sim->count];
		sim->philo[i].data = (struct s_data *)sim;
		i++;
	}
	return (0);
}

/*
 * create threads for each philosopher (pthread_create)
 * wait for all philosopher threads to finish (pthread_join)
 */
static int	init_thread(t_data *sim)
{
	int	i;

	sim->status = 1;
	sim->start = philo_clock();
	i = 0;
	while (i < sim->count)
	{
		pthread_create(&sim->philo[i].thread, NULL, philo_routine, &sim->philo[i]);
		i++;
	}
	i = 0;
	while (i < sim->count)
	{
		pthread_join(sim->philo[i].thread, NULL);
		i++;
	}
	return (0);
}

/*
 * initialize the entire sim
 */
int	philo_sim(int argc, char **argv, t_data *sim)
{
	init_param(argc, argv, sim);
	init_mutexes(sim);
	init_philosophers(sim);
	init_thread(sim);
	return (0);
}

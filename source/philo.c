#include "../include/philo.h"

/*
 * initialize the sim structure to zero
 * parse and validate command-line arguments
 * initialize the sim
 */
int	main(int argc, char **argv)
{
	t_data	sim;

	memset(&sim, 0, sizeof(t_data));
	philo_parser(argc, argv);
	philo_sim(argc, argv, &sim);
	philo_cleanup(&sim);
	return (0);
}

void	philo_error(t_data *sim, char *message)
{
	philo_putstr_fd(message, STDERR_FILENO);
	if (sim != NULL)
		philo_cleanup(sim);
	exit (EXIT_FAILURE);
}

void	philo_cleanup(t_data *sim)
{
	int	i;

	i = 0;
	if (sim->fork)
	{
		while (i < sim->count)
		{
			pthread_mutex_destroy(&sim->fork[i]);
			i++;
		}
		free(sim->fork);
	}
	if (sim->philo)
		free (sim->philo);
	pthread_mutex_destroy(&sim->mutex_print);
	pthread_mutex_destroy(&sim->mutex_death);
}

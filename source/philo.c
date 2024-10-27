#include "../include/philo.h"

/*
 * initialize the simulation structure to zero
 * parse and validate command-line arguments
 * initialize the simulation
 */

int	main(int argc, char **argv)
{
	t_data	simulation;

	memset(&simulation, 0, sizeof(t_data));
	philo_parser(argc, argv);
	philo_simulation(argc, argv, &simulation);

	philo_cleanup(&simulation);
	return (0);
}

void	philo_error(t_data *simulation, char *message)
{
	philo_putstr_fd(message, STDERR_FILENO);
	if (simulation != NULL)
		philo_cleanup(simulation);
	exit (EXIT_FAILURE);
}


void	philo_cleanup(t_data *simulation)
{
	int	i;

	i = 0;
	if (simulation->fork)
	{
		while (i < simulation->number_of_philosophers)
		{
			pthread_mutex_destroy(&simulation->fork[i]);
			i++;
		}
		free(simulation->fork);
	}
	if (simulation->philosophers)
		free (simulation->philosophers);

	pthread_mutex_destroy(&simulation->mutex_print);
	pthread_mutex_destroy(&simulation->mutex_death);
}



#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	simulation;

	philo_args(argc, argv);
	philo_init(argc, argv, &simulation);
}

void	philo_error(t_data *simulation, char *message)
{
	(void)simulation;
	philo_putstr_fd(message, STDERR_FILENO);
	/*
	 * free allocated memory for philo if applicable
	 * free allocated memory for forks if applicable
	 * - destroy each fork mutex before freeing
	 * destroy other mutexes if they have been initialized
	 * - use pthread_mutex_destroy function
	 */
	exit (EXIT_FAILURE);
}

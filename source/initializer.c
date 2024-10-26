#include "../include/philo.h"

int	philo_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 5 && argc != 6)
		philo_error(NULL, ERROR_ARGS);
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				philo_error(NULL, ERROR_DIGIT);
			j++;
		}
		if (philo_atoi(argv[i]) < 0)
			philo_error(NULL, ERROR_NEGATIVE);
		i++;
	}
	if (philo_atoi(argv[1]) < 1)
		philo_error(NULL, ERROR_N_PHILO);
	return (0);
}

int	philo_init(int argc, char **argv, t_data *simulation)
{
	simulation->number_of_philosophers = philo_atoi(argv[1]);
	simulation->time_to_die = philo_atoi(argv[2]);
	simulation->time_to_eat = philo_atoi(argv[3]);
	simulation->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		simulation->limit_meals = philo_atoi(argv[5]);
	else
		simulation->limit_meals = -1;
	return (0);
}

#include "../include/philo.h"

int	init_param(int argc, char **argv, t_data *simulation)
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

int	init_mutexes(t_data *simulation)
{

}

int	init_philosophers(t_data *simulation)
{

}

int	init_simulation(t_data *simulation)
{

}

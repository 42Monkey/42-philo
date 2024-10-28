#include "../include/philo.h"

// TO DO

static void	fork_on(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_right);
		pthread_mutex_lock(philo->fork_left);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		pthread_mutex_lock(philo->fork_right);
	}
}

static void	fork_off(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

static void	timestamp(t_data *sim, int id, char *status)
{
	long long	timestamp;

	timestamp = philo_clock() - sim->start;
	printf("%lld %d %s\n", timestamp, id, status);
}

static void	routine_sleep(int ms)
{
	usleep(ms * 1000);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*sim;

	philo = (t_philo *)arg;
	sim = philo->data;
	while (sim->status)
	{
		fork_on(philo);
		timestamp(sim, philo->id, "is eating");
		philo->time_last_meal = philo_clock();
		routine_sleep(sim->time_to_eat);
		fork_off(philo);
		if (sim->limit_meals != -1 && philo->times_eaten >= sim->limit_meals)
			return (NULL);
		timestamp(sim, philo->id, "is sleeping");
		routine_sleep(sim->time_to_sleep);
		timestamp(sim, philo->id, "is thinking");
	}
	return (NULL);
}

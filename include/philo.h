#ifndef PHILO_H
# define PHILO_H

# include <string.h> // memset
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h>

typedef struct s_philo
{
	int						id;
	int						fork_left;
	int						fork_right;
	int						meals_eaten;
	pthread_mutex_t			mutex_fork;
	pthread_mutex_t			mutex_eat;
	struct s_simulation		*sim;
}	t_philo;

typedef struct s_simulation
{
	int						num_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_meals;
	pthread_mutex_t			mutex_print;
	pthread_mutex_t			mutex_death;
	t_philo					*philosophers;
	struct timeval			start_time;
}	t_simulation;

#endif

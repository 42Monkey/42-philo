#ifndef PHILO_H
# define PHILO_H

# include <string.h> // memset
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h>

/*
 * t_philo
 * represents a single philosopher in the simulation
 * each philosopher is a thread that needs two forks to eat
 * time tracking is in milliseconds for death prevention
 */
typedef struct s_philo
{
	int						id;
	int						times_eaten;
	long long				ms_last_meal;
	pthread_t				thread;
	pthread_mutex_t			*fork_left;
	pthread_mutex_t			*fork_right;
	struct s_simulation		*data;
}	t_philo;

/*
 * t_simulation
 * main simulation structure containing shared data
 * holds simulation parameters, synchronization primitives
 * and arrays of philosophers and forks
 * all times are in milliseconds (ms)
 */
typedef struct s_simulation
{
	int						number_of_philosophers; // = number of forks
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						limit_meals; // optional
	int						running;
	long long				ms_start;
	pthread_mutex_t			*forks;
	pthread_mutex_t			print_mutex;
	t_philo					*philosophers;
}	t_simulation;

#endif

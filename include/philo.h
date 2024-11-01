#ifndef PHILO_H
# define PHILO_H

# include <string.h> // memset
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h>

# define MAX_PHILO 200

# define ERROR_DIGIT "Error: All arguments must be positive integers.\n"
# define ERROR_N_PHILO "Error: The number of philosophers must be greater than 0.\n"
# define ERROR_NEGATIVE "Error: Negative values are not allowed for any arguments.\n"
# define ERROR_ARGS "Error: invalid arguments\n\n" \
"\t ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [meal_limit]\n\n" \
"\t <number_of_philosophers>: Number of philosophers must be greater than 0.\n" \
"\t <time_to_die>: Time (in ms) before a philosopher dies without eating.\n" \
"\t <time_to_eat>: Time (in ms) a philosopher takes to eat.\n" \
"\t <time_to_sleep>: Time (in ms) a philosopher spends sleeping.\n" \
"\t [meal_limit]: Number of meals each philosopher must eat (optional).\n\n"

# define ERROR_MALLOC "Error: Memory Allocation Failed\n"
# define ERROR_MUTEX "Error: Mutex Initialization Failed\n"
# define ERROR_THREAD "Error: Thread Creation Failed\n"


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
	long long				time_last_meal;
	pthread_t				thread;
	pthread_mutex_t			*fork_left;
	pthread_mutex_t			*fork_right;
	struct s_data			*data;
}	t_philo;

/*
 * t_data
 * main simulation structure containing shared data
 * holds simulation parameters, synchronization primitives
 * and arrays of philosophers and forks
 * all times are in milliseconds (ms)
 */
typedef struct s_data
{
	int						count; // = number of forks
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						limit_meals; // optional
	int						status;
	long long				start;
	pthread_mutex_t			*fork;
	pthread_mutex_t			mutex_print;
	pthread_mutex_t			mutex_death;
	t_philo					*philo;
}	t_data;

int			philo_parser(int argc, char **argv);
int			philo_sim(int argc, char **argv, t_data *simulation);

void		philo_error(t_data *simulation, char *message);
void		philo_cleanup(t_data *simulation);

// routine
void		*philo_routine(void *arg);

// time
long long	philo_clock(t_data *sim);

// utils
size_t		philo_strlen(const char *str);
void		philo_putstr_fd(char *s, int fd);
void		philo_putchar_fd(char c, int fd);
void		philo_putnbr_fd(int n, int fd);
int			philo_atoi(const char *nptr);

#endif

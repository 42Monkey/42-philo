#include "../include/philo.h"

/*
 * get current time of the day
 * convert seconds to milliseconds
 * convert microseconcs to milliseconds and add to the total
 * tz set as NULL
 */
long long	philo_clock(void)
{
	struct timeval	tv;
	long long		ms_time;

	gettimeofday(&tv, NULL);
	ms_time = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return (ms_time);
}

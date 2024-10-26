#include "../include/philo.h"

size_t	philo_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	philo_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	philo_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	philo_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		philo_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		philo_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		philo_putnbr_fd(n / 10, fd);
	}
	philo_putchar_fd(n % 10 + '0', fd);
}

int	philo_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuyar <cuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:40:15 by cuyar             #+#    #+#             */
/*   Updated: 2024/06/30 22:28:51 by cuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

static void	send_signal(pid_t id, char *message)
{
	int	i;
	int	j;
	char	result;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			result = (message[i] >> j) & 1;
			if (result == 1)
				kill(id, SIGUSR1);
			else if (result == 0)
				kill(id, SIGUSR2);
			usleep(100);
			j--; 
		}
		i++;
	}
}

int main(int ac, char *av[])
{
	pid_t	server_id;
	
	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		send_signal(server_id, av[2]);
	}
	else
		write(1, "the requested number of arguments was not entered", 50);
	return (0);
}
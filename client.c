/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/26 23:32:09 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_format(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("\x1B[31m❌INVALID PID");
			return (1);
		}
		i++;
	}
	return (0);
}

void	tobinary(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (128 >> i & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(600);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (check_format(av[1]))
			return (0);
		while (av[2][i])
		{
			tobinary(av[2][i], pid);
			i++;
		}
	}
	else
		ft_putstr("\x1B[31m❌INVALID FORMAT: TRY ./client + pid + \"string\"");
	return (0);
}

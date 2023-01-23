/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/23 03:32:48 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int sig)
{
	ft_putstr("message delivered successfully ✅");
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
		signal(SIGUSR2, sighandler);
		usleep(500);
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
		while (av[2][i])
		{
			tobinary(av[2][i], pid);
			i++;
		}
		tobinary(0, pid);
	}
	return (0);
}

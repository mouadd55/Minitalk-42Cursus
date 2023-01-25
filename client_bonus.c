/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:16:13 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/24 23:28:14 by moudrib          ###   ########.fr       */
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
		usleep(300);
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

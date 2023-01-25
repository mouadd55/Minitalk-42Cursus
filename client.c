/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/25 00:35:29 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_format(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (!(('0' > str[i]) && '9' > str[i]))
		{
			ft_putstr("❌INVALID FORMAT: TRY ./client + pid + \"string\"");
			return (1);
		}
		i++;
	}
	return (0);
}

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

#include <string.h>
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
		tobinary(0, pid);
	}
	else
		ft_putstr("❌INVALID FORMAT: TRY ./client + pid + \"string\"");
	return (0);
}

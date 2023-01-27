/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:36:47 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/26 19:35:13 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	usr_handler(int sig, siginfo_t *info, void *ptr)
{
	static char		c;
	static int		i;
	static pid_t	pid;

	(void)ptr;
	if (pid != info->si_pid)
	{
		i = 0;
		c = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		c |= 128 >> i;
	i++;
	if (i == 8)
	{
		if (c == 0)
			kill(pid, SIGUSR2);
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = usr_handler;
	pid = getpid();
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_putstr("\x1B[33mProcess ID:\x1B[0m"" ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
}

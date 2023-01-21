/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/20 19:33:50 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void tobinary(char *str, int pid)
{
	int i;
	int j;

	j = 0;
	while (str[j])
	{
		i = -1;
		while (++i < 8)
		{
			if (128 >> i & str[j])
			{
				kill(pid, SIGUSR1);
				// write(1, "1", 1);
			}
			else
			{
				kill(pid, SIGUSR2);
				// write(1, "0", 1);
			}
			// signal();
			usleep(700);
		}
		j++;
	}
}

int main(int ac, char **av)
{
	int pid;

	pid = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		tobinary(av[2], pid);
	}
	return (0);
}

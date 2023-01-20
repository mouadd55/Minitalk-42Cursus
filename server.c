/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:26 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/20 03:29:44 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int sig)
{
	write (1, "No", 2);
	(void)sig;
}

int main ()
{	
	struct sigaction	saction;
    pid_t pid;

    pid = getpid();
    ft_putstr("Process ID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGINT, handler);
    while (1)
		pause();
}
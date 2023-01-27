/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:07 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/26 23:31:28 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(unsigned int nbr);
int		ft_strlen(char *str);
int		check_format(char *str);
void	sighandler(int sig);
void	tobinary(char c, int pid);
void	usr_handler(int sig, siginfo_t *info, void *ptr);

#endif
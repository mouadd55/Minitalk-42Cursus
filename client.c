/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:13:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/01/14 22:08:43 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


int main ()
{
    // int pid = 0;

    // printf("Enter the process id: ");
    // scanf("%d", &pid);
    // kill(pid , SIGINT);
	
   char str[80] = "Hello World!";
   const char s[2] = " ";
   char **token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   printf("%c", token[1]);
   return(0);
}

#include "minitalk.h"

// int main(int ac, char **av) 
// {
// 	if (ac == 2)
// 	{
// 		int i = 0;
// 		int j = 0;
// 		int bit = 128;
// 		int ch = 0;

// 		while (av[1][j])
// 		{
// 			while (i < 8)
// 			{
// 				if (av[1][j] && av[1][j] == '1')
// 					ch += bit;
// 				else if (av[1][j] && av[1][j] == '0')
// 					ch += 0;
// 				bit /= 2;
// 				i++;
// 				j++;
// 			}
// 			printf("%c", ch);
// 			ch = 0;
// 			i = 0;
// 			bit = 128;
// 			if (av[1][j] != '\0')
// 				j++;
// 		}
// 	}
//     return 0;
// }

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = -1;
		int j = 0;
		char c = 0;
		while (av[1][j])
		{
			while (++i < 8)
			{
				if (av[1][j] == '1')
					c |= 128 >> i;
				j++;
			}
			printf("%c", c);
			i = -1;
			c = 0;
			if (av[1][j] == ' ')
				j++;
		}
	}
	return (0);
}
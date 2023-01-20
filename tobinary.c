#include <stdio.h>

// int main (int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int		j;
// 		int		i;
// 		char	c;
// 		char	arr[8];

// 		j = 0;
// 		while (av[1][j])
// 		{
// 			i = 0;
// 			c = av[1][j];
// 			if (c < 64)
// 				printf("00");
// 			else
// 				printf("0");
// 			while (c)
// 			{
// 				arr[i++] = c % 2;
// 				c /= 2;
// 			}
// 			while (--i >= 0)
// 				printf("%d", arr[i]);
// 			j++;
// 			if (av[1][j])
// 				printf(" ");
// 		}
// 	}
// 	return (0);
// }


int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		int j;

		i = -1;
		j = 0;
		while (av[1][j])
		{
			while (++i < 8)
			{
				if (128 >> i & av[1][j])
					printf("1");
				else
					printf("0");
			}
			i = -1;
			j++;
			if (av[1][j])
				printf(" ");
		}
	}
	return (0);
}
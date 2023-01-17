#include <stdio.h>

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int		j;
		int		i;
		char	c;
		char	arr[8];

		j = 0;
		while (av[1][j])
		{
			i = 0;
			c = av[1][j];
			if (c < 64)
				printf("00");
			else
				printf("0");
			while (c)
			{
				arr[i++] = c % 2;
				c /= 2;
			}
			while (--i >= 0)
				printf("%d", arr[i]);
			j++;
			if (av[1][j])
				printf(" ");
		}
	}
	return (0);
}




			// if (arr[i] != '\x01')
			// 	arr[i] = '\0';
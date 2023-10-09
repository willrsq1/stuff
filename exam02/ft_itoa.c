
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


char *ft_itoa(int nb)
{
	if (nb == INT_MIN)
		return ("-2147483648");
	if (nb == 0)
		return ("0");

	char *s = malloc(100);
	int i = 0;

	if (nb < 0)
	{
		nb = -nb;
		s[0] = '-';
		i++;
	}

	long modulo = 100000000000;
	while (nb < modulo)
		modulo = modulo / 10;
	printf("NB = %d, MODULO = %ld\n", nb, modulo);
	while (nb || modulo)
	{
		printf("%ld\n", nb / modulo);
		s[i] = nb / modulo + 48;
		nb = nb % modulo;
		modulo = modulo / 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}
int main(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	int a = atoi(argv[1]);

	printf("%d and %s\n", a, ft_itoa(a));
	return 0;
}

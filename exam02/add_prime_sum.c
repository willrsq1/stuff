#include <unistd.h>

int	ft_atoi(char *s)
{
	long result = 0;
	int i = 0;
	
	while (s[i] && s[i] == '+')
		i++;
	if (!s[i])
		return (-1);
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + s[i] - 48;
		i++;
		if (result > 2147483647)
			return (-1);
	}
	if (s[i] != '\0')
		return (-1);
	return (result);
}

int		ft_is_prime(int nb)
{
	int i = 2;

	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	char	*str = "0123456789";

	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &str[nb % 10], 1);
}

int main(int argc, char  *argv[])
{
	int nb;
	int i = 2;
	int	result = 0;



	if (argc == 2 && ft_atoi(argv[1]) != -1)
	{
		nb = ft_atoi(argv[1]);
		while (i <= nb)
		{
			if (ft_is_prime(i))
				result += i;
			i++;
		}
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return 0;
}

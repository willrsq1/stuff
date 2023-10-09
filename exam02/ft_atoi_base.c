#include <unistd.h>

int	ft_is_valid(char c, int str_base)
{
	char *str = "0123456789abcdef";

	int	i = 0;
	while (i < str_base)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_nb(char c, int str_base)
{
	char *str = "0123456789abcdef";

	int i = 0;

	while (i < str_base)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *s, int str_base)
{
	long result = 0;
	int i = 0;
	int sign = 1;


	while (s[i])
	{
		if (s[i] >= 'A' || s[i] <= 'Z')
			s[i] = s[i] + 32;
		i++;
	}


	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}


	while (s[i])
	{
		if (ft_is_valid(s[i], str_base))
			result = result * str_base + ft_get_nb(s[i], str_base);
		i++;
	}
	return (result * sign);
}


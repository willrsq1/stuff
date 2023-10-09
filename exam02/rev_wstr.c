#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void	ft_putstr(char *s)
{
	int i;

	i =0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char **ft_split(char *s)
{
	char **tab;

	tab = malloc(100000);
	int i = 0;
	int j = 0;
	int line = 0;
	while (s && s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (!s[i])
			break ;
		tab[line] = malloc(10000);
		j = 0;
		while (s[i] && s[i] != '\t' && s[i] != ' ')
		{
			tab[line][j] = s[i];
			i++;
			j++;
		}
		tab[line][j] = '\0';
		line++;
	}
	tab[line] = NULL;
	return (tab);
}


int main(int argc, char *argv[])
{
	char **tab;

	int i;

	if (argc == 2 && argv[1][0])
	{
		tab =ft_split(argv[1]);
		i = 0;
		while (tab[i])
			i++;
		i = i - 1;
		while (i > 0)
		{
			ft_putstr(tab[i]);
			write(1, " ", 1);
			i--;
		}
		ft_putstr(tab[0]);

	}
	write(1, "\n", 1);
	return 0;
}

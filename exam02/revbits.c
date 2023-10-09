#include <unistd.h>
#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void reverse_bits(unsigned char octet)
{
	
}


int main()
{
	int a = 124;

	print_bits(a);

	write(1, "\n", 1);
	reverse_bits(124);
	return 0;
}

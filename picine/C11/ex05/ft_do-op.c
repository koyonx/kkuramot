/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:41:11 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/02 20:28:16 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	result = 0;
	count = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * count);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	do_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/' && b != 0)
		return (a / b);
	if (op == '%' && b != 0)
		return (a % b);
	return (0);
}

void	print_result(int a, int b, char op)
{
	if (op == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	else if (op == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_putnbr(do_op(a, b, op));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 4 && argv[2][1] == '\0')
		print_result(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0]);
	else if (argc == 4 && (argv[2][1] != '\0' || argv[2][0] != '+'
			|| argv[2][0] != '-' || argv[2][0] != '*' || argv[2][0] != '%'
			|| argv[2][0] != '/'))
		write(1, "0\n", 2);
	return (0);
}

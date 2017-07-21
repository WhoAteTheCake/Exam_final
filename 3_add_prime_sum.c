/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_add_prime_sum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:10:48 by laube             #+#    #+#             */
/*   Updated: 2017/07/20 22:15:13 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(char *str);
int		prime_sum(int num);
void	ft_putnbr(int sum);

int		ft_atoi(char *str)
{
	int res;
	int i;
	int sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-' ? -1 : 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		res = -res;
	return (res);
}

int		prime_sum(int num)
{
	int i;
	int k;
	int sum;
	int state;

	sum = 2;
	state = 0;
	i = 3;
	k = 2;
	if (num < 2)
		return (0);
	if (num == 2)
		return (2);
	while (i <= num)
	{
		state = 1;
		while (k < i)
		{
			if ((i % k) == 0)
				state = 0;
			k++;
		}
		if (state == 1)
			sum += i;
		i++;
		k = 2;
	}
	return (sum);
}

void	ft_putnbr(int sum)
{
	char c;
	if (sum >= 10)
	{
		ft_putnbr(sum / 10);
		ft_putnbr(sum % 10);
	}
	else if (sum < 10)
	{
		c = sum + '0';
		write(1, &c, 1);
	}
}

int		main(int argc, char **argv)
{
	int num;
	int sum;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	num = ft_atoi(argv[1]);
	sum = prime_sum(num);
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}

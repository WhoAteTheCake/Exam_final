/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 22:46:58 by laube             #+#    #+#             */
/*   Updated: 2017/07/20 23:48:47 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *str, int str_base)
{
	int i;
	int sign;
	int k;	
	int sum;
	int multi;

	multi = 1;
	k = 0;
	sum = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\t') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-' ? -1 : 1);
		i++;
	}
	k = i;
	while (str[k])
		k++;
	k--;
	
	while (k >= i)
	{
		if (str[k] >= '0' && str[k] <= '9')
		{
			sum = sum + ((str[k] - '0') * multi);
			multi *= str_base;
			k--;
		}
		else if (str[k] >= 'A' && str[k] <= 'F')
		{
			if (str[k] - 55 > (str_base - 1))
				return (0);
			sum = sum + ((str[k] - 55) * multi);
			multi *= str_base;
			k--;
		}
		else if (str[k] >= 'a' && str[k] <= 'f')
		{
			if (str[k] - 87 > (str_base - 1))
				return (0);
			sum = sum + ((str[k] - 87) * multi);
			multi *= str_base;
			k--;
		}
	}
	if (sign == -1)
		sum = -sum;
	return (sum);
}

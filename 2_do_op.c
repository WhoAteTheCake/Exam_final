/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:40:44 by laube             #+#    #+#             */
/*   Updated: 2017/07/20 18:55:37 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		oper(int num1, int num2, char *op);

int main(int argc, char **argv)
{
	int num1;
	int num2;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	printf("%d\n", oper(num1, num2, argv[2]));
	return (0);
}

int		oper(int num1, int num2, char *op)
{
	if (*op == '*')
		return (num1 * num2);
	else if (*op == '/')
		return (num1 / num2);
	else if (*op == '+')
		return (num1 + num2);
	else if (*op == '-')
		return (num1 - num2);
	else if (*op == '%')
		return (num1 % num2);
	return (404);
}

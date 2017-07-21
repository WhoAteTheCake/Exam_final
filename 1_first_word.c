/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 17:21:36 by laube             #+#    #+#             */
/*   Updated: 2017/07/20 17:53:23 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		first_word(char *str);

int 	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	first_word(argv[1]);
	return (0);
}

int	first_word(char *str)
{
	int i;
	int state;

	state = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
	{
		state = 1;
		i++;
		if (str[i + 1] == '\0')
		{
			write(1, "\n", 1);
			return (0);
		}
	}
	while ((str[i] != ' ' && str[i] != '\t') && (str[i] != '\0'))
	{
		state = 1;
		write(1, &str[i], 1);
		i++;
	}
	if (state == 1)
		write(1, "\n", 1);
	return (0);
}

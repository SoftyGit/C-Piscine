/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:58:51 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/07 13:45:16 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		else
		{
			if (*s1 == 0)
			{
				return (0);
			}
			s1++;
			s2++;
		}
	}
}

void	ft_pretty_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort(int size, char **data)
{
	int	repeat;
	int	i;

	repeat = 0;
	while (repeat < size)
	{
		i = 1;
		while (i < size - 1)
		{
			if (ft_strcmp(data[i], data[i + 1]) > 0)
			{
				ft_pretty_swap(&data[i], &data[i + 1]);
			}
			i++;
		}
		repeat++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	write(1, str, i);
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
	return (0);
}

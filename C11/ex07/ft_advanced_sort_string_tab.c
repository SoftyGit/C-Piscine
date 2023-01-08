/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:42:46 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/14 15:26:51 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
*/
int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_pretty_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	repeat;
	int	i;

	repeat = 0;
	while (repeat < ft_strlen(tab))
	{
		i = 0;
		while (i < ft_strlen(tab) - 1)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
				ft_pretty_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		repeat++;
	}
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	ft_advanced_sort_string_tab(&argv[1], ft_strcmp);

	argc++;
	argc--;
	int i = 1;
	while (argv[i])
	{
		printf("%s ",argv[i]);
		i++;
	}
}
*/

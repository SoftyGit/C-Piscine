/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:41:13 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/11 18:46:38 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen2(char *str);
void	ft_strcat(char *dest, char *src);
void	ft_count(int *count, int nbr, int length);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_pretty_strlen(char *base);
void	ft_division(long nbr, long length, char *base, char *value);
void	ft_putnbr_base(long nbr, char *base, char *value, int *num);
int		ft_str_check(char *str, int num, char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != 0)
		i++;
	j = 0;
	while (src[j] != 0 && j < 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
}

void	ft_count(int *count, int nbr, int length)
{
	if (nbr != 0)
	{
		(*count)++;
		ft_count(count, nbr / length, length);
	}
}

int	ft_pretty_strlen(char *base)
{
	int	i;
	int	check[300];

	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (-1);
	while (i < 300)
		check[i++] = 0;
	i = 0;
	while (i < 300 && base[i] != 0)
	{
		if (check[(int)base[i]] == 1 || base[i] == '+' || base[i] == '-'
			|| base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
			return (-1);
		else
			check[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

void	ft_division(long nbr, long length, char *base, char *value)
{
	if (nbr == 0)
		return ;
	ft_division(nbr / length, length, base, value);
	ft_strcat(value, base + (nbr) % length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:41:19 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/14 16:27:43 by yongjale         ###   ########.fr       */
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

int	ft_str_check(char *str, int num, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str[num] == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	point[2];

	i = 0;
	point[0] = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			point[0] *= -1;
	point[1] = 0;
	while (ft_str_check(str, i, base) != -1)
	{
		point[1] *= ft_pretty_strlen(base);
		point[1] += ft_str_check(str, i++, base);
	}
	return ((int)(point[1] * point[0]));
}

void	ft_putnbr_base(long nbr, char *base, char *value, int *num)
{
	long	length;

	length = (long)ft_pretty_strlen(base);
	if (nbr == 0)
		ft_strcat(value, base);
	else if (nbr > 0)
		ft_division(nbr, length, base, value);
	else if (nbr < 0)
	{
		nbr *= -1;
		value[(*num)++] = '-';
		value[1] = 0;
		ft_division(nbr, length, base, value);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		convert;
	int		count;
	int		check;
	char	*value;

	if (ft_pretty_strlen(base_from) == -1 || ft_pretty_strlen(base_to) == -1)
		return (NULL);
	convert = ft_atoi_base(nbr, base_from);
	count = 0;
	ft_count(&count, convert, ft_strlen2(base_to));
	if (convert == 0 || convert < 0)
		count += 1;
	value = (char *)malloc(sizeof(char) * (count + 1));
	check = 0;
	value[0] = 0;
	ft_putnbr_base((long)convert, base_to, value, &check);
	value[count] = 0;
	return (value);
}

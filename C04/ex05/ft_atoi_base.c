/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:20:22 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/07 18:51:32 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	point[2];

	i = 0;
	point[0] = 1;
	if (ft_pretty_strlen(base) == -1)
		return (-1);
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

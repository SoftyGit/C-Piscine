/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:11:26 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/05 20:15:11 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		point[1] *= 10;
		point[1] += str[i++] - '0';
	}
	return ((int)(point[1] * point[0]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:44:17 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/05 20:58:00 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	sum;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = 0;
	sum = nb;
	while (i++ < power - 1)
		sum *= nb;
	return (sum);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:00:07 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/05 21:07:09 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_new_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_new_recursive_power(nb, power - 1));
}

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_new_recursive_power(nb, power - 1));
}

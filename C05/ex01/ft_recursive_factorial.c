/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:29:56 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/06 14:35:40 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_new_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	return (nb * ft_new_recursive_factorial(nb - 1));
}

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 1)
		return (0);
	return (nb * ft_new_recursive_factorial(nb - 1));
}

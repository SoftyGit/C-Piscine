/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:45:37 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/08/26 15:07:27 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	if (*b == 0)
	{
		*a = 0;
		*b = 0;
		return ;
	}
	temp = (*a) / (*b);
	*b = (*a) % (*b);
	*a = temp;
}
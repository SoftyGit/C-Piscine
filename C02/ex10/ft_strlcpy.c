/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:40:48 by yongjale          #+#    #+#             */
/*   Updated: 2022/08/30 12:17:19 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		i;

	i = 0;
	while (src[i] != 0)
	{
		if (i < (int)size - 1)
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = 0;
		}
		i++;
	}
	dest[i] = 0;
	return (i);
}

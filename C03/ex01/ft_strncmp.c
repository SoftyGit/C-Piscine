/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:55:37 by yongjale          #+#    #+#             */
/*   Updated: 2022/08/31 13:50:35 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
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
		i++;
	}
	return (0);
}

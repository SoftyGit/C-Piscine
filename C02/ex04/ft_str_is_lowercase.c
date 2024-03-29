/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:41:09 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/08/29 12:53:01 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	while (*str != 0)
	{
		if (*str > 'z' || *str < 'a')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

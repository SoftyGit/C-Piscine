/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:42:56 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/01 16:13:16 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strstr_extra(char *str, char *to_find, int i, int check)
{
	int		j;

	j = 0;
	while (to_find[j] != 0 && check == 0)
	{
		if (str[i + j] != to_find[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	check;

	i = 0;
	if (str[i] == 0 && to_find[i] == 0)
	{
		return (str);
	}
	while (str[i] != 0)
	{
		check = 0;
		check = ft_strstr_extra(str, to_find, i, check);
		if (check == 0)
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}

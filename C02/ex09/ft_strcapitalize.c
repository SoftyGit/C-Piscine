/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:54:12 by yongjale          #+#    #+#             */
/*   Updated: 2022/08/29 12:54:56 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_are_you_lower(char *str, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		return (1);
	}
	return (0);
}

int	ft_are_you_higher(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_are_you_char(char *str, int i)
{
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		return (1);
	}
	else if (str[i] >= 'a' && str[i] <= 'z')
	{
		return (1);
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		return (1);
	}
	return (0);
}

void	ft_if_check(char *str, int check, int i)
{
	if (check == 1)
	{
		if (ft_are_you_lower(str, i))
		{
			str[i] -= 32;
		}
	}
	else
	{
		if (ft_are_you_higher(str, i))
		{
			str[i] += 32;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		check;

	i = 0;
	check = 1;
	while (str[i] != 0)
	{
		if (!(ft_are_you_char(str, i)))
		{
			check = 1;
		}
		else
		{
			ft_if_check(str, check, i);
			check = 0;
		}
		i++;
	}
	return (str);
}

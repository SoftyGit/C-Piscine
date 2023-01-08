/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunk <hyunjunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:19:03 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/11 22:09:33 by hyunjunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcat(char	*dest, char	*source)
{
	while (*dest != '\0')
		dest++;
	while (*source != '\0')
		*dest++ = *source++;
	*dest = '\0';
}

void	ft_strcpy(char	*dest, char	*source)
{
	while (*source != '\0')
		*dest++ = *source++;
	*dest = '\0';
}

char	*set_str_1(char ch)
{
	static char	buff[2];

	buff[0] = ch;
	buff[1] = '\0';
	return (buff);
}

char	*set_str_2(char ch1, char ch2)
{
	static char	buff[3];

	buff[0] = ch1;
	buff[1] = ch2;
	buff[2] = '\0';
	return (buff);
}

int	is_any_print_another(char	*str)
{
	while (*str != '\0')
	{
		if (*str != '0')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

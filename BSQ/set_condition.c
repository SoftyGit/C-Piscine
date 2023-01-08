/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:44:00 by juykim            #+#    #+#             */
/*   Updated: 2022/09/15 04:35:26 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	n_atoi(char *str, int n)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < n)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int	define_char(char *str, int len, char *sep, int *row_col)
{
	if (len < 4)
		return (-1);
	sep[0] = str[len - 3];
	sep[1] = str[len - 2];
	sep[2] = str[len - 1];
	if (sep[0] == sep[1] || sep[1] == sep[2] || sep[2] == sep[0])
		return (-1);
	row_col[0] = n_atoi(str, len - 3);
	if (row_col[0] <= 0)
		return (-1);
	return (1);
}

int	define_column(char *str)
{
	int	col;
	int	i;

	i = 0;
	col = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i + col] != '\n')
		col++;
	return (col);
}

int	define_condition(char *str)
{
	int	init_len;

	if (*str == '\n' || *str == '\0')
		return (0);
	init_len = 0;
	while (str[init_len] != '\n')
		++init_len;
	return (init_len);
}

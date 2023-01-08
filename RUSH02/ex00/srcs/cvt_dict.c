/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:39:16 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/12 17:43:37 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <unistd.h>

int	int_cvt_dict(t_dict	*dict, char	*nbr)
{
	int		nbr_len;

	if (dict == NULLPTR)
		return (BAD_RETURN);
	nbr_len = strlen_only_number(nbr);
	if (nbr_len == 0 || MAX_UNIT_LEN + 2 <= nbr_len)
	{
		free_dict(dict);
		return ((int)dict_error_ret_null());
	}
	if (find_key(dict, nbr) != NULLPTR)
	{
		write(1, find_key(dict, nbr), ft_strlen(find_key(dict, nbr)));
		free_dict(dict);
		return (0);
	}
	int_cvt_dict_print(dict, nbr, nbr_len);
	free_dict(dict);
	return (0);
}

int	small_int_cvt_dict(t_dict	*dict, char	*nbr)
{
	char	*value;
	int		print_flag;

	print_flag = -1;
	if (nbr[0] != '0')
	{
		print_flag = small_int_cvt_dict_100(dict, nbr);
	}
	if (nbr[1] != '0')
	{
		if (nbr[1] == '1' && nbr[2] != '0')
		{
			value = find_key(dict, set_str_2(nbr[1], nbr[2]));
			write(1, value, ft_strlen(value));
			if (is_any_print_another(&nbr[2 + 1]) == 1)
				write(1, " ", sizeof(char));
			return (1);
		}
		print_flag = small_int_cvt_dict_10(dict, nbr);
	}
	if (nbr[2] != '0')
	{
		print_flag = small_int_cvt_dict_1(dict, nbr);
	}
	return (print_flag);
}

char	*make_alignd_3(char	*nbr)
{
	static char	buff[1024];
	int			nbr_size;
	char		*buff_p;
	int			i;

	nbr_size = ft_strlen(nbr);
	buff_p = buff;
	i = 0;
	while (i < 3 - (nbr_size % 3) && (nbr_size % 3 != 0))
	{
		*buff_p++ = '0';
		i++;
	}
	while (*nbr != '\0')
		*buff_p++ = *nbr++;
	*buff_p = '\0';
	return (buff);
}

char	*make_number_unit(int length)
{
	static char	buff[1024];
	int			i;

	i = 1;
	buff[0] = '1';
	while (i < length)
	{
		buff[i] = '0';
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*find_key(t_dict	*dict, char	*key)
{
	while (dict->key != NULLPTR)
	{
		if (ft_strcmp(dict->key, key) == 0)
			return (dict->value);
		dict++;
	}
	return (NULLPTR);
}

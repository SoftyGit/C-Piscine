/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvt_dict2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:23:10 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/12 17:43:37 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <unistd.h>

void	int_cvt_dict_print(t_dict	*dict, char	*nbr, int nbr_len)
{
	char	*number_unit;
	int		is_printed;

	is_printed = -1;
	nbr = make_alignd_3(nbr);
	if (nbr_len % 3 != 0)
		nbr_len = (nbr_len - (nbr_len % 3)) + 3;
	while (*nbr != '\0')
	{
		is_printed = small_int_cvt_dict(dict, nbr);
		if (nbr[4] != '\0' && is_printed != -1)
		{
			number_unit = make_number_unit(nbr_len - 2);
			write(1, find_key(dict, number_unit), sizeof(number_unit));
			if (is_any_print_another(&nbr[3 + 1]) == 1)
				write(1, " ", sizeof(char));
		}
		nbr += 3;
		nbr_len -= 3;
	}
}

int	small_int_cvt_dict_100(t_dict	*dict, char	*nbr)
{
	char	*tmp;

	tmp = set_str_1(nbr[0]);
	write(1, find_key(dict, tmp), ft_strlen(find_key(dict, tmp)));
	write(1, " ", sizeof(char));
	write(1, find_key(dict, "100"), ft_strlen(find_key(dict, "100")));
	if (is_any_print_another(&nbr[0 + 1]) == 1 || nbr[4] != '\0')
	{
		write(1, " ", sizeof(char));
	}
	return (1);
}

int	small_int_cvt_dict_10(t_dict	*dict, char	*nbr)
{
	char	*tmp;

	tmp = set_str_2(nbr[1], '0');
	write(1, find_key(dict, tmp), ft_strlen(find_key(dict, tmp)));
	if (nbr[2] != '0')
		write(1, "-", sizeof(char));
	else if (is_any_print_another(&nbr[1 + 1]) == 1 || nbr[4] != '\0')
	{
		write(1, " ", sizeof(char));
	}
	return (1);
}

int	small_int_cvt_dict_1(t_dict	*dict, char	*nbr)
{
	char	*tmp;

	tmp = set_str_1(nbr[2]);
	write(1, find_key(dict, tmp), ft_strlen(find_key(dict, tmp)));
	if (is_any_print_another(&nbr[2 + 1]) == 1 || nbr[4] != '\0')
	{
		write(1, " ", sizeof(char));
	}
	return (1);
}

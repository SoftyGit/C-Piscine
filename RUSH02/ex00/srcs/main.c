/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:52:17 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/12 17:43:37 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <stdio.h>

int	main(int argc, char	**argv)
{
	t_dict	*parser_ret;

	if (argc >= 4)
		return (argc_error());
	if (argc == 1)
	{
		parser_ret = parse_dict_file(DEFAULT_DICT);
		if (parser_ret == NULLPTR)
			return (BAD_RETURN);
		free_dict(parser_ret);
		return (0);
	}
	else if (argc == 2)
	{
		parser_ret = parse_dict_file(DEFAULT_DICT);
		return (int_cvt_dict(parser_ret, argv[1]));
	}
	else if (argc == 3)
	{
		parser_ret = parse_dict_file(argv[1]);
		return (int_cvt_dict(parser_ret, argv[2]));
	}
	return (BAD_RETURN);
}

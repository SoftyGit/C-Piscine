/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:50:35 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/14 16:07:49 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (s1[0] == 0)
		return (0);
	else if (s1[1] != 0)
		return (0);
	else if (*s1 != *s2)
		return (0);
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:13:41 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/13 20:14:54 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b, int c)
{
	if (a < b)
		if (a < c)
			return (a);
		else
			return (c);
	else
		if (b < c)
			return (b);
		else
			return (c);
}
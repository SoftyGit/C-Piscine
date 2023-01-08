/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:01:50 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/14 14:25:25 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
int		doop(int a, int b, int *check, char **argv);
int		sum(int a, int b, int *check);
int		sub(int a, int b, int *check);
int		mul(int a, int b, int *check);
int		div(int a, int b, int *check);
int		mod(int a, int b, int *check);
long	ft_atoi(char *str);
void	ft_putnbr(long value);
int		main(int argc, char **argv);

#endif

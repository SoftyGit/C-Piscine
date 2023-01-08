/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:12:04 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/04 18:18:47 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRETTY_H
# define PRETTY_H

int		check_row(int header, int *data, int (*base)[10], int size);
int		check_col(int header, int *data, int (*base)[10], int size);
int		check_value(int header, int *data, int (*base)[10], int size);
void	operate(int *data, int num, int size, int (*base)[10]);
void	print_data(int *data, int size);
int		check_argv_value(int len, char *argv);
int		check_argv(int argc, char *argv);
int		check_up_col(int header, int *data, int (*base)[10], int size);
int		check_down_col(int header, int *data, int (*base)[10], int size);
int		earlycheck_up_col(int header, int *data, int (*base)[10], int size);
int		earlycheck_down_col(int header, int *data, int (*base)[10], int size);
int		earlycheck_col(int header, int *data, int (*base)[10], int size);
int		check_left_row(int header, int *data, int (*base)[10], int size);
int		check_right_row(int header, int *data, int (*base)[10], int size);
int		earlycheck_left_row(int header, int *data, int (*base)[10], int size);
int		earlycheck_right_row(int header, int *data, int (*base)[10], int size);
int		earlycheck_row(int header, int *data, int (*base)[10], int size);
void	init_data(int *data);
void	init_base(int (*base)[10], char *argv, int size);

#endif
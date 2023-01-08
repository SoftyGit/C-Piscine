/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:30:21 by juykim            #+#    #+#             */
/*   Updated: 2022/09/15 04:59:24 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// first
int		**allocate_array(int row, int col);
int		valid_char(char c, char empty, char obstacle);
int		**build_array(char *str, int row, int col, char *sep);
char	*read_file(char *argv);
int		**set_array(char *argv, int *row_col, char *sep);

int		ft_strlen(char *str);
int		n_atoi(char *str, int n);
void	ft_strncpy(char *dest, char *src, unsigned int n);
int		define_column(char *str);
int		define_char(char *str, int len, char *sep, int *row_col);
int		define_condition(char *str);

void	free_array(int **arr, int row);
void	free_str_array(char **arr, int row);
int		**error_free(char **str);

// second
void	pretty_lines(int **arr, int *row_col, int *value);
void	pretty_print(int **arr, int *row_col, char *sep);
void	init_map(int **data, int *row_col);
void	operate_map(int **data, int *value, int *row_col);
void	draw_map(int **data, int *value);
void	print_map(int **data, int *row_col, char *sep);
int		ft_min(int a, int b, int c);

// write_make_map.c
void	make_configure(char *buffer, int *row_col, char *sep);
void	make_check(char *buffer, char *sep);
void	make_col(int *row_col, char *data);
char	**make_input(int *row_col, char *sep);

// write_map.c
char	*ft_strcat(char *dest, char *src);
int		**write_to_int_map(int *row_col, char **data, char *sep);
void	write_map(void);

// error.c
void	map_error_free_one(char *src);
void	map_error_free_two(char **arr, int row);
void	map_error_free_int_two(int **arr, int row);
void	map_error_free_three(char *src, int **arr, int row);

#endif

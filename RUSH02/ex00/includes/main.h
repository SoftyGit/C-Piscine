/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunk <hyunjunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:53:13 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/11 22:09:42 by hyunjunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/* 
Global Define 
*/
# define STDOUT (1)
# define NULLPTR ((void *)0)
# define DEFAULT_DICT ("numbers.dict")
# define BAD_RETURN (-1)
# define TRUE (1)
# define FALSE (0)
/* undecillion Length */
# define MAX_UNIT_LEN (37)

/* 
@File : error.c 
*/
int		argc_error(void);
void	*dict_error_ret_null(void);

/* 
@File : parser.c 
*/
/* Array End : key == NULLPTR */
typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

/* Read file and convert t_dict array */
t_dict	*parse_dict_file(const char	*fname);
void	free_dict(t_dict	*arr);

/* @Return : buff Count
	IF FAIL, return : 0 
	IF EOF,  return : -1 */
int		get_key(int fd, char	*buff);
int		get_value(int fd, char	*buff);
int		get_dict_count(const char	*fname);

/* Presume arr_size is enough
	@Return : end of arr */
t_dict	*parse_dict_cat(t_dict *arr, int fd);

/* 
@File : cvt_dict.c
*/
int		int_cvt_dict(t_dict	*dict, char	*nbr);
void	int_cvt_dict_print(t_dict	*dict, char	*nbr, int nbr_len);

/* 	make number_unit like "1000000", "1000" */
char	*make_number_unit(int length);
/* return value */
char	*find_key(t_dict	*dict, char	*key);
/* only process formatted 000 (ex. 912, 012, 001)
	IF nothing print, return (-1)
	else return (1) */
int		small_int_cvt_dict(t_dict	*dict, char	*nbr);
/* make string to aligned by 3 length
	"123453" -> "123453"
	"1232" -> "001232"
	"1" -> "001" */
char	*make_alignd_3(char	*nbr);
/* print each number unit 
	always return (1) */
int		small_int_cvt_dict_100(t_dict	*dict, char	*nbr);
int		small_int_cvt_dict_10(t_dict	*dict, char	*nbr);
int		small_int_cvt_dict_1(t_dict	*dict, char	*nbr);

/* 
@File : util.c 
*/
int		my_is_space(char ch);
char	*ft_strdup(char	*src);
int		ft_strlen(char	*str);
int		ft_strcmp(char *s1, char	*s2);
void	ft_strcat(char	*dest, char	*source);
void	ft_strcpy(char	*dest, char	*source);
int		strlen_only_number(char	*str);
char	*set_str_1(char ch);
char	*set_str_2(char ch1, char ch2);
int		is_any_print_another(char	*str);

#endif

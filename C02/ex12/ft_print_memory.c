/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:23:39 by yongjale          #+#    #+#             */
/*   Updated: 2022/12/15 09:37:04 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_pretty_16(void *addr, int num, char *hex)
{
	int		i;
	long	value;
	long	r;

	i = 0;
	value = (long)(addr + num);
	while (i < 16)
	{
		r = value % 16;
		value /= 16;
		if (r < 10)
		{
			hex[num + (15 - i)] = r + 48;
		}
		else if (r < 16)
		{
			hex[num + (15 - i)] = r + 87;
		}
		i++;
	}
	write(1, hex + num, 16);
	write(1, ":", 1);
	i += 16;
}

void	ft_int_16char(int a, int b)
{
	char	hex;

	if (a < 10)
	{
		hex = a + 48;
	}
	else
	{
		hex = a + 87;
	}
	write(1, &hex, 1);
	if (b < 10)
	{
		hex = b + 48;
	}
	else
	{
		hex = b + 87;
	}
	write(1, &hex, 1);
}

void	ft_pretty_32(void *addr, int num, unsigned int size)
{
	int	i;
	int	value;
	int	r;

	i = 0;
	while (i < 16)
	{
		if (i % 2 == 0)
		{
			write(1, " ", 1);
		}
		if (num + i < (int)size)
		{
			value = *((unsigned char *)addr + num + i);
			r = value % 16;
			value /= 16;
			ft_int_16char(value, r);
		}
		else
		{
			write(1, "  ", 2);
		}
		i++;
	}
}

void	ft_print_extra(void *addr, int i, int j, unsigned int size)
{
	while (j < 16)
	{
		if (i + j < (int)size)
		{
			if (*((unsigned char *)addr + i + j) > 31)
			{
				if (*((unsigned char *)addr + i + j) < 127)
				{
					write(1, addr + i + j, 1);
				}
				else
				{
					write(1, ".", 1);
				}
			}
			else
			{
				write(1, ".", 1);
			}
		}
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	int		j;
	char	hex[100];

	i = 0;
	while (i < (int)size)
	{
		ft_pretty_16(addr, i, hex);
		ft_pretty_32(addr, i, size);
		write(1, " ", 1);
		j = 0;
		ft_print_extra(addr, i, j, size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

#include <unistd.h>
#define	X 27
#define Y 9


#include <unistd.h>

void	init_map(int (*data)[Y])
{
	int	i;
	int	j;

	i = 0;
	while (i < Y)
	{
		j = 0;
		while (j < X)
		{
			data[j][i] = 1;
			j++;
		}
		i++;
	}
}

void	operate_map(int (*data)[Y], int *value)
{
	int	i;
	int	j;

	value[0] = data[0][0];
	i = 1;
	while (i < Y)
	{
		j = 1;
		while (j < X)
		{
			if (data[j][i] == 1)
			{
				data[j][i] = ft_min(data[j - 1][i - 1], data[j][i - 1], data[j - 1][i]) + 1;
				if (data[j][i] > value[0])
				{
					value[0] = data[j][i];
					value[1] = j;
					value[2] = i;
				}
			}
			j++;
		}
		i++;
	}
}

void	draw_map(int (*data)[Y], int *value)
{
	int	i;
	int	j;
	int	size;

	size = data[value[1]][value[2]];
	i = value[2];
	while (i > value[2] - size)
	{
		j = value[1];
		while (j > value[1] - size)
		{
			data[j][i] = -1;
			j--;
		}
		i--;
	}
}

void	print_map(int (*data)[Y])
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (i < Y)
	{
		j = 0;
		while (j < X)
		{
			if (data[j][i] > 0)
				write(1, ".", 1);
			else if (data[j][i] < 0)
				write(1, "X", 1);
			else
				write(1, "O", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

#include <stdio.h>
int main()
{
	int	i;

	i = 0;
	int data[X][Y];
	int value[3];
	
	init_map(data);
	data[4][1] = 0;
	data[4][4] = 0;
	data[6][7] = 0;
	data[10][8] = 0;
	data[12][2] = 0;
	data[15][5] = 0;
	data[2][8] = 0;
	data[21][7] = 0;
	print_map(data);
	printf("\n");
	operate_map(data, value);
	draw_map(data, value);
	print_map(data);
}

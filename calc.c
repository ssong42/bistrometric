/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:14:37 by ssong             #+#    #+#             */
/*   Updated: 2018/01/09 10:56:22 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"
#include <stdio.h>

/*
Error handling
multi digit numbers
multiplication and division
*/
char *read_stdin(int inputsize)
{
	int ret;
	char *tmp;
	char buf[BUFF_SIZE + 1];
	
	tmp = NULL;
	while (inputsize >= BUFF_SIZE && (ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		tmp = ft_strjoin(tmp, buf);
		inputsize -= BUFF_SIZE;
		ft_bzero((void*)buf, BUFF_SIZE);
	}
	ret = read(0, buf, inputsize);
		tmp = ft_strjoin(tmp, buf);
	return (tmp);
}
/*
double parseSum()
{
	double left = parseProduct();
	while (*x == '+')

*/	
double parseNumber(char *x)
{
	long double number = 0;
	long double weight;
	double scaled;

	while (*x >= '0' && *x <= '9')
	{
		number = number * 10;
		number = number + *x - '0';
		x++;
	}
	if (*x == '.')
	{
		++x;
		weight = 1;
		while (*x >= '0' && *x <= '9')
		{
			weight = weight / 10;
			scaled = (*x - '0') * weight;
			number = number + scaled;
			++x;
		}
	}
	return (number);
}

/*
**	parseNumber() will iterate through the integer and will account for both 
**	multi-digit numbers as well as decimal numbers.
*/

int main(int argc, char **argv)
{
	char *str;
	int inputsize;

	str = NULL;
	if (argc != 3)
	{
		ft_putstr("syntax error\n");
		return (-1);
	}
	inputsize = ft_atoi(argv[2]);
	str	= read_stdin(inputsize);
	ft_putendl(str);
	return (0);
}

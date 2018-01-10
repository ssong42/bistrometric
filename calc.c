/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:14:37 by ssong             #+#    #+#             */
/*   Updated: 2018/01/09 21:46:19 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"
#include <stdio.h>
#include <stdlib.h>

/*
Error handling
multi digit numbers
multiplication and division
*/
/*
long double parseSum()
{
	long double left = parseProduct();
	while (*str == '+')
}

long double parseProduct()
{

}

long double parseFactor(char *str, int *i)
{
	if (str[i] >= '0' && 'str' <= '9')
	{
		return (parseNumber(str, *i))
	}
	else
	{
		printf("number not within base\n")
		exit(0);
	}
}

long double parseNumber(char *str)
{
	long double number = 0;
	long double weight;
	long double scaled;

	while (*str >= '0' && *x <= '9')
	{
		number = number * 10;
		number = number + *str - '0';
		str++;
	}
	if (*str == '.')
	{
		++str;
		weight = 1;
		while (*str >= '0' && *x <= '9')
		{
			weight = weight / 10;
			scaled = (*str - '0') * weight;
			number = number + scaled;
			++str;
		}
	}
	return (number);
}
*/

char *read_stdin(int inputsize)
{
	int ret;
	char *buf;

	buf = malloc(sizeof(char)*inputsize + 1);
	ret = read(0, buf, inputsize);
	buf[ret] = 0;
	return (buf);
}

int validation(char *str, char *base)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			if ((ft_isdigit(str[i + 1]) || !ft_isdigit(str[i - 1])) && str[i + 1] != '-' && str[i + 1] != '+')
				return (0);
		}
		else if (str[i] == ')')
		{
			if ((!ft_isdigit(str[i + 1]) || ft_isdigit(str[i - 1])) && str[i - 1] != '-' && str[i - 1] != '+')
				return (0);
		}
		else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			if (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '%')
				return (0);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (i > 0 && str[i - 1] != '(' && (str[i + 1] == '+' || str[i + 1] == '-'))
				return (0);
		}
		else if (strchr(base, str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	char *str;
	int i;

	i = 0;
	str = NULL;
	if (argc != 3)
	{
		ft_putstr("syntax error\n");
		return (-1);
	}
	argv[1] = "012";
	str	= read_stdin(ft_atoi(argv[2]));
	if (validation(str,argv[1]) == 0)
	{
		ft_putstr("parse error\n");
		return (0);
	}
	printf("%s\n", str);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:21:41 by iganiev           #+#    #+#             */
/*   Updated: 2023/05/17 17:35:00 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max_param(float x, float y)
{
	float	max;

	max = 0;
	if (x > y)
		max = x;
	else if (y > x)
		max = y;
	return (max);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != '\0')
	{	
		if (*str >= '0' && *str <= '9')
			res = res * str_base + *str - 48;
		else if (*str >= 'A' && *str <= 'F')
			res = res * str_base + *str - 55;
		else if (*str >= 'a' && *str <= 'f')
			res = res * str_base + *str - 87;
		else
		{
			break ;
		}
		str++;
	}
	return (sign * res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1 - s2);
}

int	element_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || !str[0])
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:24:57 by iwithmor          #+#    #+#             */
/*   Updated: 2016/09/23 17:24:59 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] >= 0 && (str[i] < 33 || str[i] == 127))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	if (ft_isdigit((int)str[i]) == 0)
		return (0);
	while (ft_isdigit((int)str[i]) == 1)
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (neg * result);
}

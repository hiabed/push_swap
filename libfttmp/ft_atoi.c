/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:39:45 by mhassani          #+#    #+#             */
/*   Updated: 2023/03/01 22:53:21 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

// int	main(void)
// {
// 	printf("my own ft_atoi is: %ld\n", ft_atoi("2147483648515645"));
// 	return (0);
// }

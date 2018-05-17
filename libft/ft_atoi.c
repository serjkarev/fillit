/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 20:14:16 by skarev            #+#    #+#             */
/*   Updated: 2018/04/06 20:14:17 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long int	i;
	long long int	n;
	int				znak;

	i = 0;
	n = 0;
	znak = 1;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			znak = -1;
	while (str[i] >= '0' && str[i] <= '9' && n >= 0)
		n = n * 10 + ((long long int)str[i++] - '0');
	if (n < 0)
	{
		if (znak == -1)
			return (0);
		return (-1);
	}
	return ((int)n * (int)znak);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:42:18 by miahmadi          #+#    #+#             */
/*   Updated: 2022/04/03 02:00:50 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		tot;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	tot = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(tot + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	tot = i;
	while (s2[i - tot])
	{
		new[i] = s2[i - tot];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:27:12 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/30 12:25:58 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*join;

	i = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1 && *s1)
	{
		join[i] = *s1;
		i++;
		s1++;
	}
	while (s2 && *s2)
	{
		join[i] = *s2;
		i++;
		s2++;
	}
	join[i] = '\0';
	return (join);
}

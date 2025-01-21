/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:50:11 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/21 02:24:34 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				k;
	int				j;
	unsigned char	*t;

	i = ft_strlen((char *)s1);
	k = ft_strlen((char *)s2);
	j = 0;
	t = malloc((i + k + 1) + sizeof(char));
	if (!t)
		return (NULL);
	while (s1[j] != '\0')
	{
		t[j] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		t[i + j] = s2[j];
		j++;
	}
	t[i + j] = '\0';
	return ((char *)t);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*t;

	i = ft_strlen((char *)s);
	t = malloc(i + 1);
	if (!t)
		return (NULL);
	i = 0;
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	k;
	char			*f;

	i = ft_strlen((char *)s);
	k = 0;
	if (!s || len == 0 || start > i)
		return (ft_strdup(""));
	if ((size_t)start + len > i)
		len = i - start;
	f = malloc(len + 1 * sizeof(char));
	if (!f)
	{
		return (NULL);
	}
	while ((size_t)k < len)
	{
		f[k] = s[start + k];
		k++;
	}
	f[k] = '\0';
	return (f);
}

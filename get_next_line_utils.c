/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:16:00 by mvalerio          #+#    #+#             */
/*   Updated: 2023/05/23 00:59:08 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *string)
{
	size_t	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	return (i);
}

void	ft_empty_buffer(char *buffer, size_t *i)
{
	size_t	a;

	a = 0;
	while (a <= BUFFER_SIZE && buffer)
		buffer[a++] = 0;
	*i = 0;
}

char	*ft_strjoin_nl(char *line, char *buffer, size_t *i)
{
	char	*final;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	final = malloc(sizeof(char) * ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!final)
		return (NULL);
	while (line && line[a])
		final[b++] = line[a++];
	a = 0;
	while (buffer && buffer[a] && buffer[a] != '\n')
		final[b++] = buffer[a++];
	if (buffer && buffer[a] == '\n')
	{
		final[b++] = '\n';
		*i += a + 1;
	}
	else
		*i = 0;
	final[b] = '\0';
	if (line)
		free (line);
	return (final);
}

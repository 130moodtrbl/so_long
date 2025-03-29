/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speters <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:00:01 by speters           #+#    #+#             */
/*   Updated: 2025/01/03 12:37:05 by speters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*read_in_file(char *temp, int fd)
{
	char	*buffer;
	char	*storage;
	int		to_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!temp)
		temp = ft_strdup("");
	to_read = 1;
	while (to_read > 0 && check_line(temp, '\n') != 1)
	{
		to_read = read(fd, buffer, BUFFER_SIZE);
		if (to_read == -1)
			return (free(temp), free(buffer), temp = NULL, NULL);
		buffer[to_read] = '\0';
		storage = ft_strjoin(temp, buffer);
		if (!storage)
			return (free(temp), free(buffer), NULL);
		free (temp);
		temp = storage;
	}
	free(buffer);
	return (temp);
}

char	*make_line(char **storage)
{
	char	*t_zone;
	char	*new_line;
	int		i;

	if (!storage || !*storage || !**storage)
		return (NULL);
	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		i++;
	if ((*storage)[i] == '\n')
		i++;
	new_line = ft_substr(*storage, 0, i);
	if (!new_line)
		return (free(*storage), *storage = NULL, NULL);
	t_zone = ft_strdup(*storage + i);
	if (!t_zone)
		return (free(new_line), free(*storage), *storage = NULL, NULL);
	free (*storage);
	*storage = t_zone;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_in_file(storage, fd);
	if (!storage || !*storage)
		return (free(storage), storage = NULL, NULL);
	line = make_line(&storage);
	return (line);
}

/*int   main(void)
{
      int         fd;
      char  *next_line;
      int line;

      line = 0;
      fd = open("test_text.txt", O_RDONLY);
      if (fd < 0)
            return (1);
      while ((next_line = get_next_line(fd)) != NULL)
      {
            printf("[%d] %s", line, next_line);
            free(next_line);
            line++;
      }
      close(fd);
      return (0);
}*/
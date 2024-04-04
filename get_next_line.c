/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:53:20 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/04 13:39:24 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list **list)
{
	int		str_len;
	char	*next_str;

	if (*list == NULL)
		return (NULL);
	str_len = len_to_new_line(*list);
	next_str = malloc(str_len + 1 * sizeof(char));
	if (next_str == NULL)
		return (NULL);
	copy_str(*list, next_str);
	return (next_str);
}

void	create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buf;

	if (*list == NULL)
		return ;
	while (found_new_line(*list) == 0)
	{
		buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (buf == NULL)
			return ;
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[chars_read] = '\0';
		append(list, buf);
	}
}

// why can't I simply pass next_line = get_line(list) instead of (&list)?
// I'm not changing anything in list inside get_line()...
char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	list = NULL;
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(&list);
	return (next_line);
}

/*int	main(void)
{
	int			fd;
	const char	*filename;
	char		*next_line;

	filename = "hello.txt";
	fd = open(filename, O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	return (0);
}*/

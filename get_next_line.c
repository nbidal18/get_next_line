/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:53:20 by nbidal            #+#    #+#             */
/*   Updated: 2024/05/02 14:05:36 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list != NULL)
	{
		tmp = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buf[0] != '\0')
		*list = clean_node;
	else
	{
		free(clean_node);
		free(buf);
	}
}

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	clean_node = malloc(sizeof(t_list));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (clean_node == NULL || buf == NULL)
		return ;
	last_node = get_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->buf[i] != '\n' && last_node->buf[i] != '\0')
		i++;
	while (last_node->buf[i] != '\0')
		buf[k++] = last_node->buf[++i];
	buf[k] = '\0';
	clean_node->buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*ft_get_line(t_list *list)
{
	int		str_len;
	char	*str;

	if (list == NULL)
		return (NULL);
	str_len = line_len(list);
	str = malloc(str_len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	fill(list, str);
	return (str);
}

void	create(t_list **list, int fd)
{
	int		count_chars;
	char	*buf;

	while (search_new_line(*list) == 0)
	{
		buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (buf == NULL)
			return ;
		count_chars = 0;
		count_chars = read(fd, buf, BUFFER_SIZE);
		if (count_chars <= 0)
		{
			free(buf);
			return ;
		}
		buf[count_chars] = '\0';
		manage_list(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_get_line(list);
	clean_list(&list);
	return (next_line);
}

int	main(void)
{
	int			fd;
	const char	*filename;
	char		*next_line;
	int			i;

	filename = "lorem.txt";
	fd = open(filename, O_RDONLY);
	i = 10; // How many times it keeps reading each times it reaches a new line
	while (i-- >= 0)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
	}
	free(next_line);
	close(fd);
	return (0);
}

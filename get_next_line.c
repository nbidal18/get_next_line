/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:53:20 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/08 11:52:24 by nbidal           ###   ########.fr       */
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

void	polish_list(t_list **list)
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
	last_node = find_last_node(*list);
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
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_new_line(list);
	next_str = malloc(str_len + 1 * sizeof(char));
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	create_list(t_list **list, int fd)
{
	int		chars_read;
	char	*buf;

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

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_get_line(list);
	polish_list(&list);
	return (next_line);
}

/*int	main(void)
{
	int			fd;
	const char	*filename;
	char		*next_line;

	filename = "lorem.txt";
	fd = open(filename, O_RDONLY);
	next_line = get_next_line(fd);
	printf("%s", next_line);
	return (0);
}*/

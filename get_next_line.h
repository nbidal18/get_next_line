/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:39:23 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/11 10:31:32 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct list
{
	char		*buf;
	struct list	*next;
}	t_list;

char	*get_next_line(int fd);
void	create(t_list **list, int fd);
int		search_new_line(t_list *list);
void	manage_list(t_list **list, char *buf);
t_list	*get_last_node(t_list *list);
char	*ft_get_line(t_list *list);
int		line_len(t_list *list);
void	fill(t_list *list, char *str);
void	clean_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);

#endif

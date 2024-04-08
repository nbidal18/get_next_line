/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:40:34 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/08 10:27:12 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			if (list->buf[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->buf[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

int	len_to_new_line(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->buf[i] != '\0')
		{
			if (list->buf[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->buf = buf;
	new_node->next = NULL;
	last_node = find_last_node(*list);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

// do I really need to check all of the nodes with list = list->next?
int	found_new_line(t_list *list)
{
	int	i;

	while (list != NULL)
	{
		i = 0;
		while (list->buf[i] != '\0' && i < BUFFER_SIZE)
		{
			if (list->buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:39:23 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/06 11:01:27 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h> // contains printf()
# include <unistd.h> // contains read()
# include <stdlib.h> // contains malloc()
# include <fcntl.h> // contains open()

// WRITE A README TO EXPLAIN AND REVISE IN FUTURE
// * what each function does?
// * maybe even a diagram showing the flow of the logic

typedef struct list
{
	char		*buf;
	struct list	*next;
}	t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
int		found_new_line(t_list *list);
void	append(t_list **list, char *buf);
t_list	*find_last_node(t_list *list);
char	*get_line(t_list *list);
int		len_to_new_line(t_list *list);
void	copy_str(t_list *list, char *str);
//void	polish_list(); //1
//void	dealloc(); //1

#endif

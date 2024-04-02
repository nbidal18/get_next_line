/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:39:23 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/02 16:37:34 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h> // contains read()
# include <unistd.h> // contains printf()
# include <stdlib.h> // contains malloc()
# include <fcntl.h> // contains open()

typedef struct list
{
	char		*str_buf;
	struct list	*next_line;
}	t_list;
char	*get_next_line(int fd);
void	create_list(); //1
int		found_new_line(); //2
void	append(); //2
t_list	*find_last_node(); //2
char	*get_line(); //1
int		len_to_new_line(); //2
void	copy_str(); //2
void	polish_list(); //1
void	dealloc(); //1

#endif

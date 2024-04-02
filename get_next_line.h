/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:39:23 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/02 12:38:14 by nbidal           ###   ########.fr       */
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
	char		line[BUFFER_SIZE];
	struct list	*next_line;
}	t_list;
char	*get_next_line(int fd);

#endif

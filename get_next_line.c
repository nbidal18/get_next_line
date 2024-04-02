/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:53:20 by nbidal            #+#    #+#             */
/*   Updated: 2024/04/02 12:51:30 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

}

int	main(void)
{

}

//reads from the file BUFFER_SIZE bytes and prints them,
//then repeats until end of file.
int	main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		chars_read;

	//fd = open("hello.txt", O_RDONLY);
	//fd = open("lorem.txt", O_RDONLY);
	do
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		buf[chars_read] = '\0';
		printf("->%s\n", buf);
	} while (chars_read);
}

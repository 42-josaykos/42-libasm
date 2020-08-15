/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:46:13 by jonny             #+#    #+#             */
/*   Updated: 2020/08/15 17:02:14 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);

int main(void)
{
	int ret = 0;
	char buf[20];
	int fd;

	// ft_write
	write(1, "\033[1;32mMINE : \033[0m", 18);
	ret = ft_write(1, "Hello", 6);
	printf(" | ret = %d\n", ret);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	ret = write(1, "Hello", 6);
	printf(" | ret = %d\n\n", ret);

	// ft_read
	write(1, "\033[1;32mMINE : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = ft_read(fd, buf, 20);
	close(fd);
	printf("%s", buf);
	printf(" | ret = %d\n", ret);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = read(fd, buf, 20);
	close(fd);
	printf("%s", buf);
	printf(" | ret = %d\n", ret);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:46:13 by jonny             #+#    #+#             */
/*   Updated: 2020/08/21 14:40:54 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main(void)
{
	int ret;
	char buf[20];
	char *buf_alloc;
	char *str = "";
	char str1[20];
	char *str2 = "Salut";
	int fd;

	puts("\n----------- ft_write -----------");

	// ft_write test 1
	write(1, "\033[1;32mMINE : \033[0m", 18);
	ret = ft_write(1, "Hello", 6);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	ret = write(1, "Hello", 6);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	// ft_write test 2
	write(1, "\033[1;32mMINE : \033[0m", 18);
	ret = ft_write(1, NULL, 1);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	ret = write(1, NULL, 1);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	// ft_write test 3
	write(1, "\033[1;32mMINE : \033[0m", 18);
	ret = ft_write(1, "", 1);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	ret = write(1, "", 1);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	puts("\n----------- ft_read -----------");

	// ft_read test 1 - static buffer
	write(1, "\033[1;32mMINE : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = ft_read(fd, buf, 20);
	close(fd);
	printf("%s", buf);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = read(fd, buf, 20);
	printf("%s", buf);
	close(fd);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	// ft_read test 2 - allocated buffer
	buf_alloc = calloc(sizeof(char), 40);

	write(1, "\033[1;32mMINE : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = ft_read(fd, buf_alloc, 40);
	close(fd);
	write(1, buf_alloc, 40);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = read(fd, buf_alloc, 40);
	close(fd);
	write(1, buf_alloc, 40);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	free(buf_alloc);

	// ft_read test 3 - NULL buffer
	buf_alloc = NULL;

	write(1, "\033[1;32mMINE : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = ft_read(fd, buf_alloc, 40);
	close(fd);
	write(1, buf_alloc, 40);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	fd = open("testfiles/text-01.txt", O_RDONLY);
	ret = read(fd, buf_alloc, 40);
	close(fd);
	write(1, buf_alloc, 40);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	puts("\n----------- ft_strlen -----------");

	// ft_strlen test 1
	write(1, "\033[1;32mMINE : \033[0m", 18);
	ret = ft_strlen("Hello");
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	ret = strlen("Hello");
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	// ft_strlen test 2
	write(1, "\033[1;32mMINE : \033[0m", 18);
	ret = ft_strlen(str);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	ret = strlen(str);
	printf(" | ret = %d", ret);
	printf(" | errno = %d\n", errno);

	puts("\n----------- ft_strcpy -----------");

	// ft_strcpy test 1
	write(1, "\033[1;32mMINE : \033[0m", 18);
	str = ft_strcpy(str1, str2);
	printf("%s", str);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	str = strcpy(str1, str2);
	printf("%s", str);
	printf(" | errno = %d\n", errno);

	// ft_strcpy test 2
	str = malloc(sizeof(char) * 20);
	str2 = "Hello, world!";

	write(1, "\033[1;32mMINE : \033[0m", 18);
	str = ft_strcpy(str1, str2);
	printf("%s", str);
	printf(" | errno = %d\n", errno);

	write(1, "\033[1;31mREAL : \033[0m", 18);
	str = strcpy(str1, str2);
	printf("%s", str);
	printf(" | errno = %d\n", errno);

	return (EXIT_SUCCESS);
}

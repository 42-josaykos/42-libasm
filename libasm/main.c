/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 14:46:13 by jonny             #+#    #+#             */
/*   Updated: 2020/08/15 14:58:48 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

ssize_t ft_write(int fd, const void *buf, size_t count);

int main(void)
{
	ft_write(1, "Hello\n", 6);
	return (0);
}

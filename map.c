/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:04:23 by lkiloul           #+#    #+#             */
/*   Updated: 2025/01/21 02:34:00 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
 int check_map(char **argv)
 {
    char *line;
    int fd;
    int i;

    i = 0;
    ssize_t bytes_read;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (-1);
    line = malloc(1024);
    if (!line)
        return (-1);
    bytes_read = read(fd, line, 1023);
    if (bytes_read == -1)
    {
        free(line);
        close(fd);
        return (-1);
    }
    line[bytes_read] = '\0';
    while (line[i])
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E' && line[i] != 'C' && line[i] != '\n')
            return (0);
        i++;
    }
    free(line);
    close(fd);
    return (1);
 }
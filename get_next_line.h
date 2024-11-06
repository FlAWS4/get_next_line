/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:22:22 by mshariar          #+#    #+#             */
/*   Updated: 2024/11/06 17:26:39 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

typedef struct s_list
{
	char			buffer[BUFFER_SIZE];
	char			*content;
	struct s_list	*next;
}		t_list;

t_list	*list_last(t_list *list);
int		get_len(t_list *list);
void	copy_lines(t_list *list, char *str);
char	*get_next_line(int fd);
void	free_malloc(t_list **list, t_list *newnode, char *buff);
int		find_newline(t_list *list);
char	*nxt_line(t_list *list);
void	write_line(t_list **list, char *buff);
void	create_list(t_list **list, int fd);
void	list_clear(t_list **list);

#endif
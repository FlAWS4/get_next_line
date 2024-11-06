/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:26:50 by mshariar          #+#    #+#             */
/*   Updated: 2024/11/06 19:13:20 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nxt_line(t_list *list)
{
	int		len;
	char	*strs;

	if (list == NULL)
		return (NULL);
	len = get_len(list);
	strs = malloc(len + 1);
	if (!strs)
		return (NULL);
	copy_lines(list, strs);
	return (strs);
}

void	lst_new_and_append(t_list **list, char *buff)
{
	t_list	*newnode;
	t_list	*last_node;

	last_node = list_last(*list);
	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return ;
	newnode->content = buff;
	newnode->next = NULL;
	if (last_node == NULL)
		*list = newnode;
	else
		last_node->next = newnode;
	
}

void	create_list(t_list **list, int fd)
{
	char	*buff;
	int		chars_read;

	while (!find_newline(*list))
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buff == NULL)
			return ;
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buff);
			return ;
		}
		buff[chars_read] = '\0';
		lst_new_and_append(list, buff);
	}
}

void	list_clear(t_list **list)
{
	int		i;
	int		j;
	t_list	*last_node;
	t_list	*newnode;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	newnode = malloc(sizeof(t_list));
	if (buff == NULL || newnode == NULL)
		return ;
	last_node = list_last(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[i++])
		buff[j++] = last_node->content[i];
	buff[j] = '\0';
	newnode->content = buff;
	newnode->next = NULL;
	free_malloc(list, newnode, buff);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &newline, 0) < 0)
	{
		free(list);
		free(newline);
		list = NULL;
		return (NULL);
	}
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	newline = nxt_line(list);
	{
		if (!newline)
			free()
	}
	list_clear(&list);
	return (newline);
}

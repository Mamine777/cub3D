/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:58:38 by mokariou          #+#    #+#             */
/*   Updated: 2025/01/31 12:11:40 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 64
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_gnl
{
	char			*str;
	struct s_gnl	*next;
}	t_gnl;

typedef struct t_stack
{
	t_gnl	*top;
	int		size;
}	t_stack;

void	deallocate(t_stack *list, t_gnl *new_node, char *buffer);
void	add_stack(t_stack *stack, char *buffer);
char	*ft_strcpy(char *str, t_stack *stack);
void	create(t_stack *list, int fd);
char	*get_da_line(t_stack *stack);
void	next_call(t_stack *stack);
char	*get_next_line(int fd);
int		len_to_ln(t_stack *stack);
int		new_line(t_stack *stack);
char	*extract_after_newline(t_stack *stack);

#endif
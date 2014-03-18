/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:08:12 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/03/18 16:08:49 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
typedef unsigned int u_int;
typedef struct		s_list
{
	void			*data;
	size_t			size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				lst_pushback(t_list **list, void *data, size_t size);
void				lst_free(t_list **list);
#endif /* !LIST_H */

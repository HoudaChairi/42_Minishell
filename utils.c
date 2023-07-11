/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:54:33 by hchairi           #+#    #+#             */
/*   Updated: 2023/07/11 15:18:30 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_lstaddback(t_nodes *node, t_nodes *new)
{
	if (!node || !new)
		return ;
	while (node->next)
		node = node->next;
	node->next = new;
}

void	g_all_clear_cmd()
{
	t_cmd	*tmp;
	int i;
	t_cmd	*tmp_next;

	if (!g_all.cmd)
		return ;
	
	tmp = g_all.cmd;
	while (tmp)
	{
		i = -1;
		tmp_next = tmp->next;
		while (tmp->data[++i])
			free (tmp->data[i]); // ??
		free (tmp->data);
		free (tmp);
		tmp = tmp_next;
	}
	g_all.cmd = NULL;
}

void	g_all_clear()
{
	t_nodes	*tmp;
	t_nodes	*tmp_next;

	if (!g_all.head)
		return ;
	tmp = g_all.head;
	while (tmp)
	{
		tmp_next = tmp->next;
		free (tmp->valeur);
		free (tmp);
		tmp = tmp_next;
	}
	g_all.head = NULL;
}

int    char_special(int c)
{
    if (c == '-' || c == '+' || c == '/' || c == '^'
        || c == '%' || c == '.' || c == ',' || c == '=')
        return (1);
    return (0);
}

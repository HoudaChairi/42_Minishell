/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:07:44 by hchairi           #+#    #+#             */
/*   Updated: 2023/07/13 21:43:51 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char* get_node_value(t_env* head, char* var) 
{
    t_env* curr;
    
    if (!var)
        return (NULL);
    curr = head;
    if (!ft_strncmp(var, "$", 1))
        return (ft_strdup("1337"));
    if (!ft_strncmp(var, "?", 1))
        return (ft_itoa(g_all.status_val));
    while (curr != NULL) 
    {
        // cherche variable jusqu'a '='
        if (ft_strncmp(curr->s, var, ft_strlen(var)) == 0 && curr->s[ft_strlen(var)] == '=')
            return (ft_substr(curr->s, ft_strlen(var) + 1, ft_strlen(curr->s) - ft_strlen(var)));
        curr = curr->next;
    }
    return (NULL);
}

int check_node(t_nodes *node)
{
    int i;

    i = 0;
    if (node->valeur && (node->valeur[i] == '_' || ft_isalpha(node->valeur[i])))
        while(node->valeur && (node->valeur[++i] == '_' || ft_isalnum(node->valeur[i])))
            ;
    else
        i = 1;
    return (i);
}

void    rm_quotes()
{
    t_nodes *node;

    node = g_all.head;
    if (node && node->quotes == 0 && (node->type == DOUBLES_QUOTES || node->type == SINGLE_QUOTES) && node->next)
    {
        node = g_all.head->next;
        free(g_all.head->valeur);
        free(g_all.head);
        g_all.head = node;
    }
    while (node  && node->next)
    {
        if (node->next && node->next->quotes == 0 && (node->next->type == DOUBLES_QUOTES || node->next->type == SINGLE_QUOTES) && node)
        {
            free_node_exp(node);
        }
        else if (node->next)
            node = node->next;
    }
}

int check_space(char *value)
{
    int i;

    i = 0;
    if (!value)
        return (0);
    while (value[i])
    {
        if (value[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}


void    save_list(t_nodes **node, char *val)
{
	int i;

	i = 0;
    char **tab = ft_split(val, ' ');
	while (tab[i])
	{
        lstaddback_save(node, lstnew_expand(tab[i]));
		i++;
	}
    // i = 0;
    // while (tab[i++])
    //     free(tab[i]);
    // free(tab);
}


char    *global_expand(t_env *env)
{
    t_nodes *head;
    t_nodes *save;
    char    *expand_val;
    int i;
    int len;

    head = g_all.head;
    save = NULL;
    while (head != NULL && head->next != NULL)
    {
        if (head->type == DOLLAR && !head->next)
            ;
        if (head->type == DOLLAR && head->quotes == 0 && head->next && head)
        {
            expand_val = get_node_value(env, ft_substr(head->next->valeur, 0, check_node(head->next)));
            if (check_space(expand_val))
            {
                save_list(&save, expand_val);
                if (save && head->next->next)
                    ft_lstlast(save)->next = head->next->next;
                delete_node_expanded(head, save);
                head = save;
            } 
        }
        if (head && head->next && head->type == DOLLAR && head->quotes != 1 && !char_special(head->next->valeur[0]))
        {
            len = ft_strlen(head->next->valeur);
            i = check_node(head->next);
            expand_val = get_node_value(env, ft_substr(head->next->valeur, 0, i));
            head->valeur = ft_strjoin(expand_val, ft_substr(head->next->valeur, i, len)); 
            free_node_exp(head); // exp "$@USER" -> @USER pour free node qui est apres dollar
        }
        // free(expand_val);
        if (head)
            head = head->next;
    }
    rm_quotes();
    link_strings();
    link_tous();
    // free(expand_val);
    return (NULL);
}

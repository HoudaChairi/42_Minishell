/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:35:19 by hchairi           #+#    #+#             */
/*   Updated: 2023/07/12 12:58:37 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_readline(char **env)
{
    t_env *env_n = NULL;

    g_all.status_val = 0;
    while (1)
    {
        g_all.line = readline("minishell> ");
        if (g_all.line == NULL)
            return ;
        add_history(g_all.line);
        split_function();
        if (syntaxe_err())
        {
            printf("syntaxe err \n");
            g_all_clear();
            continue;
        }
        change_type();
        save_env(&env_n, env);
        global_expand(env_n);
        // voir_nodes();
        g_all_clear();
    }
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    // (void)env;
    ft_readline(env);
    return 0;
}





//---------? print nodes env
        // t_node *curr = node;

        // while (curr)
        // {
        //     printf("%s\n", curr->s);
        //     curr = curr->next;
        // }
// -------> print env
    // while (env[i] != NULL)
    // {
    //     printf("%s\n", env[i]);
    //     i++;
    // }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:35:20 by fbelahse          #+#    #+#             */
/*   Updated: 2023/07/28 15:12:27 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_.h"

void dup_first(t_path *path, int fd)
{
	if (dup2(path->pipes_fd[fd][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		return;
	}
	close(path->pipes_fd[fd][0]);
	close(path->pipes_fd[fd][1]);
}

void dup_middle(t_path *path, int fd)
{
	if (dup2(path->pipes_fd[fd - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		return;
	}
	close(path->pipes_fd[fd - 1][0]);
	close(path->pipes_fd[fd - 1][1]);
	if (dup2(path->pipes_fd[fd][1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		return;
	}
	close(path->pipes_fd[fd][0]);
	close(path->pipes_fd[fd][1]);
}

void dup_end(t_path *path, int fd)
{
	if (dup2(path->pipes_fd[fd - 1][0], STDIN_FILENO) == -1)
		{
			perror("dup2");
			return;
		}
		close(path->pipes_fd[fd - 1][0]);
		close(path->pipes_fd[fd - 1][1]);
}

void close_pipes(t_path *path)
{
	int i;
	t_cmd *tmp;
	
	i = 0;
	tmp = g_all.cmd;
	while (i < path->n_pipes)
	{
		close(path->pipes_fd[i][0]);
		close(path->pipes_fd[i][1]);
		i++;
	}
	while (tmp)
	{
		if (tmp->in != 0)
			close(tmp->in);
		if (tmp->out != 1)
			close(tmp->out);
		tmp = tmp->next;
	}
}

char *find_path(t_env *env)
{
    char **key_value;
	char *path;
	int i;

	i = 0;
    while (env)
    {
        key_value = ft_split(env->s, '=');
        if (!ft_strncmp(key_value[0], "PATH", ft_strlen(env->s)))
		{
            path = key_value[1];
			free_val(key_value);
			free(key_value);
			break;
		}
		free_val(key_value);
        env = env->next;
    }
	return (path);
}

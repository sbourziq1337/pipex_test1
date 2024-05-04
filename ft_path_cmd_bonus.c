/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:16:21 by sbourziq          #+#    #+#             */
/*   Updated: 2024/04/27 19:16:23 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strlen_space(char *av, char c)
{
	int	i;

	i = 0;
	while (av[i] != '\0' && av[i] != c)
		i++;
	return (i);
}

char	*ft_check_space(char *av, char c, t_alloc **gc)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)gc_malloc(gc, (ft_strlen_space(av, ' ') + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '/';
	i++;
	while (av[j] != '\0' && av[j] != c)
	{
		str[i] = av[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(char *str, char *path, int line)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (i < line)
	{
		if (str[i] == path[i])
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_find_path(t_cmd *ptr, char **str, char **cmd, t_alloc **gc)
{
	int	i;

	i = 0;
	ptr->access_path = ft_helper_find_path(gc, ptr);
	if (ptr->access_path == NULL)
		return ;
	while ((ptr->access_path)[i] != NULL)
	{
		(ptr->access_path)[i] = ft_strjoin((ptr->access_path)[i], *cmd);
		if (access((ptr->access_path)[i], F_OK) == 0)
		{
			if (access((ptr->access_path)[i], X_OK) == 0)
				*str = (ptr->access_path)[i];
			else
				ft_erorr_cmmd(ptr, i, gc);
		}
		i++;
	}
}

char	*ft_check_path(t_cmd *ptr, char *argv, t_alloc **gc)
{
	char	*cmd;
	int		i;
	char	*str;

	i = 0;
	if (ft_chck_spase(argv) == 1)
		return (NULL);
	cmd = ft_check_space(argv, ' ', gc);
	if (cmd == NULL)
		return (NULL);
	str = NULL;
	if (ft_strchr(argv, '/') != NULL || argv[0] == '.')
	{
		ptr->access_path = ft_split(argv, ' ', gc);
		if (access((ptr->access_path)[0], F_OK) == 0)
		{
			if (access((ptr->access_path)[0], X_OK) == 0)
				str = (ptr->access_path)[0];
			else
				ft_erorr_cmmd(ptr, 0, gc);
		}
	}
	else
		ft_find_path(ptr, &str, &cmd, gc);
	return (str);
}

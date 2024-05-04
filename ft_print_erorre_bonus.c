/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_erorre_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:17:04 by sbourziq          #+#    #+#             */
/*   Updated: 2024/04/27 19:17:09 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_erorr_infile(t_cmd *str, int i, t_alloc **gc)
{
	if ((access(str->av[1], F_OK)) == 0)
	{
		if ((access(str->av[i + 1], R_OK)) < 0)
		{
			perror(str->av[1]);
			(ft_lstclear(gc), exit(1));
		}
	}
	write(2, str->av[1], ft_strlen(str->av[1]));
	write(2, ": No such file or directory\n", 29);
	(ft_lstclear(gc), exit(1));
}

void	ft_erorr_outfiel(t_cmd *str, t_alloc **gc)
{
	perror(str->av[str->ac - 1]);
	(ft_lstclear(gc), exit(1));
}

void	ft_erorr_cmmd(t_cmd *ptr, int i, t_alloc **gc)
{
	perror((ptr->access_path)[i]);
	(ft_lstclear(gc), exit(126));
}

int	ft_chck_spase(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str == NULL || str[i] == '\0')
		return (1);
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == ' ')
		return (1);
	return (0);
}

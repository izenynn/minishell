/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostal- <acostal-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:36:37 by acostal-          #+#    #+#             */
/*   Updated: 2021/11/22 17:24:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void	p_print_error(void)
{
	write(STDERR_FILENO, "pwd: too many arguments\n", 25);
	g_sh.status = 1;
}

int	ft_get_wdir(const char *n)
{
	char	*pwd;

	pwd = (char *)malloc(sizeof(char) * PATH_MAX);
	if (!pwd)
		return (1);
	if (!n)
	{
		if (getcwd(pwd, PATH_MAX))
		{
			write(STDOUT_FILENO, pwd, ft_strlen(pwd));
			write(STDOUT_FILENO, "\n", 1);
			g_sh.status = 0;
			free(pwd);
			return (0);
		}
		else
		{
			g_sh.status = 1;
			free(pwd);
			return (1);
		}
	}
	p_print_error();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:27:40 by mporcher          #+#    #+#             */
/*   Updated: 2015/06/02 15:38:27 by mporcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	flag_list(t_format *flag)
{
	flag[0].name = '%';
	flag[0].func = &flag_percent;
	flag[0].disabled = "0";
	flag[1].name = 's';
	flag[1].func = &flag_s;
	flag[1].disabled = "0";
	flag[2].name = 's';
	flag[2].func = &flag_s;
	flag[2].disabled = "0";
	flag[3].name = 'S';
	flag[3].func = &flag_s;
	flag[3].disabled = "0";
	flag[4].name = 'd';
	flag[4].func = &flag_d;
	flag[4].disabled = "";
	flag[5].name = 'D';
	flag[5].func = &flag_d;
	flag[5].disabled = "";
	flag[6].name = 'i';
	flag[6].func = &flag_d;
	flag[6].disabled = "";
	flag[7].name = 'o';
	flag[7].func = &flag_o;
	flag[7].disabled = "+";
}

void	flag_list2(t_format *flag)
{
	flag[8].name = 'O';
	flag[8].func = &flag_o;
	flag[8].disabled = "+";
	flag[9].name = 'u';
	flag[9].func = &flag_u;
	flag[9].disabled = "+";
	flag[10].name = 'U';
	flag[10].func = &flag_u;
	flag[10].disabled = "+";
	flag[11].name = 'x';
	flag[11].func = &flag_x;
	flag[11].disabled = "+";
	flag[12].name = 'X';
	flag[12].func = &flag_x;
	flag[12].disabled = "+";
	flag[13].name = 'c';
	flag[13].func = &flag_c;
	flag[13].disabled = "";
	flag[14].name = 'C';
	flag[14].func = &flag_c;
	flag[14].disabled = "";
}

void	flag_list3(t_format *flag)
{
	flag[15].name = 'p';
	flag[15].func = &flag_p;
	flag[15].disabled = "";
	flag[16].name = '\0';
	flag[16].func = NULL;
	flag[16].disabled = NULL;
}

void	format_len(char **tab)
{
	tab[0] = "hh";
	tab[1] = "h";
	tab[2] = "ll";
	tab[3] = "l";
	tab[4] = "L";
	tab[5] = "j";
	tab[6] = "t";
	tab[7] = "I";
	tab[8] = "z";
	tab[9] = NULL;
}

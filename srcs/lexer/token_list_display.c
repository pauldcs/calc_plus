/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:24:02 by pducos            #+#    #+#             */
/*   Updated: 2022/11/06 18:26:17 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include "lexer.h"

void token_list_display(t_token *list)
{
	t_token *tmp;

	tmp = list;
	putstr("< ");
	while (tmp)
	{
		if (tmp->kind == TOKEN_VAL)
			putstr("@ ");
		else if (tmp->kind == TOKEN_ADD)
			putstr("+ ");
		else if (tmp->kind == TOKEN_DIV)
			putstr("/ ");
		else if (tmp->kind == TOKEN_MOD)
			putstr("% ");
		else if (tmp->kind == TOKEN_SUB)
			putstr("- ");
		else if (tmp->kind == TOKEN_MUL)
			putstr("* ");
		else if (tmp->kind == TOKEN_LPAREN)
			putstr("[ ");
		else if (tmp->kind == TOKEN_RPAREN)
			putstr("] ");	
		else if (tmp->kind == TOKEN_END)
			putstr(">");	
		tmp = tmp->next;
	}
	putstr("\n");	
}

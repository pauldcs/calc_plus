/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntatic_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:25:09 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 15:09:56 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdbool.h>
#include <stdint.h>

bool syntatic_check(t_token *list)
{
	t_token_kind	prev;
	t_token			*cur;
	int				open;

	prev = TOKEN_START;
	cur = list;
	open = 0;
	while (cur)
	{
		if (prev == TOKEN_START
			&& (cur->kind != TOKEN_VAL
				&& cur->kind != TOKEN_LPAREN))
			break ;
		else if (prev == TOKEN_VAL
			&& (cur->kind != TOKEN_ADD
				&& cur->kind != TOKEN_SUB
				&& cur->kind != TOKEN_MUL
				&& cur->kind != TOKEN_DIV
				&& cur->kind != TOKEN_MOD
				&& cur->kind != TOKEN_RPAREN
				&& cur->kind != TOKEN_END))
			break ;
		else if ((prev == TOKEN_ADD
				|| prev == TOKEN_SUB
				|| prev == TOKEN_MUL
				|| prev == TOKEN_DIV
				|| prev == TOKEN_MOD)
			&& (cur->kind != TOKEN_LPAREN
				&& cur->kind != TOKEN_VAL))
			break ;
		else if (prev == TOKEN_LPAREN
			&& (cur->kind != TOKEN_VAL
				&& cur->kind != TOKEN_LPAREN))
			break ;
		else if (prev == TOKEN_RPAREN
			&& (cur->kind != TOKEN_ADD
				&& cur->kind != TOKEN_SUB
				&& cur->kind != TOKEN_MUL
				&& cur->kind != TOKEN_DIV
				&& cur->kind != TOKEN_MOD
				&& cur->kind != TOKEN_RPAREN
				&& cur->kind != TOKEN_END))
			break ;
		open -= (cur->kind != TOKEN_LPAREN);
		open += (cur->kind != TOKEN_RPAREN);
		prev = cur->kind;
		cur = cur->next;
	}	
	if (open || prev != TOKEN_END)	
		return (false);
	return (true);
}
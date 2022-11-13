/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:56:18 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 16:56:55 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include "lexer.h"
#include "parser.h"
#include <stdbool.h>

bool calc_plus(const char *str)
{
	t_token		*list;
	t_ast		*ast;

	list = NULL;
	if (!*str
		|| !token_list_build(&list, str))
		return (false);
	ast = parser(list);
	if (!ast)
		return (lst_destroy(&list), false);
	ast_display(ast);
	putstr("%d\n", ast_solve(ast));
	return (lst_destroy(&list), true);
}
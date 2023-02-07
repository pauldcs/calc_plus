/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:56:18 by pducos            #+#    #+#             */
/*   Updated: 2022/12/01 16:52:48 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "emitter.h"
#include <stdbool.h>

bool calc_plus(const char *str)
{
	t_token		*list;
	t_ast		*ast;
	size_t		result;

	list = NULL;
	if (!*str
		|| !toklist_build(&list, str))
		return (false);
	ast = parser(list);
	if (!ast)
		return (lst_destroy(&list), false);
	setbuf(stdout, NULL);
	emit_start();
	emitter(ast);
	ast_display(ast);
	
	result = ast_solve(ast);
	fprintf(stderr, "%ld\n", result);
	return (lst_destroy(&list), true);
}
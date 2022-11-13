/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:02:40 by pducos            #+#    #+#             */
/*   Updated: 2022/11/13 16:54:38 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstringf.h"
#include "lexer.h"
#include "parser.h"
#include <stdbool.h>
#include <math.h>

t_ast	*parser(t_token *list)
{
	t_ast	*ast;

	if (!syntatic_check(list))
		return (putstr("Syntax Error\n"), NULL);
	ast = ast_create(list);
	if (!ast)
		return (fputstr(2, "Failed to build AST\n"), NULL);
	return (ast);
}

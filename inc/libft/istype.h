/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istype.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:25:51 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 23:38:06 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISTYPE_H
# define ISTYPE_H

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isdigit_comma(int c, int *commas);
int		ft_isflag(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		str_is_alnum(char *s);
int		str_is_digit(char *s);
int		str_is_equal(const char *s1, const char *s2);
int		str_is_only_char(char *str, int c);

#endif

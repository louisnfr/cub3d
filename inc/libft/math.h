/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:24:56 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 23:36:13 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

int					ft_abs(int n);
unsigned long long	ft_atoull(const char *str);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
int					ft_atoi_base(char *str, const char *base);
long long			ft_atol(const char *str);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_nbrlen_u(unsigned int n, int base_size);
int					ft_nbrlen_ul(unsigned long n, int base_size);
int					ft_nbrlen(long n, int base_size);
int					ft_rgb_to_color(int t, int r, int g, int b);

#endif

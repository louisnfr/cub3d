/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:26:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 23:37:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

int		ft_put0xhexa_ret(unsigned long n, const char *base);
void	ft_putchar_fd(char c, int fd);
int		ft_putchar_ret(int c);
void	ft_putchar(char c);
void	ft_putendl_fd(char *s, int fd);
int		ft_puthexa_ret(unsigned int n, const char *base);
void	ft_putnbr_fd(int n, int fd);
int		ft_putnbr_u_ret(unsigned int n);
void	ft_putnbr_u(unsigned int n);
int		ft_putnbr_ret(int n);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr_n_ret(char *s, int n);
int		ft_putstr_ret(char *s);
void	ft_putstr(const char *s);

#endif

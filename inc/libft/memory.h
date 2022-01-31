/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:25:58 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 23:37:03 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

int		ft_bzero(void *s);
void	*ft_calloc(int count, int size);
void	clean_free(char **str);
void	free_double_str(char **str);
void	*ft_memccpy(void *dst, const void *src, int c, int n);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
void	*ft_memset(void *b, int c, int len);
void	*ft_realloc(void *ptr, size_t size);
void	ft_swap(int *a, int *b);

#endif

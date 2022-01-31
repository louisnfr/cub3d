/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:26:02 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 23:37:09 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

char	**ft_split_charset(char *str, char *charset);
char	**ft_split_on_first(const char *s, char c);
char	**ft_split(const char *s, char c);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_and_free(char *s1, char *s2);
int		ft_strlcat(char *dst, const char *src, int dstsize);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlen_double_str(char **double_str);
int		ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strnstr(char *haystack, char *needle, int len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(const char *s, int start, int len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		get_next_line(int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:59:04 by amejia            #+#    #+#             */
/*   Updated: 2022/11/23 04:39:28 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

int		evaluator_function_n(char c);
int		ft_str_is_numeric(char *str);
int		check_space(char c);
int		ft_atoi(char *str);
void	ft_delete_char(char *str);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
int		evaluator_function(char c);
int		ft_str_is_printable(char *str);
int		ft_strlen(char *str);
char	*ft_strstr(char *s1, char *s2);
void	ft_putstr(char *str);
int		count_char(int fo);
char	**lines_to_map(char **lines, int n_lines, char *symbols);
char	*read_text_file2(int fo, int fsize);
char	*read_text_file(char *path);
int		count_lines(char *str);
char	**linefy(char *str, int *n_lines);
void	print_lines(char **lines, int n_lines);
int		check_map2(char *symbols, char **lines, int *size);
int		check_map(char **lines, int *size, char *symbols);
void	map_error(void);
void	map_cicle_aux(char **lines, int *size);
void	map_cicle(char *file_content);
void	map_cicle_from_file(char *path);
void	append_nlines(char *bigstr, int nlines, int *nchars);
char	*std_in_to_str(void);
int		solve(char **map, int *sz);
void	find_sol(char **map, int *sz, int *sol);
void	update(char **map, int *sz, int *pos, int *sol);
int		check(char **map, int num, int y, int x);
void	drawsq(char **map, int *sq);
int		number_from_header(char *str);
void	get_symbols(char *str, char *symbols);
void	swap(char **map, int *sz, char *symbols, int mode);
void	swap_old_new(char **map, int *sz, char *old, char *new);

#endif

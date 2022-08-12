/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:27:00 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/26 23:27:03 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

char	*ft_itoa_simple(int number);
void	find_and_print(int number, char **keys, char **values);
void	print_numbers(char **keys, char **values, int number, int base);
void	ft_print(char **arr);
void	splitting(char **arr, char *argv);
int		ft_str_compare(char *str1, char *str2);
void	ft_putstr(char *str);
int		is_valid_dict(char **keys);
int		argv_parse(char *argv);
int		ft_strlen(char *src);
int		*input_triada(char *str, int *trd);
int		input_validation(int argc, char **argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:14:06 by marvin            #+#    #+#             */
/*   Updated: 2024/07/18 00:14:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c, int *counter);
int	ft_putstr(char *str, int *counter);
int	ft_putnbr_ptr(unsigned long nbr, char *base, int *counter);
int	ft_putptr(void *ptr, int *counter);
int	ft_putnbr_base(long nbr, char *base, int *counter);
int	ft_printf(const char *str, ...);

#endif
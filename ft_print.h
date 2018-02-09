/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.h                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/28 22:54:17 by JianMing                                 */
/*   Updated: 2017/11/13 17:42:58 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

#include "struct.h"

void	print_read_in(ofstream&, Card*);
double	price_of_order(int, double, ofstream&);
void	print_heading(Card*, Card*, ofstream&);
void	print_total(ofstream&, double, int, int&);

#endif

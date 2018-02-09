/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.h                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/28 21:37:13 by JianMing                                 */
/*   Updated: 2017/11/13 17:42:28 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

#include "struct.h"

using namespace std;

void	get_head(string, ifstream&);
bool	isEmpty(Card*);
void	pushFirstElement(Card*&, Card*&, int, double);
void	push(Card*&, int, double);;
void	check_list(Card*&, Card*&, int, ofstream&, int, int&);
void	pop(Card*&, Card*&);

#endif

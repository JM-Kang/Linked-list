/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.h                                                                 */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/28 20:28:25 by JianMing                                 */
/*   Updated: 2017/11/13 16:27:06 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include <string>
#include <fstream>
#include <iostream> 

using namespace std;

struct Card
{
	char	type;
	int	amt;
	double	price;
	int	discount;
	Card	*next;
	Card();
	Card(ifstream &cin);	
};

#endif

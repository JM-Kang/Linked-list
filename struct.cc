/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   struct.cc                                                                */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/28 20:52:09 by JianMing                                 */
/*   Updated: 2017/11/13 16:22:02 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

Card::Card(void)
{
	type = 'X';
	amt = 0;
	price = 0.00;
	discount = 0.00;
}

Card::Card(ifstream &cin)
{
	char	c;
	cin >> type;
	switch(type)
	{
		case 'R':	cin >> amt;
				cin >> price;
				break;
		case 'S':	cin >> amt;
				break;
		case 'P':	cin >> discount;
				cin >> c;
				break;
		default: 	break;
	}
}

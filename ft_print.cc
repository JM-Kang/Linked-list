/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print.cc                                                              */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/28 22:46:35 by JianMing                                 */
/*   Updated: 2017/11/13 18:52:32 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

//print the read in record
void	print_read_in(ofstream &cout, Card *cur)
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);

	switch(cur->type)
	{
		case 'R':	cout << cur->amt << " of Widgets received, ";
				cout << "and cost: " << cur->price << " each.";
				break;
		case 'S':	cout << cur->amt << " of Widgets sold";
				break;
		case 'P':	cout << cur->discount << "% discount off ";
				cout << "for next two customers.";
				break;
		default: 	break;;
	}
	cout << endl;
}

//print the current price of the order
double	price_of_order(int amt, double price, ofstream &c_out)
{
	c_out << amt << "\t at \t";
	c_out << price * 1.3 << " each \t";

	price = amt * price * 1.3;
	c_out << "Sales: $" << price << endl;
	return (price);
}

//print the total price of the order
void	print_total(ofstream &c_out, double total, int dis, int &num)
{
	double	discount = 1.00;

	//check if the num have value
	if(num)
	{
		c_out << "received " << dis << "% off" << endl;
		discount = 1 - dis * 1.00 / 100;
		num--;
	}
	c_out << "\t\t\t" << "Total Sales: " << total * discount << endl;
}

//print the remaining in stock		
void	print_heading(Card *head, Card *tail, ofstream &c_out)
{
	Card	*temp;
	c_out << "Remaining stock:" << endl;
	
	//check if head not equal tail
	while(head != tail)
	{
		temp = head;
		while(temp->next != tail)
			temp = temp->next;
		c_out << "Widgets " << tail->amt << " in stock ";
		c_out << "and original purchase price is: " << tail->price << endl;
		delete tail;
		tail = temp;
		tail->next = NULL;	
	}
	
	//check if head has value
	if(head)
	{
		c_out << "Widgets " << head->amt << " in stock ";
		c_out << "and original purchase price is: " << head->price << endl;
	}
}	

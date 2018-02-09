/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   testing.cc                                                               */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/28 21:09:58 by JianMing                                 */
/*   Updated: 2017/11/13 18:46:34 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"
#include "ft_print.h"

//check if the file can acess and go through the heading
void	get_head(string filename, ifstream &cin)
{
	char	c;
	
	if(!cin)
		cout << filename << " cannot open, please check." << endl;
	while(cin.get(c))
	{
		if(c == '%')
			break;
	}
}

//ckeck if the address of pointer has value 
bool	isEmpty(Card *head)
{
	if(head == NULL)
		return (true);
	else
		return (false);
}

//push the first card into the first element of the list
void	pushFirstElement(Card *&head, Card *&tail, int amt, double price)
{
	Card *temp = new Card;
	temp->price = price;
	temp->amt = amt;
	temp->next = NULL;
	head = temp;
	tail = temp;
}

//push receipt record into the list
void	push(Card *&head, int amt, double price)
{
	Card *temp = new Card;
	temp->price = price;
	temp->amt = amt ;
	temp->next = head;
	head = temp;
}

//check the list information
void	check_list(Card *&head, Card *&tail, int amt, ofstream &c_out, int dis, int &num)
{        
	double	cur_price = 0.00;
	double	total = 0.00;
	
	while(amt > 0)
	{
		//check if the tail has no value while head equal to tail
		if(!tail->amt && head == tail)
		{
			c_out << "remainder of " << amt <<"  Widgets not available" << endl;
			break;
		}

		//check if the tail amount greater than the sales amount
		if(tail->amt > amt)
		{
			tail->amt -= amt;
			cur_price = price_of_order(amt, tail->price, c_out);
			amt = 0;
		}

		//check if the tail amount less than the asles amount
		else
		{
			//check if the tail of amount have no value
			if(!tail->amt)
				pop(tail, head);
			cur_price = price_of_order(tail->amt, tail->price, c_out);
			amt -= tail->amt;
			tail->amt = 0;
			pop(tail, head);	
		}
		total += cur_price;
	}
	//print the total price of the order
	print_total(c_out, total, dis, num);
}

//pop the tail in the list
void	pop(Card *&tail, Card *&head)
{
	Card	*temp;
	temp = head;
	//check if tail not equal to head
	if(tail != head)
	{
		while(temp->next != tail)
			temp = temp->next;
		delete tail;
		tail = temp;
		tail->next = NULL;
	}
}

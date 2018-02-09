/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.cc                                                                  */
/*                                                                            */
/*   By: JianMing <jason.kang1106@gmail.com>                                  */
/*                                                                            */
/*   Created: 2017/10/25 11:44:33 by JianMing                                 */
/*   Updated: 2017/11/13 18:19:52 by JianMing                                 */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_print.h"
#include "testing.h"

int	main(void)
{
	ifstream	cin;
	ofstream	c_out;
	Card		*tail;
	Card		*head;
	Card		*ca_in;
	int 		count = 0;
	int			discount = 1;

	cin.open("data.txt");
	c_out.open("statement.txt");

	head = NULL;
	tail = NULL;

	//check the first line of the file
	get_head("data.txt", cin);
	while(cin)
	{	
		ca_in = new Card(cin);
		//check if type are RSP
		if(ca_in->type != 'R' && ca_in->type != 'S' && ca_in->type != 'P')
			break;
		//print the read in record
		print_read_in(c_out, ca_in);

		//if the head is empty then push the first elemnet of list
		if(isEmpty(head))
			pushFirstElement(head, tail, ca_in->amt, ca_in->price);
		
		//if the type is R, push the record into list
		else if(ca_in->type == 'R')
			push(head, ca_in->amt, ca_in->price);

		//if the type is S, check the all kind information
		else if(ca_in->type == 'S')
			check_list(head, tail,  ca_in->amt, c_out, discount, count);
		else if(ca_in->type == 'P')
		{
			count = 2;
			discount = ca_in->discount;
		}
		c_out << endl;
		ca_in->type = ' ';
		delete ca_in;
	}
	//print the last remaining in stock
	print_heading(head, tail, c_out);
	cin.close();
	c_out.close();
	return (0);
}		
		

# **************************************************************************** #
#                                                                              #
#                                                                              #
#    makefile                                                                  #
#                                                                              #
#    By: JianMing <jason.kang1106@gmail.com>                                   #
#                                                                              #
#    Created: 2017/10/25 11:51:03 by JianMing                                  #
#    Updated: 2017/10/25 11:57:23 by JianMing                                  #
#                                                                              #
# **************************************************************************** #

NAME = a.out
OBJS = *.o
SRCS = *.cc
HEADER = *.h

all: $(NAME)
	g++ $(OBJS) -o $(NAME)

$(NAME): $(SRCS) $(HEADER)
	g++ -Wall -c $(SRCS)

clean:
	rm -rf $(OBJS)
	rm -rf statement.txt

fclean: clean
	rm -rf $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onouaman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 18:38:53 by onouaman          #+#    #+#              #
#    Updated: 2019/03/06 17:00:57 by onouaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRC = *.c

INCLD = *.h

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) -I $(INCLD)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f a.out
	rm -f libft.a

re: fclean all

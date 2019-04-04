SRCDIR = src
LIB = libs
FLAG = -Wall -Wextra -Werror

INC = ./libftprintf.a
SRC = $(SRCDIR)/Helper\ Func/*.c\
$(SRCDIR)/main\ Func/*.c\
$(SRCDIR)/Type\ d/*.c\
$(SRCDIR)/Type\ diffec/*.c\
$(SRCDIR)/Type\ f/*.c\
$(SRCDIR)/Type\ simple/*.c\
$(SRCDIR)/*.c

OBJ = $(LIB)/*.o

NAME = ./libftprintf.a

all : $(NAME)

main :
	gcc main.c libftprintf.a -o ft_printf

$(NAME):
		make re -C $(LIB)/libft
		@mv $(LIB)/libft/libft.a libs/
		gcc -c $(FLAG) $(SRC)
		@mv *.o libs/
		@mv ./libs/libft/*.o libs/
		ar rc $(INC) $(OBJ) 
		ranlib $(INC)

clean:
		make -C libs/libft clean
		rm -f libs/*.o

fclean: clean
		make -C libs/libft fclean
		rm -f $(INC)

re: fclean all

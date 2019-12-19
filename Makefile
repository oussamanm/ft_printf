SRCDIR = src
LIB = libs
FLAG = -Wall -Wextra -Werror
INC = ./libftprintf.a
SRC = $(SRCDIR)/Helper_Func/*.c\
$(SRCDIR)/Main_Func/*.c\
$(SRCDIR)/Type_d/*.c\
$(SRCDIR)/Opr_Math/*.c\
$(SRCDIR)/Type_diffec/*.c\
$(SRCDIR)/Type_f/*.c\
$(SRCDIR)/Type_simple/*.c\
$(SRCDIR)/BONUS/*.c
OBJ = $(LIB)/*.o
NAME = ./libftprintf.a

all : $(NAME)

$(NAME):
		make re -C $(LIB)/libft
		@mv $(LIB)/libft/libft.a libs/
		gcc -I includes -c $(FLAG) $(SRC)
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
		rm -f $(LIB)/libft.a
		rm -f ./ft_printf

re: fclean all

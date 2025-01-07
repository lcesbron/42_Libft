NAME = libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = libft/
INCLUDE = includes/

LIB_NAME = libft.a
LIB_TARGET = $(addprefix $(LIB_DIR), $(LIB_NAME))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE)

AR = ar
ARFLAGS = -rs

RM = rm -f

SRCS = $(SRC_DIR)ft_printf.c \
	$(SRC_DIR)ft_appends.c \
	$(SRC_DIR)ft_fill.c \
	$(SRC_DIR)ft_lens.c \
	$(SRC_DIR)ft_intlens.c \
	$(SRC_DIR)ft_intappends.c

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(LIB_TARGET) $(NAME)

$(LIB_TARGET): $(LIB_DIR)libft.h
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB_TARGET)
	cp $(LIB_TARGET) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
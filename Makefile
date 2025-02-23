NAME = libft.a

# --- CONFIG ---

CC = cc
CFLAGS = -Wall -Wextra # -Werror
CPPFLAGS = -I $(INCLUDE_DIR) -MMD -MP

AR = ar
ARFLAGS = -rcs

RM = rm -rf

# --- FILES ---

MAKE_DIR = .make/
BUILD_DIR = $(addprefix $(MAKE_DIR), build/)

SRC_DIR = srcs/
INCLUDE_DIR = includes/

SRCS = 

OBJS = $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

DEPS = $(patsubst %.c, $(BUILD_DIR)%.d, $(SRCS))

# --- FT_PRINTF ---

#FT_PRINTF_DIR = $(addprefix $(SRC_DIR), ft_printf)/
FT_PRINTF_DIR = ft_printf/

FT_PRINTF_SRCS =	ft_appends.c \
					ft_fill.c \
					ft_intappends.c \
					ft_intlens.c \
					ft_lens.c \
					ft_printf.c \

SRCS += $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_SRCS))

# --- GET_NEXT_LINE ---

#GET_NEXT_LINE_DIR = $(addprefix $(SRC_DIR), get_next_line)/
GET_NEXT_LINE_DIR = get_next_line/

GET_NEXT_LINE_SRCS = 	get_next_line.c \
						get_next_line_utils.c \

SRCS += $(addprefix $(GET_NEXT_LINE_DIR), $(GET_NEXT_LINE_SRCS))

# --- CHAR ---

#CHAR_DIR = $(addprefix $(SRC_DIR), char)/
CHAR_DIR = char/

CHAR_SRCS =	ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			lc_isspace.c

SRCS += $(addprefix $(CHAR_DIR), $(CHAR_SRCS)) 

# --- STR ---

#STR_DIR = $(addprefix $(SRC_DIR), str)/
STR_DIR = str/

STR_SRCS = 	ft_strlen.c \
    	   	ft_strchr.c \
    	   	ft_strrchr.c \
    	   	ft_strlcpy.c \
    	   	ft_strncmp.c \
		   	ft_strnstr.c \
		   	ft_atoi.c \
		   	ft_strlcat.c \
		   	ft_strdup.c \
		   	ft_substr.c \
		   	ft_strjoin.c \
		   	ft_strtrim.c \
		   	ft_split.c \
		   	ft_itoa.c \
		   	ft_strmapi.c \
		   	ft_striteri.c \
			lc_strtol.c \

SRCS += $(addprefix $(STR_DIR), $(STR_SRCS)) 

# --- FD ---

#FD_DIR = $(addprefix $(SRC_DIR), fd)/
FD_DIR = fd/

FD_SRCS = 	ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

SRCS += $(addprefix $(FD_DIR), $(FD_SRCS)) 

# --- MEM ---

#MEM_DIR = $(addprefix $(SRC_DIR), mem)/
MEM_DIR = mem/

MEM_SRCS = 	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_swap.c

SRCS += $(addprefix $(MEM_DIR), $(MEM_SRCS)) 

# --- LST --- 

#LST_DIR = $(addprefix $(SRC_DIR), lst)/
LST_DIR = lst/

LST_SRCS = 	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

SRCS += $(addprefix $(LST_DIR), $(LST_SRCS)) 

# --- MATHS ---

MATHS_DIR = lc_maths/

MATHS_SRCS =	lc_sqrt.c \
				lc_abs.c

SRCS += $(addprefix $(MATHS_DIR), $(MATHS_SRCS))

# -- RULES ---

.PHONY: all
all: $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "[$(GREEN)✓$(NC)] $(notdir $<)"

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "[$(GREEN)✓$(NC)] $(BOLD)$(NAME)$(NC)"

.PHONY: test
test: $(NAME)
	$(CC) $(CFLAGS) $(CPPFLAGS) test.c -L. -lft -o $@

.PHONY: clean
clean:
	@$(RM) $(MAKE_DIR)
	@echo "[$(GREEN)✓$(NC)] $(BOLD)Clean$(NC)"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "[$(GREEN)✓$(NC)] $(BOLD)Full Clean$(NC)"

.PHONY: re
re: fclean all

-include $(DEPS)

# --- COLORS ---

NC		=	\e[0m
BOLD	=	\033[1m
GREEN 	= 	\033[32m
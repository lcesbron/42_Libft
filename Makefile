NAME = libft.a

# --- FILES ---

include libft_srcs.mk

MAKE_DIR = .make/
BUILD_DIR = $(addprefix $(MAKE_DIR), build/)

SRC_DIR = srcs/
INCLUDE_DIR = includes/

OBJS = $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

DEPS = $(patsubst %.c, $(BUILD_DIR)%.d, $(SRCS))

# --- CONFIG ---

CC = cc
CFLAGS = -Wall -Wextra # -Werror
CPPFLAGS = -I $(INCLUDE_DIR) -MMD -MP

AR = ar
ARFLAGS = -rcs

RM = rm -rf

# -- RULES ---

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "[$(GREEN)✓$(NC)] $(BOLD)$(NAME)$(NC)"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "[$(GREEN)✓$(NC)] $(notdir $<)"

.PHONY: test
test: $(NAME)
	$(CC) $(CFLAGS) $(CPPFLAGS) test.c -L. -lft -g3 -o $@

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
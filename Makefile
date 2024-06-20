# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 20:58:07 by apaula-l          #+#    #+#              #
#    Updated: 2024/06/19 22:42:05 by apaula-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME#
NAME_CLIENT = client
NAME_SERVER = server
.DEFAULT_GOAL := all
.PHONY: all clean fclean re
.SILENT:

#PATH#
SRCS_PATH = ./src/
INCS_PATH = ./include/ ./lib/libft/ ./lib/printf/
BUILD_DIR := ./obj/
LIBFT_DIR := ./lib/libft/
PRINTF_DIR := ./lib/

#FILES#
SRC_CLIENT := $(addprefix $(SRCS_PATH), client/client.c)
SRC_SERVER := $(addprefix $(SRCS_PATH), server/server.c)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
PRINTF = $(addprefix $(PRINTF_DIR), printf.a)
OBJ_CLIENT := $(SRC_CLIENT:$(SRCS_PATH)%.c=$(BUILD_DIR)%.o)
OBJ_SERVER := $(SRC_SERVER:$(SRCS_PATH)%.c=$(BUILD_DIR)%.o)
OBJS = $(OBJ_CLIENT) $(OBJ_SERVER)
DEPS = $(OBJS:.o=.d)

#COMMANDS#
MKDIR = mkdir -p
RM = rm -rf
SLEEP = sleep 0.1
CC = cc

#FLAGS#
CFLAGS = -Wall -Werror -Wextra -g3
DFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
CPPFLAGS = $(addprefix -I ,$(INCS_PATH)) -MMD -MP
LDLIBS = $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a
LDFLAGS = -ldl -lglfw -pthread

#COMPILATION#
COMP_OBJ = $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE_CLIENT = $(CC) $(LDFLAGS) $(OBJ_CLIENT) $(LDLIBS) -o $(NAME_CLIENT)
COMP_EXE_SERVER = $(CC) $(LDFLAGS) $(OBJ_SERVER) $(LDLIBS) -o $(NAME_SERVER)

#FUNCTIONS#
define create_dir
		$(MKDIR) $(dir $@)
endef

define comp_objs
		$(COMP_OBJ)
endef

define comp_libft
		printf "$(CYAN)Building libft files\n$(RESET)"
		$(MAKE) -C $(LIBFT_DIR)
endef

define comp_printf
		printf "$(CYAN)Building printf files\n$(RESET)"
		$(MAKE) -C $(PRINTF_DIR)
endef

define comp_exe_client
		$(COMP_EXE_CLIENT)
		printf "$(PURPLE)CLIENT-> $(RESET)$(GREEN)Ready!\n$(RESET)"
endef

define comp_exe_server
		$(COMP_EXE_SERVER)
		printf "$(PURPLE)SERVER-> $(RESET)$(GREEN)Ready!\n$(RESET)"
endef

#TARGETS#

all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

teste:
	echo 

$(BUILD_DIR)%.o: $(SRCS_PATH)%.c
		$(call create_dir)
		$(call comp_objs)

$(NAME_CLIENT): $(OBJ_CLIENT)
		$(call comp_exe_client)

$(NAME_SERVER): $(OBJ_SERVER)
		$(call comp_exe_server)

$(LIBFT):
		$(call comp_libft)

$(PRINTF):
		$(call comp_printf)

clean:
		$(RM) $(BUILD_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all


-include $(DEPS)
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 20:58:07 by apaula-l          #+#    #+#              #
#    Updated: 2024/07/09 17:55:06 by apaula-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME#
NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
.DEFAULT_GOAL := all
.PHONY: all clean fclean re
.SILENT:

#PATH#
SRCS_PATH = ./src/
SRCS_PATH_BONUS = ./bonus/
INCS_PATH = ./include/ ./lib/libft/ ./lib/printf/
BUILD_DIR := ./obj/
BUILD_DIR_BONUS := ./obj_bonus/
LIBFT_DIR := ./lib/libft/
PRINTF_DIR := ./lib/

#FILES#
SRC_CLIENT := $(addprefix $(SRCS_PATH), client/client.c)
SRC_SERVER := $(addprefix $(SRCS_PATH), server/server.c)
SRC_CLIENT_BONUS := $(addprefix $(SRCS_PATH_BONUS), client/client_bonus.c)
SRC_SERVER_BONUS := $(addprefix $(SRCS_PATH_BONUS), server/server_bonus.c)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
PRINTF = $(addprefix $(PRINTF_DIR), libftprintf.a)
OBJ_CLIENT := $(SRC_CLIENT:$(SRCS_PATH)%.c=$(BUILD_DIR)%.o)
OBJ_SERVER := $(SRC_SERVER:$(SRCS_PATH)%.c=$(BUILD_DIR)%.o)
OBJ_CLIENT_BONUS := $(SRC_CLIENT_BONUS:$(SRCS_PATH_BONUS)%.c=$(BUILD_DIR_BONUS)%.o)
OBJ_SERVER_BONUS := $(SRC_SERVER_BONUS:$(SRCS_PATH_BONUS)%.c=$(BUILD_DIR_BONUS)%.o)
OBJS = $(OBJ_CLIENT) $(OBJ_SERVER)
DEPS = $(OBJS:.o=.d)
OBJS_BONUS = $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
DEPS_BONUS = $(OBJS_BONUS:.o=.d)

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
COMP_EXE_CLIENT_BONUS = $(CC) $(LDFLAGS) $(OBJ_CLIENT_BONUS) $(LDLIBS) -o $(NAME_CLIENT_BONUS)
COMP_EXE_SERVER_BONUS = $(CC) $(LDFLAGS) $(OBJ_SERVER_BONUS) $(LDLIBS) -o $(NAME_SERVER_BONUS)

#FUNCTIONS#
define create_dir
		$(MKDIR) $(dir $@)
endef

define bonus
		$(MAKE) WITH_BONUS=TRUE
endef

define comp_objs
		$(COMP_OBJ)
endef

define comp_libft
		printf "Building libft files\n"
		$(MAKE) -C $(LIBFT_DIR)
endef

define comp_printf
		printf "Building printf files\n"
		$(MAKE) -C $(PRINTF_DIR)
endef

define comp_exe_client

define comp_exe_client_bonus
		$(COMP_EXE_CLIENT_BONUS)
		printf "CLIENT_BONUS-> Ready!\n"
endef

define comp_exe_server_bonus
		$(COMP_EXE_SERVER_BONUS)
		printf "SERVER_BONUS-> Ready!\n"
endef

#TARGETS#

all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)
bonus: $(LIBFT) $(PRINTF) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(BUILD_DIR)%.o: $(SRCS_PATH)%.c
		$(call create_dir)
		$(call comp_objs)

$(BUILD_DIR_BONUS)%.o: $(SRCS_PATH_BONUS)%.c
		$(call create_dir)
		$(call comp_objs)

$(NAME_CLIENT): $(OBJ_CLIENT)
		$(call comp_exe_client)

$(NAME_SERVER): $(OBJ_SERVER)
		$(call comp_exe_server)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
		$(call comp_exe_client_bonus)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
		$(call comp_exe_server_bonus)

$(LIBFT):
		$(call comp_libft)

$(PRINTF):
		$(call comp_printf)

clean:
		$(RM) $(BUILD_DIR)
		$(RM) $(BUILD_DIR_BONUS)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

-include $(DEPS)

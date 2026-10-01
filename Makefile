##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME		= amazed

SRCS		= src/main.c \
			  src/free_all/free_all.c \
			  src/innit/innit_struct_amazed.c \
			  src/innit/innit_struct_info.c \
			  src/innit/innit_cells.c \
			  src/innit/innit_path.c \
			  src/innit/innit_cells_name.c \
			  src/fill_linked_list/create_tab_node.c \
			  src/innit/check_backslash_n.c \
			  src/print_parsing.c \
			  src/fill_linked_list/fill_node.c \
			  src/fill_linked_list/create_node.c \
			  src/fill_linked_list/add_node_next.c \
			  src/fill_linked_list/realloc_linked_list.c \
			  src/find_all_path/find_all_path.c \
			  src/fill_linked_list/add_node_previous.c \
			  src/check/check_multiple_start_end.c \
			  src/check/check_name_coord.c \
			  src/move_robots/move_robots.c \
			  src/fill_linked_list/add_node.c

OBJS     = $(SRCS:.c=.o)

CFLAGS   = -Wall -Wextra -I include -I lib/include

	GREEN=\033[1;32m
	YELLOW=\033[1;93m
	GREY=\033[2;49m
	ITALIC=\033[3m
	NC=\033[0m

all: $(NAME)

$(NAME): build_lib $(OBJS)
	 	@ gcc -o $(NAME) $(OBJS) -L./lib -lmy

build_lib:
	make -C ./lib

clean:
	make fclean -C ./lib
	@ $(RM) $(OBJS)
	@ find . -name "#*#" -delete -o -name "*~" -delete
	@ $(RM) coding-style-reports.log
	@ $(RM) vgcore*

fclean: clean
	@ $(RM) a.out
	@ $(RM) lib/libmy.a
	@ $(RM) $(NAME)

re: fclean all

debug: fclean
debug: CFLAGS += -g
debug: all

.c.o:
	@ $(CC) -o $(subst .c,.o,$<) -c $< $(CFLAGS) \
		&& echo -e "[ ${GREEN}OK${NC} ] ${GREY}$<${NC}" \
		|| echo -e "[ ${YELLOW}KO${NC} ] ${ITALIC}$<${NC}"

.PHONY: re fclean clean all .c.o

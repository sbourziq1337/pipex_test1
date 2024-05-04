SORBN = ft_split_bonus.c ft_path_cmd_bonus.c write_path_bonus.c pipex_bonus.c ft_creat_child_bonus.c ft_hanld_nor_bonus.c ft_free_bonus.c ft_print_erorre_bonus.c ft_helper_bonus.c
SOR = ft_split.c ft_path_cmd.c write_path.c pipex.c ft_creat_child.c ft_hanld_nor.c ft_free.c ft_print_erorre.c ft_helper.c
OBJC=$(SOR:.c=.o)
OBJCBN=$(SORBN:.c=.o)
NAME = pipex
BNAME = pipex_bonus
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJC)
	$(CC) -o $@ $^

bonus: $(BNAME)

$(BNAME): $(OBJCBN)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJC) $(OBJCBN)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

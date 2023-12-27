SRCS = window.c map.c map1.c map2.c map3.c main.c window1.c

OBJS = $(SRCS:.c=.o)

LIBFTDIR = lib/

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

HEADER = so_long.h

INC = mlx/

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) make_libs
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) \
	-lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

make_libs:
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(INC)

clean:
	$(RM) $(OBJS) 
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(INC) clean

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(INC) clean
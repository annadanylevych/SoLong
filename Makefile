SRCS = 

OBJS = $(SRCS:.c=.o)

LIBFTDIR = lib/

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

INC = minilib/

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) make_libs
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)
	$(CC) -02 $(OBJS) -L$(INC) -lmlx -o $(NAME)


make_libs:
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(INC)

clean:
	$(RM) $(OBJS) 
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBFTDIR) fclean
HDIR	:=	hdr/
SDIR	:=	src/
ODIR	:=	obj/
CC		:=	cc
MLX		:=	/home/ll-hotel/p/cc2/minilibx-linux/
DEBUG	=
CFLAGS	:=	-Wall -Wextra -Werror $(DEBUG)
IFLAGS	:=	-I$(HDIR) -I$(MLX) -I./libft/
LFLAGS	:=	-L$(MLX) -L./libft -lft -lmlx_Linux -lm -lX11 -lXext
hdr		:=	fdf_data fdf_events fdf ft_put_pixels fdf_map
obj		:=	fdf_events fdf_data ft_put_pixels main fdf_parser
HDR		=	$(hdr:%=$(HDIR)%.h)
OBJ		=	$(obj:%=$(ODIR)%.o)
NAME	:=	fdf
LIBFT	:=	libft/libft.a

.PHONY: clean fclean re all tmp

all: $(LIBFT) $(NAME)

$(NAME): $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $(OBJ) $(LFLAGS)

$(ODIR):
	mkdir $(ODIR)

$(ODIR)%.o: $(SDIR)%.c $(HDR)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(LIBFT): libft
	cd libft && make

clean:
	cd libft && make clean
	rm -rf $(ODIR)

fclean:
	cd libft && make fclean
	make clean
	rm -f $(NAME)

re: fclean all

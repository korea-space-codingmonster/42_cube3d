NAME = cube3D

CC = gcc -g -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -g

CFLAGS = 


###################### libft #########################
LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_INC_DIR)
#####################################################

###################### minilibx #####################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_SUBMODULE = git submodule update --init
	MLX = libmlx.a
	MLX_DIR = lib/minilibx-linux
	MLX_FLAGS = -L./$(MLX_DIR) -lmlx -lXext -lX11 -lm
	MLX_NOTIC = @printf "✅ $(FG_TEXT_PRIMARY)If you having trouble building minilibx library, \
	try installing the package below.\n\
	$(FG_TEXT)$(CL_BOLD)gcc make xorg libxext-dev libbsd-dev$(NO_COLOR)\n"
endif
ifeq ($(UNAME_S), Darwin)
	MLX = libmlx.dylib
	MLX_DIR = lib/minilibx_mms_20200219
	MLX_FLAGS = -L./$(MLX_DIR) -lmlx
	MLX_CP = cp $(MLX_FILE) $(MLX)
	MLX_RM = rm -f $(MLX)
endif
#####################################################

MLX_FILE = $(MLX_DIR)/$(MLX)
MLX_INC_DIR = $(MLX_DIR)
CINCLUDES += -I $(MLX_INC_DIR)

RM = rm
RMFLAGS = -f

INC_DIR = include
CINCLUDES += -I $(INC_DIR)
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(wildcard $(INC_DIR)/*.h)

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(wildcard $(UTIL_DIR)/*.c)

INIT_DIR = $(SRC_DIR)/init
INIT_SRCS = $(wildcard $(INIT_DIR)/*.c)

CAL_DIR = $(SRC_DIR)/cal
CAL_SRCS = $(wildcard $(CAL_DIR)/*.c)

KEY_DIR = $(SRC_DIR)/key_event
KEY_SRCS = $(wildcard $(KEY_DIR)/*.c)

SRCS = \
		$(wildcard $(SRC_DIR)/*.c) \
		$(UTIL_SRCS) \
		$(INIT_SRCS) \
		$(CAL_SRCS)  \
		$(KEY_SRCS)  \


vpath %.c \
		$(SRC_DIR) \
		$(UTIL_DIR) \
		$(INIT_DIR) \
		$(CAL_DIR)	\
		$(KEY_DIR)  \


OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

########################### color ##########################
CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)
##############################################################


########################### compile ##########################
all : $(NAME)

clean : 
		$(RM) $(RMFLAGS) $(OBJS)
		printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY) $(NAME)'s Object files...\n"

fclean : clean
		$(RM) $(RMFLAGS) $(NAME)
		printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY) $(NAME)"

re :	fclean all

lib_clean : $(LIBFT)_fclean
##############################################################


####################### cube3d 실행단 ##########################
$(OBJ_DIR) : 
		mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
		$(CC) $(CDEBUG) $(CFLAGS) $(CINCLUDES) -c $< -o $@
		printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"
$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
		$(CC) $(CDEBUG) $(CFALGS) $(CINCLUDES) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)
		printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
		printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)cub3D$(FG_TEXT)!\n"
		$(CC) $(CDEBUG) $(CFLAGS) $(CINCLUDES) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)
		printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

##############################################################


###################### libft 실행단 ##########################
$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE):
		make -C $(LIBFT_DIR)

$(LIBFT)_clean:
		make -C $(LIBFT_DIR) clean

$(LIBFT)_fclean:
		make -C $(LIBFT_DIR) fclean

###########################################################


###################### minilibx 실행단 ######################
$(MLX) : $(MLX_FILE)

$(MLX_FILE) :
		printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)minilibx$(FG_TEXT)!\n"
		$(MLX_SUBMODULE)
		$(MLX_NOTIC)
		make --no-print-directory -C $(MLX_DIR)
		printf "$(CRLF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)minilibx $(FG_TEXT)!\n"
		$(MLX_CP)

$(MLX)_clean :
		make --no-print-directory -C $(MLX_DIR) clean
		$(MLX_RM)
###########################################################

.PHONY : all clean fclean re test\
		$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
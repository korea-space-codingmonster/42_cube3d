NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

ifeq ($(DEBUG),true)
	CFLAGS += -g
endif


###################### libft #########################
LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_INC_DIR)
#####################################################


###################### minlibx #########################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
		MLX_SUBMODULE = git submodul update --init
		MLX = libmlx.a
		MLX_DIR = lib/minilibx-Linux
		MLX_FLAGS = -L./$(MLX_DIR) -lmlx -lXext -lX11 -lm
		MLX_NOTIC = @printf "✅ $(FG_TEXT_PRIMARY)If you having trouble building minilibx library, \
		try installing the package below.\n\
		$(FG_TEXT)$(CL_BOLD)gcc make xorg libxext-dev libbsd-dev$(NO_COLOR)\n"
endif
ifeq ($(UNAME_S),Darwin)
		MLX = libmlx.dylib
		MLX_DIR = lib/minilibx_mms_20200219
		MLX_FLAGS = -L./$(MLX_DIR) -lmlx
		MLX_CP = cp $(MLX_FILE) $(MLX)
		MLX_RM = rm -f $(MLX)
endif
#####################################################


################### minilibx compile ################
MLX_DIR = lib/minilibx_mms_20200219
MLX_FILE = $(MLX_DIR)
MLX_INC_DIR = $(MLX_DIR)
CINCLUDES += -I $(MLX_INC_DIR)
#####################################################

RM = rm
RMFLAGS = -f

INC_DIR = include
CINCLIDES += -I $(INC_DIR)
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(wildcard $(INC_DIR)/*.h)# 헤더파일 가져오기

UTIL_DIR = $(SRC_DIR)/util#util파일에서 가져오기
UTIL_SRCS = $(wildcard $(UTIL_DIR)/*.c)

INIT_DIR = $(SRC_DIR)/init
INIT_SRCS = $(wildcard $(INIT_DIR)/*.c)#init 파일에서 가져오기

RENDER_DIR = $(SRC_DIR)/render
RENDER_SRCS = $(wildcard $(RENDER_DIR)/*.c)#rendering

UPDATE_DIR = $(SRC_DIR)/update
UPDATE_SRCS = $(wildcard $(UPDATE_DIR)/*.c)#위치 update


SRCS = \
		$(wildcard $(SRC_DIR)/*.c) \
		$(UTIL_SRCS) \
		$(INIT_SRCS) \
		$(RENDER_SRCS) \
		$(UPDATE_SRCS) \

vpath %.c \
		$(SRC_DIR) \
		$(UTIL_DIR) \
		$(INIT_DIR) \
		${RENDER_DIR} \
		${UPDATE_DIR} \


###################이미지 color 설정#############################
#corlor
CL_BOLD = \e[1m
CL_DIM = \e[2m
CL_UDLINE = \e[4m]

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF = \n$(LF)
##############################################################


all : $(NAME)

clean : 
		@$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
		@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY) $(NAME)'s Object files...\n"

fclean : clean
		@$(RM) $(RMFLAGS) $(NAME)
		@printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY) $(NAME)"

re : 	fclean all

lib_clean : $(LIBFT)_fclean $(MLX)_clean


#######################cube3d 실행단########################
$(OBJ_DIR) :
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
		@$(CC) $(CDEBUG) $(CFLAGS) $(CINCLUDES) -c $< -o $@
		@printf "$(LF)🚧 $(FG_TEXT) Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(MLX_FILE) $(LIBFT_FILE) $(HEADERS) $(OBJS)
		@printf "$(LF) 🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY) $(NAME)'s Object files $(FG_TEXT)!"
		@printf "$(CRLF) 📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY) cube_3D $(FG_TEXT)!"
		@$(CC) $(CDEBUG) $(CFALGS) $(CINCLUDES) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)
		@printf "$(LF) 🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

##########################################################


######################libft 실행단##########################
$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE):
		@make -C $(LIBFT_DIR)

$(LIBFT)_clean:
		@make -C $(LIBFT_DIR) clean

$(LIBFT)_fclean:
		@make -C $(LIBFT_DIR) fclean

###########################################################


######################minilibx 실행단########################
$(MLX) : $(MLX_FILE)

$(MLX_FILE) :
		@printf "$(CRLF) 📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)minilibx $(FG_TEXT)!\n"
		$(MLX_SUBMODULE)
		@$(MLX_NOTIC)
		@make -C $(MLX_DIR)
		@printf "$(CRLF) 🎉 $(FG_TEXT) Successfully Created $(FG_TEXT_PRIMARY)minilibx $(FG_TEXT)!\n"
		@$(MLX_CP)
$(MLX)_clean :
		@make -C $(MLX_DIR) clean
		@$(MLX_RM)
###########################################################


.PHONY : all clean fclean re test\
		$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
		$(MLX) $(MLX)_clean lib_clean

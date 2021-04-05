NAME = CUBE3D
CC = gcc
CFALGS = -Wall -Wextra -Werror

#삭제 키워드 및 삭제 플래그
RM = rm
RMFLAGS = -f


OBJ_DIR = obj
SRC_DIR = src

#############################LIBFT 경로 설정#########################
LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
##################################################################

##########################MINILIBX 경로설정#########################

##############################################################



#############################기본유틸############################
UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(wildcard $(UTIL_DIR)/*.c)


#init파일
INIT_DIR = $(SRC_DIR)/init
INIT_SRCS = $(wildcard $(INIT_DIR)/*.c)



#렌더링 파일 렌더링
RENDER_DIR = $(SRC_DIR)/render
RENDER_SRCS = $(wildcard $(RENDER_DIR)/*.c)

#플레이어 업데이트
UPDATE_DIR = $(SRC_DIR)/update
UPDATE_SRCS = $(wildcard $(PLAYER_DIR)/*.c)



SRCS = \
		$(wildcard $(SRC_DIR/*.c)) \
		$(UTIL_SRCS) \
		$(INIT_SRCS) \
		${RENDER_SRCS} \
		${UPDATE_SRCS}


OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS: .c=.o)))
#############################################################


#############################보너스############################
#보너스 과정 대비
# UTIL_BONUS_DIR = $(SrC_BONUS_DIR)/util
# UTIL_BONUS_SRCS = $(wildcard $(UTIL_BONUS_DIR)/*.c)

#보너스 과정 대비
# INIT_BONUS_DIR = $(SRC_BONUS_DIR)/init
# INIT_BONUS_SRCS = $(wildcard $(INIT_BONUS_DIR)/*.c)

#보너스 과정 대비
# RENDER_BONUS_DIR = $(SRC_DIR)/render
# RENDER_BONUS_SRCS = $(wildcard $(RENDER_BONUS_DIR)/*.c)

#보너스 과정 대비
# UPDATE_BONUS_DIR = $(SRC_BONUS_DIR)/update
# UPDATE_BONUS_SRCS = $(wildcard $(PLAYER_BONUS_DIR)/*.c)


# BONUS_SRCS = \
# 		$(wildcard $(SRC_BONUS_DIR)/*.c)
# 		$(UTIL_BONUS_SRCS) \
# 		$(INIT_BONUS_SRCS) \
# 		$(RENDER_BONUS_SRCS) \
# 		$(UPDATE_BONUS_SRCS)

OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS: .c=.o)))
##############################################################



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
	@$(RM) $(RMFALGS) $(OBJS) $(OBJS_BONUS)
	@printf "$(LF)🧹 $"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

#re_bonus : fclean bonus

lib_clean : $(LIBFT)_fclean $(MLX)_clean
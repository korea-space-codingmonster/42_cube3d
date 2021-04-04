NAME = CUBE3D


#삭제 키워드 및 삭제 플래그
RM = rm
RMFLAGS = -f


OBJ_DIR = obj
SRC_DIR = src
 
UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(wildcard $(UTIL_DIR)/*.c)

#보너스 과정 대비 ㅋㅋㅋㅋㅋ
# UTIL_BONUS_DIR = $(SrC_BONUS_DIR)/util
# UTIL_BONUS_SRCS = $(wildcard $(UTIL_BONUS_DIR)/*.c)

#init파일
INIT_DIR = $(SRC_DIR)/init
INIT_SRCS = $(wildcard $(INIT_DIR)/*.c)

#보너스 과정 대비
# INIT_BONUS_DIR = $(SRC_BONUS_DIR)/init
# INIT_BONUS_SRCS = $(wildcard $(INIT_BONUS_DIR)/*.c)

#렌더링 파일 렌더링
RENDER_DIR = $(SRC_DIR)/render
RENDER_SRCS = $(wildcard $(RENDER_DIR)/*.c)

#보너스 과정 대비
# RENDER_BONUS_DIR = $(SRC_DIR)/render
# RENDER_BONUS_SRCS = $(wildcard $(RENDER_BONUS_DIR)/*.c)

#플레이어 업데이트
PLAYER_DIR = $(SRC_DIR)/update
PLAYER_SRCS = $(wildcard $(PLAYER_DIR)/*.c)

#보너스 과정 대비
# PLAYER_BONUS_DIR = $(SRC_BONUS_DIR)/update
# PLAYER_BONUS_SRCS = $(wildcard $(PLAYER_BONUS_DIR)/*.c)



SRCS = \
		$(wildcard $(SRC_DIR/*.c)) \
		$(UTIL_SRCS) \
		$(INIT_SRCS) \
		${RENDER_SRCS} \
		${UPDATE_SRCS}




OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS: .c=.o)))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS: .c=.o)))



CC = gcc
CFALGS = -Wall -Wextra -Werror

# libft



all : $(NAME)

clean : 
	@$(RM) $(RMFALGS) $(OBJS) $(OBJS_BONUS)
fclean : clean
		
SERVER_DIR = srcs/Server
CLIENT_DIR = srcs/Client

GAME_NAME = dealerGame
SERVER_NAME = ${GAME_NAME}_server
CLIENT_NAME = ${GAME_NAME}_client

#color
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.PHONY: all server client clean fclean re

all: server client

server:
	@$(MAKE) -C ${SERVER_DIR}
	@mv ${SERVER_DIR}/${SERVER_NAME} .
	@echo "$(GREEN)Server compiled!$(DEF_COLOR)"

client:
	@$(MAKE) -C ${CLIENT_DIR}
	@mv ${CLIENT_DIR}/${CLIENT_NAME} .
	@echo "$(GREEN)Client compiled!$(DEF_COLOR)"

clean:
	@$(MAKE) -C ${SERVER_DIR} clean
	@$(MAKE) -C ${CLIENT_DIR} clean
	@echo "$(BLUE)${GAME_NAME} object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f ${SERVER_NAME} ${CLIENT_NAME}
	@echo "$(YELLOW)${GAME_NAME} library files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(MAGENTA)Cleaned and rebuilt everything for ${GAME_NAME}!$(DEF_COLOR)"
CXX = c++

HEAD = includes

CLIENT_SRCS_DIR = srcs

CLIENT_SRCS = ${CLIENT_SRCS_DIR}/main.cpp
CLIENT_OBJS = $(CLIENT_SRCS:.cpp=.o)
CLIENT_CFLAGS = -Wall -Wextra -Werror -std=c++11 -I${HEAD}
DEBUG_FLAGS = -g3 -fsanitize=address

CLIENT_NAME = dealerGame_client

.PHONY: all clean fclean re

all: $(CLIENT_NAME)

%.o: %.cpp
	$(CXX) $(CLIENT_CFLAGS) -c $< -o $@

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CXX) $(CLIENT_LFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

debug: $(CLIENT_OBJS)
	$(CXX) $(DEBUG_FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)


clean:
	rm -f $(CLIENT_OBJS)

fclean: clean
	rm -f $(CLIENT_NAME)

re: fclean all
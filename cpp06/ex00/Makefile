NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCDIR = srcs
INCDIR = headers
INCLUDES = -I$(INCDIR)

vpath %.cpp $(SRCDIR)
vpath %.hpp $(INCDIR)

SRCS = main.cpp \
		ScalarConverter.cpp \
		utils_00.cpp

HEADERS = ScalarConverter.hpp \
			utils.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
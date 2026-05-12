NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRCDIR = srcs
INCDIR = headers
INCLUDES = -I$(INCDIR)

SRCS = $(SRCDIR)/main.cpp \
	$(SRCDIR)/Bureaucrat.cpp \
	$(SRCDIR)/AForm.cpp \
	$(SRCDIR)/PresidentialPardonForm.cpp \
	$(SRCDIR)/RobotomyRequestForm.cpp \
	$(SRCDIR)/ShrubberyCreationForm.cpp \
	$(SRCDIR)/Intern.cpp

HEADERS = $(INCDIR)/Bureaucrat.hpp \
	$(INCDIR)/AForm.hpp \
	$(INCDIR)/PresidentialPardonForm.hpp \
	$(INCDIR)/RobotomyRequestForm.hpp \
	$(INCDIR)/ShrubberyCreationForm.hpp \
	$(INCDIR)/Intern.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
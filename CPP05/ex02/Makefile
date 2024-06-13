################################ Colors ####################################

BLUE    = \033[0;34m
MAGENT  = \033[0;35m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE_B  = \033[1;34m
MAG_B   = \033[1;35m
WHITE   = \033[1;37m
RESET   = \033[0m

################################# Project ###################################

NAME    	= ex02
NAME_TEST	= test-ex01
HEADER  	= ./include

################################# Sources ###################################

TEST_DIR	= ./src/tests
FILES   	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
# TEST_SRCS	= $(shell find $(TEST_DIR) -name '*.cpp')
SRC = $(addprefix ./src/, $(FILES))

SRCS_COMMON = $(filter-out ./src/main.cpp, $(SRC))
OBJS_COMMON = $(SRCS_COMMON:./src/%.cpp=$(OBJS_DIR)/%.o)

################################# Objects ###################################

OBJS_DIR    = ./objs
OBJS        = $(SRC:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(OBJS_DIR)/tests/%.o)

################################# Flags #####################################

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -I$(HEADER)

################################ Progress ###################################

TOTAL_FILES =    $(words $(SRC))
CURRENT_FILES = 0

define print_progress
    $(eval CURRENT_FILES=$(shell echo $$(($(CURRENT_FILES)+1))))
    @echo -n "\r$(MAG_B)Progress: $(MAGENT)$(CURRENT_FILES) / $(TOTAL_FILES) [$$((($(CURRENT_FILES) * 100) / $(TOTAL_FILES)))%] $(RESET) : $(BLUE)$(1)$(RESET) "
endef

################################# Rules ####################################

all: $(NAME)

$(NAME): $(OBJS:%=$(OBJS_DIR)/%)
	@$(CPP) $(OBJS:%=$(OBJS_DIR)/%) -o $(NAME)
	@echo ""
	@echo "$(GREEN)$(NAME) created$(RESET)"

test: CPPFLAGS += -DTEST
test: $(OBJS:%=$(OBJS_DIR)/%)
	@$(CPP) $(OBJS:%=$(OBJS_DIR)/%) -o $(NAME)
	@echo ""
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS_DIR)/%.o: ./%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	$(call print_progress, $(BLUE_B)Compiling:$(RESET) $<)

$(OBJS_DIR)/tests/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	$(call print_progress, $(BLUE_B)Compiling:$(RESET) $<)

clean: 
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Objects deleted$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_TEST)
	@echo "$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
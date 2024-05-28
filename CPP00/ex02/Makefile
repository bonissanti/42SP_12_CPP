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

NAME    = ex02
HEADER  = ./

################################# Sources ###################################

PROGRAM   = Account.cpp tests.cpp
SRC = $(addprefix ./src/, $(PROGRAM))

################################# Objects ###################################

OBJS_DIR    = ./objs
OBJS        = $(SRC:.cpp=.o)

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

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	$(call print_progress, $(BLUE_B)Compiling:$(RESET) $<)

clean: 
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Objects deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re


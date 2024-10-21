# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwillis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:09:19 by lwillis           #+#    #+#              #
#    Updated: 2024/10/21 12:37:00 by lwillis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

# Defines where the source files are
SOURCES = srcs/main.c srcs/files.c srcs/str_utils.c srcs/map_checker.c

# Shortcut to do the same but with the object files
OBJECTS = $(SOURCES:c=o)

# Defines the compiler and its flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

# Puts the .o files into a library
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

# Builds the .o files. $@ = target name
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(@:o=c) -o $@

# Deletes .o files
clean:
	rm -f $(OBJECTS)

# Deletes object files, then the output file
fclean: clean
	rm -f $(NAME)

# Rebuilds, so first deletes all then builds again
re: fclean all

# Tells Make that these commands don't build files with those names
.PHONY: all clean fclean re

########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = gcc
CXXFLAGS = -std=c11 -Wall
LDFLAGS = 

# Makefile settings - Can be customized.
APPNAME = shell
EXT = .c
LIBDIR = src


################### Cleaning rules for Unix-based OS ###################
build: 
	$(CC) $(CXXFLAGS) -o $(APPNAME) ./*$(EXT) -I $(LIBDIR)



.PHONY: clean
clean:
	$(RM) $(APPNAME)
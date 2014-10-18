#
# TODO: Generate the Makefile via autotool
#

##### MACROS #####
CC       := gcc
RM       := rm -f
CFLAGS   += -I../../ 
LDFLAGS  += -Wl,-wrap,fputs

SOURCES  := hello_world.c test_hello_world.c
OBJECTS  := $(SOURCES:.c=.o)
TEST     := test_hello_world

##### RULES #####
.PHONEY : all clean check
all : $(TEST) 
%.o : %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(TEST) : $(OBJECTS) 
	$(CC) -o $@ $^ $(LDFLAGS) 

clean :
	$(RM) *.o $(TEST)

check : all
	@for test in $(TEST);			\
	do					\
		echo "./$$test";		\
		if ./$$test;			\
		then				\
			echo "";		\
		else				\
			exit 1;			\
		fi;				\
	done



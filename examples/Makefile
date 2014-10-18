#
# TODO: Generate the Makefile via autotool
#
SUBDIRS := hello_world

##### RULES #####
.PHONEY : all clean check
all : 
	@for dic in $(SUBDIRS);			\
	do					\
		cd $$dic;			\
		make;				\
	done

clean :
	@for dic in $(SUBDIRS);			\
	do					\
		cd $$dic;			\
		make clean;			\
	done

check : all
	@for dic in $(SUBDIRS);			\
	do					\
		cd $$dic;			\
		make check;			\
	done
	@echo "All unit tests pass"


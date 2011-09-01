CC=gcc
CFLAGS=-Wall -Werror -O2 -ggdb -pedantic
CSRC=$(wildcard ./src/*.c)
BUILDDIR=build
OBJ=$(CSRC:%.c=%.o)
TGT=crckt

$(TGT): $(OBJ)
	@echo LD $@
	@$(CC) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c $(BUILDIR)
	@echo C $(basename $(notdir $@))
	@$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@
#   Gen-make-1.0.0
#   https://github.com/Ideas100/Gen-make
#

CC       := gcc
CFLAGS   := -I include
LDLIBS   := -lncurses
SRCS     := $(addprefix src/, logic.c run.c game.c view.c)
OBJS     := $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(OBJS) $(LDLIBS) -o tic-tac-toe

.PHONY: clean
clean :
	rm $(OBJS)
	rm tic-tac-toe

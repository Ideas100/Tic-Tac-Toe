CFLAGS = -I ./include
LIBS = -lncurses
OBJS = src/game.o src/logic.o src/view.o src/run.o


all: out
	cp src/out tic-tac-toe

out: $(OBJS)
	gcc $(OBJS) $(LIBS) -o src/out

%.o: %.c 
	gcc $(CFLAGS) -c $^ -o $@


.PHONY: clean distclean
clean:
	rm src/*.o
	rm src/out
	rm tic-tac-toe

distclean:
	find . -name *~ -delete
	find src/ -name *~ -delete

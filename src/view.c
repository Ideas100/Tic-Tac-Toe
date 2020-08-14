#include <ncurses.h>
#include <game.h>
#include <view.h>
#include <graph.h>
#include <logic.h>

#define CHECK_INT(x) (x>=48 && x<=57)
#define CONVERT(x) (x-48)

static inline void layout_init()
{
	const char init = '_';

	clear();
	print_str(TITLE, "tic-tac-toe");
	for (int i = 0; i < MAX_SIZE; i++)
		print_char(i, init);
}

static inline void loop(char ch, int pos, int inc)
{
	for (int i = 0; i < 3; i++) {
		print_char(pos, ch);
		pos += inc;
	}
}

void print_str(int pos, char *info)
{
	attron(A_BOLD);
	mvaddstr(info_xy[pos].y, info_xy[pos].x, info);
	attroff(A_BOLD);
	refresh();
}

void print_char(int pos, char val)
{
	mvaddch(map_xy[pos].y, map_xy[pos].x, val);
	refresh();
}

void highlights(int check, char ch, int pos)
{
	attron(A_REVERSE);	
	switch(check) {
	case H_CHECK:
		loop(ch, pos, 1);
		break;
	case V_CHECK:
		loop(ch, pos, 3);
		break;
	case C_CHECK:
		if (pos == 0)
			loop(ch, pos, 4);
		else
			loop(ch, pos, 2);
		break;
	}		
	attroff(A_REVERSE);
}

void view_init()
{
        initscr();
	cbreak();
	noecho();
	layout_init();
}

int read_data(struct game_item *item)
{
	char val;

	val = getchar();
	if (val == 'r') {
		view_init();
		refresh_buf(item);
	}
	if (CHECK_INT(val))
		return CONVERT(val)-1;
	else
		return -1;
}

void view_cleanup()
{
	endwin();
}


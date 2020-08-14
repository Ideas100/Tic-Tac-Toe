#include <stdio.h>
#include <game.h>
#include <view.h>
#include <logic.h>

#define QUIT 'q'
#define NUL '\0'

static char buf[MAX_SIZE];

static char check_player_turn(int *turn)
{
	*turn = ~(*turn);
	if(*turn)
		return 'X';
	else
		return 'O';
}

static char* declare_winner(char value)
{
	if (value == 'X')
		return "X wins";
	else
		return "O wins";
}

char check_result(struct game_item *item)
{
	char val;
	int ret = -1, pos;
	int (*func_ptr[]) (struct game_item*, char*) = {hori_check,
							vert_check,
							cros_check};
	for (int i = 0; i < 3; i++) {
		ret = (*func_ptr[i]) (item, &val);
		if (ret != -1) {
			highlights(i, val, ret);
			print_str(1, declare_winner(val));
			return QUIT;
		}
	}
        if (is_buffer_full(item)) {
		print_str(1, "game ties");
		return QUIT;
	}
	return NUL;
}

void load_and_check(struct game_item *item, int pos)
{
	char val;
	
	if (is_empty(item, pos) && pos != -1) {
		val = check_player_turn(&item->turn);
		insert(item, val, pos);
		print_char(pos, val);
	}
      	if (check_result(item) == QUIT)
		while (1) {
			if (getchar() == 'r') {
				view_init();
				refresh_buf(item);
				break;
			}
		}
}

void main()
{
	int pos;
	char ch;
	struct game_item item;
	game_init(&item, buf);
	view_init();

	while (1) {
		pos = read_data(&item);
		load_and_check(&item, pos);
	}
	
	return;
}

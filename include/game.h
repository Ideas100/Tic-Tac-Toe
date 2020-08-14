#ifndef GAME_H
#define GAME_H

#define MAX_SIZE 9

struct game_item
{
	char *ibox;
	int size;
	int turn;
};

/*
 * Initializes the game items
 */
void game_init(struct game_item *game_item, char *ibox);

/*
 * Flush ibox array
 */
void refresh_buf(struct game_item *item);

#endif

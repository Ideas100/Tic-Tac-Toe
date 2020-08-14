#include <string.h>
#include <game.h>

void game_init(struct game_item *item, char *ibox)
{
	item->ibox = ibox;
	item->size = MAX_SIZE;
	item->turn = 0;
}

void refresh_buf(struct game_item *item)
{
	memset(item->ibox, '\0', MAX_SIZE * sizeof(char));
}

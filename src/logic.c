#include <game.h>
#include <logic.h>

#define SET 3
#define MID 4

bool is_empty(struct game_item *item, int box_id)
{
	if (item->ibox[box_id] == '\0')
		return true;
	
	return false;
}

bool is_buffer_full(struct game_item *item)
{
	for (int i = 0; i < item->size; i++)
		if (is_empty(item, i))
			return false;
		
	return true;
}

void insert(struct game_item *item, char value, int pos)
{
	item->ibox[pos] = value;
}

static inline bool equals(char a, char b, char c)
{
	if ( a==b && b==c && a==c && a!='\0')
		return true;
	
	return false;
}

int hori_check(struct game_item *item, char *value)
{
	for (int i=0, j=0; j<3; j++) {
		if (equals(item->ibox[i], item->ibox[i+1], item->ibox[i+2])) {
			*value = item->ibox[i];
			return i;
		}
		i += 3;
	}
	
	return -1;
}

int vert_check(struct game_item *item, char *value)
{
	for (int i=0, j=0; j<3; j++) {
		if (equals(item->ibox[i], item->ibox[i+3], item->ibox[i+6])) {
			*value = item->ibox[i];
			return i;
		}
		i += 1;
	}
	
	return -1;	
}

int cros_check(struct game_item *item, char *value)
{
	if (equals(item->ibox[MID], item->ibox[MID+2], item->ibox[MID-2])) {
	        *value = item->ibox[MID];
		return MID-2;
	} 
	if (equals(item->ibox[MID], item->ibox[MID+4], item->ibox[MID-4])) {
	        *value = item->ibox[MID];
		return MID-4;
	}
	
	return -1;
}

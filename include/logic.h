#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>

/*
 * Checking the presence of value within the ibox
 * array for the given position
 */
bool is_empty(struct game_item *item, int box_id);

/*
 * Checking the ibox array is full
 */
bool is_buffer_full(struct game_item *item);

/*
 * Inserting the value to the ibox array
 */
void insert(struct game_item *item, char value, int pos);

/*
 * Checking for the horizontal match, return the 
 * starting position and also the character. 
 */
int hori_check(struct game_item *item, char *value);

/*
 * Checking for the vertical match, return the 
 * starting position and also the character.
 */
int vert_check(struct game_item *item, char *value);

/*
 * Checking for the cross match, return the 
 * starting position and also the character.
 */
int cros_check(struct game_item *item, char *value);

#endif

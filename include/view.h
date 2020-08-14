#ifndef VIEW_H
#define VIEW_H

enum
{
	H_CHECK,
	V_CHECK,
	C_CHECK
};

/*
 * Initialize the ncurses library
 */
void view_init();

/*
 * Reads the input from the user
 */
int read_data(struct game_item *item);

/*
 * Print the character in the game window
 */
void print_char(int pos, char val);

/*
 * Print the string in the game window
 */
void print_str(int pos, char *info);

/*
 * Highlights the winning logic of the game
 */
void highlights(int check, char ch, int pos);

/*
 * deallocates the ncurses library
 */
void view_cleanup();

#endif

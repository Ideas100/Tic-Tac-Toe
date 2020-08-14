/*
 * Setting the integer constant
 */
enum
{
	TITLE,
	INFO
};

/*
 * Setting the coordinates for title and info
 * to be printed on the game window 
 */
struct
{
	int y;
	int x;
} info_xy[] = {
	[TITLE] = {1, 7},
	[INFO]  = {11, 9}
};

/*
 * Setting the coordinates for the value to be 
 * printed inside the game window
 */
struct
{
	int y;
	int x;
} map_xy[] = {
	{3, 4}, {3, 12}, {3, 20},
	{6, 4}, {6, 12}, {6, 20},
	{9, 4}, {9, 12}, {9, 20}
};

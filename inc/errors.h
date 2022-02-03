#ifndef ERROR_MSG
# define ERROR_MSG

// Msg errors walls

# define ERROR_WALLS_WRONG_3RD_LETTER "Error\nThe 3rd letter for your walls is wrong\n"
# define ERROR_WALLS_WRONG_ARGUMENTS "Error\nArguments for your walls are wrong\n"
# define ERROR_WALLS_NUMBERS "Error\nToo much or too few walls_path in your cub file\n"
# define ERROR_WALLS_WRONG_IMG "Error\nThe path of the img is wrong\n"

// Msg errors ceiling/floor

# define ERROR_CEILING_FLOOR_LEN_COLOR_TOO_LONG "Error\nThe numbers for the color are wrong\n"
# define ERROR_CEILING_FLOOR_WRONG_2ND_LETTERS "Error\nThe 2nd letter for your ceiling or floor is wrong\n"
# define ERROR_CEILING_FLOOR_CALLED_TOO_MANY "Error\nYou have too many ceiling or floor lines\n"
# define ERROR_CEILING_FLOOR_ARGUMENTS_PROBLEMS "Error\nProblem with your arguments ceiling or floor\n"
# define ERROR_CEILING_FLOOR_OTHER_THAN_NUMBER "Error\nYour colors in your ceiling or floor contains are not only number\n"
# define ERROR_CEILING_FLOOR_FIRST_LETTER_WRONG "Error\nYour first letter is a comma for your ceiling or floor\n"
# define ERROR_CEILING_FLOOR_TOO_MANY_COMMA "Error\nYour have too many commas on your ceiling or floor\n"
# define ERROR_CEILING_FLOOR_COMMA_PROBLEM "Error\nProblem with you commas on ceiling or floor in your file\n"
# define ERROR_CEILING_FLOOR_WRONG_NUMBER_LINES "Error\nToo much or to few ceiling or floor lines in your file\n"

// Msg errors map

# define ERROR_MAP_NOT_AT_END "Error\nYour first or your last line of your map has a problem or no map at all\n"
# define ERROR_MAP_TOO_FEW_LINES "Error\nYour map has too few lines\n"
# define ERROR_MAP_MALLOC_PROBLEM "Error\nProblem during the malloc of your map\n"
# define ERROR_MAP_FIRST_LETTER "Error\nThe first number of one of your line is not a '1'\n"
# define ERROR_MAP_LAST_LETTER "Error\nThe last number of one of your line is not a '1'\n"
# define ERROR_MAP_UNAUTHORIZED_LETTER "Error\nUnauthorized letter in your map'\n"
# define ERROR_MAP_TOO_MUCH_PLAYER "Error\nYou put your player more than once\n"
# define ERROR_MAP_PROBLEM_INSIDE_WALLS "Error\nProblem inside your walls, check the '0', or player's letter\n"

#endif
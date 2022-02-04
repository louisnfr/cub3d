#ifndef ERROR_MSG
# define ERROR_MSG

// Msg errors walls

# define ERROR_WALLS_WRONG_3RD_LETTER "Error\n" \
					"The 3rd letter for your walls is wrong\n"
# define ERROR_WALLS_WRONG_ARGUMENTS "Error\n" \
					"Arguments for your walls are wrong\n"
# define ERROR_WALLS_NUMBERS "Error\n" \
							"Too much or too few walls_path in your cub file\n"
# define ERROR_WALLS_WRONG_IMG "Error\nThe path of the img is wrong\n"

// Msg errors ceiling/floor

# define ERROR_CEILING_FLOOR_LEN_COLOR_TOO_LONG "Error\n"\
								"The numbers for the color are wrong\n"
# define ERROR_CEILING_FLOOR_WRONG_2ND_LETTERS "Error\n"\
						"The 2nd letter for your ceiling or floor is wrong\n"
# define ERROR_CEILING_FLOOR_CALLED_TOO_MANY "Error\n"\
								"You have too many ceiling or floor lines\n"
# define ERROR_CEILING_FLOOR_ARGUMENTS_PROBLEMS "Error\n"\
							"Problem with your arguments ceiling or floor\n"
# define ERROR_CEILING_FLOOR_OTHER_THAN_NUMBER "Error\n"\
		"Your colors in your ceiling or floor contains are not only number\n"
# define ERROR_CEILING_FLOOR_FIRST_LETTER_WRONG "Error\n"\
				"Your first letter is a comma for your ceiling or floor\n"
# define ERROR_CEILING_FLOOR_TOO_MANY_COMMA "Error\n"\
						"Your have too many commas on your ceiling or floor\n"
# define ERROR_CEILING_FLOOR_COMMA_PROBLEM "Error\n"\
				"Problem with you commas on ceiling or floor in your file\n"
# define ERROR_CEILING_FLOOR_WRONG_NUMBER_LINES "Error\n"\
				"Too much or to few ceiling or floor lines in your file\n"

// Msg errors map

# define ERROR_MAP_NOT_AT_END "Error\n" \
"Your first or your last line of your map has a problem or no map at all\n"
# define ERROR_MAP_TOO_FEW_LINES "Error\n" \
						"Your map has too few lines\n"
# define ERROR_MAP_MALLOC_PROBLEM "Error\n" \
						"Problem during the malloc of your map\n"
# define ERROR_MAP_FIRST_LETTER "Error\n" \
						"The first number of one of your line is not a '1'\n"
# define ERROR_MAP_LAST_LETTER "Error\n" \
						"The last number of one of your line is not a '1'\n"
# define ERROR_MAP_UNAUTHORIZED_LETTER "Error\n" \
						"Unauthorized letter in your map'\n"
# define ERROR_MAP_TOO_MUCH_PLAYER "Error\n" \
						"You put your player more than once\n"
# define ERROR_MAP_PROBLEM_INSIDE_WALLS "Error\n" \
			"Problem inside your walls, check the '0', or player's letter\n"

#endif
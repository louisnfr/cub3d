/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:26:02 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/24 16:05:34 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/* memory errors */

# define MALLOC "Error\nMalloc failed\n"

/* wall errors */

# define WALLS_WRONG_3RD_LETTER "Error\n3rd letter for your walls is wrong\n"
# define WALLS_WRONG_ARGUMENTS "Error\nWrong wall arguments\n"
# define WALLS_NUMBERS "Error\nToo many or too few walls_path in your file\n"
# define WALLS_WRONG_IMG "Error\nWrong image path\n"

/* ceiling floor errors */

# define CEILING_FLOOR_LEN_COLOR_TOO_LONG "Error\nWrong color numbers\n"
# define CEILING_FLOOR_WRONG_2ND_LETTERS "Error\nWrong 2nd letter in C/F\n"
# define CEILING_FLOOR_CALLED_TOO_MANY "Error\nToo many C/F lines\n"
# define CEILING_FLOOR_ARGUMENTS_PROBLEMS "Error\nWrong C/F arguments\n"
# define CEILING_FLOOR_OTHER_THAN_NUMBER "Error\nWrong characters in C/F\n"
# define CEILING_FLOOR_FIRST_LETTER_WRONG "Error\nWrong 1st letter in C/F\n"
# define CEILING_FLOOR_TOO_MANY_COMMA "Error\nToo many commas in C/F\n"
# define CEILING_FLOOR_COMMA_PROBLEM "Error\nWrong commas in C/F\n"
# define CEILING_FLOOR_WRONG_NUMBER_LINES "Error\nWrong C/F lines number\n"

/* map errors */

# define MAP_NOT_AT_END "Error\nMap reading error\n"
# define MAP_TOO_FEW_LINES "Error\nMap has too few lines\n"
# define MAP_MALLOC_PROBLEM "Error\nMap malloc failed\n"
# define MAP_FIRST_LETTER "Error\nFirst char of line is not a '1'\n"
# define MAP_LAST_LETTER "Error\nLast char of line is not a '1'\n"
# define MAP_UNAUTHORIZED_LETTER "Error\nUnauthorized letter in your map'\n"
# define MAP_TOO_MUCH_PLAYER "Error\nPlayer present more than once\n"
# define MAP_PROBLEM_INSIDE_WALLS "Error\nWrong core of map\n"

#endif

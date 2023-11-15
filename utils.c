#include "monty.h"

/**
 * is_number - this function check if the str
 * is number or not
 * @str: this is the string that will be check
 * Return: 1 if integer, 0 if NULL or not digit
 */
int is_number(char *str)
{
	if (str == NULL)
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * isempty - Checks if a string contains only non-alphabetic characters.
 *
 * @str: The input string to be checked.
 *
 * Description:
 *   This function iterates through the characters of the input string,
 *   checking if any of them is alphabetic using the _isalpha function.
 *   If an alphabetic character is found, the function returns 1. If the
 *   string is empty or consists solely of non-alphabetic characters,
 *   the function returns -1.
 *
 * Return:
 *   -1 if the string is empty or contains only non-alphabetic characters,
 *   1 if an alphabetic character is found.
 */
int isempty(char *str)
{
	while (*str != '\0')
	{
		if (_isalpha(*str) == 1)
			return (1);
		str++;
	}

	return (-1);
}

/**
 * _isalpha - Checks if a character is an alphabetic character.
 *
 * @c: The character to be checked.
 *
 * Description:
 *   This function determines if the input character is an alphabetic
 *   character by checking if it falls within the ASCII ranges of lowercase
 *   or uppercase letters. If the character is an alphabetic letter, the
 *   function returns 1; otherwise, it returns 0.
 *
 * Return:
 *   1 if the character is an alphabetic character, 0 otherwise.
 */
int _isalpha(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

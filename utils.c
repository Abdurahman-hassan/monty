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
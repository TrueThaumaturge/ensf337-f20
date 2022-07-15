/* read_int.c
 * ENSF 337 Fall 2020 Lab 4 Exercise  E
 *
 * Quentin Jennings
 */

#include "read_input.h"

int read_real(char* digits, int n, double* num)
{
	if(get_string(digits, n)== EOF)
		return EOF;

    if(is_valid_double(digits))
	{
		if(digits[0] == '-')
		  *num = -convert_to_double(digits + 1);
		else if(digits[0] == '+') 
		  *num = convert_to_double(digits + 1);
		else
		  *num = convert_to_double(digits);
		
		return 1;
	}

    return 0;
}

int is_valid_double(const char* digits)
{
	int valid = 1;
	int i;
	int isDot = 0;
	
	//i is the index of the beginning of the number
	if(digits[0] == '+' || digits[0] == '-') //adjusts i index depending on whether there is a sign given or not
		i = 1;
	else
		i = 0;

	if (digits[i] == '\0') //if the string is empty, there is no number - invalid
		valid = 0;
	{
		while (valid && (digits[i] != '\0')) //loops through each index of the string
		{
			if(digits[i] == '.' && !isDot) //allows for one dot in the string
				isDot++;
			else if(digits[i] < '0' ||  digits[i] > '9') //invalid if not a digit (0-9)
				valid = 0;
			
			i++;
		}
	}
	  
	return valid;
}

double convert_to_double(const char* digits)
{
	double sum = 0;
	int i = 0, temp = 0;
	
	while(digits[i] != '\0') //handles numbers before the decimal
	{
		if(digits[i] == '.')
			temp = i+1;
		else
			sum = 10 * sum + (digits[i] - '0');
		
		i++;
	}
	
	if(temp) //if the temp value isn't 0, that means there was a decimal so it divides the total number based on where the decimal was
	{
		for(int j = i - temp; j > 0; j--)
			sum /= 10;
	}
	
	return sum;
}
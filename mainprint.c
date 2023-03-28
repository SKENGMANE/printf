#include "main.h"

/**
 * _printf - Printf function
 * @format: is a variable accepted for print out.
 * Return: Charaters to be printed
 */
int _printf(const char *format, ...)
{
	int indexItem = 0;
	int i;
	int CharPrinted = 0;
	int PrintValue = 0;
	int FlagVar, WidthVar, PrecVar, SizeVar;
	va_list list;
	char buffer[SIZEBUFFER];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			printvalues(buffer, &indexItem);
			FlagVar = getFlags(format, &i);
			WidthVar = GetWidth(format, &i, list);
			PrecVar = GetPrecision(format, &i, list);
			SizeVar = GetSize(format, &i);
			++i;
			CharPrinted = PrintFormat(format, &i, list, buffer,
				FlagVar, WidthVar, PrecVar, SizeVar);
			if (CharPrinted == -1)
				return (-1);
			PrintValue += CharPrinted;
			
		}
		else
		{
			buffer[indexItem++] = format[i];
			if (indexItem == SIZEBUFFER)
				printvalues(buffer, &indexItem);
			/* write(1, &format[i], 1);*/
			PrintValue++;
		}
	}

	printvalues(buffer, &indexItem);

	va_end(list);

	return (PrintValue);
}

/**
 * printvalues - main entry for print
 * @buffer: list of chars
 * @indexItem: indext to the next char
 */
void printvalues(char buffer[], int *indexItem)
{
	if (*indexItem > 0)
		write(1, &buffer[0], *indexItem);

	*indexItem = 0;
}



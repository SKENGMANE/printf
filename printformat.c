#include "main.h"
/**
 * PrintFormat - Prints an argument based on its type
 * @formattype: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int PrintFormat(const char *formattype, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	formattype_t formattype_types[] = {
		{'c', PrintChar}, {'s', PrintString}, {'%', PrintPercent},
		{'i', PrintInt}, {'d', PrintInt}, {'b', PrintBinary},
		{'u', PrintUnsigned}, {'o', PrintOctal}, {'x', PrintHexaDecimal},
		{'X', PrintHexaUpper}, {'p', PrintPointer}, {'S', PrintNotPrintable},
		{'r', PrintReverse}, {'R', PrintRotlString}, {'\0', NULL}
	};
	for (i = 0; formattype_types[i].formattype != '\0'; i++)
		if (formattype[*ind] == formattype_types[i].formattype)
			return (formattype_types[i].fn(list, buffer, flags, width, precision, size));

	if (formattype_types[i].formattype == '\0')
	{
		if (formattype[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (formattype[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formattype[*ind] != ' ' && formattype[*ind] != '%')
				--(*ind);
			if (formattype[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &formattype[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}


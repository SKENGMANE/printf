#ifndef PROJECTF
#define PROJECTF
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define SIZEBUFFER 1024
#define LONGVAR 2
#define SHORVAR 1
#define MINUSSIGN 1
#define PLUSSIGN 2
#define ZEROSIGN 4
#define HASHSIGN 8
#define SPACESIGN 16

void printvalues(char buffer[], int *buff_ind);
int IsPrintable(char);
int HexaCodeMerge(char, char[], int);
int IsDigit(char);

long int SizeNumberConvert(long int num, int size);
long int UnsignedSizeConvert(unsigned long int num, int size);


/**
 * struct formattype - Struct op
 *
 * @formattype: The format.
 * @fn: The function associated.
 */
struct formattype
{
	char formattype;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct formattype formattype_t - Struct op
 *
 * @formattype: The format.
 * @fm_t: The function associated.
 */
typedef struct formattype formattype_t;

int _printf(const char *format, ...);
int PrintFormat(const char *formattype, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int PrintPercent(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintInt(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintBinary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintUnsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintChar(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintString(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintOctal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintHexaDecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintHexaUpper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintHexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int PrintNotPrintable(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintPointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
int GetWidth(const char *format, int *i, va_list list);
int GetPrecision(const char *format, int *i, va_list list);
int GetSize(const char *format, int *i);
int getFlags(const char *format, int *i);
int PrintReverse(va_list types, char buffer[],
int flags, int width, int precision, int size);
int PrintRotlString(va_list types, char buffer[],
int flags, int width, int precision, int size);
int WriteCharHandle(char c, char buffer[],
int flags, int width, int precision, int size);
int NumberWrite(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int NumWrite(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int PointerWrite(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int UnsignedWrite(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
#endif /* MAIN_H */

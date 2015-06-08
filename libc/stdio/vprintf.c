#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


static void print(const char* data, size_t data_length)
{
	for ( size_t i = 0; i < data_length; i++ )
		putchar((int) ((const unsigned char*) data)[i]);
}

static size_t itoa(unsigned int value, char* str, unsigned int base)
{	
	char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char tmp[32];
	
	if (base < 2 || base > 36) return 0;
	
	if (value == 0)
	{
		str[0] = '0';
		return 1;
	}
	
	size_t current = 0;		
	while (value) 
	{
		int index = value % base;
		value = value / base;
		
		tmp[current] = digits[index];
		current++;
	}
	
	size_t i = 0;
	for (; i < current; i++)
	{
		str[i] = tmp[current - 1 - i];
	}
	
	return i;
}

int vprintf(const char* restrict format, va_list argp)
{	
	const char* p;
	int i;
	char buff[32];
	char* s;
				
	int written = 0;
	
	for(p = format; *p != '\0'; p++)
	{
		if (*p != '%') 
		{
			print(p, 1);
			written++;
		}
		else
		{
			switch (*++p)
			{
				case 'b':
					i = va_arg(argp, int);
					i = itoa(i, buff, 2);
					print(buff, i);
					written += i;
					break;	
					
				case 'c':					
					buff[0] = va_arg(argp, int);					
					print(buff, 1);
					written++;
					break;		
					
				case 'd':
					i = va_arg(argp, int);
					i = itoa(i, buff, 10);
					print(buff, i);
					written += i;
					break;	
					
				case 's':
					s = va_arg(argp, char *);
					i = strlen(s);
					print(s, i);
					written += i;
					break;
					
				case 'x':
        case 'p':
					i = va_arg(argp, int);
					i = itoa(i, buff, 16);
					print(buff, i);
					written += i;
					break;
					
				case '%':					
					print(p, 1);
					written++;
					break;
					
				default:
					print((p-1), 1);
					print(p, 1);
					written += 2;
					break;
			}
		}
	}
	
	return written;
}

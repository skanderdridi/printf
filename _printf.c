#include "main.h"
/**
 * print_number - writes the character c to stdout
 * @n:integer
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_number(int n)
{int x, k, r = 1, s = 0;

	if (n == 0)
	{putchar(48);
		s += 1;
		return (s);
	}
	x = n;
	if (x == -2147483648)
	{x = x + 1;
	}
	if (n < 0)
	{x = -x;
		putchar('-');
		s += 1;
	}
	while (r < 1000000000 && (x - (r * 10) >= 0))
	{r = r * 10;
	}
	while (x > 0)
	{k = x / r;
		x = x % r;
		r /= 10;
		if (x < r)
		{putchar(k + 48);
			 s += 1;
			putchar(48);
			 s += 1;
			r /= 10;
		}
		else if (n == -2147483648 && k == 7 && r == 0)
		{putchar(k + 49);
			 s += 1;
		}
		else
		{putchar(k + 48);
			 s += 1;
		}
	}
	return (s);
}
/**
 *pr_char - pr
 *@c: char
 *Return: char
 */
int pr_char(char c)
{
	putchar(c);
	return (1);
}
/**
 *pr_string - prs
 *@ch: str
 *Return: string
 */
int pr_string(char *ch)
{
	int i;

	if (ch == NULL)
		return (0);
	for (i = 0; ch[i] != '\0'; i++)
		putchar(ch[i]);
	return (i);
}
/**
 *_printf - print any thing
 *@format: input
 *Return: int
 */
int _printf(const char *format, ...)
{int i = 0, j, length = 0;
	char c, *ch;
	va_list l;

	if (format == NULL)
		return (-1);
	va_start(l, format);
	while (format[i])
	{
		if (format[i] != '%')
		{putchar(format[i]);
			length += 1;
		}
		else
		{
			if (format[i + 1] == '\0')
				return (-1);
			if (format[i + 1] == 'd')
			{j = va_arg(l, int);
				length += print_number(j);
			}
			if (format[i + 1] == 'c')
			{c = va_arg(l, int);
				length += pr_char(c);
			}
			if (format[i + 1] == 's')
			{ch = va_arg(l, char*);
				if (!ch)
					ch = "(null)";
				length += pr_string(ch);
			}
			if (format[i + 1] == 'i')
			{j =  va_arg(l, int);
				length += print_number(j);
			}
			if (format[i + 1] == '%')
			{putchar('%');
				length += 1;
			}
			i++;
		}
		i++;
	va_end(l); }
	return (length); }

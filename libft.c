#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(const char *str)
{
    int i = 0;

    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}
void    ft_putnbr(int nb)
{
    long i;

    i = nb;
    if (i < 0)
    {
        ft_putchar('-');
        i = i * (-1);
    }
    if (i > 9)
    {
        ft_putnbr(i / 10);
        ft_putnbr(i % 10);
    }
    else
    {
        ft_putchar(i + '0');
    }
}
size_t ft_strlen(char *str)
{
    int i = 0;

    while(*str++)
        i++;
    
    return i + 1;
}


int ft_atoi(char *str)
{
    int x = 0;
    int neg = 1;
    int nb = 0;

    while(str[x] == '\t' || str[x] == '\v' || str[x] == '\n'||str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
        x++;
    while(str[x] == '-' || str[x] == '+')
    {
        if(str[x] == '-')
            neg *= -1;
        x++;
    }
    while(str[x] >= '0'&& str[x] <= '9')
    {
        nb = nb + str[x] - '0';
        
        if(str[x+1] >= '0' && str[x+1] <= '9')
            nb *= 10;
        x++;
    }
    nb *= neg;
    return nb;
}

static size_t   number_size(int n)
{
        size_t  size;

        size = 0;
        if (n <= 0)
                size++;
        while (n != 0)
        {
                n /= 10;
                size++;
        }
        return (size);
}

char    *ft_itoa(int n)
{
    char    *res;
    int             sign;
    size_t  i;

    i = number_size(n);
    sign = 1;
    res = malloc(sizeof(*res) * (i + 1));
    if (!res)
        return (0);
    res[i] = 0;
    i--;
    if (n < 0)
    {
        sign *= -1;
        res[0] = '-';
    }
    if (n == 0)
        res[i] = '0';
    while (n != 0)
    {
        res[i] = ((n % 10) * sign) + 48;
        n /= 10;
        i--;
    }
    return (res);
}

int ft_octal(int nb)
{
    int e = 1;
    int y = 0;
    int i = 0;
    int final = 0;;

    int *octal;

    while(e >= nb)
    {
        e*=10;
        y++;
    }
    if(!(octal = (int*) malloc(sizeof(int) * y)))
        return 0;
    while(nb != 0)
    {
        octal[i++] = nb % 8;
        nb /= 8;
    }
    while(i >= 0)
    {
        final *= 10;
        final += octal[i--];
    }
    
    free(octal);

    return final;
}


char    *ft_unsigned_itoa(unsigned int n)
{
    char    *res;
    size_t  i;

    i = number_size(n);
    res = malloc(sizeof(*res) * (i + 1));
    if (!res)
        return (0);
    res[i] = 0;
    i--;
    if (n == 0)
        res[i] = '0';
    while (n != 0)
    {
        res[i] = (n % 10) + 48;
        n /= 10;
        i--;
    }
    return (res);
}
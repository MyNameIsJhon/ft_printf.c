#include "libft.h"
#include "extern.h"
#include "list.h"


char *ft_str_recup_flags(const char *str, t_list **alst, va_list ap)
{
    int i = 0;
    int y = 0;
    int z = 0; // compteur pour première allocation t_list 
    char *st;
    
    t_list *lst;

    while(str[i])
    {
        if(str[i] == '%' && str[i+1] != '%' && str[i-1] != '%')
        {
            switch(str[i+1]){

                case 'd':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;

                case 'D':
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;

                case 's'://string
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(pointer_create(va_arg(ap, char*))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(pointer_create(va_arg(ap, char*)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;
                
                case 'S'://string 
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(pointer_create(va_arg(ap, char*))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(pointer_create(va_arg(ap, char*)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;

                case 'o'://conversion octal
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int)))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int))));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;

                case 'O'://retour nombre octal
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int)))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(ft_octal(va_arg(ap, int))));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;
                
                case 'u'://unsigned int
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;
                
                case 'U'://unsigned int
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(ft_unsigned_itoa(va_arg(ap, int))));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(ft_unsigned_itoa(va_arg(ap, int)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;

                case 'c'://print char
                    char *c = (char*) malloc(sizeof(char) * 1);
                    int lt = va_arg(ap, int);
                    c = (char*) &lt;
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(c));
                    else if(z == 0)
                    {
                        lst = ft_lstnew(c);
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                    break;
                
                
                
                /*case 'p'://error
                {
                    if(z > 0)
                        ft_lstadd_back(alst, ft_lstnew(st));
                    else if(z == 0)
                    {
                        void *point = va_arg(ap, void*);
                        int nb = &point;
                        lst = ft_lstnew(ft_itoa((point)));
                        alst = &lst;
                    }
                    ft_putstr((char*)(*alst)->content);
                    ft_putchar('\n');
                }
                    */
                
                

            }
            z++;
        }
        i++;
    }
}

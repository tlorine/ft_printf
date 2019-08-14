#include "ft_printf.h"
char *assignment(int *size, int *save, int *i, int exp)
{
    *size = 64;
    char *buffer;

    buffer = NULL;
    if (exp < 0)
    {
        buffer = (char *)malloc(sizeof(char) * 2);
        buffer[0] = '0';
        buffer[1] = '\0';
        *i = 1;
        *save = 1;
        *size = 64;
    }
    return(buffer);
}

void  compaund(t_float nw, int i, char **res, params arg)
{
    int size;
    char *po_to;
    char *do_to;
    char *buff;

    size = i;
    IN_VAR(i, nw.bits.exp, nw.bits.exp, nw.bits.exp);
    while (i != size)
    {
        if (i == nw.bits.mantisa && po_to != NULL)
        {
            do_to = ft_strdup(po_to);
            po_to = ft_strdel(&po_to);
            nw.bits.exp = (ft_strlen(do_to));
        }
        buff = add_float(po_to, res[i]);
        po_to = ft_strdel(&po_to);
        po_to = ft_strdup(buff);
        buff = ft_strdel(&buff);
        i++;
    }
    if(do_to)
    {
        buff = ft_strjoin(do_to, po_to);
        put_float(buff, nw.bits.exp, arg, nw.bits.zn);
        buff = ft_strdel(&buff);
        do_to = ft_strdel(&do_to);
    }
    else
        put_float(po_to, ft_strlen(po_to), arg, nw.bits.zn);
    while (size-- > 0)
        res[size] = ft_strdel(&res[size]);
    po_to = ft_strdel(&po_to);
}
void ft_fitoa(long double x, params arg)
{
    t_float nw;
    char *res[200];
    int i;
    int save;
    int size;

    nw.d = x;
    nw.bits.exp = nw.bits.exp - 16383;
    res[0] = assignment(&size, &save, &i, nw.bits.exp);
    while (size != 0)
    {
        size--;
        if (nw.bits.mantisa >> size & 1)
        {
            res[i] = power_of(nw.bits.exp);
            i++;
        }
        nw.bits.exp--;
        if (nw.bits.exp == -1 && save == 0)
            save = i;
    }
    nw.bits.mantisa = save;
    compaund(nw, i, res, arg);
}
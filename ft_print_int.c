#include "ft_printf.h"

int put_ar(params argument, char **buff, char *s_num)
{
    if (*s_num == '-' && (POZ_1 & argument.flag) == 0)
    {
        **buff = '-';
        return (1);
    }
    else if ((POZ_1 & argument.flag) == POZ_1)
    {
        **buff = ' ';
        return (1);
    }
    else if ((POZ_5 & argument.flag) == POZ_5)
    {
        if (*s_num == '-')
            **buff = '-';
        else
            **buff = '+';
        return (1);
    }
    return (0);
}

int put_sim(int sim, char *s_num, params argument, char **buff)
{
    if(put_ar(argument, buff, s_num) == 1 && argument.type != 'u' && argument.type != 'o' && argument.type != 'x' && argument.type != 'X')
        ++(*buff);
    while (argument.accur - sim > 0)
    {
        **buff = '0';
        argument.accur = argument.accur - 1;
        ++(*buff);
    }
    if (*s_num == '-')
        ++s_num;
    while (*s_num != '\0')
    {
        **buff = *s_num;
        ++s_num;
        ++(*buff);
    }
    **buff = '\0';
    return (0);
}
char *put_width(int max, params argument, char **save, int size)
{
    if ((POZ_3 & argument.flag) == POZ_3 && (argument.type == 'x' || argument.type == 'X' || argument.type == 'b')) //  eto gavno dlya #
        max = max + 2;
     if ((POZ_2 & argument.flag) == POZ_2)
    {
        if ((POZ_3 & argument.flag) == POZ_3 && (argument.type == 'x' || argument.type == 'X' || argument.type == 'b')) // i vot eto gavno dlya #
        {
            write(1, "0", 1);
            write(1, &argument.type, 1);
        }
        write(1, *save, size);
        while (argument.width - max > 0)
        {
            argument.width--;
            write(1, " ", 1);
        }
    }
    else
    {
        while (argument.width - max > 0)
        {
            argument.width--;
            write(1, " ", 1);
        }
        if ((POZ_3 & argument.flag) == POZ_3 && (argument.type == 'x' || argument.type == 'X' || argument.type == 'b')) // i eto gavno dlya #
        {
            write(1, "0", 1);
            write(1, &argument.type, 1);
        }
        write(1, *save, size);
    }
    free(*save);
    *save = NULL;
    return (NULL);
}
void put_int(long long int num, params argument, long long int base, char a)
{
    char *s_num;
    char *buff;
    char *save;
    int sim;
    int size;
    if (num == 0 && argument.accur == 0)
        return ;
    s_num = argument.type == 'u' ? ft_uitoa(num, base, a) : ft_itoa(num, base, a);
    sim = ft_strlen(s_num);
    if ((POZ_3 & argument.flag) == POZ_3 && (argument.type == 'x' || argument.type == 'X'))
    if (*s_num == '-')
        sim = sim - 1;
    if ((POZ_4 & argument.flag) == POZ_4 && argument.accur == 0)
    {
        argument.accur = argument.width;
        argument.width = 0;
        if (AR_SIM(argument.flag, argument.type, *s_num)) 
            argument.accur = argument.accur - 1;
    }
    size = sim > argument.accur ? sim : argument.accur;
     if (AR_SIM(argument.flag, argument.type, *s_num))
        size++;
    buff = (char *)malloc(sizeof(char) * size + 1);
    save = buff;
    put_sim(sim, s_num, argument, &buff);
    save = put_width(ft_strlen(save), argument, &save, size);
}
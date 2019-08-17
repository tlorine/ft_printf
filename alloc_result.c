#include "ft_printf.h"

void ft_else_w(params argument, char **save, int size, int max)
{
		while (argument.width - max > 0)
		{
			argument.width--;
			write(1, " ", 1);
		}
		if ((POZ_3 & argument.flag) == POZ_3 && (argument.type == 'x' || argument.type == 'X' || argument.type == 'b'))
		{
			write(1, "0", 1);
			write(1, &argument.type, 1);
		}
		write(1, *save, size);
}

void ft_if_poz_chetire(params *argument, char *s_num)
{
    if ((POZ_4 & argument->flag) == POZ_4 && argument->accur == 0)
	{
		argument->accur = argument->width;
		argument->width = 0;
		if (AR_SIM(argument->flag, argument->type, *s_num))
			argument->accur = argument->accur - 1;
	}
}

char *ft_if_ost(int ost, int *i2, int size)
{
    char *buffer;

    buffer = (char *)malloc(sizeof(char) * (size + 1) + ost);
    if (ost)
	{
		buffer[0] = '1';
		*i2 = *i2 + 1;
	}
    return (buffer);
}

char *if_e(params arg, notation notation, char *buffer, int i2)
{
	char *ft_buff;
	char *ft_itoa_1;
    if (arg.type != 'f')
	{
		buffer[i2] = arg.type;
		buffer[i2 + 1] = notation.ar;
		i2 = i2 + 2;
		if(notation.notation < 10)
		{
			buffer[i2] = '0';
			i2++;
		}
		buffer[i2] = '\0';
		ft_itoa_1 = ft_itoa(notation.notation, 10, 'a');
		ft_buff = ft_strjoin(buffer, ft_itoa_1);
		ft_itoa_1 = ft_strdel(&ft_itoa_1);
		buffer = ft_strdel(&buffer);
		return(ft_buff);
	}
    else
        return (buffer);
}

void alloc_result(afloat *af, long_ar *la, char *num1, char *num2)
{
	IN_VAR(la->ost, la->ost, af->len1, af->len2);
	af->len1 = ft_strlen(num1) - 1;
	af->len2 = ft_strlen(num2) - 1;
	af->size = count_num(num1, num2, af->len1, af->len2);
	af->result = (char *)malloc(sizeof(char) * (af->size + 1));
	af->result[af->size] = '\0';
	af->size--;
	while (af->len2 > af->len1)
	{
		af->result[af->size] = num2[af->len2];
		SHIFT_LEFT(af->len2, af->size);
	}
	return ;
}
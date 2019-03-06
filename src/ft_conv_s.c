#include "ft_printf.h"

char	*ft_jonh_claude(char *flags, t_data *data)
{
	int		i;
	int		ap;
	 char	*final;


(void)i;
(void)ap;
(void)flags;
(void)data;
	 if(!(final = ft_strdup("SALUT")))
	 	return (NULL);
	data->conv_sz = 5;
	data->conv_t_sz += data->conv_sz;
	// i = 0;
	// ap = (va_arg(data->ap, int));
	// data->ap_size = (data->flag_size - ft_intlen(ap));
	// while (flags[i] != '\0')
	// {
	// 	if (flags[i] == '0')
	// 		ft_flag_zero(flags, data);
	// 	// if (flags[i] == '+')
	// 	// 	ft_flag_plus(flags, data);
	// 	// if (flags[i] == '-')
	// 	// 	ft_flag_minus(flags, data);
	// 	// if (flags[i] == ' ')
	// 	// 	ft_flag_space(flags, data);
	// 	// if (flags[i] >= '0' && flags[i] <= '9')
	// 	// 	ft_espaces(flags, data);
	// 	// if (flags[i] == '.' && (flags[i + 1] >= '0') && (flags[i + 1] <= '9'))
	// 	// 	ft_precision(flags, data);
	// 	i++;
	// }
	// final = ft_strcat(flags, ft_itoa(ap));
	return (final);
}

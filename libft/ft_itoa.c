#include "libft.h"

static int	ft_get_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill_digits(char *result, int n, size_t len, size_t i)
{
	if (n < 0)
	{
		result[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (len-- > i)
	{
		if (n < 0)
		{
			result[len] = '0' + n % 10 * (-1);
			n = n / 10;
		}
		else
		{
			result[len] = '0' + n % 10;
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_get_len(n);
	result = (char *)malloc(len + 1);
	if (!(result))
		return (NULL);
	ft_fill_digits(result, n, len, 0);
	result[len] = '\0';
	return (result);
}

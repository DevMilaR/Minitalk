#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	len_s1;
	size_t	start;

	len_s1 = ft_strlen(s1);
	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (len_s1 > start && ft_strchr(set, s1[len_s1 - 1]))
		len_s1--;
	newstr = (char *)malloc(sizeof(char) * (len_s1 - start + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1 + start, len_s1 - start + 1);
	return (newstr);
}

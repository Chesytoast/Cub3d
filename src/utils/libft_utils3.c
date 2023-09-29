/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   libft_utils3.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: mcourtin <mcourtin@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/09/15 01:55:56 by aabda	 #+#	#+#	 */
/*   Updated: 2023/09/15 02:55:14 by mcourtin	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static size_t	check_str(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 1;
	n = 0;
	if (!(s[0]))
		return (0);
	if (s[0] != c)
		n++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

static void	ft_free_split(char **spl, size_t i)
{
	while (i > 0)
	{
		ft_free((void **)&spl[i]);
		i--;
	}
	ft_free((void **)&spl[0]);
	ft_free((void **)&spl);
}

static char	*ft_strndup(char const *str, size_t size)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_create_str(char **spl, char const *s, char c, int i)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start])
	{
		end = 0;
		while (s[start + end] && s[start + end] != c)
			end++;
		if (end > 0)
		{
			spl[i] = ft_strndup(s + start, end);
			if (!spl[i])
			{
				ft_free_split(spl, i);
				return (NULL);
			}
			i++;
			start = start + end;
		}
		if (s[start])
			start++;
	}
	spl[i] = NULL;
	return (spl);
}

char	**ft_split(t_data *data, char const *s, char c)
{
	char	**spl;
	size_t	size;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	i = -1;
	while (s && s[++i])
		if (s[i] == ',')
			++count;
	if (count != 2)
		errors(data, RGB_COMMA);
	i = 0;
	size = check_str(s, c);
	spl = (char **)malloc(sizeof(spl) * (size + 1));
	if (!spl)
		return (NULL);
	spl = ft_create_str(spl, s, c, i);
	return (spl);
}

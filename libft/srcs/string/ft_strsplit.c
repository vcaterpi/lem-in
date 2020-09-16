/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsprouts <jsprouts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 01:09:00 by vcaterpi          #+#    #+#             */
/*   Updated: 2020/02/22 13:35:13 by jsprouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_skipdelim(char const *str, int *i, char c)
{
	while (str[*i] == c)
		(*i)++;
}

static int		ft_findmaxword(char const *str, char c)
{
	int max_word;
	int cur_word;
	int i;

	i = -1;
	max_word = 0;
	while (str[++i])
	{
		ft_skipdelim(str, &i, c);
		cur_word = 0;
		while (str[i] != c && str[i++])
			cur_word++;
		if (cur_word > max_word)
			max_word = cur_word;
		i--;
		if (!str[i])
			break ;
	}
	return (max_word);
}

static int		ft_wordcount(char const *str, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			count++;
	return (count);
}

static void		ft_fillarray(char **result, char const *str, char c)
{
	int k;
	int j;
	int i;

	i = -1;
	k = 0;
	j = 0;
	while (str[++i])
	{
		ft_skipdelim(str, &i, c);
		k = 0;
		while (str[i] != c && str[i])
			result[j][k++] = str[i++];
		result[j++][k] = '\0';
		if (!str[i] || !result[j])
			break ;
	}
}

char			**ft_strsplit(char const *str, char c)
{
	char	**result;
	int		nwords;
	int		wordlen;

	nwords = ft_wordcount(str, c);
	wordlen = ft_findmaxword(str, c);
	result = ft_double_new(nwords, wordlen);
	if (!nwords)
		return (result);
	ft_fillarray(result, str, c);
	return (result);
}

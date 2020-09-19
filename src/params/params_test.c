/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antondob <antondob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:14:06 by antondob          #+#    #+#             */
/*   Updated: 2020/09/19 15:57:20 by antondob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Ввод графов для теста вручную
*/ 

void test_params(t_lemin *params)
{
	int i;
	int j;

	/*
	** Указываем количество комнат
	*/
	ROOMS_NUM = 3;

	/*
	** Задаем вручную связи между комнатами.
	** Ограничения:
	** 1. Стартовая вершина имеет индекс 0 
	** 2. Конечная вершина имеет максимальный индекс
	** 3. MATRIX[i][j] = 1 -> ребро, направленное из i в j
	** 4. Тк граф неориентированный, то если между вершинами есть связь,
	**    то она реализуется с помощью двух ребер: i->j и j->i
	** 5. Тк пропускные способности всех ребер 1, то данная матрица явялется
	**    матрицей начальных пропусных способностей
	** 
	** Ниже представлены примеры различных графов	
	*/

	CAP_MATRIX = ft_do_table(ROOMS_NUM, ROOMS_NUM);
	
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][2] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][2] = 1;
	CAP_MATRIX[2][1] = 1;
	CAP_MATRIX[2][0] = 1;

	CAP_MATRIX[1][0] = 1;
	/*
	//Граф 7 вершин
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][2] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][3] = 1;
	CAP_MATRIX[2][0] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[3][1] = 1;
	CAP_MATRIX[3][2] = 1;
	CAP_MATRIX[3][4] = 1;
	CAP_MATRIX[3][5] = 1;
	CAP_MATRIX[4][3] = 1;
	CAP_MATRIX[4][6] = 1;
	CAP_MATRIX[5][3] = 1;
	CAP_MATRIX[5][6] = 1;
	CAP_MATRIX[6][4] = 1;
	CAP_MATRIX[6][5] = 1;
	*/
	/*
	//Граф 6 вершин
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][3] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][2] = 1;
	CAP_MATRIX[2][1] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[2][5] = 1;
	CAP_MATRIX[3][0] = 1;
	CAP_MATRIX[3][2] = 1;
	CAP_MATRIX[3][4] = 1;
	CAP_MATRIX[4][3] = 1;
	CAP_MATRIX[4][5] = 1;
	CAP_MATRIX[5][2] = 1;
	CAP_MATRIX[5][4] = 1;
	*/
	/*
	//Граф 12 вершин
	CAP_MATRIX[0][1] =  1;
	CAP_MATRIX[0][6] =  1;
	CAP_MATRIX[1][0] =  1;
	CAP_MATRIX[1][2] =  1;
	CAP_MATRIX[2][1] =  1;
	CAP_MATRIX[2][3] =  1;
	CAP_MATRIX[3][2] =  1;
	CAP_MATRIX[3][4] =  1;
	CAP_MATRIX[4][3] =  1;
	CAP_MATRIX[4][5] =  1;
	CAP_MATRIX[5][4] =  1;
	CAP_MATRIX[5][6] =  1;
	CAP_MATRIX[5][11] = 1;
	CAP_MATRIX[6][0] =  1;
	CAP_MATRIX[6][5] =  1;
	CAP_MATRIX[6][7] =  1;
	CAP_MATRIX[7][6] =  1;
	CAP_MATRIX[7][8] =  1;
	CAP_MATRIX[8][7] =  1;
	CAP_MATRIX[8][9] =  1;
	CAP_MATRIX[9][8] =  1;
	CAP_MATRIX[9][10] = 1;
	CAP_MATRIX[10][9] = 1;
	CAP_MATRIX[10][11] = 1;
	CAP_MATRIX[11][5] = 1;
	CAP_MATRIX[11][10] = 1;
	*/

	/*
	//Граф 4 вершины 
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][2] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][2] = 1;
	CAP_MATRIX[1][3] = 1;
	CAP_MATRIX[2][0] = 1;
	CAP_MATRIX[2][1] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[3][1] = 1;
	CAP_MATRIX[3][2] = 1;
	*/

	/*
	Граф 4 вершин 
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][2] = 1;
	CAP_MATRIX[2][1] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[3][2] = 1;
	*/

	/*
	//Граф 13 верши 
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][5] = 1;
	CAP_MATRIX[0][7] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][2] = 1;
	CAP_MATRIX[2][1] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[3][2] = 1;
	CAP_MATRIX[3][4] = 1;
	CAP_MATRIX[4][3] = 1;
	CAP_MATRIX[4][5] = 1;
	CAP_MATRIX[5][0] = 1;
	CAP_MATRIX[5][4] = 1;
	CAP_MATRIX[5][6] = 1;
	CAP_MATRIX[5][12] = 1;
	CAP_MATRIX[6][5] = 1;
	CAP_MATRIX[6][12] = 1;
	CAP_MATRIX[7][0] = 1;
	CAP_MATRIX[7][8] = 1;
	CAP_MATRIX[8][7] = 1;
	CAP_MATRIX[8][9] = 1;
	CAP_MATRIX[9][8] = 1;
	CAP_MATRIX[9][10] = 1;
	CAP_MATRIX[10][9] = 1;
	CAP_MATRIX[10][11] = 1;
	CAP_MATRIX[11][10] = 1;
	CAP_MATRIX[11][12] = 1;
	CAP_MATRIX[12][5] = 1;
	CAP_MATRIX[12][6] = 1;
	CAP_MATRIX[12][11] = 1;
	*/

	/*
	//Граф 8 вершин
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][5] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][2] = 1;
	CAP_MATRIX[2][1] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[3][2] = 1;
	CAP_MATRIX[3][4] = 1;
	CAP_MATRIX[4][3] = 1;
	CAP_MATRIX[4][5] = 1;
	CAP_MATRIX[5][0] = 1;
	CAP_MATRIX[5][4] = 1;
	CAP_MATRIX[5][6] = 1;
	CAP_MATRIX[5][7] = 1;
	CAP_MATRIX[6][5] = 1;
	CAP_MATRIX[6][7] = 1;
	CAP_MATRIX[7][6] = 1;
	CAP_MATRIX[7][5] = 1;
	*/

	/*
	//Граф 6 вершин 
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][2] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][3] = 1;
	CAP_MATRIX[2][0] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[2][4] = 1;
	CAP_MATRIX[3][1] = 1;
	CAP_MATRIX[3][2] = 1;
	CAP_MATRIX[3][5] = 1;
	CAP_MATRIX[4][2] = 1;
	CAP_MATRIX[4][5] = 1;
	CAP_MATRIX[5][3] = 1;
	CAP_MATRIX[5][4] = 1;
	*/

	/*
	//Граф 21 вершина
	CAP_MATRIX[0][1] = 1;
	CAP_MATRIX[0][5] = 1;
	CAP_MATRIX[0][13] = 1;
	CAP_MATRIX[1][0] = 1;
	CAP_MATRIX[1][2] = 1;
	CAP_MATRIX[2][1] = 1;
	CAP_MATRIX[2][3] = 1;
	CAP_MATRIX[3][2] = 1;
	CAP_MATRIX[3][20] = 1;
	CAP_MATRIX[4][20] = 1;
	CAP_MATRIX[4][19] = 1;
	CAP_MATRIX[5][0] = 1;
	CAP_MATRIX[5][6] = 1;
	CAP_MATRIX[6][5] = 1;
	CAP_MATRIX[6][7] = 1;
	CAP_MATRIX[7][6] = 1;
	CAP_MATRIX[7][8] = 1;
	CAP_MATRIX[8][7] = 1;
	CAP_MATRIX[8][9] = 1;
	CAP_MATRIX[9][8] = 1;
	CAP_MATRIX[9][10] = 1;
	CAP_MATRIX[10][9] = 1;
	CAP_MATRIX[10][11] = 1;
	CAP_MATRIX[11][10] = 1;
	CAP_MATRIX[11][12] = 1;
	CAP_MATRIX[12][11] = 1;
	CAP_MATRIX[12][20] = 1;
	CAP_MATRIX[13][0] = 1;
	CAP_MATRIX[13][14] = 1;
	CAP_MATRIX[14][13] = 1;
	CAP_MATRIX[14][15] = 1;
	CAP_MATRIX[15][14] = 1;
	CAP_MATRIX[15][16] = 1;
	CAP_MATRIX[16][15] = 1;
	CAP_MATRIX[16][17] = 1;
	CAP_MATRIX[17][16] = 1;
	CAP_MATRIX[17][18] = 1;
	CAP_MATRIX[18][17] = 1;
	CAP_MATRIX[18][19] = 1;
	CAP_MATRIX[19][18] = 1;
	CAP_MATRIX[19][4] = 1;
	CAP_MATRIX[20][3] = 1;
	CAP_MATRIX[20][4] = 1;
	CAP_MATRIX[20][12] = 1;
	*/
}
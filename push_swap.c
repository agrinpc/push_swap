/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:06:21 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/09 14:33:12 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define ROWS 2

void	sa(int *a, int start)
{
	int	tmp;

	tmp = a[start];
	a[start] = a[start + 1];
	a[start + 1] = tmp;
	printf("sa\n");
}

void	sb(int *b, int size)
{
	int	tmp;

	tmp = b[size - 1];
	b[size - 1] = b[size - 2];
	b[size - 2] = tmp;
	printf("sb\n");
}

void	pa(int *a, int *b, int start)
{
	b[start] = a[start];
	printf("pa\n");
}

void	pb(int *b, int *a, int start)
{
	a[start] = b[start];
	printf("pb\n");
}

void	rra(int *a, int start, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = a[size - 1];
	while (--i > start)
		a[i] = a[i - 1];
	a[start] = tmp;
	printf("rra\n");
}

void	rr(int *a, int *b, int start, int size)
{
	int	i;
	int	tmp;

	i = start - 1;
	tmp = a[start];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;

	i = start;
	tmp = b[start - 1];
	while (--i > 0)
		b[i] = b[i - 1];
	b[0] = tmp;
	printf("rr\n");
}

void	rrr(int *a, int *b, int start, int size)
{
	int	i;
	int tmp;
	
	i = size;
	tmp = a[size - 1];
	while (--i > start)
		a[i] = a[i - 1];
	a[start] = tmp;

	i = -1;
	tmp = b[0];
	while (++i < start - 1)
		b[i] = b[i + 1];
	b[start - 1] = tmp;
	printf("rrr\n");
}

void	rb(int *b, int start, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = b[size - 1];
	while (--i > start)
		b[i] = b[i - 1];
	b[start] = tmp;
	printf("rb\n");
}

void	ra(int *a, int start, int size)
{
	int	i;
	int tmp;
	
	i = start - 1;
	tmp = a[start];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;
	printf("ra\n");
}

void	rrb(int *b, int start, int size)
{
	int	i;
	int tmp;
	
	i = start - 1;
	tmp = b[start];
	while (++i < size - 1)
		b[i] = b[i + 1];
	b[size - 1] = tmp;
	printf("rrb\n");
}

void	print_a(int *a, int start, int size)
{
	int	i;

	i = start - 1;
	while (++i < size)
		printf("%d\n", a[i]);
	printf("*********************\n");
}

int	get_b_index(int *b, int val, int size)
{
	int i;

	i = -1;
	while (++i < size - 1)
	{
		if (val > b[i])
			if (val < b[i + 1] || b[i + 1] < b[i])
				return (i + 1);
		if (val < b[i + 1] && b[i + 1] < b[i] )
				return (i + 1);
	}
	return (size);
}

void sort_b(int *b, int size, int i)
{
	int j;

	if (size < 2)
		return ;
	if (i > 0)
	{
		j = -1;
		if (size - i < size / 2)
			while (++j < size - i)
				rb(b, 0, size);
		else
			while (++j < i)
				rrb(b, 0, size);
	}
}

int	get_small_elm(int *a, int size, int start)
{
	int	sm;
	int	*tmp;
	int	i;
	int	max;

	i = 0;
	max = 0;
	tmp = malloc(2 * sizeof(int) * ROWS);
	while (i < ROWS)
	{
		tmp[i * 2] = a[start + i];
		tmp[i * 2 + 1] = a[size - i - 1];
		i++;
	}
	i = 0;
	while (++i < 2 * ROWS)
		if (tmp[i] < tmp[max])
			max = i;
	// print_a(tmp, 2 * ROWS);
	return (max);
}

int return_b_r(int *b, int size, int i)
{
	if (size < 2)
		return (0);
	if (size - i < size / 2)
		return (size - 2);
	return (-i - 1);
}

int	is_odd(int num)
{
	if (num % 2 == 0)
		return (1);
	return (0);
}

int do_it(int *a, int *b, int start, int size)
{
	int	max;
	int	i;
	int j;
	int	tmp;

	i = -1;
	max = get_small_elm(a, size, start);
	// j = get_b_index(b, a[start], start);
	// printf("\nmax = %d\n", max);
	if (is_odd(max))
	{
		// printf("\n##########\n#        #\n#%4.d   #\n#        #\n##########\n", a[max / 2]);
		j = get_b_index(b, a[max / 2], start);
		tmp = return_b_r(b, start, j);
		while (++i < max / 2)
		{
			if (tmp > 0)
			{
				if (i < tmp)
					rr(a, b, start, size);
			}
			else
				ra(a, start, size);
		}
	}
	else
	{
		// printf("\n##########\n#        #\n# %d   #\n#        #\n##########\n", a[size - (max + 1) / 2]);
		j = get_b_index(b, a[size - (max + 1) / 2], start);
		tmp = return_b_r(b, start, j);
		// printf("\ntmp = %d\n", tmp);
		while (++i < max / 2 + 1)
		{
			if (tmp < 0)
			{
				if (i < -tmp)
					rrr(a, b, start, size);
			}
			else
				rra(a, start, size);
		}
	}
	// printf("\na0 = %d\n", a[start]);
	// printf("\n start = %d\n", start);
	j = get_b_index(b, a[start], start);
	// print_a(a, start, size);
	// printf("\n j = %d\n", j);
	// printf("\nFIRST B, J = %d, start = %d\n", j, start);
	// print_a(b, 0, start);
	sort_b(b, start, j);
	// printf("\nSECOND B\n");
	// print_a(b, 0, start);
	pa(a, b, start);
	start++;
	// printf("\nTHIRD B\n");
	// print_a(b, 0, start);
	// cond(b, a, 0, start);
	// printf("\n b ");
}

void	finalize_b(int *b, int start)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (++i < start)
		if (b[i] > b[max])
			max = i;
	max++;
	sort_b(b, start, max);
}

void	do_2(int *a, int start)
{
	if (a[start] > a[start + 1])
		sa(a, start);
}

void	do_3(int *a, int start)
{
	if (a[start] > a[start + 2])
	{
		ra(a, start, start + 3);
		if (a[start] > a[start + 2])
			ra(a, start, start + 3);
	}
	if (a[start] > a[start + 1])
		sa(a, start);
}

int	cond(int *a, int *b, int start, int size)
{
	int	i;

	i = -1;
	if (size < 2)
		return (start);
	if (size < 3)
		do_2(a, start);
	else if (size < 4)
		do_3(a, start);
	else if (start < size - 3)
	{
		do_it(a, b, start, size);
		start++;
		// print_a(b, 0, start);
		start = cond(a, b, start, size);
	} else {
		finalize_b(b, start);
		// printf("\nstart = %d, a[%d] = %d, a[%d] = %d, a[%d] = %d\n", start, start, a[start], start + 1, a[start + 1], start + 2, a[start + 2]);
		do_3(a, start);
		while (++i < start)
			pb(b, a, i);
		start = 0;
	}
	return (start);
}

void	push_swap(int *a, int size)
{
	int	*b;
	int	max;
	int	start;
	int	i;

	start = 0;
	i = -1;
	// print_a(a, start, size);
	b = malloc(size * sizeof(int));
	start = cond(a, b, start, size);
	// print_a(b, 0, size);
	// print_a(a, start, size);
}

int main()
{
	int	size = 6;
	int	a[6] = {2, 1, 3, 6, 5, 8};
	// int	a[500] = {-3132, -5181, 2925, 7147, 4303, 5250, 2092, 4738, -6539, 5464, -8992, 9725, -1311, -3990, -352, 8135, 7656, 3215, -1808, -6762, 8261, -1707, -1052, -8614, -2311, -5128, 9171, 
	// -4459, 5287, -5750, 5331, 9307, -4255, -9583, -8877, -2106, 8379, -2720, 2946, -5211, -3154, -7785, -2872, 5686, -3104, -9556, 1372, 9311, -1729, -2788, 3351, -8184, -6024, 6204, -2980, 7900, 
	// -6365, 8410, -4696, -2738, -7409, -855, 2521, 1126, 658, 7227, -7796, 7942, -9842, -3065, -4768, -3866, 2359, 9757, 9538, -6446, 867, -6040, -5090, 9529, 7861, 2199, -7170, 2063, 4474, 106, 
	// 9571, 872, -9836, 1357, -5796, 3522, 3618, 9321, -423, -1938, -3412, 5797, -9521, 2888, -1113, 7826, 5268, 6671, 8899, 6500, 7418, 1540, 5597, 2189, -6690, -3598, -9043, 6192, -4365, 8434, 
	// -6095, -3291, -8466, -581, -3403, 4285, 6635, 3282, 9740, 5128, 3130, -4625, -6542, 7013, -8960, -4330, -4285, 3466, -1131, -3441, 4405, 8013, -8870, 6350, 673, 463, 4063, 1812, 1216, -353, 
	// 5404, 1720, -7382, -5070, 2769, -182, -3674, 8212, 6327, -592, -940, -1492, -4662, -696, -2672, 3415, 6226, -6183, 7547, -206, 9053, -6596, 4029, 6468, -1438, 6916, -6758, -7485, -7652, -6098, 
	// 7274, 2355, 8565, 65, -729, 5213, 357, -5651, -9972, 9539, 4450, 5396, 1423, 9410, -127, 5375, 2987, -8688, -242, -3330, 7429, 7137, -8520, -7079, -1403, -3589, 7090, 8059, -8187, -2439, 6590, 
	// 4103, 3872, 4083, -8484, 3222, -4811, -3931, 7552, -6906, -1327, -1172, -988, -1599, -8796, 9728, -3969, -137, -5595, 2849, 4835, 1567, -1452, -8223, 7201, 3700, 1983, 9598, -7215, 5284, 8504, 
	// 7621, -3047, -5960, -9061, 1099, -1751, 8136, 119, -3148, -1738, -950, -1226, -8249, 7494, -8940, -7803, -8666, 5741, 1838, 147, -9847, 929, -841, 2540, -3351, -5668, -2425, 8758, -6081, 1599, 
	// 892, -4031, 4762, -492, -1641, 2876, -9483, -2885, -2123, -7374, -9399, 4119, 175, -2466, 8437, -35, 7163, -2214, 6842, 4173, 1932, -9101, -9309, -1860, 8180, -8874, -7576, 5242, -8674, -5450, 
	// -6363, -519, 3446, -773, -152, -2746, -2175, -975, 755, 330, -9124, -1917, -8984, 7037, 9255, -9505, -3562, -2089, -3993, -3920, 2663, -1445, -3983, 2393, 2682, -9426, -8007, 4270, 6253, 8597, 
	// -6099, -8441, -8837, -4221, -9304, 3103, -9803, -9678, 8040, 5270, -7495, -7274, 4008, -1480, 2678, -6037, -991, -7180, -9208, 5784, 8528, 6377, 4369, -6585, -8873, -8168, -3701, -3012, -8682, 
	// -2712, 3912, -8772, 4447, 7848, 1134, -6909, 6510, -9603, 3947, 3950, 2754, -9315, -6046, -9669, -3214, 9586, -4921, 2036, -8139, 5473, -6600, 7741, -3252, 5628, -8881, 6464, 7416, -8865, 6391, 
	// 8479, -6227, -9434, -1357, 9975, 9760, 8452, -5987, 6176, -5101, 222, -7286, -1363, -8645, -6324, 4218, -3998, -3927, -6186, -8622, -190, -3387, -8929, 5895, -8782, 3027, 9129, -1285, 1976, 6778, 
	// 84, -3366, 4322, 2140, 6195, 4885, 3201, -1854, 7386, -5887, 230, 9563, -8238, 7202, 5548, -5657, -499, -4440, 2308, 1304, 4500, 3758, 3161, 4907, -1724, -8161, 7578, 3233, -9012, 2291, -1347, 
	// 6522, 9869, 5001, -1359, 4159, -5196, -6439, -9890, -5985, 3392, -6894, 9361, 2166, -9839, -9723, -7670, 6814, 2241, 1578, 7246, 9767, 7789, -4010, 4380, -5771, -1626, 4276, 498, 5229, 8814, -4769, 
	// -4301, -1198, -6828, -5418, -7871, 5324, 239, 944, -2169, -1727, -8148, 2399, -1269, -6172, -7986, 7510, -1999, 8402, 2111, -6349, -8437, -5540};

	push_swap(a, size);
	return (0);
}

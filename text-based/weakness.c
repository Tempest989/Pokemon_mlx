#include "Trainer.h"

//all types are in defence, ie pokemon being hit 

/*
Dragon = A
Water = W
Poison = X
Grass = M
Normal = N
Dark = D
Fairy = F
Fighting = T
Ghost = H
Electric = E
Ice = I
Flying = L
Ground = G
Rock = R
Bug = B
Steel = S
Fire = Q
Psychic = P
*/

void	ft_type_set_1(char type, char element, double *multiplier)
{
	if (type ==  'N' && element  ==  'T')
		*multiplier *= 2.0;
	else if (type == 'N' && element == 'H')
		*multiplier *= 0;
	if (type == 'T' && (element == 'L' || element == 'P' || element == 'F'))
		*multiplier *= 2.0;
	else if (type == 'T' && (element == 'R' || element == 'B' || element == 'D'))
		*multiplier *= 0.5;
	if (type == 'L' && (element == 'R' || element == 'I' || element == 'E'))
		*multiplier *= 2.0;
	else if (type == 'L' && (element == 'T' || element == 'B' || element == 'M'))
		*multiplier *= 0.5;
	else if (type == 'L' && element == 'G')
		*multiplier *= 0;
	if (type == 'X' && (element == 'G' || element == 'P'))
		*multiplier *= 2.0;
	else if (type == 'X' && (element == 'T' || element == 'B' || element == 'X' || element == 'M' || element == 'F'))
		*multiplier *= 0.5;
	if (type == 'G' && (element == 'W' || element == 'I' || element == 'M'))
		*multiplier *= 2.0;
	else if (type == 'G' && (element == 'X' || element == 'R'))
		*multiplier *= 0.5;
	else if (type == 'G' && element == 'E')
		*multiplier *= 0;
}

void	ft_type_set_2(char type, char element, double *multiplier)
{
	if (type == 'R' && (element == 'T' || element == 'G' || element == 'S' || element == 'W' || element == 'M'))
		*multiplier *= 2.0;
	else if (type == 'R' && (element == 'N' || element == 'L' || element == 'X' || element == 'Q'))
		*multiplier *= 0.5;
	if (type == 'B' && (element == 'L' || element == 'R' || element == 'Q'))
		*multiplier *= 2.0;
	else if (type == 'B' && (element == 'T' || element == 'G' || element == 'M'))
		*multiplier *= 0.5;
	if (type == 'H' && (element == 'H' || element == 'D'))
		*multiplier *= 2.0;
	else if (type == 'H' && (element == 'X' || element == 'B'))
		*multiplier *= 0.5;
	else if (type == 'H' && (element == 'N' || element == 'T'))
		*multiplier *= 0;
	if (type == 'S' && (element == 'T' || element == 'G' || element == 'Q'))
		*multiplier *= 2.0;
	else if (type == 'S' && (element == 'N' || element == 'L' || element == 'R' || element == 'B' || element == 'S' || element == 'M' || element == 'P' || element == 'I' || element == 'A' || element == 'F'))
		*multiplier *= 0.5;
	else if (type == 'S' && element == 'X')
		*multiplier *= 0;
	if (type == 'Q' && (element == 'G' || element == 'R' || element == 'W'))
		*multiplier *= 2.0;
	else if (type == 'Q' && (element == 'B' || element == 'S' || element == 'Q' || element == 'M' || element == 'I' || element == 'F'))
		*multiplier *= 0.5;
}

void	ft_type_set_3(char type, char element, double *multiplier)
{
	if (type == 'W' && (element == 'M' || element == 'E'))
		*multiplier *= 2.0;
	else if (type == 'W' && (element == 'S' || element == 'Q' || element == 'W' || element == 'I'))
		*multiplier *= 0.5;
	if (type == 'M' && (element == 'L' || element == 'X' || element == 'B' || element == 'Q' || element == 'I'))
		*multiplier *= 2.0;
	else if (type == 'M' && (element == 'G' || element == 'W' || element == 'M' || element == 'E'))
		*multiplier *= 0.5;
	if (type == 'E' && element == 'G')
		*multiplier *= 2.0;
	else if (type == 'E' && (element == 'L' || element == 'S' || element == 'E'))
		*multiplier *= 0.5;
	if (type == 'P' && (element == 'B' || element == 'H' || element == 'D'))
		*multiplier *= 2.0;
	else if (type == 'P' && (element == 'T' || element == 'P'))
		*multiplier *= 0.5;
	if (type == 'I' && (element == 'T' || element == 'R' || element == 'S' || element == 'Q'))
		*multiplier *= 2.0;
	else if (type == 'I' && element == 'I')
		*multiplier *= 0.5;
}

void	ft_type_set_4(char type, char element, double *multiplier)
{
	if (type == 'A' && (element == 'I' || element == 'A' || element == 'F'))
		*multiplier *= 2.0;
	else if (type == 'A' && (element == 'Q' || element == 'W' || element == 'M' || element == 'E'))
		*multiplier *= 0.5;
	if (type == 'D' && (element == 'T' || element == 'B' || element == 'F'))
		*multiplier *= 2.0;
	else if (type == 'D' && (element == 'D' || element == 'H'))
		*multiplier *= 0.5;
	else if (type == 'D' && element == 'P')
		*multiplier *= 0;
	if (type == 'F' && (element == 'X' || element == 'S'))
		*multiplier *= 2.0;
	else if (type == 'F' && (element == 'T' || element == 'B' || element == 'D'))
		*multiplier *= 0.5;
	else if (type == 'F' && element == 'A')
		*multiplier *= 0;
}

double	ft_weakness(int typeNum, char type[2], char element)
{
	double	multiplier;
	int		i;
	
	multiplier = 1.0;
	i = -1;
	while (++i < typeNum)
	{
		if (type[i] == 'N' || type[i] == 'T' || type[i] == 'L' || type[i] == 'X' || type[i] == 'G')
			ft_type_set_1(type[i], element, &multiplier);
		else if (type[i] == 'R' || type[i] == 'B' || type[i] == 'H' || type[i] == 'S' || type[i] == 'Q')
			ft_type_set_2(type[i], element, &multiplier);
		else if (type[i] == 'W' || type[i] == 'M' || type[i] == 'E' || type[i] == 'P' || type[i] == 'I')
			ft_type_set_3(type[i], element, &multiplier);
		else
			ft_type_set_4(type[i], element, &multiplier);
	}
	return (multiplier);
}
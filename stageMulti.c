#include "Trainer.h"

void	ft_print_ele(char ele)
{
	if (ele == 'A')
		printf("Dragon");
	else if (ele == 'W')
		printf("Water");
	else if (ele == 'X')
		printf("Poison");
	else if (ele == 'M')
		printf("Grass");
	else if (ele == 'N')
		printf("Normal");
	else if (ele == 'D')
		printf("Dark");
	else if (ele == 'F')
		printf("Fairy");
	else if (ele == 'T')
		printf("Fighting");
	else if (ele == 'H')
		printf("Ghost");
	else if (ele == 'E')
		printf("Electic");
	else if (ele == 'I')
		printf("Ice");
	else if (ele == 'L')
		printf("Flying");
	else if (ele == 'G')
		printf("Ground");
	else if (ele == 'R')
		printf("Rock");
	else if (ele == 'B')
		printf("Bug");
	else if (ele == 'S')
		printf("Steel");
	else if (ele == 'Q')
		printf("Fire");
	else if (ele == 'P')
		printf("Psychic");
	else
		printf("Error Ele printing");
}

void	ft_print_condition(char condition)
{
	if (condition == 'x')
		printf("Poisoned");
	else if (condition == 'X')
		printf("Badly Poisoned");
	else if (condition == 'y')
		printf("Confused");
	else if (condition == 'f')
		printf("Frozen");
	else if (condition == 'p')
		printf("Paralyzed");
	else if (condition == 'n')
		printf("None");
	else if (condition == 'b')
		printf("Burned");
	else if (condition == 's')
		printf("Sleeping");
	else
		printf("Error Condition printing");
}

void	ft_print_type(char type)
{
	if (type == 'P')
		printf("Physical");
	else if (type == 'S')
		printf("Special");
	else if (type == 'T')
		printf("Status");
	else
		printf("Error Type printing");
}

double	ft_filler(int stage, int stat)
{
	if (stage == 0)
		return (1 / 24);
	else if (stage == 1)
		return (1 / 8);
	else if (stage == 2)
		return (1 / 2);
	else if (stage > 2)
		return (1);
	else
		return (-1);
}

double	ft_stageMulti (int stage, int stat)
{
	if (stat < 5 && stat >= 0)
	{
		if (stage >= 0 && stage < 7)
			return ((2 + stage) / 2);
		else if (stage <= 0 && stage > -7)
			return (2 / (stage + 2));
		else
			return (-1);
	}
	else if (stat == 5)
	{
		if (stage >= 0 && stage < 7)
			return ((3 + stage) / 3);
		else if (stage <= 0 && stage > -7)
			return (3 / (stage + 3));
		else
			return (-1);
	}
	else if (stat == -1)
		return (ft_filler(stage, stat));
	return (-69);
}
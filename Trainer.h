#ifndef TRAINER_H
#define TRAINER_H
#include "Pokemon.h"
#include <stdio.h>

typedef struct s_Trainer
{
	char		type;
    char		name[11];
    int			current;
    t_Pokemon	party[6];
}	t_Trainer;

void	ft_randomise_pokemon(t_Pokemon party[6], char type, int track, int check);
void	ft_assign_steven(t_Pokemon party[6]);
void	ft_initialize_trainer(t_Trainer *trainer, char type);

int		ft_enemyAttack(t_Trainer *player,t_Trainer *enemy);
double	ft_weakness(int typeNum, char type[2], char element);
double	ft_stageMulti (int stage, int stat);
void	ft_print_ele(char ele);
void	ft_print_type(char type);
void	ft_print_condition(char condition);
// int		ft_enemyItem(t_Trainer *enemy,t_Trainer *player);

#endif

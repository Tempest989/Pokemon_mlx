#include "Trainer.h"

void	ft_randomise_pokemon(t_Pokemon party[6], char type, int track, int check)
{
	int randomiser[6];

	while (++track < 6)
	{
		randomiser[track] = rand() % 17;
		check = -1;
		while (++check < track)
		{
			if (randomiser[check] == randomiser[track])
			{
				track--;
				break ;
			}
		}
		if (track == check)
			ft_initialize_pokemon(&party[track], randomiser[track]);
	}	
}

void	ft_steven_assign(t_Pokemon party[6])
{
	ft_initialize_pokemon(&party[0], 12);
	ft_initialize_pokemon(&party[1], 15);
	ft_initialize_pokemon(&party[2], 16);
	ft_initialize_pokemon(&party[3], 13);
	ft_initialize_pokemon(&party[4], 14);
	ft_initialize_pokemon(&party[5], 11);
}

void	ft_single(t_Pokemon party[6])
{
	ft_initialize_pokemon(&party[0], 0);
	ft_initialize_pokemon(&party[1], 1);
	ft_initialize_pokemon(&party[2], 2);
	ft_initialize_pokemon(&party[3], 3);
	ft_initialize_pokemon(&party[4], 4);
	ft_initialize_pokemon(&party[5], 5);
}

void	ft_initialize_trainer(t_Trainer *trainer, char type)
{
	if (type == 's')
	{
		ft_strcpy(trainer->name, "Steven");
		ft_steven_assign(trainer->party);
	}
	else if (type == 't')
	{
		ft_strcpy(trainer->name, "Test");
		ft_single(trainer->party);
	}
	else
	{
		ft_strcpy(trainer->name, "Darcy");
		// scanf("%10s", trainer->name);
		ft_randomise_pokemon(trainer->party, type, -1, 0);
	}
	trainer->type = type;
	trainer->current = 0;
}

int ft_enemyAttack(t_Trainer *player, t_Trainer *enemy)
{
    double stab=1.0;
    double burn=1.0;
    double weather=1.0;
    double effective=1.0;
    double damage=0.0;
    int ppCheck=0;
    double Effect[2]={0,1.0};

    for (int i=0;i<4;i++)
    {
        if (enemy->party[enemy->current].moveset[i].moveType != 'T' && enemy->party[enemy->current].moveset[i].movePP > 0)
        {
            effective = ft_weakness(player->party[player->current].typeNum, player->party[player->current].type, enemy->party[enemy->current].moveset[i].moveEle);
            if (effective > Effect[0])
            {
                Effect[1] = effective;
                Effect[0] = i;
            }
            for (int j=0;j<enemy->party[enemy->current].typeNum;j++)
            {
                if (enemy->party[enemy->current].moveset[i].moveEle == enemy->party[enemy->current].type[j])
                {
                    stab = 1.5;
                    break ;
                }
            }
            if (enemy->party[enemy->current].moveset[i].moveType == 'P')
            {
                if (enemy->party[enemy->current].condition[0] == 'B')
                    burn = 0.5;
                damage += ((((((2 * 50) / 5) + 2) * enemy->party[enemy->current].moveset[i].movePow * ((enemy->party[enemy->current].current[1] * (ft_stageMulti(enemy->party[enemy->current].statMultiplier[0], 0))) / (player->party[player->current].current[2] * (ft_stageMulti(player->party[player->current].statMultiplier[1], 1))))) / 50) + 2) * weather * stab * 0.85 * burn * effective;
            }
            else if (enemy->party[enemy->current].moveset[i].moveType == 'S')
				damage += ((((((2 * 50) / 5) + 2) * enemy->party[enemy->current].moveset[i].movePow * ((enemy->party[enemy->current].current[3] * (ft_stageMulti(enemy->party[enemy->current].statMultiplier[2], 2))) / (player->party[player->current].current[4] * (ft_stageMulti(player->party[player->current].statMultiplier[3], 3))))) / 50) + 2) * weather * stab * 0.85 * burn * effective;
            if (damage >= player->party[player->current].current[0])
                return (i);
        }
        if (enemy->party[enemy->current].moveset[i].movePP > 0)
            ppCheck++;
    }
    if (ft_strcmp(enemy->party[enemy->current].pokeName, "Cradily") == 'y')
    {
        if (player->party[player->current].condition[1] == 'n' && enemy->party[enemy->current].moveset[0].movePP > 0)
            return (0);
    }
    if (Effect[1] > 1.0 && enemy->party[enemy->current].moveset[(int)Effect[0]].movePP > 0)
        return (Effect[0]);
    while (ppCheck > 0)
    {
        int chance = rand() % 4;
        if (enemy->party[enemy->current].moveset[chance].movePP > 0)
            return (chance);
    }
	return (0);
}
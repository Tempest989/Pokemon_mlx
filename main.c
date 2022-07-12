#include "Battle.h"

int main()
{
	srand(time(NULL));
	t_Battle battle;
	t_Trainer player;
	t_Trainer enemy;

	ft_initialize_trainer(&enemy, 's');
	ft_initialize_trainer(&player, 'a');
	ft_initialize_battle(&battle);

	ft_turn(&player, &enemy, &battle);
	printf("GAME FINISHED\n");
	return (0);
}
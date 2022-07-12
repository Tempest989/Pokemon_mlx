#ifndef BATTLE_H
#define BATTLE_H
#include "Trainer.h"
#include <time.h>
#include <unistd.h>

typedef struct s_Battle
{
	//string weatherCondition;
	int playerSpikes;   //if the player has laid down spikes (0 to 3 where 0 is no spikes)
	int enemySpikes;	//if the AI has laid down spikes (0 to 3)
	int playerReflect;  //if the player has a reflect up
	int enemyReflect;   //if the AI has a reflect up
	int playerLightScreen;  //Same as above but for lightscreen
	int enemyLightScreen;   //Same as above but for lightscreen
	//string first;
}	t_Battle;

void	ft_initialize_battle(t_Battle *battle);
int		ft_enemySwitch(t_Trainer *player, t_Trainer *enemy);
int		ft_playerBattle(t_Trainer *player);	   // might delete
int		ft_playerItem(t_Trainer *player);	 	// might delete
int		ft_playerSwitch(t_Trainer *player, t_Trainer *enemy);	   // might delete
int		ft_turnAttack(t_Pokemon *atk, t_Pokemon *def, int attack, char user);
int		ft_turnStatus(t_Pokemon *atk, t_Pokemon *def, t_Battle *battle, char user, int attack);
double	ft_turn(t_Trainer* player, t_Trainer* enemy, t_Battle *battle);
int		ft_confusionProc(t_Pokemon* pokemon, int choice);
int		ft_movePriority(t_Pokemon* player, t_Pokemon* enemy, int enemyCheck, int choice, int choices);
#endif

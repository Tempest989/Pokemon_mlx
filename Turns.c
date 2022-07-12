#include "Battle.h"

double ft_turn(t_Trainer* player, t_Trainer* enemy, t_Battle *battle)
{
	int turnCounter=0;
	int checker=0;
	double results=0;
	int	end = 0;
	int check;
	int checkP;
	int checkE;
	int choice;
	int choices;
	double chance;
	int enemyCheck;
	int switchedP;
	int switchedE;
	int confusedP;
	int confusedE;

	while (checker == 0)
	{
		//player turn
		turnCounter++;
		printf("\n\n\n\n");
		usleep(1500000);
		printf("---------------------------\n");
		printf("      Turn Number: %d\n", turnCounter);
		printf("---------------------------\n");
		printf("\n\n\n\n");
		usleep(1500000);
		//initialising variables
		check=2;
		checkP=1;
		checkE=1;
		enemyCheck=0;
		switchedP=0;
		switchedE=0;
		confusedP=0;
		confusedE=0;
		if (ft_strcmp(player->party[player->current].ability, "Intimidate") == 'y' && ft_strcmp(enemy->party[enemy->current].ability, "Clear Body") == 'n' && (turnCounter == 1))
		{
			printf("%s's Intimidate Ability has lowered %s's ATK!\n", player->party[player->current].pokeName, enemy->party[enemy->current].pokeName);
			usleep(750000);
			enemy->party[enemy->current].statMultiplier[1] -= 1;
		}
		else if (ft_strcmp(player->party[player->current].ability, "Intimidate") == 'y' && ft_strcmp(enemy->party[enemy->current].ability, "Clear Body") == 'y' && (turnCounter == 1))
		{
			printf("%s's Intimidate Ability has No Effect on %s Due to its Clear Body Ability!\n", player->party[player->current].pokeName, enemy->party[enemy->current].pokeName);
			usleep(750000);
		}

		if (ft_strcmp(enemy->party[enemy->current].ability, "Intimidate") == 'y' && ft_strcmp(player->party[enemy->current].ability, "Clear Body") == 'n' && turnCounter == 1)
		{
			printf("%s's Intimidate Ability has lowered %s's ATK!\n", enemy->party[enemy->current].pokeName, enemy->party[enemy->current].pokeName);
			usleep(750000);
			player->party[player->current].statMultiplier[1] -= 1;
		}
		else if (ft_strcmp(enemy->party[enemy->current].ability, "Intimidate") == 'y' && ft_strcmp(player->party[enemy->current].ability, "Clear Body") == 'y' && turnCounter == 1)
		{
			printf("%s's Intimidate Ability has No Effect on %s Due to its Clear Body Ability!\n", enemy->party[enemy->current].pokeName, player->party[enemy->current].pokeName);
			usleep(750000);
		}
		if (player->party[player->current].destiny != 0)
			player->party[player->current].destiny = 0;
		if (enemy->party[enemy->current].destiny != 0)
			enemy->party[enemy->current].destiny = 0;
		if (player->party[player->current].flinched != 0)
			player->party[player->current].flinched = 0;
		if (enemy->party[enemy->current].flinched != 0)
			enemy->party[enemy->current].flinched = 0;
		// //do checks for cooldown  > 0 and cooldown  < 0 to perform certain moves etc.
		// if (player->party[player->current].cooldown > 0)
		// {
		//	 player->party[player->current].setCooldown(1,"-");
		// }
		// if (enemy->party[enemy->current].cooldown > 0)
		// {
		//	 enemy->party[enemy->current].setCooldown(1,"-");
		// }
		//reducing light screen timers by 1 per turn for players and changing stats if its active
		if (player->party[player->current].outrage == 1)
			player->party[player->current].outrage = 2;
		else if (player->party[player->current].outrage == 2)
		{
			int outrage = rand() % 2;
			if (outrage == 0)
				player->party[player->current].outrage = 3;
			else
			{
				player->party[player->current].outrage = 0;
				player->party[player->current].condition[1] = 'y';
				printf("%s has become Confused!\n\n", player->party[player->current].pokeName); 
			}
		}
		else if (player->party[player->current].outrage == 3)
		{
			player->party[player->current].outrage = 0;
			player->party[player->current].condition[1] = 'y';			
			printf("%s has become Confused!\n\n", player->party[player->current].pokeName); 
		}
		if (enemy->party[enemy->current].outrage == 1)
			enemy->party[enemy->current].outrage = 2;
		else if (enemy->party[enemy->current].outrage == 2)
		{
			int outrage = rand() % 2;
			if (outrage == 0)
				enemy->party[enemy->current].outrage = 3;
			else
			{
				enemy->party[enemy->current].outrage = 0;
				enemy->party[enemy->current].condition[1] = 'y';
				printf("%s has become Confused!\n\n", enemy->party[enemy->current].pokeName);
			}
		}
		else if (enemy->party[enemy->current].outrage == 3)
		{
			enemy->party[enemy->current].outrage = 0;
			enemy->party[enemy->current].condition[1] = 'y';			
			printf("%s has become Confused!\n\n", enemy->party[enemy->current].pokeName);
		}

		if (battle->playerLightScreen == 5)
		{
			player->party[player->current].current[4] *= 1.5;
			battle->playerLightScreen -= 1;
		}
		else if (battle->playerLightScreen > 0)
		{
			battle->playerLightScreen -= 1;
			if (battle->playerLightScreen == 0)
				player->party[player->current].current[4] /= 1.5;
		}
		//reducing reflect timers by 1 per turn for players and changing stats if its active
		if (battle->playerReflect == 5)
		{
			player->party[player->current].current[2] *= 1.5;
			battle->playerReflect -= 1;
		}
		else if (battle->playerReflect > 0)
		{
			battle->playerReflect -= 1;
			if (battle->playerReflect == 0)
				player->party[player->current].current[2] /= 1.5;
		}
		//reducing light screen timers by 1 per turn for enemy AI and changing stats if its active
		if (battle->enemyLightScreen == 5)
		{
			enemy->party[enemy->current].current[4] *= 1.5;
			battle->enemyLightScreen -= 1;
		}
		else if (battle->enemyLightScreen > 0)
		{
			battle->enemyLightScreen -= 1;
			if (battle->enemyLightScreen == 0)
				enemy->party[enemy->current].current[4] /= 1.5;
		}
		//reducing ref;ect timers by 1 per turn for enemy AI and changing stats if its active
		if (battle->enemyReflect == 5)
		{
			enemy->party[enemy->current].current[2] *= 1.5;
			battle->enemyReflect -= 1;
		}
		else if (battle->enemyReflect > 0)
		{
			battle->enemyReflect -= 1;
			if (battle->enemyReflect == 0)
				enemy->party[enemy->current].current[2] /= 1.5;
		}
		if (player->party[player->current].outrage != 0)
		{
			printf("\n%s's Pokemon:\n", enemy->name);
			printf("%s's HP: %d / %d\n", enemy->party[enemy->current].pokeName, enemy->party[enemy->current].current[0], enemy->party[enemy->current].base[0]);
			printf("Status Condition: ");
			ft_print_condition(enemy->party[enemy->current].condition[0]);
			printf(", ");
			ft_print_condition(enemy->party[enemy->current].condition[1]);
			printf("\n");
			//print if light screen and/or reflect are up or not
			if (battle->enemyLightScreen > 0)
				printf("Enemy's Side of the field is covered in a Screen of Light\n");
			if (battle->enemyReflect > 0)
				printf("Enemy's Side of the field is protected by a Wall of Reflecting Light\n");
			printf("\n");
			//dispaying player's currnet pokemon's stats and conditions
			printf("%s's Pokemon:\n", player->name);
			printf("%s's HP: %d / %d\n", player->party[player->current].pokeName, player->party[player->current].current[0], player->party[player->current].base[0]);
			printf("Status Condition: ");
			ft_print_condition(player->party[player->current].condition[0]);
			printf(", ");
			ft_print_condition(player->party[player->current].condition[1]);
			printf("\n");
			if (battle->playerLightScreen > 0)
				printf("Player's Side of the field is covered in a Screen of Light\n");
			if (battle->playerReflect > 0)
				printf("Player's Side of the field is protected by a Wall of Reflecting Light\n");
			printf("\n\n");
		}
		while (check != 0 && player->party[player->current].outrage == 0)
		{
			//dispaying enemy AI's currnet pokemon's stats and conditions
			printf("\n%s's Pokemon:\n", enemy->name);
			printf("%s's HP: %d / %d\n", enemy->party[enemy->current].pokeName, enemy->party[enemy->current].current[0], enemy->party[enemy->current].base[0]);
			printf("Status Condition: ");
			ft_print_condition(enemy->party[enemy->current].condition[0]);
			printf(", ");
			ft_print_condition(enemy->party[enemy->current].condition[1]);
			printf("\n");
			//print if light screen and/or reflect are up or not
			if (battle->enemyLightScreen > 0)
				printf("Enemy's Side of the field is covered in a Screen of Light\n");
			if (battle->enemyReflect > 0)
				printf("Enemy's Side of the field is protected by a Wall of Reflecting Light\n");
			printf("\n");
			//dispaying player's currnet pokemon's stats and conditions
			printf("%s's Pokemon:\n", player->name);
			printf("%s's HP: %d / %d\n", player->party[player->current].pokeName, player->party[player->current].current[0], player->party[player->current].base[0]);
			printf("Status Condition: ");
			ft_print_condition(player->party[player->current].condition[0]);
			printf(", ");
			ft_print_condition(player->party[player->current].condition[1]);
			printf("\n");
			if (battle->playerLightScreen > 0)
				printf("Player's Side of the field is covered in a Screen of Light\n");
			if (battle->playerReflect > 0)
				printf("Player's Side of the field is protected by a Wall of Reflecting Light\n");
			printf("\n");
			if (player->party[player->current].cooldown == 0)
			{
				printf("What would you like to do? (1 = Attack, 2 = Use Item, 3 = Switch): ");
				scanf("%1d", &choice);
				while (choice < 1 || choice > 3)
				{
					printf("Invalid Input!!! Please Try again (1 = Attack, 2 = Use Item, 3 = Switch): ");
					scanf("%1d", &choice);
				}
				//accepting input from user (attack item or switch)
				printf("\n");
				if (choice == 1)
					choices = ft_playerBattle(player);
				else if (choice == 2)
					choices = ft_playerItem(player);
				else if (choice == 3)
					choices = ft_playerSwitch(player, enemy);
			}
			else if (player->party[player->current].cooldown != 0)
			{
				if (player->party[player->current].cooldown < 0)	//if a move has a cooldown force the user to not be able to do anything this turn
				{
					printf("%s is still RECOVERING\n", player->party[player->current].pokeName);
					usleep(1500000);
				}
				break ;
			}
			if (choices != -1)
			{
				check=0;
				if (choice == 3)
					switchedP=1;
			}
			if (choices == -1)
				check=1;
		}
		//player switching into spikes increasing damage per amount of spikes laid
		if (battle->enemySpikes > 0 && choice == 3)
		{
			switch (battle->enemySpikes)
			{
				case 1:
				{
					player->party[player->current].current[0] -= ((double)(1) /  8) * player->party[player->current].base[0];
					break ;
				}
				case 2:
				{
					player->party[player->current].current[0] -= ((double)(1) /  6) * player->party[player->current].base[0];
					break ;
				}
				default:
				{
					player->party[player->current].current[0] -= ((double)(1) /  4) * player->party[player->current].base[0];
					break ;
				}
			}
		}
		//enemy turn
		//once teams have been created, call what team their versing, which champions team, the have functions within for what pokemon is out and what moves it will do.
		//check if player and enemy can even move (status conditions etc).
		
			// enemyCheck = ft_enemyItem(enemy,player,battle);
			// if (enemyCheck != -2)
		enemyCheck = ft_enemySwitch(player, enemy);
		if (enemyCheck != -1)
			enemyCheck = ft_enemyAttack(player, enemy);
		else
			switchedE = 2;
		if (enemyCheck == -1 && battle->playerSpikes > 0)
		{
			switch (battle->playerSpikes)
			{
				case 1:
				{
					enemy->party[enemy->current].current[0] -= ((double)(1) /  8) * enemy->party[enemy->current].base[0];
					break ;
				}
				case 2:
				{
					enemy->party[enemy->current].current[0] -= ((double)(1) /  6) * enemy->party[enemy->current].base[0];
					break ;
				}
				default:
				{
					enemy->party[enemy->current].current[0] -= ((double)(1) /  4) * enemy->party[enemy->current].base[0];
					break ;
				}
			}
		}
		//condition cooldowns, wkaing player pokemon up/un-freezing if the conditincool down number of turns have passed
		if (player->party[player->current].conditionCool[0] > 0)
		{
			player->party[player->current].conditionCool[0] -= 1;
			if (player->party[player->current].conditionCool[0] == 0 && player->party[player->current].condition[0] == 's')
			{
				printf("%s is no longer ASLEEP!\n", player->party[player->current].pokeName);
				player->party[player->current].condition[0] = 'n';
			}
		}
		if (choice == 1 && player->party[player->current].condition[0] == 'f')
		{
			chance = rand() % 100;
			if (chance <= 20)
			{
				player->party[player->current].condition[0] = 'n';
				choice = -10;
			}
		}
		if ((player->party[player->current].condition[0] == 's' && ft_strcmp(player->party[player->current].moveset[choices].moveName, "Sleep Talk") == 'n' || player->party[player->current].condition[0] == 'f'))
		{
			// if (player->party[player->current].condition[0] == 's' && (choice == 1 && player->party[player->current].moveset[choices].getMoveName() == "SleepTalk"))
			// {
			//	 //skip this choice, if break might break while loop for whole turns thing, come up with another solution later?
			// }
			// else
			// {
				choice = -10;
			// }
		}
		if (player->party[player->current].condition[0] == 'p')   //force player pokemon to be unable to move if paralyzed (25% chance)
		{
			chance = rand() % 100;
			if (chance <= 25)
			{
				printf("%s is Paralyzed and unable to move!\n", player->party[player->current].pokeName);
				choice = -10;
			}
		}
		//condition cooldowns, wkaing enemy AI pokemon up/un-freezing if the conditincool down number of turns have passed
		if (enemy->party[enemy->current].conditionCool[0] > 0)
		{
			enemy->party[enemy->current].conditionCool[0] -= 1;
			if (enemy->party[enemy->current].conditionCool[0] == 0 && enemy->party[enemy->current].condition[0] == 's')
			{
				printf("%s is no longer ALSEEP!\n", enemy->party[enemy->current].pokeName);
				enemy->party[enemy->current].condition[0] = 'n';
				choice = -10;
			}
		}
		if (enemyCheck >= 0 && enemy->party[enemy->current].condition[0] == 'f')
		{
			chance = rand() % 100;
			if (chance <= 20)
				enemy->party[enemy->current].condition[0] = 'n';
		}
		if (enemy->party[enemy->current].condition[0] == 's' || enemy->party[enemy->current].condition[0] == 'f')
			enemyCheck = -10;
		if (enemy->party[enemy->current].condition[0] == 'p')	 //force enemy AI pokemon to be unable to move if paralyzed (25% chance)
		{
			chance = rand() % 100;
			if (chance <= 25)
			{
				printf("%s is Paralyzed and unable to move!\n", enemy->party[enemy->current].pokeName);
				enemyCheck = -10;
			}
		}
		//death system which forces switcihng and checks for end states
		if (player->party[player->current].current[0] <= 0)
		{
			checkP = ft_playerSwitch(player,enemy);
			switchedP = 1;								//if current player pokemon dies force them to switch
		}
		if (checkP == -1)
		{
			printf("Player is out of usable POKEMON, PLAYER LOSES!!\n");	  //return 0 if player is out of usuable pokemon (Player lose state)
			return (results);
		}
		if (enemy->party[enemy->current].current[0] <= 0)
		{
			checkE = ft_enemySwitch(player,enemy);
			switchedE=1;								//if current enemy pokemon dies force them to switch
		}
		if (checkE == -1)
		{
			printf("Enemy is out of usable POKEMON, PLAYER WINS!!\n");		 //return 1 if enemy AI is out of usuable pokemon (Player win state)
			int counter=0;
			for (int i=0;i < 6;i++)
			{
				if (player->party[i].current[0] > 0)
					counter++;
				else
					break ;
			}
			results = 1;
			if (counter == 6)
				results = 1.5;
			return (results);
		}
		//figuring out who moves first
		printf("\n");
		if (player->party[player->current].current[0] > 0 && enemy->party[enemy->current].current[0] > 0)
		{
			end = ft_movePriority(&player->party[player->current], &enemy->party[enemy->current], enemyCheck, choice, choices);
			if (end == 0)
			{
				confusedP = ft_confusionProc(&player->party[player->current], choice);
				if (player->party[player->current].moveset[choices].moveType != 'T')
				{
					if (confusedP == 0 && player->party[player->current].flinched == 0)
						ft_turnAttack(&player->party[player->current], &enemy->party[enemy->current], choices, 'p');
				}
				else if (player->party[player->current].moveset[choices].moveType == 'T')
				{
					if (confusedP == 0 && player->party[player->current].flinched == 0)
						ft_turnStatus(&player->party[player->current], &enemy->party[enemy->current], battle, 'p', choices);
				}
				printf("\n\n");
				if (enemy->party[enemy->current].current[0] <= 0)
				{
					checkE = ft_enemySwitch(player, enemy);
					switchedE=1;
					confusedE=0;
				}
				if (enemyCheck >= 0)
					confusedE = ft_confusionProc(&enemy->party[enemy->current], 1);
				if (checkE != -10 && switchedE == 0 && enemyCheck  >=  0)
				{
					if (enemy->party[enemy->current].moveset[enemyCheck].moveType != 'T')
					{
						if (confusedE == 0 && enemy->party[enemy->current].flinched == 0)
							ft_turnAttack(&enemy->party[enemy->current], &player->party[player->current], enemyCheck, 'e');
					}
					else if (enemy->party[enemy->current].moveset[enemyCheck].moveType == 'T')
					{
						if (confusedE == 0 && enemy->party[enemy->current].flinched == 0)
							ft_turnStatus(&enemy->party[enemy->current], &player->party[player->current], battle, 'e', enemyCheck);
					}
				}
			}
			else
			{
				if (enemyCheck >= 0)
					confusedE = ft_confusionProc(&enemy->party[enemy->current], 1);
				if (enemy->party[enemy->current].moveset[enemyCheck].moveType != 'T')
				{
					if (confusedE == 0 && enemy->party[enemy->current].flinched == 0)
						ft_turnAttack(&enemy->party[enemy->current], &player->party[player->current], enemyCheck, 'e');
				}
				else if (enemy->party[enemy->current].moveset[enemyCheck].moveType == 'T')
				{
					if (confusedE == 0 && enemy->party[enemy->current].flinched == 0)
						ft_turnStatus(&enemy->party[enemy->current], &player->party[player->current], battle, 'e', enemyCheck);
				}
				printf("\n\n");
				if (player->party[player->current].current[0] <= 0)
				{
					checkP = ft_playerSwitch(player,enemy);
					switchedP = 1;
					confusedP = 0;
				}
				if (choice == 1)
					confusedP = ft_confusionProc(&player->party[player->current], choice);
				if (checkP != -10 && switchedP == 0 && choice == 1)
				{
					if (player->party[player->current].moveset[choices].moveType != 'T')
					{
						if (confusedP == 0 && player->party[player->current].flinched == 0)
							ft_turnAttack(&player->party[player->current], &enemy->party[enemy->current], choices, 'p');
					}
					else if (player->party[player->current].moveset[choices].moveType == 'T')
					{
						if (confusedP == 0 && player->party[player->current].flinched == 0)
							ft_turnStatus(&player->party[player->current], &enemy->party[enemy->current], battle, 'p', choices);
					}
				}
			}
		}
		if (enemy->party[enemy->current].flinched != 0)
		{
			printf("%s FLINCHED and was Unable to Attack!\n", enemy->party[enemy->current].pokeName);
			usleep(750000);
		}
		if (player->party[player->current].flinched != 0)
		{
			printf("%s FLINCHED and was Unable to Attack!\n", player->party[player->current].pokeName);
			usleep(750000);
		}
		//damaging status effects on Player pokemon (Poison, Burned)
		if (player->party[player->current].current[0] > 0)
		{
			if (player->party[player->current].condition[0] == 'x' || player->party[player->current].condition[0] == 'b')
			{
				player->party[player->current].current[0] -= ((double)(1) /  16) * player->party[player->current].base[0];
				if (player->party[player->current].condition[0] == 'x')
					printf("%s has been hurt by the POISON\n", player->party[player->current].pokeName);
				else if (player->party[player->current].condition[0] == 'b')
					printf("%s has been hurt by the BURN\n", player->party[player->current].pokeName);
				if (player->party[player->current].current[0] < 0)
					player->party[player->current].current[0] = 0;
			}
			//damaging status effects on Player pokemon (badly Poisoned)
			if (player->party[player->current].condition[0] == 'X')
			{
				player->party[player->current].current[0] -= ((double)(1) /  16) * player->party[player->current].badCounter * player->party[player->current].base[0];
				player->party[player->current].badCounter += 1;
				printf("%s has been hurt by the POISON\n", player->party[player->current].pokeName);
				if (player->party[player->current].current[0] < 0)
					player->party[player->current].current[0] = 0;
			}
		}
		//damaging status effects on Enemy AI pokemon (Poison, Burned)
		if (enemy->party[player->current].current[0] > 0)
		{
			if (enemy->party[enemy->current].condition[0] == 'x' || enemy->party[enemy->current].condition[0] == 'b')
			{
				enemy->party[enemy->current].current[0] -= ((double)(1) /  16) * enemy->party[enemy->current].base[0];
				if (enemy->party[enemy->current].condition[0] == 'x')
					printf("%s has been hurt by the POISON\n", enemy->party[enemy->current].pokeName);
				else if (enemy->party[enemy->current].condition[0] == 'b')
					printf("%s has been hurt by the BURN\n", enemy->party[enemy->current].pokeName);
				if (enemy->party[enemy->current].current[0] < 0)
					enemy->party[enemy->current].current[0] = 0;
			}
			//damaging status effects on enemy AI pokemon (badly Poisoned)
			if (enemy->party[enemy->current].condition[0] == 'X')
			{
				enemy->party[enemy->current].current[0] -= ((double)(1) /  16) * enemy->party[enemy->current].badCounter * enemy->party[enemy->current].base[0];
				enemy->party[enemy->current].badCounter += 1;
				printf("%s has been hurt by the POISON\n", enemy->party[enemy->current].pokeName);
				if (enemy->party[enemy->current].current[0] < 0)
					enemy->party[enemy->current].current[0] = 0;
			}
		}
		//second death check in case of pokemon death after moves have been used. (smae as above death systm)
		if (player->party[player->current].current[0] <= 0)
			checkP = ft_playerSwitch(player,enemy);
		if (checkP == -10)
		{
			printf("Player is out of usable POKEMON, ENEMY WINS!!\n");
			return (results);
		}
		if (enemy->party[enemy->current].current[0] <= 0)
			checkE = ft_enemySwitch(player,enemy);
		if (checkE == -10)
		{
			printf("Enemy is out of usable POKEMON, PLAYER WINS!!\n");
			int counter=0;
			for (int i=0;i < 6;i++)
			{
				if (player->party[i].current[0] > 0)
					counter++;
				else
					break ;
			}
			results=1;
			if (counter == 6)
				results = 1.5;
			return (results);
		}
	}
	return (results);
}
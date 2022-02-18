#include "Battle.h"

void	ft_initialize_battle(t_Battle *battle)
{
	//weatherCondition="None";
	battle->playerSpikes=0;
	battle->enemySpikes=0;
	battle->playerReflect=0;
	battle->enemyReflect=0;
	battle->playerLightScreen=0;
	battle->enemyLightScreen=0;
}

int	ft_enemySwitch(t_Trainer* player, t_Trainer* enemy)
{
	double weak = 1.0;

	for (int i = 0; i < player->party[player->current].typeNum; i++)
		weak *= ft_weakness(enemy->party[enemy->current].typeNum, enemy->party[enemy->current].type, player->party[player->current].type[i]);
	if (weak >= 2.0 && enemy->party[enemy->current].current[0] <= ((6.0/10.0) * enemy->party[enemy->current].base[0]))
	{
		for (int i = 0; i < 5; i++)
		{
			weak = 1.0;
			if (i == enemy->current)
				i++;
			for (int j = 0; i < player->party[player->current].typeNum; i++)
				weak *= ft_weakness(enemy->party[i].typeNum, enemy->party[i].type, player->party[player->current].type[j]);
			if (weak <= 1.0 && enemy->party[i].current[0] >= ((7.0 / 10.0) * enemy->party[i].base[0]))  //swap in here
			{
				for (int j = 0; j < 6; j++)				   //removing confused and resetting counters when player switches pokemon
					enemy->party[enemy->current].statMultiplier[j] = 0;
				enemy->party[enemy->current].condition[1] = 'n';
				enemy->party[enemy->current].conditionCool[1] = 0;
				enemy->party[enemy->current].badCounter = 0;
				enemy->party[enemy->current].protect = 0;
				enemy->party[enemy->current].outrage = 0;
				enemy->party[enemy->current].flinched = 0;
				printf("Enemy's %s has SWITCHED OUT for ", enemy->party[enemy->current].pokeName);
				enemy->current = i;
				printf("%s\n", enemy->party[enemy->current].pokeName);
				return (-1);
			}
		}
	}
	if (enemy->party[enemy->current].current[0] <= 0)
	{
		int counter = 0;

		for (int i = 0; i < 6; i++)
		{
			if (enemy->party[i].current[0] <= 0)
				counter++;
			else if (enemy->party[i].current[0] > 0)
			{
				for (int j = 0; j < 6; j++)				   //removing confused and resetting counters when player switches pokemon
					enemy->party[enemy->current].statMultiplier[j] = 0;
				enemy->party[enemy->current].condition[1] = 'n';
				enemy->party[enemy->current].conditionCool[1] = 0;
				enemy->party[enemy->current].badCounter = 0;
				enemy->party[enemy->current].protect = 0;
				enemy->party[enemy->current].outrage = 0;
				enemy->party[enemy->current].flinched = 0;
				printf("Enemy's %s has SWITCHED OUT for ", enemy->party[enemy->current].pokeName);
				enemy->current = i;
				printf("%s\n", enemy->party[enemy->current].pokeName);
				return (-1);
			}
		}
		if (counter == 6)
			return (-10);
	}
	return (1);
}

int ft_playerBattle(t_Trainer* player)
{
	int choice; //displaying player current pokemons moves

	printf("---------------MOVESET---------------\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d = %s, TYPE = ", i, player->party[player->current].moveset[i].moveName);
		ft_print_ele(player->party[player->current].moveset[i].moveEle);
		printf(", PP = %d\n\n", player->party[player->current].moveset[i].movePP);
	}
	printf("-------------------------------------\n");
	printf("What MOVE should %s use? ", player->party[player->current].pokeName);
	scanf("%1d", &choice);
	while (choice < -1 || choice > 3)   //preventing user from entering invalid inputs
	{
		printf("Please Try again (-1 is back): ");
		scanf("%1d", &choice);
	}
	printf("\n");
	if (choice == -1)
		return (-1);
	while (player->party[player->current].moveset[choice].movePP <= 0) //preventing user from picking a move with no PP remaining
	{
		printf("Not enough POWER POINTS to use this move, Pick another move: ");
		scanf("%1d", &choice);
		while ((choice < -1 || choice > 3))
		{
			printf("Please Try again (-1 is back): ");
			scanf("%1d", &choice);
		}
		if (choice == -1)
			return (-1);
	}
	return (choice);
}

int ft_playerItem(t_Trainer* player)
{
	printf("\n\nNOPE, There Are NO ITEMS, Have FUN Its HARDCORE NUZLOCKE TIME!!!!!!\n\n");
	return (0);
}
	/* PROPER ITEM MENU DISPLAY, UNCOMMENT AND IT SHOULD WORK (SOME OF THE ITEMS MIGHT NOT THOUGH, MOST SHOULD HOPEFULLY)*/
//	int choice;
//	int choicePoke=-1;
//	double check=1;
//	int pp;
//	int pokeStat=1;
//	//player item usage
//	while (choicePoke == -1)
//	{
//		cout << "-----------------Items-------------------------" << endl;
//		for (int i=0;i<6;i++)
//		{
//			cout << i << " = " << player->getItem(i) << ":" << endl << "Description: " << player->getItemDescript(i) << endl;
//		}
//		cout << "-----------------------------------------------" << endl;
//
//		//print out items, basic effect & how many are left.
//		cout << "Which ITEM would you like to use?: ";
//		scanf("%1d", &choice);
//
//		while ((choice != 2 && choice != 1 && choice != -1 && choice != 3 && choice != 4 && choice != 5 && choice != 0) || (cin.fail() == true))
//		{
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//			printf("Please Try Again: ");
//			scanf("%1d", &choice);
//			if ((!cin.fail()) && (choice >= -1 && choice <= 5))
//			{
//				break ;
//			}
//		}
//		//preventing user from using items which do no have any stored
//		while ((player->getItemUse(choice) <= 0) && (choice != -1))
//		{
//			cout << "ITEM out of stock, Please try again: ";
//			scanf("%1d", &choice);
//			while ((choice != 2 && choice != 1 && choice != -1 && choice != 3 && choice != 4 && choice != 5 && choice != 0) || (cin.fail() == true))
//			{
//				cin.clear();
//				cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//				printf("Please Try Again: ");
//				scanf("%1d", &choice);
//				if ((!cin.fail()) && (choice >= -1 && choice <= 5))
//				{
//					break ;
//				}
//			}
//		}
//
//		if (choice == -1)
//		{
//			return (0);
//		}
//		else
//		{   //viewing pokemon player stats
//			while (choice > -1 && choicePoke == -1)
//			{
//				while (pokeStat != 0)
//				{
//					for (int i=0;i<6;i++)
//					{
//						printf("%d = %s, HP: %d / %d\n", i, player->party[i].pokeName, player->party[i].current[0], player->party[i].base[0]);
//					}
//
//					cout << "Which POKEMON STATS would you like to fully view? ";
//					cin >> pokeStat;
//
//					while ((pokeStat != 1 && pokeStat != 2 && pokeStat != 3 && pokeStat != 4 && pokeStat != 0 && pokeStat != 5 && pokeStat != -1) || (cin.fail() == true))
//					{
//						cin.clear();
//						cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//						printf("Please Try Again: ");
//						cin >> pokeStat;
//						if ((!cin.fail()) && (pokeStat >= -1 && pokeStat <= 5))
//						{
//							break ;
//						}
//					}
//					if (pokeStat == -1)
//					{
//						break ; // check if this works
//					}
//
//					if (player->party[pokeStat].typeNum == 2)
//					{
//						cout << "Types: " << player->party[pokeStat].type[0] << " & " << player->party[pokeStat].type[1] << endl;
//					}
//					else
//					cout << "Type: " << player->party[pokeStat].type[0] << endl;
//
//					cout << endl << player->party[pokeStat].pokeName << "'s Moveset: " << endl;
//
//					for (int i=0;i<4;i++)
//					{
//						cout << player->party[pokeStat].moveset[i].moveEle << " Type Move: " << player->party[pokeStat].moveset[i].moveName << endl;
//						cout << "Power = " << player->party[pokeStat].moveset[i].movePow << " , Accuracy = " << player->party[pokeStat].moveset[i].moveAcc;
//						cout << " , Impact Type: " << player->party[pokeStat].moveset[i].moveType << " , PP: " << player->party[pokeStat].moveset[i].movePP << " / " << player->party[pokeStat].moveset[i].or_movePP << endl;
//						cout << "Move Description: " << player->party[pokeStat].moveset[i].moveDescript << endl << endl;
//					}
//
//					cout << "HP: " << player->party[pokeStat].base[0] << endl;
//					cout << "ATK: " << player->party[pokeStat].base[1] << endl;
//					cout << "DEF: " << player->party[pokeStat].base[2] << endl;
//					cout << "SP.ATK: " << player->party[pokeStat].base[3] << endl;
//					cout << "SP.DEF: " << player->party[pokeStat].base[4] << endl;
//					cout << "SPD: " << player->party[pokeStat].base[5] << endl;
//
//					cout << "Ability: " << player->party[pokeStat].ability << endl;
//					cout << "Description: " << player->party[pokeStat].abilityDescript << endl << endl;
//
//					//cout << "Held Item: " << player->party[pokeStat].item << endl;
//					//need to add item descriptions/effects etc
//
//					//add item description once its added (if, probs though)
//
//					cout << "Would you like to view another Pokemon's Stats?: (0 = No, 1 = Yes) ";
//					cin >> pokeStat;
//					while ((pokeStat != 0 && pokeStat != 1) || (cin.fail() == true))
//					{
//						cin.clear();
//						cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//						printf("Please Try Again: ");
//						scanf("%1d", &choice);
//						if ((!cin.fail()) && (pokeStat >= 0 && pokeStat <= 1))
//						{
//							break ;
//						}
//					}
//					//ask which pokemon stat they want to view, view it etc etc
//					// then return to top, maybe make whole thing in while loop using choice for switch or back as breaks/returns?
//				}
//					//using an item on allied pokemon
//				cout << "Which pokemon would you like to use this item on?: ";
//				cin >> choicePoke;
//				while ((choicePoke<-1 || choicePoke > 5) || (cin.fail() == true))
//				{
//					cin.clear();
//					cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//					printf("Please Try Again: ");								   //preventing invalid inputs
//					cin >> choicePoke;
//					if ((!cin.fail()) && (choicePoke >= -1 && choicePoke <= 5))
//					{
//						break ;
//					}
//				}
//
//				for (int i=0;i<5;i++)
//				{
//					if (player->party[choicePoke).getStatMultiplier(i) == 6.0)
//					{
//						check -= 0.2;
//					}
//				}
//
//				while (choice == 5)   //using exlirs on allied pokemon
//				{
//					cout << "What move would you like to restore the PP of?: ";
//					cin >> pp;
//					while ((pp != 1 && pp != 2 && pp != 3 && pp != 4 && pp != -1) || (cin.fail() == true))
//					{
//						cin.clear();
//						cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//						printf("Please Try Again: ");
//						cin >> pp;
//						if ((!cin.fail()) && ((pp >= 1 && pp <= 4) || pp == -1))
//						{
//							break ;
//						}
//					}
//					if (pp != -1)
//					{
//						while (player->party[choicePoke).getMoves(pp).movePP == player->party[choicePoke).getMoves(pp).or_movePP)
//						{
//							cout << player->party[choicePoke).getMoves(pp).moveName << "'s PP is at maximum, Please choose another move or change Pokemon: ";
//							cin >> pp;
//							while ((pp != 1 && pp != 2 && pp != 3 && pp != 4 && pp != -1) || (cin.fail() == true))
//							{
//								cin.clear();
//								cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//								printf("Please Try Again: ");
//								cin >> pp;
//								if ((!cin.fail()) && ((pp >= 1 && pp <= 4) || pp == -1))
//								{
//									break ;
//								}
//							}
//							if (pp == -1)
//							{
//								break ;
//							}
//						}
//					}
//
//					if (pp == -1)
//					{
//						break ;
//					}
//				}
//
//				while (((choice == 1 || choice == 2) && ((player->party[choicePoke).current[0] == player->party[choicePoke).base[0]) || player->party[choicePoke).current[0] <= 0)) || (choice == 3 && (player->party[choicePoke).condition[0] == "None" && player->party[choicePoke).condition[1] == "Not Confused")) || (choice == 4 && player->party[choicePoke).current[0] > 0) || (choice == 6 && (player->party[choicePoke).current[0] <= 0)) || (choicePoke != player->current] || (check == 0))
//				{
//					cout << "Will have no effect, Please choose a different Pokemon: "; //preventing invalid inputs
//					cin >> choicePoke;
//					while ((choicePoke != 2 && choicePoke != 1 && choicePoke != -1 && choicePoke != 3 && choicePoke != 4 && choicePoke != 5 && choicePoke != 0) || (cin.fail() == true))
//					{
//						cin.clear();
//						cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//						printf("Please Try Again: ");
//						scanf("%1d", &choice);
//						if ((!cin.fail()) && (choicePoke >= -1 && choicePoke <= 5))
//						{
//							break ;
//						}
//					}
//				}
//
//				while ((choicePoke != 2 && choicePoke != 1 && choicePoke != -1 && choicePoke != 3 && choicePoke != 4 && choicePoke != 5 && choicePoke != 0) || (cin.fail() == true))
//				{
//					cin.clear();
//					cin.ignore(numeric_limits<streamsize > ::max(),'\n');
//					printf("Please Try Again: ");
//					cin >> choicePoke;
//					if ((!cin.fail()) && (choicePoke >= -1 && choicePoke <= 5))
//					{
//						break ;
//					}
//				}
//				/* while (((choice == 1 || choice == 2 || choice == 5) && ((player->party[choicePoke).current[0] == player->party[choicePoke).base[0]) || player->party[choicePoke).current[0] <= 0))
//				{
//					cout << "Will have no effect, Please choose a different Pokemon: ";
//					cin >> choicePoke;
//				}
//
//				while (choice == 3 && (player->party[choicePoke).condition == "None"))
//				{
//					cout << "Will have no effect, Please choose a different Pokemon: ";
//					cin >> choicePoke;
//				}
//
//				while (choice == 4 && (player->party[choicePoke).current[0] > 0))
//				{
//					cout << "Will have no effect, Please choose a different Pokemon: ";
//					cin >> choicePoke;
//				}
//
//				while (choice == 6 && ((player->party[choicePoke).current[0] <= 0) || (choicePoke != player->current) || (check == 0)))
//				{
//					cout << "Will have no effect, Please choose a different Pokemon: ";
//					cin >> choicePoke;
//				} */
//				//compare if item will have any effect (hp allowed, stats already maxed etc), will need multiply layered if statement.
//
//				if (choicePoke != -1 && choice != 5)
//				{
//					if (choice == 1)
//					{							   //restoring health and status when full restore is used
//						//print full restore has been used.
//						cout << "FULL RESTORE has been used on " << player->party[choicePoke).pokeName << ", HP and STATUS conditions fully restored." << endl;
//						player->party[choicePoke).setCurrent(0,player->party[choicePoke).base[0],"=");
//						player->party[choicePoke).setCondition(0,"None");
//						player->party[choicePoke).setCondition(1,"Not Confused");
//						player->party[choicePoke).setConditionCool(0,0,"=");
//						player->party[choicePoke).setConditionCool(1,0,"=");
//						player->setItemUse(0,1,"-");
//						return (1);
//					}
//					else if (choice == 2)
//					{		   //restoring heath when hyper potion is used
//						//print hyper potion has been used
//						cout << "HYPER POTION has been used on " << player->party[choicePoke).pokeName << ", HP has been restored by 200 points." << endl;
//						player->party[choicePoke).setCurrent(0,200,"+");
//						if (player->party[choicePoke).current[0] > player->party[choicePoke).base[0])
//						{
//							player->party[choicePoke).setCurrent(0,player->party[choicePoke).base[0],"=");
//						}
//						player->setItemUse(1,1,"-");
//						return (1);
//					}
//					else if (choice == 3)
//					{					   //removing status effects when full heal is used
//						//print full heal has been used
//						cout << "FULL HEAL has been used on " << player->party[choicePoke).pokeName << ", STATUS conditions has been healed." << endl;
//						player->party[choicePoke).setCondition(0,"None");
//						player->party[choicePoke).setCondition(1,"Not Confused");
//						player->party[choicePoke).setConditionCool(0,0,"=");
//						player->party[choicePoke).setConditionCool(1,0,"=");
//						player->setItemUse(2,1,"-");
//						return (1);
//					}
//					else if (choice == 4)
//					{						//reviving a pokemon when revive is used
//						//print revive has been used
//						cout << "REVIVE has been used on " << player->party[choicePoke).pokeName << ", they can continue fighting!!" << endl;
//						player->party[choicePoke).setCurrent(0,(player->party[choicePoke).base[0]/2),"+");
//						player->setItemUse(3,1,"-");
//						return (1);
//					}
//					else if (choice == 6)
//					{
//						//print X-Up has been used
//						cout << "X-UP has been used on " << player->party[choicePoke).pokeName << ", all STATS have been getBuffed by 1 STAGE." << endl;
//						for (int i=0;i<5;i++)
//						{
//							if (player->party[choicePoke).getStatMultiplier(i)<6.0)
//							{
//								player->party[choicePoke).setStatMultiplier(i,1,"+");
//							}
//						}
//						player->setItemUse(5,1,"-");
//						return (1);
//					}
//				}
//				else if (choicePoke != -1 && choice == 5)
//				{
//					//print PP++ has been used
//					cout << "PP++ has been used on " << player->party[choicePoke).pokeName << ", PP of " << player->party[choicePoke).getMoves(pp).moveName << " has been fully restored." << endl;
//					player->party[choicePoke).getMoves(pp).setMovePP(player->party[choicePoke).getMoves(pp).or_movePP,"=");
//					player->setItemUse(4,1,"-");
//					return (1);
//				}
//			}
//		}
//	}
//
//	return -69;

// need to fix so infinite switching from viewing stats to switching etc.

int	ft_playerSwitch(t_Trainer* player, t_Trainer* enemy)
{
	int choice;
	int pokeStat = 1;
	int checker = 0;

	for (int i = 0; i < 6; i++)
	{
		if (player->party[i].current[0] <= 0)
			checker++;
		if (checker == 6)
			return (-10);
	}
	printf("\n\n");
	for (int i = 0; i < 6; i++)
		printf("%d = %s, HP: %d / %d\n", i, player->party[i].pokeName, player->party[i].current[0], player->party[i].base[0]);
	printf("\n");
	//print out pokemon to swap to and brief stats (hp condition);
	printf("Would you like to view a Pokemon's Stats? (0 = No, 1 = Yes):  ");
	scanf("%1d", &choice);
	while (choice != 0 && choice != 1)
	{
		printf("Please Try Again: ");
		scanf("%1d", &choice);
	}
	if (choice == 1)
	{
		while (pokeStat != 0)
		{
			printf("Which Pokemon stats would you like to view? (Enter corresponding number): ");
			scanf("%1d", &pokeStat);
			while (pokeStat < 0 || pokeStat > 5)
			{
				printf("Please Try Again: ");
				scanf("%1d", &pokeStat);
			}
			printf("\n\n");
			if (player->party[pokeStat].typeNum == 2)
			{
				printf("Types: ");
				ft_print_ele(player->party[pokeStat].type[0]);
				printf(" & ");
				ft_print_ele(player->party[pokeStat].type[1]);
			}
			else
			{
				printf("Type: ");
				ft_print_ele(player->party[pokeStat].type[0]);
			}
			printf("\n\n%s's Moveset: \n\n", player->party[pokeStat].pokeName);
			for (int i = 0; i < 4; i++)
			{
				ft_print_ele(player->party[pokeStat].moveset[i].moveEle);
				printf(" Type Move: %s\nPower = %d, Accuracy = %d%%, Move Type: ", player->party[pokeStat].moveset[i].moveName, player->party[pokeStat].moveset[i].movePow, player->party[pokeStat].moveset[i].moveAcc);
				ft_print_type(player->party[pokeStat].moveset[i].moveType);
				printf(", PP: %d / %d\nMove Description: %s\n\n", player->party[pokeStat].moveset[i].movePP, player->party[pokeStat].moveset[i].or_movePP, player->party[pokeStat].moveset[i].moveDescript);
			}
			printf("HP:     %d\n", player->party[pokeStat].base[0]);
			printf("ATK:    %d\n", player->party[pokeStat].base[1]);
			printf("DEF:    %d\n", player->party[pokeStat].base[2]);
			printf("SP.ATK: %d\n", player->party[pokeStat].base[3]);
			printf("SP.DEF: %d\n", player->party[pokeStat].base[4]);
			printf("SPD:    %d\n", player->party[pokeStat].base[5]);
			printf("Ability: %s\n", player->party[pokeStat].ability);
			printf("Description: %s\n\n", player->party[pokeStat].abilityDescript);
			//add item description once its added (if, probs though)
			printf("Would you like to view another Pokemon's Stats?(0 = No, 1 = Yes): ");
			scanf("%1d", &pokeStat);
			while (pokeStat != 0 && pokeStat != 1)
			{
				printf("Please Try Again: ");
				scanf("%1d", &pokeStat);
			}
			if (pokeStat == 0)
				break ;
			//ask which pokemon stat they want to view, view it etc etc
			// then return to top, maybe make whole thing in while loop using choice for switch or back as breaks/returns?
		}
	}
	printf("\n\n");
			//player pokemon switching
	printf("Which Pokemon would you like to switch in?: ");
	scanf("%1d", &choice);
	while (choice < -1 || choice > 5)
	{
		printf("Please Try Again: ");
		scanf("%1d", &choice);
	}
	if (choice == -1)
		return (-1);
	while (choice == player->current || player->party[choice].current[0] <= 0)
	{		   ///preventing invalid inputs
		printf("Pokemon is already in or is unable to continue, Please try again: ");
		scanf("%1d", &choice);
		while (choice < -1 || choice > 5)
		{
			printf("Please Try Again: ");
			scanf("%1d", &choice);
		}
		if (choice != player->current && player->party[choice].current[0] > 0)
			break ;
		if (choice == -1)
			return (-1);
	}
	for (int j = 0; j < 6; j++)						   //removing confused and resetting counters when player switches pokemon
		player->party[player->current].statMultiplier[j] = 0;
	player->party[player->current].condition[1] = 'n';
	player->party[player->current].conditionCool[1] = 0;
	player->party[player->current].badCounter = 0;
	player->party[player->current].protect = 0;
	player->party[player->current].outrage = 0;
	player->party[player->current].flinched = 0;
	printf("Player's %s has SWITCHED OUT for ", player->party[player->current].pokeName);
	player->current = choice;
	printf("%s\n", player->party[player->current].pokeName);
	if (ft_strcmp(player->party[player->current].ability, "Intimidate") == 'y' && ft_strcmp(enemy->party[enemy->current].ability, "Clear Body") == 'n')
	{
		printf("%s Intimidate Ability has lowered %s  ATK!\n", player->party[player->current].pokeName, enemy->party[enemy->current].pokeName);
		usleep(750000);
		enemy->party[enemy->current].statMultiplier[0] -= 1;
	}
	else if (ft_strcmp(player->party[player->current].ability, "Intimidate") == 'y' && ft_strcmp(enemy->party[enemy->current].ability, "Clear Body") == 'y')
	{
		printf("%s Intimidate Ability has No Effect on %s!\n", player->party[player->current].pokeName, enemy->party[enemy->current].pokeName);
		usleep(750000);
	}
	return (1);
}

int	ft_turnAttack(t_Pokemon* atk, t_Pokemon* def, int attack, char user)
{
	//destiny bond and overall check so can't do moves whilst dead
	if (atk->current[0] <= 0 && def->current[0] <= 0)
	{
		atk->current[0] = 0;
		def->current[0] = 0;
		return (1);
	}
	else if (atk->current[0] <= 0)
	{
		atk->current[0] = 0;
		return (1);
	}
	else if (def->current[0] <= 0)
	{
		def->current[0] = 0;
		return (1);
	}
	int damage = 0;
	double stab = 1.0;
	double burn = 1.0;
	double weather = 1.0;
	double effective = 1.0;
	double random;
	double chance;
	double crit;
	int numHitsCheck = 1;
	double speedEnemy;
	double speedPlayer;
	int serene = 1;
	int pressure = 1;
	if (ft_strcmp(def->ability, "Pressure") == 'y')
		pressure=2;
	if (ft_strcmp(atk->ability, "Serene Grace") == 'y')
		serene=2;
	if (ft_strcmp(atk->moveset[attack].moveName, "Outrage") == 'y')
		atk->outrage = atk->outrage + 1;
	if (atk->protect > 0 && ft_strcmp(atk->moveset[attack].moveName, "Protect") == 'n')
		atk->protect = 0;
	//special if statements for certain moves which have extra effects
	if (ft_strcmp(atk->moveset[attack].moveName, "Fishious Rend") == 'y')
	{
		if (user == 'p')
		{
			speedPlayer = atk->current[5] * ft_stageMulti(atk->statMultiplier[4],4);
			speedEnemy= def->current[5] * ft_stageMulti(def->statMultiplier[4],4);
			if (atk->condition[0] == 'p')
				speedPlayer *= (1 / 2);
			if (def->condition[0] == 'p')
				speedEnemy *= (1 / 2);
		}
		else if (user == 'e')
		{
			speedPlayer = def->current[5] * ft_stageMulti(def->statMultiplier[4],4);
			speedEnemy= atk->current[5] * ft_stageMulti(atk->statMultiplier[4],4);
			if (def->condition[0] == 'p')
				speedPlayer *= (1 / 2);
			if (atk->condition[0] == 'p')
				speedEnemy *= (1 / 2);
		}
	}
				//DIG / phantom force invicibility
	if (atk->moveset[attack].cooldown > 0 && atk->cooldown == 0)
	{
		atk->cooldown += atk->moveset[attack].cooldown + 1;
		atk->impermeable = 1;
		if (ft_strcmp(atk->moveset[attack].moveName, "Dig") == 'y')
			printf("%s has DUG UNDERGROUND!\n", atk->pokeName);
		if (ft_strcmp(atk->moveset[attack].moveName, "Phantom Force") == 'y')
			printf("%s has FADED into the SHADOWS!\n", atk->pokeName);
		return (0);
	}
	if (atk->cooldown < 0)
	{
		atk->cooldown = 0;
		return (0);
	}
	else if (atk->cooldown > 0)
		atk->cooldown = 0;
	if (user == 'p')
		printf("Player");
	else
		printf("Enemy");
	printf("'s %s uses %s\n", atk->pokeName, atk->moveset[attack].moveName);
	usleep(1500000);
	if (atk->condition[0] == 'b')			 //halves player physical attack if poemon is burned
		burn=0.5;
	if (atk->moveset[attack].numHits[0] > 1)			 //multi hit moves
	{
		numHitsCheck = atk->moveset[attack].numHits[1] - atk->moveset[attack].numHits[0];
		chance = rand() % numHitsCheck + atk->moveset[attack].numHits[0];
		numHitsCheck = chance;
	}
	if (def->roost == 1)
	{
		char fake[2] = {'.', '.'};

		if (def->type[0] == 'L' && def->typeNum == 1)
			fake[0] = 'N';
		else if (def->type[0] == 'L' && def->typeNum == 2)
			fake[0] = def->type[1];
		else if (def->type[1] == 'L' && def->typeNum == 2)
			fake[0] = def->type[0];
		effective = ft_weakness(1, fake, atk->moveset[attack].moveEle);
	}
	else
		effective = ft_weakness(def->typeNum, def->type, atk->moveset[attack].moveEle);
	for (int i = 0; i < atk->typeNum; i++)
	{
		if (atk->type[i] == atk->moveset[attack].moveEle)
		{
			stab = 1.5;							//increase damage if STAB is in effect
			break ;
		}
	}
	if (def->protect >= 1)
	{
		atk->moveset[attack].movePP -= pressure;
		printf("%s Was BLOCKED!\n", atk->moveset[attack].moveName);
		return (0);
	}
	if (def->impermeable > 0)
	{
		def->impermeable -= 1;
		printf("%s MISSED!\n", atk->moveset[attack].moveName);			 //if enemy pokemon cannot be hit force a MISS
		return (0);
	}
	if (atk->moveset[attack].moveAcc * atk->statMultiplier[5] < 100 && atk->moveset[attack].moveAcc * atk->statMultiplier[5] != 0)
	{
		chance = rand() % 100;
		if (chance > atk->moveset[attack].moveAcc * atk->statMultiplier[5])
		{
			atk->moveset[attack].movePP -= pressure;
			printf("%s MISSED!\n", atk->moveset[attack].moveName);
			return (0);
		}
	}
	atk->moveset[attack].movePP -= pressure;
	if ((ft_strcmp(def->ability, "Wonder Guard") == 'y' && effective < 2.0) || (ft_strcmp(def->ability, "Levitate") == 'y' && atk->moveset[attack].moveEle == 'G'))
	{
		printf("%s USED %s\n", atk->pokeName, atk->moveset[attack].moveName);
		printf("%s dealt 0.0 DAMAGE Thanks to %s!\n", atk->moveset[attack].moveName, def->ability);
		return (0);
	}
	for (int i = 0; i < numHitsCheck; i++)
	{
		random = rand() % 16 + 85;
		random /= 100;
		if (atk->moveset[attack].moveType == 'P')
		{
			damage += ((((((2 * 50) / 5) + 2) * atk->moveset[attack].movePow * ((atk->current[1] * (ft_stageMulti(atk->statMultiplier[0], 0))) / (def->current[2] * (ft_stageMulti(def->statMultiplier[1], 1))))) / 50) + 2) * weather * stab * random * burn * effective * 1.5;
			if ((((user == 'p') && (speedPlayer > speedEnemy)) || ((user == 'e') && (speedPlayer < speedEnemy))) && ft_strcmp(atk->moveset[attack].moveName, "Fishious Rend") == 'y')
				damage *= 2;
		}
		else if (atk->moveset[attack].moveType == 'S')
		{
			damage += ((((((2 * 50) / 5) + 2) * atk->moveset[attack].movePow * ((atk->current[3] * (ft_stageMulti(atk->statMultiplier[2], 2))) / (def->current[4] * (ft_stageMulti(def->statMultiplier[3], 3))))) / 50) + 2) * weather * stab * random * effective * 1.5;
			if (ft_strcmp(atk->moveset[attack].moveName, "Brine") == 'y' && def->current[0] <= 0.5 * def->base[0])
				damage *= 2;
			else if ((ft_strcmp(atk->ability, "Blaze") == 'y') && (atk->current[0] <= ((1 / 3) * atk->base[0])) && (atk->moveset[attack].moveEle == 'Q'))
				damage *= 1.5;
		}
	}
	// printf("DAMAGE CALC == %d\n", damage);
	crit = ft_stageMulti(atk->moveset[attack].crit_ratio, -1);
	chance = rand() % 100;
	if ((chance <= crit) && (ft_strcmp(def->ability, "Shell Armour") == 'n' && ft_strcmp(def->ability, "Battle Armour") == 'n'))
	{
		damage *= 2.0;
		printf("CRITICAL HIT!!\n");
	}
	if (effective  >=  2.0)
		printf("SUPER EFFECTIVE!!\n");
	else if (effective < 1)
		printf("NOT VERY EFFECTIVE!!\n");
	else if (effective == 0)
		printf("IT HAD NO EFFECT!!\n");
	//water absorb stuff!!!
	if (atk->moveset[attack].moveEle == 'W' && ft_strcmp(def->ability, "Water Absorb") == 'y')
	{
		printf("%s Absorbed %s Attack and Gain HP!\n", def->pokeName, atk->pokeName);		
		usleep(1500000);
		def->current[0] += damage * 0.25;
		if (def->current[0] > def->base[0])
			def->current[0] = def->base[0];
		damage = 0;
	}
	else
		printf("%s dealt ", atk->moveset[attack].moveName);
	if (ft_strcmp(def->ability, "Thick Fat") == 'y' && (atk->moveset[attack].moveEle == 'Q' || atk->moveset[attack].moveEle == 'I'))
		damage *= 0.5;
	if ((((def->current[0] - damage) <= 0) && def->current[0] == def->base[0]) && ft_strcmp(def->ability, "Sturdy") == 'y')
		damage = def->current[0] - 1;
	def->current[0] -= damage;
	printf("%d DAMAGE!\n", damage);
	usleep(1500000);
	if (def->current[0] <= 0)
	{
		def->current[0] = 0;
		printf("%s has FAINTED!\n", def->pokeName);
		if (def->destiny != 0)
		{
			printf("%s HAS TAKEN %s DOWN WITH IT!!!\n", def->pokeName, atk->pokeName);
			usleep(1500000);
			atk->current[0] = 0;
			return (1);
		} 
	}
	if (atk->moveset[attack].recoil[0] == 1 && ft_strcmp(atk->ability, "Rock Head") == 'n')
	{
		int recoil = damage * ((double)atk->moveset[attack].recoil[1] / 100);
		atk->current[0] -= recoil;
		printf("%s lost %d DAMAGE to RECOIL\n", atk->pokeName, recoil);
		usleep(750000);
		if (atk->current[0] < 0)
			atk->current[0] = 0;
	}
	if (atk->moveset[attack].flinch > 0)
	{
		chance = rand() % 100;
		if (chance <= atk->moveset[attack].flinch)
			def->flinched = 1;
	}
	if (atk->moveset[attack].contact == 1 && ft_strcmp(def->ability, "Static") == 'y')
	{
		atk->condition[0] = 'p';
		printf("%s has been PARALYZED\n", atk->pokeName);
		atk->conditionCool[0] = -1;
	}
	//check if works, not sure about ancient power stat up if statement
	chance = rand() % 100;
	if (atk->moveset[attack].buff[0] > 0)
	{
		if (atk->moveset[attack].buff[0] == 69 && (chance <= (atk->moveset[attack].buff[2] * serene)))
		{
			printf("All of %s's stats have been increased by 1 Stage, including ATK, DEF, SP.ATK, SP.DEF, SPD & ACC\n", atk->pokeName);
			usleep(750000);
			for (int i = 0; i < 6; i++)
				atk->statMultiplier[i] += 1;
		}
		else if (chance <= (atk->moveset[attack].buff[2] * serene))
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff[0] == 6)
				printf("ACC");
			printf(" stat has been increased by %d Stages\n", atk->moveset[attack].buff[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff[0] - 1] += atk->moveset[attack].buff[1];
		}
	}
	if (atk->moveset[attack].buff2[0] > 0)
	{
		if (chance <= (atk->moveset[attack].buff2[2] * serene))
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff2[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff2[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff2[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff2[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff2[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff2[0] == 6)
				printf("ACC");
			printf(" stat has been increased by %d Stages\n", atk->moveset[attack].buff2[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff2[0] - 1] += atk->moveset[attack].buff2[1];
		}
	}
	if (atk->moveset[attack].buff3[0] > 0)
	{
		if (chance <= (atk->moveset[attack].buff3[2] * serene))
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff3[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff3[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff3[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff3[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff3[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff3[0] == 6)
				printf("ACC");
			printf(" stat has been increased by %d Stages\n", atk->moveset[attack].buff3[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff3[0] - 1] += atk->moveset[attack].buff3[1];
		}
	}
	if (atk->moveset[attack].buff[0] < 0)
	{
		if (chance <= atk->moveset[attack].buff[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff[0] == 6)
				printf("ACC");
			printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].buff[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff[0] - 1] -= atk->moveset[attack].buff[1];
		}
	}
	if (atk->moveset[attack].buff2[0] < 0)
	{
		if (chance <= atk->moveset[attack].buff2[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff2[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff2[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff2[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff2[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff2[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff2[0] == 6)
				printf("ACC");
			printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].buff2[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff2[0] - 1] -= atk->moveset[attack].buff2[1];
		}
	}
	if (atk->moveset[attack].buff3[0] < 0)
	{
		if (chance <= atk->moveset[attack].buff3[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff3[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff3[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff3[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff3[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff3[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff3[0] == 6)
				printf("ACC");
			printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].buff3[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff3[0] - 1] -= atk->moveset[attack].buff3[1];
		}
	}
	if (atk->moveset[attack].status[0] > 0)
	{
		chance = rand() % 100;
		if (chance <= (atk->moveset[attack].status[1] * serene))
		{
			switch (atk->moveset[attack].status[0])
			{
				case 1:
				{
					if (def->type[0] != 'E' && def->type[1] != 'E')
					{
						def->condition[0] = 'p';
						printf("%s has been PARALYZED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 2:
				{
					def->condition[0] = 's';
					chance = rand() % 3;
					printf("%s has been put to SLEEP\n", def->pokeName);
					def->conditionCool[0] = chance + 1;
					break ;
				}
				case 3:
				{
					if (def->type[0] != 'Q' && def->type[1] != 'Q')
					{
						def->condition[0] = 'b';
						printf("%s has been BURNED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 4:
				{
					if ((def->type[0] != 'X' && def->type[1] != 'X') && (def->type[0] != 'S' && def->type[1] != 'S'))
					{
						def->condition[0] = 'X';
						printf("%s has been POISONED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 5:
				{
					if (def->type[0] != 'I' && def->type[1] != 'I')
					{
						def->condition[0]= 'f';
						printf("%s has been FROZEN\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 6:
				{
					if ((def->type[0] != 'X' && def->type[1] != 'X') && (def->type[0] != 'S' && def->type[1] != 'S'))
					{
						def->condition[0]= 'X';
						printf("%s has been BADLY POISONED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
			}
		}
	}
	if (atk->moveset[attack].confuse[0] > 0)
	{
		chance = rand() % 100;
		if (chance <= (atk->moveset[attack].confuse[1] * serene))
		{
			def->condition[1] = 'y';
			printf("%s has become CONFUSED\n", def->pokeName);
			def->conditionCool[1] = 1;
		}
	}
	if (ft_strcmp(atk->moveset[attack].moveName, "Giga Drain") == 'y')
	{
		atk->current[0] += 0.5 * damage;
		printf("%s drained %d from %s!\n", atk->pokeName, (int)(0.5 * damage), def->pokeName);
		usleep(750000);
		if (atk->current[0] > atk->base[0])
			atk->current[0] = atk->base[0];
	}
	if (atk->moveset[attack].deBuff[0] > 0 && ft_strcmp(def->ability, "Clear Body") == 'n')
	{
		chance = rand() % 100;
		if (chance <= (atk->moveset[attack].deBuff[2] * serene))
		{
			if (atk->moveset[attack].deBuff[0] == 6 && ft_strcmp(def->ability, "Keen Eye") == 'y')
			{
				printf("%s ACC Drop had NO EFFECT and %s is Keenly Watching %s!\n", atk->pokeName, def->pokeName, atk->pokeName);
				usleep(750000);
			}
			else
			{
				printf("%s's ", def->pokeName);
				if (atk->moveset[attack].deBuff[0] == 1)
					printf("ATK");
				else if (atk->moveset[attack].deBuff[0] == 2)
					printf("DEF");
				else if (atk->moveset[attack].deBuff[0] == 3)
					printf("SP.ATK");
				else if (atk->moveset[attack].deBuff[0] == 4)
					printf("SP.DEF");
				else if (atk->moveset[attack].deBuff[0] == 5)
					printf("SPD");
				else if (atk->moveset[attack].deBuff[0] == 6)
					printf("ACC");
				printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].deBuff[1]);
				usleep(750000);
				def->statMultiplier[atk->moveset[attack].deBuff[0] - 1] -= atk->moveset[attack].deBuff[1];
			}
		}
	}
	if (atk->moveset[attack].cooldown < 0 && atk->cooldown == 0)
	{
		atk->cooldown += atk->moveset[attack].cooldown - 1;
		return (1);
	}
	//implement weather changes if weather is completely implemented
	return (1);
}

int	ft_turnStatus(t_Pokemon* atk, t_Pokemon* def, t_Battle *battle, char user, int attack)
{
	//destiny bond and overall check so can't do moves whilst dead
	if (atk->current[0] <= 0 && def->current[0] <= 0)
	{
		atk->current[0] = 0;
		def->current[0] = 0;
		return (1);
	}
	else if (atk->current[0] <= 0)
	{
		atk->current[0] = 0;
		return (1);
	}
	else if (def->current[0] <= 0)
	{
		def->current[0] = 0;
		return (1);
	}
	double chance=0;
	int pressure=1;
	if (ft_strcmp(def->ability, "Pressure") == 'y')
		pressure=2;
	if (user == 'p')
		printf("Player");
	else
		printf("Enemy");
	printf("'s %s uses %s\n", atk->pokeName, atk->moveset[attack].moveName);
	usleep(1500000);
	if (ft_strcmp(atk->moveset[attack].moveName, "Destiny Bond") == 'y')
	{
		printf("%s is preparing to Take its Enemy Down With It!!\n", atk->pokeName);
		atk->destiny = 1;
		atk->moveset[attack].movePP -= pressure;
		usleep(1500000);
		return (1);
	}
	if (atk->condition[0] == 's' && ft_strcmp(atk->moveset[attack].moveName, "Sleep Talk") == 'y')
	{
		int talk = rand() % 3;
		if (talk == attack && attack < 3)
			talk++;
		else if (talk == attack && attack == 3)
			talk--;
		atk->moveset[attack].movePP -= pressure;
		if (ft_strcmp(atk->moveset[talk].moveName, "Rest") == 'y')
		{
			atk->moveset[attack].movePP -= pressure;
			printf("Sleep Talk FAILED!\n\n");
			return (0);
		}
		atk->moveset[talk].movePP += pressure;
		if (atk->moveset[talk].moveType == 'T')
		{
			ft_turnStatus(atk, def, battle, user, talk);
			return (0);
		}
		else if (atk->moveset[talk].moveType == 'S' || atk->moveset[talk].moveType == 'P')
		{
			ft_turnAttack(atk, def, talk, user);
			return (0);
		}
	}
	else if (atk->condition[0] != 's' && ft_strcmp(atk->moveset[attack].moveName, "Sleep Talk") == 'y')
	{
		printf("Sleep Talk FAILED!\n\n");
		atk->moveset[attack].movePP -= pressure;
		return (0);
	}
	if (atk->current[0] == atk->base[0] && ft_strcmp(atk->moveset[attack].moveName, "Rest") == 'y')
	{
		printf("Rest FAILED, %s is already at FULL HP!\n\n", atk->pokeName);
		atk->moveset[attack].movePP -= pressure;
		return (0);
	}
	if (atk->protect > 0 && ft_strcmp(atk->moveset[attack].moveName, "Protect") == 'n')
		atk->protect = 0;
	if (ft_strcmp(atk->moveset[attack].moveName, "Protect") == 'y' && atk->protect > 0)
	{
		chance = rand() % 100;
		if ((100.0 / (atk->protect)) > chance)
		{
			atk->moveset[attack].movePP -= pressure;
			printf("%s FAILED!\n", atk->moveset[attack].moveName);
			atk->protect = 0;
			return (0);
		}
		else
		{
			atk->protect = atk->protect + 1;
			atk->moveset[attack].movePP -= pressure;
			printf("%s has covered itself in a Veil of Protection!\n\n", atk->pokeName);
			return (0);
		}
	}
	else if (ft_strcmp(atk->moveset[attack].moveName, "Protect") == 'y')
	{
		atk->protect = atk->protect + 1;
		atk->moveset[attack].movePP -= pressure;
		printf("%s has covered itself in a Veil of Protection!\n\n", atk->pokeName);
		return (0);
	}
	if (atk->moveset[attack].heal > 0 && atk->current[0] >= atk->base[0])
	{
		printf("%s's %s FAILED, %s is already at FULL HP!\n\n", atk->pokeName, atk->moveset[attack].moveName, atk->pokeName);
		atk->moveset[attack].movePP -= pressure;
		return (0);
	}
	if (atk->moveset[attack].moveAcc * atk->statMultiplier[5] < 100 && atk->moveset[attack].moveAcc * atk->statMultiplier[5] != 0)
	{
		chance = rand() % 100;
		if (chance > atk->moveset[attack].moveAcc * atk->statMultiplier[5])
		{
			atk->moveset[attack].movePP -= pressure;
			printf("%s MISSED!\n", atk->moveset[attack].moveName);
			return (0);
		}
	}
//	if ((atk->moveset[attack].moveName == "Curse") && (atk->type[0] == "Ghost" || atk->type[1] == "Ghost"))
//	{
//		// if (atk->current[0] >= atk->base[0])
//		// {
//		//	 atk->setCurrent(0,(1/2),"*");
//		//	 def->setCurse(1);
//		// }
//		// else
//		{
//			cout << "Unable to use CURSE, not enough HP." << endl;
//		}
//	}
	if (atk->moveset[attack].heal > 0)
	{
		atk->current[0] += (atk->moveset[attack].heal / 100.0) * atk->base[0];
		if (atk->current[0] > atk->base[0])
			atk->current[0] = atk->base[0];
		printf("%s has Recovered %d%% of its HP!\n", atk->pokeName, atk->moveset[attack].heal);
		usleep(750000);
	}
	if (atk->moveset[attack].buff[0] > 0)
	{
		if (chance <= atk->moveset[attack].buff[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff[0] == 6)
				printf("ACC");
			printf(" stat has been increased by %d Stages\n", atk->moveset[attack].buff[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff[0] - 1] += atk->moveset[attack].buff[1];
		}
	}
	if (atk->moveset[attack].buff2[0] > 0)
	{
		if (chance <= atk->moveset[attack].buff2[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff2[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff2[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff2[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff2[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff2[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff2[0] == 6)
				printf("ACC");
			printf(" stat has been increased by %d Stages\n", atk->moveset[attack].buff2[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff2[0] - 1] += atk->moveset[attack].buff2[1];
		}
	}
	if (atk->moveset[attack].buff3[0] > 0)
	{
		if (chance <= atk->moveset[attack].buff3[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff3[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff3[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff3[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff3[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff3[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff3[0] == 6)
				printf("ACC");
			printf(" stat has been increased by %d Stages\n", atk->moveset[attack].buff3[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff3[0] - 1] += atk->moveset[attack].buff3[1];
		}
	}
	if (atk->moveset[attack].buff[0]<0)
	{
		if (chance <= atk->moveset[attack].buff[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff[0] == 6)
				printf("ACC");
			printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].buff[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff[0] - 1] -= atk->moveset[attack].buff[1];
		}
	}

	if (atk->moveset[attack].buff2[0]<0)
	{
		if (chance <= atk->moveset[attack].buff2[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff2[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff2[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff2[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff2[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff2[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff2[0] == 6)
				printf("ACC");			printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].buff2[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff2[0] - 1] -= atk->moveset[attack].buff2[1];
		}
	}

	if (atk->moveset[attack].buff3[0]<0)
	{
		if (chance <= atk->moveset[attack].buff3[2])
		{
			printf("%s's ", atk->pokeName);
			if (atk->moveset[attack].buff3[0] == 1)
				printf("ATK");
			else if (atk->moveset[attack].buff3[0] == 2)
				printf("DEF");
			else if (atk->moveset[attack].buff3[0] == 3)
				printf("SP.ATK");
			else if (atk->moveset[attack].buff3[0] == 4)
				printf("SP.DEF");
			else if (atk->moveset[attack].buff3[0] == 5)
				printf("SPD");
			else if (atk->moveset[attack].buff3[0] == 6)
				printf("ACC");
			printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].buff3[1]);
			usleep(750000);
			atk->statMultiplier[atk->moveset[attack].buff3[0] - 1] -= atk->moveset[attack].buff3[1];
		}
	}
	if (atk->moveset[attack].status[0] > 0)
	{
		chance = rand() % 100;
		if (chance <= atk->moveset[attack].status[1])
		{
			switch (atk->moveset[attack].status[0])
			{
				case 1:
				{
					if (def->type[0] != 'E' && def->type[1] != 'E')
					{
						def->condition[0] = 'p';
						printf("%s has been PARALYZED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 2:
				{
					def->condition[0] = 's';
					chance = rand() % 3 + 1;
					printf("%s has been put to SLEEP\n", def->pokeName);
					def->conditionCool[0] = chance + 1;
					break ;
				}
				case 3:
				{
					if (def->type[0] != 'Q' && def->type[1] != 'Q')
					{
						def->condition[0] = 'b';
						printf("%s has been BURNED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 4:
				{
					if ((def->type[0] != 'X' && def->type[1] != 'X') && (def->type[0] != 'S' && def->type[1] != 'S'))
					{
						def->condition[0] = 'X';
						printf("%s has been POISONED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 5:
				{
					if (def->type[0] != 'I' && def->type[1] != 'I')
					{
						def->condition[0]= 'f';
						printf("%s has been FROZEN\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
				case 6:
				{
					if ((def->type[0] != 'X' && def->type[1] != 'X') && (def->type[0] != 'S' && def->type[1] != 'S'))
					{
						def->condition[0]= 'X';
						printf("%s has been BADLY POISONED\n", def->pokeName);
						def->conditionCool[0] = -1;
					}
					break ;
				}
			}
		}
	}
	if (atk->moveset[attack].confuse[0] > 0)
	{
		chance = rand() % 100;
		if (chance <= atk->moveset[attack].confuse[1])
		{
			def->condition[1] = 'y';
			printf("%s has become CONFUSED\n", def->pokeName);
			def->conditionCool[1] = 1;
		}
	}
	if (atk->moveset[attack].deBuff[0] > 0 && ft_strcmp(def->ability, "Clear Body") == 'n')
	{
		chance = rand() % 100;
		if (chance <= atk->moveset[attack].deBuff[2])
		{
			if (atk->moveset[attack].deBuff[0] == 6 && ft_strcmp(def->ability, "Keen Eye") == 'y')
			{
				printf("%s ACC Drop had NO EFFECT and %s is Keenly Watching %s!\n", atk->pokeName, def->pokeName, atk->pokeName);
				usleep(750000);
			}
			else
			{
				printf("%s's ", def->pokeName);
				if (atk->moveset[attack].deBuff[0] == 1)
					printf("ATK");
				else if (atk->moveset[attack].deBuff[0] == 2)
					printf("DEF");
				else if (atk->moveset[attack].deBuff[0] == 3)
					printf("SP.ATK");
				else if (atk->moveset[attack].deBuff[0] == 4)
					printf("SP.DEF");
				else if (atk->moveset[attack].deBuff[0] == 5)
					printf("SPD");
				else if (atk->moveset[attack].deBuff[0] == 6)
					printf("ACC");
				printf(" stat has been reduced by %d Stages\n", atk->moveset[attack].deBuff[1]);
				usleep(750000);
				def->statMultiplier[atk->moveset[attack].deBuff[0] - 1] -= atk->moveset[attack].deBuff[1];
			}
		}
	}
	if (ft_strcmp(atk->moveset[attack].moveName, "Belly Drum") == 'y')
	{
		if (atk->current[0] > 0.5*atk->base[0])
		{
			atk->statMultiplier[0] = 6.0;
			atk->current[0] -= 0.5 * atk->base[0];
			printf("ATK has been increased to 6th Stage, HP reduced by 1/2 its Max HP\n");
		}
		else
			printf("Belly Drum Failed!\n");
	}
	if (ft_strcmp(atk->moveset[attack].moveName, "Rest") == 'y')
	{
		atk->current[0] = atk->base[0];
		atk->condition[0] = 's';
		printf("%s has been put to SLEEP and has recovered its HP and healed all status conditions\n", atk->pokeName);
		atk->conditionCool[0] = 2;
	}
	if (ft_strcmp(atk->moveset[attack].moveName, "Reflect") == 'y')
	{
		if (user == 'p')
		{
			battle->playerReflect = 5;
			printf("A REFLECTIVE SCREEN of light has formed on the Player's side of the field!\n");
		}
		else if (user == 'e')
		{
			battle->enemyReflect = 5;
			printf("A REFLECTIVE SCREEN of light has formed on the Enemy's side of the field!\n");
		}
	}
	if (ft_strcmp(atk->moveset[attack].moveName, "Light Screen") == 'y')
	{
		if (user == 'p')
		{
			battle->playerLightScreen = 5;
			printf("A SCREEN of LIGHT has formed on the Player's side of the field!\n");
		}
		else if (user == 'e')
		{
			battle->enemyLightScreen = 5;
			printf("A REFLECTIVE of LIGHT has formed on the Enemy's side of the field!\n");
		}
	}

	if (ft_strcmp(atk->moveset[attack].moveName, "Spikes") == 'y')
	{
		if (user == 'p')
		{
			battle->playerSpikes++;
			printf("A layer of SPIKES has been placed on the Enemy's side of the field!\n");
		}
		else if (user == 'e')
		{
			battle->enemySpikes++;
			printf("A layer of SPIKES has been placed on the Enemy's side of the field!\n");
		}
	}
	atk->moveset[attack].movePP -= pressure;
	return (1);
}

int	ft_confusionProc(t_Pokemon* pokemon, int choice)
{
	if (choice == 1 && pokemon->condition[1] == 'y')	 //force player pokemon to hurt itself in confusion if confused (50% chance_)
	{
		int chance = rand() % 100;
		printf("%s Is Confused\n", pokemon->pokeName);
		usleep(150000);
		if (chance <= 50)
		{
			double random = rand() % 15 + 85;
			random /= 100;
			pokemon->current[0] -= ((((2 * 50) / 5) + 2) * 40 * (pokemon->current[1] * (ft_stageMulti(pokemon->statMultiplier[0],0)) / (pokemon->current[2] * (ft_stageMulti(pokemon->statMultiplier[1],1)))) / 50 + 2) * random;
			pokemon->conditionCool[1] += 1;
			printf("%s Hurt Itself in its Confusion!\n", pokemon->pokeName);
			if (pokemon->current[0]<0)
				pokemon->current[0] = 0;
			return (1);
		}
		if (pokemon->conditionCool[1] >= 5)
		{
			pokemon->conditionCool[1] = 0;
			pokemon->condition[1] = 'n';
			printf("%s has BROKEN OUT of its CONFUSION!\n", pokemon->pokeName);
			usleep(1500000);
			return (0);
		}
		pokemon->conditionCool[1] += 1;
	}
	return (0);
}

int	ft_movePriority(t_Pokemon* player, t_Pokemon* enemy, int enemyCheck, int choice, int choices)
{
	if (enemyCheck >= 0 && choice != 1)
		return (1);
	else if (enemyCheck<0 && choice == 1)
		return (0);
	else if (enemyCheck < 0  &&  choice == 1)
		return (-1);
	else
	{
		if (player->moveset[choices].movePriority > enemy->moveset[enemyCheck].movePriority)
			return (0);
		else if (player->moveset[choices].movePriority < enemy->moveset[enemyCheck].movePriority)
			return (1);
		double speedPlayer = player->current[5] * ft_stageMulti(player->statMultiplier[4],4);
		double speedEnemy = enemy->current[5] * ft_stageMulti(enemy->statMultiplier[4],4);
		if (player->condition[0] == 'p')
			speedPlayer *= (1 / 2);
		if (enemy->condition[0] == 'p')
			speedEnemy *= (1 / 2);
		if (speedPlayer > speedEnemy)
			return (0);
		if (speedPlayer < speedEnemy)
			return (1);
		int flip = rand() % 2;
		if (flip == 0)
			return (0);
		return (1);
	}
}

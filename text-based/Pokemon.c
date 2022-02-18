#include "Pokemon.h"
/*
status:
None = 'n'
Paralysis = 'p'
Poison = 'x'
Badly Poisoned = 'X'
Sleep = 's'
Frozen = 'f'
Burned = 'b'

confused:
yes = 'y'
no = 'n'
*/

/*					:POKEMON:				*/
	//moves thunderbolt, dig, focus blast, nasty plot
void	ft_raichu(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Raichu");
	pokemon->type[0] = 'E';
	pokemon->type[1] = '.';
	pokemon->typeNum = 1;
	ft_initialize_move(&pokemon->moveset[0], 5);
	ft_initialize_move(&pokemon->moveset[1], 6);
	ft_initialize_move(&pokemon->moveset[2], 7);
	ft_initialize_move(&pokemon->moveset[3], 8);
	pokemon->current[0] = 120 + rand() % 48;
	pokemon->current[1] = 85 + rand() % 99;
	pokemon->current[2] = 54 + rand() % 64;
	pokemon->current[3] = 85 + rand() % 72;
	pokemon->current[4] = 76 + rand() % 70;
	pokemon->current[5] = 103 + rand() % 76;
	ft_strcpy(pokemon->ability, "Static");
	ft_strcpy(pokemon->abilityDescript, "Inflicts Paralysis on Enemy upon the User being Hit by a Physical Type move.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//moves phantom force, x-scissor, shadow ball and hone claws
void	ft_shedinja(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Shedinja");
	pokemon->typeNum = 2;
	pokemon->type[0] = 'H';
	pokemon->type[1] = 'B';
	ft_initialize_move(&pokemon->moveset[0], 1);
	ft_initialize_move(&pokemon->moveset[1], 2);
	ft_initialize_move(&pokemon->moveset[2], 3);
	ft_initialize_move(&pokemon->moveset[3], 4);
	pokemon->current[0] = 1;
	pokemon->current[1] = 85 + rand() % 72;
	pokemon->current[2] = 45 + rand() % 62;
	pokemon->current[3] = 31 + rand() % 60;
	pokemon->current[4] = 31 + rand() % 60;
	pokemon->current[5] = 40 + rand() % 62;
	ft_strcpy(pokemon->ability, "Wonder Guard");
	ft_strcpy(pokemon->abilityDescript, "Only Super-Effective moves can cause Damage to the User.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//move flare blitz, dragon dance, earthquake, dragon claw (change to flamethrower, blast burn, earthquake,roost)
void	ft_charizard(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Charizard");
	pokemon->type[0] = 'Q';
	pokemon->type[1] = 'L';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 32);
	ft_initialize_move(&pokemon->moveset[1], 36);
	ft_initialize_move(&pokemon->moveset[2], 10);
	ft_initialize_move(&pokemon->moveset[3], 37);
	pokemon->current[0] = 138 + rand() % 47;
	pokemon->current[1] = 80 + rand() % 69;
	pokemon->current[2] = 74 + rand() % 69;
	pokemon->current[3] = 102 + rand() % 75;
	pokemon->current[4] = 81 + rand() % 69;
	pokemon->current[5] = 94 + rand() % 73;
	ft_strcpy(pokemon->ability, "Blaze");
	ft_strcpy(pokemon->abilityDescript, "Increases the Power of User's Fire Type moves by 50%% when User is At or Below 1/3 HP.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//move belly drum, rest, double edge, body slam (return, rest, sleep talk, earthquake)
void	ft_snorlax(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Snorlax");
	pokemon->type[0] = 'N';
	pokemon->type[1] = '.';
	pokemon->typeNum = 1;
	ft_initialize_move(&pokemon->moveset[0], 38);
	ft_initialize_move(&pokemon->moveset[1], 46);
	ft_initialize_move(&pokemon->moveset[2], 39);
	ft_initialize_move(&pokemon->moveset[3], 10);
	pokemon->current[0] = 220 + rand() % 48;
	pokemon->current[1] = 103 + rand() % 76;
	pokemon->current[2] = 63 + rand() % 66;
	pokemon->current[3] = 63 + rand() % 66;
	pokemon->current[4] = 103 + rand() % 76;
	pokemon->current[5] = 31 + rand() % 60;
	ft_strcpy(pokemon->ability, "Thick Fat");
	ft_strcpy(pokemon->abilityDescript, "User takes 1/2 Damage from Fire and Ice Type moves.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//move brine, rest, ice beam, thunderbolt (change thunderbolt to surf, rest to protect)
void	ft_lapras(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Lapras");
	pokemon->type[0] = 'W';
	pokemon->type[1] = 'I';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 11);
	ft_initialize_move(&pokemon->moveset[1], 41);
	ft_initialize_move(&pokemon->moveset[2], 12);
	ft_initialize_move(&pokemon->moveset[3], 40);
	pokemon->current[0] = 190 + rand() % 48;
	pokemon->current[1] = 81 + rand() % 70;
	pokemon->current[2] = 76 + rand() % 70;
	pokemon->current[3] = 81 + rand() % 70;
	pokemon->current[4] = 90 + rand() % 72;
	pokemon->current[5] = 58 + rand() % 66;
	ft_strcpy(pokemon->ability, "Shell Armour");
	ft_strcpy(pokemon->abilityDescript, "User Cannot be Critically Hit.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//fishious rend, brine, ancient power, body slam (fishious rend, crunch, protect, outrage)
void	ft_dracovish(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Dracovish");
	pokemon->type[0] = 'W';
	pokemon->type[1] = 'A';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 35);
	ft_initialize_move(&pokemon->moveset[1], 30);
	ft_initialize_move(&pokemon->moveset[2], 41);
	ft_initialize_move(&pokemon->moveset[3], 42);
	pokemon->current[0] = 150 + rand() % 48;
	pokemon->current[1] = 85 + rand() % 72;
	pokemon->current[2] = 94 + rand() % 74;
	pokemon->current[3] = 67 + rand() % 68;
	pokemon->current[4] = 76 + rand() % 70;
	pokemon->current[5] = 72 + rand() % 68;
	ft_strcpy(pokemon->ability, "Strong Jaw");
	ft_strcpy(pokemon->abilityDescript, "Increases the power of all 'biting' moves by 50%%.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//light screen, soft boiled, thunderbolt, ice beam
void	ft_blissey(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Blissey");
	pokemon->type[0] = 'N';
	pokemon->type[1] = 'F';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 18);
	ft_initialize_move(&pokemon->moveset[1], 43);
	ft_initialize_move(&pokemon->moveset[2], 5);
	ft_initialize_move(&pokemon->moveset[3], 12);
	pokemon->current[0] = 315 + rand() % 48;
	pokemon->current[1] = 13 + rand() % 56;
	pokemon->current[2] = 13 + rand() % 56;
	pokemon->current[3] = 72 + rand() % 68;
	pokemon->current[4] = 126 + rand() % 80;
	pokemon->current[5] = 54 + rand() % 64;
	ft_strcpy(pokemon->ability, "Serene Grace");
	ft_strcpy(pokemon->abilityDescript, "Doubles the Chance of Secondary Effects Activating for this User's Moves.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//earthquake, dragon dance, crunch, aqua tail
void	ft_gyarados(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Gyarados");
	pokemon->type[0] = 'W';
	pokemon->type[1] = 'L';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 10);
	ft_initialize_move(&pokemon->moveset[1], 9);
	ft_initialize_move(&pokemon->moveset[2], 30);
	ft_initialize_move(&pokemon->moveset[3], 23);
	pokemon->current[0] = 155 + rand() % 48;
	pokemon->current[1] = 117 + rand() % 78;
	pokemon->current[2] = 75 + rand() % 70;
	pokemon->current[3] = 58 + rand() % 66;
	pokemon->current[4] = 94 + rand() % 74;
	pokemon->current[5] = 77 + rand() % 70;
	ft_strcpy(pokemon->ability, "Intimidate");
	ft_strcpy(pokemon->abilityDescript, "When User Enters onto the Field, All Enemy Pokemon have their ATK Reduced by 1 Stage.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		// destiny bond, protect, shadow ball, sludge bomb
void	ft_gengar(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Gengar");
	pokemon->type[0] = 'H';
	pokemon->type[1] = 'X';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 31);
	ft_initialize_move(&pokemon->moveset[1], 41);
	ft_initialize_move(&pokemon->moveset[2], 3);
	ft_initialize_move(&pokemon->moveset[3], 25);
	pokemon->current[0] = 120 + rand() % 48;
	pokemon->current[1] = 63 + rand() % 66;
	pokemon->current[2] = 58 + rand() % 66;
	pokemon->current[3] = 121 + rand() % 80;
	pokemon->current[4] = 72 + rand() % 68;
	pokemon->current[5] = 103 + rand() % 76;
	ft_strcpy(pokemon->ability, "Levitate");
	ft_strcpy(pokemon->abilityDescript, "User is Floating above the Ground, making it Immune to all Ground-type Moves.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//Drill peck, roost, brave bird, iron head
void	ft_corviknight(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Corviknight");
	pokemon->type[0] = 'S';
	pokemon->type[1] = 'L';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 44);
	ft_initialize_move(&pokemon->moveset[1], 37);
	ft_initialize_move(&pokemon->moveset[2], 29);
	ft_initialize_move(&pokemon->moveset[3], 34);
	pokemon->current[0] = 158 + rand() % 48;
	pokemon->current[1] = 82 + rand() % 71;
	pokemon->current[2] = 99 + rand() % 74;
	pokemon->current[3] = 52 + rand() % 64;
	pokemon->current[4] = 81 + rand() % 70;
	pokemon->current[5] = 64 + rand() % 67;
	ft_strcpy(pokemon->ability, "Pressure");
	ft_strcpy(pokemon->abilityDescript, "All Moves used against the User use Double the PP Cost.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//hone claws, roost, brave bird, return
void	ft_braviary(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Braviary");
	pokemon->type[0] = 'N';
	pokemon->type[1] = 'L';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 4);
	ft_initialize_move(&pokemon->moveset[1], 37);
	ft_initialize_move(&pokemon->moveset[2], 29);
	ft_initialize_move(&pokemon->moveset[3], 38);
	pokemon->current[0] = 160 + rand() % 48;
	pokemon->current[1] = 115 + rand() % 78;
	pokemon->current[2] = 72 + rand() % 68;
	pokemon->current[3] = 55 + rand() % 65;
	pokemon->current[4] = 72 + rand() % 68;
	pokemon->current[5] = 76 + rand() % 70;
	ft_strcpy(pokemon->ability, "Keen Eye");
	ft_strcpy(pokemon->abilityDescript, "Prevents Enemy Pokemon from lowering Users ACC Stat Stages.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//moves meteor mash, psychic, hyper beam (changed to giga impact), earthquake
		//notes: meteor 20 %  chance raise user ATK by 1, psychic 10 %  chance lowering SP.DEF by 1.
void	ft_metagross(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Metagross");
	pokemon->type[0] = 'S';
	pokemon->type[1] = 'P';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 13);
	ft_initialize_move(&pokemon->moveset[1], 14);
	ft_initialize_move(&pokemon->moveset[2], 15);
	ft_initialize_move(&pokemon->moveset[3], 10);
	pokemon->current[0] = 140 + rand() % 48;
	pokemon->current[1] = 126 + rand() % 80;
	pokemon->current[2] = 121 + rand() % 80;
	pokemon->current[3] = 90 + rand() % 72;
	pokemon->current[4] = 85 + rand() % 72;
	pokemon->current[5] = 67 + rand() % 68;
	ft_strcpy(pokemon->ability, "Clear Body");
	ft_strcpy(pokemon->abilityDescript, "Prevents Enemy Moves from Reducing Any of the Users Stats.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//moves steel wing, aerial ace, toxic, spikes (spikes to rock slide)
		//notes: steel wing 10 %  chance raise user DEF by 1, check toxic formula (same as normal poison?), spikes hurts for 12.5 %  HP upon switch in (can be stacked up to 25 %  for 3 check online).
void	ft_skarmory(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Skarmory");
	pokemon->type[0] = 'S';
	pokemon->type[1] = 'L';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 16);
	ft_initialize_move(&pokemon->moveset[1], 17);
	ft_initialize_move(&pokemon->moveset[2], 47);
	ft_initialize_move(&pokemon->moveset[3], 45);
	pokemon->current[0] = 125 + rand() % 48;
	pokemon->current[1] = 76 + rand() % 70;
	pokemon->current[2] = 130 + rand() % 82;
	pokemon->current[3] = 40 + rand() % 62;
	pokemon->current[4] = 67 + rand() % 68;
	pokemon->current[5] = 67 + rand() % 68;
	ft_strcpy(pokemon->ability, "Sturdy");
	ft_strcpy(pokemon->abilityDescript, "While at Full HP, Prevents User from Dying in 1 Hit, Instead Leaves them with 1HP remaining.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//moves light screen, reflect, ancient power, earthquake

		//notes: light doubles SP.DEF of users for 5 turns & relfect doubles DEF users 5 turns, Ancient 10 %  chance increaing all stat multi by 1 stage (not ACC).
void	ft_claydol(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Claydol");
	pokemon->type[0] = 'G';
	pokemon->type[1] = 'P';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 18);
	ft_initialize_move(&pokemon->moveset[1], 20);
	ft_initialize_move(&pokemon->moveset[2], 19);
	ft_initialize_move(&pokemon->moveset[3], 10);
	pokemon->current[0] = 120 + rand() % 48;
	pokemon->current[1] = 67 + rand() % 68;
	pokemon->current[2] = 99 + rand() % 74;
	pokemon->current[3] = 67 + rand() % 68;
	pokemon->current[4] = 112 + rand() % 78;
	pokemon->current[5] = 72 + rand() % 68;
	ft_strcpy(pokemon->ability, "Levitate");
	ft_strcpy(pokemon->abilityDescript, "User is Floating above the Ground, making it Immune to all Ground-type Moves.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//moves curses, head smash, aqua tail, earthquake
		//notes: thunder 30 %  chance paralyze, solar charges first turn then fires second.
void	ft_aggron(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Aggron");
	pokemon->type[0] = 'S';
	pokemon->type[1] = 'R';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 21);
	ft_initialize_move(&pokemon->moveset[1], 22);
	ft_initialize_move(&pokemon->moveset[2], 23);
	ft_initialize_move(&pokemon->moveset[3], 10);
	pokemon->current[0] = 130 + rand() % 48;
	pokemon->current[1] = 103 + rand() % 76;
	pokemon->current[2] = 166 + rand() % 90;
	pokemon->current[3] = 58 + rand() % 66;
	pokemon->current[4] = 58 + rand() % 66;
	pokemon->current[5] = 49 + rand() % 64;
	ft_strcpy(pokemon->ability, "Rock Head");
	ft_strcpy(pokemon->abilityDescript, "User takes No Recoil Damage.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//moves confuse ray, sludge bomb, giga drain, ancient power
		//notes: confuse if hits confuses, Sludge 30 %  to poison, giga heals 50 %  of damage dealt, Ancient 10 %  chance increaing all stat multi by 1 stage (not ACC).
void	ft_cradily(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Cradily");
	pokemon->type[0] = 'M';
	pokemon->type[1] = 'R';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 24);
	ft_initialize_move(&pokemon->moveset[1], 25);
	ft_initialize_move(&pokemon->moveset[2], 26);
	ft_initialize_move(&pokemon->moveset[3], 19);
	pokemon->current[0] = 146 + rand() % 48;
	pokemon->current[1] = 77 + rand() % 70;
	pokemon->current[2] = 91 + rand() % 73;
	pokemon->current[3] = 77 + rand() % 70;
	pokemon->current[4] = 100 + rand() % 75;
	pokemon->current[5] = 43 + rand() % 62;
	ft_strcpy(pokemon->ability, "Suction Cups");
	ft_strcpy(pokemon->abilityDescript, "User cCannot be Forced to Leave the Field by an Enemy Move.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

		//moves slash, water pulse, ancient power, aerial ace
		//notes: slash increased crit chance (maybe 1.5X??), pulse 20 %  to confuse enemy, Ancient 10 %  chance increaing all stat multi by 1 stage (not ACC).
void	ft_armaldo(t_Pokemon *pokemon, int track)
{
	ft_strcpy(pokemon->pokeName, "Armaldo");
	pokemon->type[0] = 'B';
	pokemon->type[1] = 'R';
	pokemon->typeNum = 2;
	ft_initialize_move(&pokemon->moveset[0], 27);
	ft_initialize_move(&pokemon->moveset[1], 28);
	ft_initialize_move(&pokemon->moveset[2], 19);
	ft_initialize_move(&pokemon->moveset[3], 17);
	pokemon->current[0] = 135 + rand() % 48;
	pokemon->current[1] = 117 + rand() % 78;
	pokemon->current[2] = 94 + rand() % 74;
	pokemon->current[3] = 67 + rand() % 68;
	pokemon->current[4] = 76 + rand() % 70;
	pokemon->current[5] = 45 + rand() % 62;
	ft_strcpy(pokemon->ability, "Battle Armour");
	ft_strcpy(pokemon->abilityDescript, "User Cannot be Critically Hit.");
	while (++track < 6)
	{
		pokemon->base[track] = pokemon->current[track];
		pokemon->statMultiplier[track] = 0;
	}
}

void	ft_pokemon_set_2(t_Pokemon *pokemon, int num)
{
	if (num == 12)
		ft_skarmory(pokemon, -1);
	else if (num == 13)
		ft_claydol(pokemon, -1);
	else if (num == 14)
		ft_aggron(pokemon, -1);
	else if (num == 15)
		ft_cradily(pokemon, -1);
	else if (num == 16)
		ft_armaldo(pokemon, -1);
	// else if (num == 6)
	// 	ft_dracovish(pokemon, -1);
	// else if (num == 7)
	// 	ft_blissey(pokemon, -1);
	// else if (num == 8)
	// 	ft_gyarados(pokemon, -1);
	// else if (num == 9)
	// 	ft_gengar(pokemon, -1);
	// else if (num == 10)
	// 	ft_corviknight(pokemon, -1);
	// else if (num == 11)
	// 	ft_braviary(pokemon, -1);
	// else if (num == 12)
	// 	ft_metagross(pokemon, -1);
}

void	ft_pokemon_set_1(t_Pokemon *pokemon, int num)
{
	if (num == 0)
		ft_raichu(pokemon, -1);
	else if (num == 1)
		ft_shedinja(pokemon, -1);
	else if (num == 2)
		ft_charizard(pokemon, -1);
	else if (num == 3)
		ft_snorlax(pokemon, -1);
	else if (num == 4)
		ft_lapras(pokemon, -1);
	else if (num == 5)
		ft_dracovish(pokemon, -1);
	else if (num == 6)
		ft_blissey(pokemon, -1);
	else if (num == 7)
		ft_gyarados(pokemon, -1);
	else if (num == 8)
		ft_gengar(pokemon, -1);
	else if (num == 9)
		ft_corviknight(pokemon, -1);
	else if (num == 10)
		ft_braviary(pokemon, -1);
	else if (num == 11)
		ft_metagross(pokemon, -1);
}

void	ft_initialize_pokemon(t_Pokemon *pokemon, int num)
{
	pokemon->cooldown = 0;
	pokemon->badCounter = 1;
	pokemon->condition[0] = 'n';
	pokemon->condition[1] = 'n';
	pokemon->conditionCool[0] = 0;
	pokemon->conditionCool[1] = 0;
	pokemon->impermeable = 0;
	pokemon->protect = 0;
	pokemon->roost = 0;
	pokemon->outrage = 0;
	pokemon->flinched = 0;
	if (num >= 0 && num < 12)
		ft_pokemon_set_1(pokemon, num);
	else if (num >= 12 && num < 17)
		ft_pokemon_set_2(pokemon, num);
}

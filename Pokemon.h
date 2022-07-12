#ifndef POKEMON_H
#define POKEMON_H
#include "Moves.h"
#include <stdlib.h>

typedef struct s_Pokemon
{
	int		current[6]; //stores the pokemon's current stats, 0=hp, 1=atk,2=def,3=sp.atk,4=sp.def,5=spd
	int		base[6]; //stores the pokemon's base stats
	char	type[2]; //stores the pokemon's type
	char	pokeName[12];
	int		typeNum; //stores how many types the pokemon has (1 or 2)
	char	condition[2]; //stores status conditions. element 0 = status, element 1 = confusion
	int		conditionCool[2];
	char	ability[16];
	// string heldItem; //just store the item's name, empty string if no item 	//yet to implement aka a massive pain
	double	statMultiplier[6]; //# of stages, 0=atk.....4=spd, 5=acc
	char	abilityDescript[160];
	int		impermeable; //if pokemon is currently invicible (protect, dig, fly, ect.)
	int		cooldown;
	int		badCounter; //turn counter for badly poisoned

	t_Moves moveset[4];

	int		roost; //if roost was activated last turn or not
	int		protect; // if they are protected/used protect, 1=protected, 2+=used protect last turn
	int		outrage; // if using outrage, counts how many turns, max 3 min 2
	int		destiny; // 0 if nothing, 1 if destiny bond active
	int		flinched; //0 is nothing, 1 is flinched

	//stuff max has added
	// int		turnCount; //number of turns the pokeon has been in battle (resets on switch)
	// int		damageLast; //damage this pokemon did previous turn
	// int		critLast; //if this pokemon crit previous turn
	//int seeded; //If this pokemon has been leech seeded
	//int subbed; //integer that stores the precentage health of a substitute, 0 if no sub
	//int veiled; //If this pokemon has a water veil (Aqua Ring)
	//string lastMove; //the move this pokemon used last turn.
	//int switched; //this pokemon has used the move Trick or Switeroo
}	t_Pokemon;

void	ft_initialize_pokemon(t_Pokemon *pokemon, int num);

/*			POKEMON FUNCTIONS		*/
void	ft_raichu(t_Pokemon *pokemon, int track);
void	ft_shedinja(t_Pokemon *pokemon, int track);
void	ft_charizard(t_Pokemon *pokemon, int track);
void	ft_snorlax(t_Pokemon *pokemon, int track);
void	ft_lapras(t_Pokemon *pokemon, int track);
void	ft_dracovish(t_Pokemon *pokemon, int track);
void	ft_blissey(t_Pokemon *pokemon, int track);
void	ft_gyarados(t_Pokemon *pokemon, int track);
void	ft_gengar(t_Pokemon *pokemon, int track);
void	ft_corviknight(t_Pokemon *pokemon, int track);
void	ft_braviary(t_Pokemon *pokemon, int track);
void	ft_metagross(t_Pokemon *pokemon, int track);
void	ft_skarmory(t_Pokemon *pokemon, int track);
void	ft_claydol(t_Pokemon *pokemon, int track);
void	ft_aggron(t_Pokemon *pokemon, int track);
void	ft_cradily(t_Pokemon *pokemon, int track);
void	ft_armaldo(t_Pokemon *pokemon, int track);

#endif

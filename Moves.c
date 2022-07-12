#include "Moves.h"

void	ft_strcpy(char *dest, char *input)
{
	int	track;

	track = -1;
	while (input[++track] != '\0')
		dest[track] = input[track];
	dest[track] = '\0';
}

char	ft_strcmp(char *first, char *second)
{
	int		track;

	track = 0;
	while (first[track] == second[track] && first[track] != '\0' && second[track] != '\0')
		track++;
	if (first[track] == '\0' && second[track] == '\0')
		return ('y');
	return ('n');
}

void	ft_start(t_Moves *move, int track)
{
	move->crit_ratio = 0;
	move->cooldown = 0;
	while (++track < 2)
	{
		move->buff[track] = 0;
		move->deBuff[track] = 0;
		move->status[track] = 0;
		move->confuse[track] = 0;
		move->recoil[track] = 0;
		move->buff2[track] = 0;
		move->buff3[track] = 0;
		move->numHits[track] = 0;
	}
	move->flinch = 0;
	move->buff[2] = 0;
	move->deBuff[2] = 0;
	move->buff2[2] = 0;
	move->buff3[2] = 0;
	move->contact = 0;
	move->movePriority = 0;
	move->or_movePP = 0;
	move->drain = 0;
	move->heal = 0;
}

void	ft_phantom_force(t_Moves *move)
{
	ft_strcpy(move->moveName, "Phantom Force");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'G';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "User vanishes for 1 turn upon casting, then attacks enemy the next turn. Ignores all protection moves.");
	move->cooldown = 1; // leave 1
	move->contact = 1;
}

void	ft_x_scissor(t_Moves *move)
{
	ft_strcpy(move->moveName, "X-Scissor");
	move->movePow = 80;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'B';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Slashes enemy in a X formation");
	move->contact = 1;
}

void	ft_shadow_ball(t_Moves *move)
{
	ft_strcpy(move->moveName, "Shadow Ball");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'H';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Has 20% chance to lower Sp.Def of enemy by 1 stage.");
	move->deBuff[0] = 4;
	move->deBuff[1] = 1;
	move->deBuff[2] = 20;
}

void	ft_hone_claws(t_Moves *move)
{
	ft_strcpy(move->moveName, "Hone Claws");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 15;
	move->moveEle = 'D';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Raises User's ATK and ACC stat by 1 stage.");
	move->buff[0] = 1;
	move->buff[1] = 1;
	move->buff[2] = 100;
	move->buff2[0] = 6;
	move->buff2[1] = 1;
	move->buff2[2] = 100;
}

void	ft_thunderbolt(t_Moves *move)
{
	ft_strcpy(move->moveName,  "Thunderbolt");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'E';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Hits enemy with bolt of lightning, 10% chance of inflicting Paralysis.");
	move->status[0] = 1;
	move->status[1] = 10;
}

void	ft_nasty_plot(t_Moves *move)
{
	ft_strcpy(move->moveName, "Nasty Plot");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 20;
	move->moveEle = 'D';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Raises User's Sp.ATK by 2 stages.");
	move->buff[0] = 3;
	move->buff[1] = 2;
	move->buff[2] = 100;
}

void	ft_focus_blast(t_Moves *move)
{
	ft_strcpy(move->moveName, "Focus Blast");
	move->movePow = 120;
	move->moveAcc = 70;
	move->movePP = 5;
	move->moveEle = 'T';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Fires a focused blast, has 10% chance to lower Sp.Def of enemy by 1 stage.");
	move->deBuff[0] = 4;
	move->deBuff[1] = 1;
	move->deBuff[2] = 10;
}

void	ft_dig(t_Moves *move)
{
	ft_strcpy(move->moveName, "Dig");
	move->movePow = 80;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'G';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "User digs underground for 1 turn upon casting, then attacks enemy the next turn.");
	move->contact = 1;
	move->cooldown = 1;
}

void	ft_dragon_dance(t_Moves *move)
{
	ft_strcpy(move->moveName, "Dragon Dance");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 20;
	move->moveEle = 'A';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Raises User's ATK and SPD by 1 stage.");
	move->buff[0] = 1;
	move->buff[1] = 1;
	move->buff[2] = 100;
	move->buff2[0] = 5;
	move->buff2[1] = 1;
	move->buff2[2] = 100;
}

void	ft_earthquake(t_Moves *move)
{
	ft_strcpy(move->moveName, "Earthquake");
	move->movePow = 100;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'G';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Violently shakes the ground beneath enemy, inflicting damage.");
}

void	ft_dragon_claw(t_Moves *move)
{
	ft_strcpy(move->moveName, "Dragon Claw");
	move->movePow = 80;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'A';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Slashs enemy with a dragonic claw, inflicting damage.");
	move->contact = 1;
}

void	ft_belly_drum(t_Moves *move)
{
	ft_strcpy(move->moveName, "Belly Drum");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 10;
	move->moveEle = 'N';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Increases User's ATK stat to +6 stage at the cost of 1/2 their HP, cannot use if User's HP is below 1/2 their MAX HP.");
}

void	ft_rest(t_Moves *move)
{
	ft_strcpy(move->moveName, "Rest");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 10;
	move->moveEle = 'P';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Recovers User's HP to MAX, User falls asleep for 2-3 turns, includes casting turn.");
}

void	ft_double_edge(t_Moves *move)
{
	ft_strcpy(move->moveName, "Double Edge");
	move->movePow = 120;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'N';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "User tackles enemy full-force, inflicting damage and taking 1/3 of the inflicted damage as recoil.");
	move->recoil[0] = 1;
	move->recoil[1] = 33;
	move->contact = 1;
}

void	ft_brine(t_Moves *move)
{
	ft_strcpy(move->moveName, "Brine");
	move->movePow = 65;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'W';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Doubles in Power when enemy is at or below 1/2 their MAX HP.");
}

void	ft_ice_beam(t_Moves *move)
{
	ft_strcpy(move->moveName, "Ice Beam");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'I';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Fires a beam of ice at the opponent, has 10% chance to Freeze.");
	move->status[0] = 5;
	move->status[1] = 10;
}

void	ft_meteor_mash(t_Moves *move)
{
	ft_strcpy(move->moveName, "Meteor Mash");
	move->movePow = 90;
	move->moveAcc = 90;
	move->movePP = 10;
	move->moveEle = 'S';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Hits enemy with a Meteor-like punch, 20% chance to increase ATK.");
	move->contact = 1;
	move->buff[0] = 1;
	move->buff[1] = 1;
	move->buff[2] = 20;
}

void	ft_psychic(t_Moves *move)
{
	ft_strcpy(move->moveName, "Psychic");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'P';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Fires a strong telekinetic force at the opponent, 10% chance to reduce Sp.Def.");
	move->deBuff[0] = 4;
	move->deBuff[1] = 1;
	move->deBuff[2] = 10;
}

void	ft_giga_impact(t_Moves *move)
{
	ft_strcpy(move->moveName, "Giga Impact");
	move->movePow = 150;
	move->moveAcc = 90;
	move->movePP = 5;
	move->moveEle = 'N';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "The user charges at the target using every bit of its power. The user must recover their energy next turn.");
	move->cooldown = -1;
}

void	ft_steel_wing(t_Moves *move)
{
	ft_strcpy(move->moveName, "Steel Wing");
	move->movePow = 70;
	move->moveAcc = 90;
	move->movePP = 25;
	move->moveEle = 'S';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Strikes enemy with a pair of steel wings, 10% chance to increase DEF.");
	move->contact = 1;
	move->buff[0] = 2;
	move->buff[1] = 1;
	move->buff[2] = 10;
}

void	ft_aerial_ace(t_Moves *move)
{
	ft_strcpy(move->moveName, "Aerial Ace");
	move->movePow = 60;
	move->moveAcc = 0;
	move->movePP = 20;
	move->moveEle = 'L';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Slashes enemy at extremely high speed, cannot miss unless enemy untouchable (flying, digging etc).");
	move->contact = 1;
}

void	ft_toxic(t_Moves *move)
{
	ft_strcpy(move->moveName, "Toxic");
	move->movePow = 0;
	move->moveAcc = 90;
	move->movePP = 10;
	move->moveEle = 'X';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Badly poisons enemy, damage increase each turn.");
	move->status[0] = 6;
	move->status[1] = 100;
}
	
void	ft_light_screen(t_Moves *move)
{
	ft_strcpy(move->moveName, "Light Screen");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 30;
	move->moveEle = 'P';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Puts up screen of light, reduces all incoming Special damage by 1/2.");
}

void	ft_ancient_power(t_Moves *move)
{
	ft_strcpy(move->moveName, "Ancient Power");
	move->movePow = 60;
	move->moveAcc = 100;
	move->movePP = 5;
	move->moveEle = 'R';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Enemy is hit with a prehistoric power, 10% chance to increase all stats");
	move->buff[0] = 69;
	move->buff[1] = 1;
	move->buff[2] = 10;
}

void	ft_reflect(t_Moves *move)
{
	ft_strcpy(move->moveName, "Reflect");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 20;
	move->moveEle = 'P';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Puts up wall of light, reduces all incoming Physical damage by 1/2.");
}

void	ft_curse(t_Moves *move)
{
	ft_strcpy(move->moveName, "Curse");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 10;
	move->moveEle = 'H';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "For non-Ghost type User, will increase ATK & DEF but reduce SPD. For Ghost type user, cuts user's HP in 1/2 to inflict curse on enemy, dealing damage per turn.");
	move->buff[0] = 1;
	move->buff[1] = 1;
	move->buff[2] = 100;
	move->buff2[0] = 2;
	move->buff2[1] = 1;
	move->buff2[2] = 100;
	move->buff3[0] = 5;
	move->buff3[1] = -1;
	move->buff3[2] = 100;
}

void	ft_head_smash(t_Moves *move)
{
	ft_strcpy(move->moveName, "Head Smash");
	move->movePow = 150;
	move->moveAcc = 80;
	move->movePP = 5;
	move->moveEle = 'R';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "User smashes head-first into enemy, inflicting damage. Takes 1/2 damage dealt as move->recoil.");
	move->recoil[0] = 1;
	move->recoil[1] = 50;
	move->contact = 1;
}

void	ft_aqua_tail(t_Moves *move)
{
	ft_strcpy(move->moveName, "Aqua Tail");
	move->movePow = 90;
	move->moveAcc = 90;
	move->movePP = 10;
	move->moveEle = 'W';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "User hits the opponent with their swinging tail as if it's were a vicious wave in a raging storm.");
	move->contact = 1;
}

void	ft_confuse_ray(t_Moves *move)
{
	ft_strcpy(move->moveName, "Confuse Ray");
	move->movePow = 0;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'H';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Sinister ray that confuses the opponent.");
	move->confuse[0] = 1;
	move->confuse[1] = 100;
}

void	ft_sludge_bomb(t_Moves *move)
{
	ft_strcpy(move->moveName, "Sludge Bomb");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'X';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Throws poisonous sludge at the opponent, 30% chance to poison.");
	move->status[0] = 4;
	move->status[1] = 30;
}

void	ft_giga_drain(t_Moves *move)
{
	ft_strcpy(move->moveName, "Giga Drain");
	move->movePow = 75;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'M';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Inflicts damage on enemy, User absorbs 50% damage as HP.");
	move->drain = 50;
}

void	ft_slash(t_Moves *move)
{
	ft_strcpy(move->moveName, "Slash");
	move->movePow = 70;
	move->moveAcc = 100;
	move->movePP = 20;
	move->moveEle = 'N';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Slashes the opponent, has a high crit-ratio.");
	move->contact = 1;
	move->crit_ratio = 1;
}

void	ft_water_pulse(t_Moves *move)
{
	ft_strcpy(move->moveName, "Water Pulse");
	move->movePow = 60;
	move->moveAcc = 100;
	move->movePP = 20;
	move->moveEle = 'W';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Fires a pulsing blast of water at the opponent, 20% chance to confuse.");
	move->confuse[0] = 1;
	move->confuse[1] = 20;
}

void	ft_brave_bird(t_Moves *move)
{
	ft_strcpy(move->moveName, "Brave Bird");
	move->movePow = 120;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'L';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "The user tucks in its wings and charges from a low altitude. User takes 1/3 of the damage done to the opponent as recoil.");
	move->contact = 1;
	move->recoil[0] = 1;
	move->recoil[1] = 30;
}
	
void	ft_crunch(t_Moves *move)
{
	ft_strcpy(move->moveName, "Crunch");
	move->movePow = 80;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'D';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "The user crunches up the target with sharp fangs. 20% chance to lower Defence of enemy by 1 stage.");
	move->contact = 1;
	move->deBuff[0] = 2;
	move->deBuff[1] = 1;
	move->deBuff[2] = 20; //Defence, 1 stage, 20%
}
	
void	ft_destiny_bond(t_Moves *move)
{
	ft_strcpy(move->moveName, "Destiny Bond");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 5;
	move->moveEle = 'H';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "When this move is used, if the user faints, the Pokémon that landed the knockout hit also faints.");
}

void	ft_flamethrower(t_Moves *move)
{
	ft_strcpy(move->moveName, "Flamethrower");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'Q';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "The target is scorched with an intense blast of fire, has a 10% chance to cause burn.");
	move->status[0] = 3;
	move->status[1] = 10; //Burn, 10%
}
	
void	ft_ice_fang(t_Moves *move)
{
	ft_strcpy(move->moveName, "Ice Fang");
	move->movePow = 65;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'I';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "The user bites with cold-infused fangs, has a 10% chance cause flinching and 10% chance to cause freeze.");
	move->contact = 1;
	move->status[0] = 5;
	move->status[1] = 10; //Freeze, 10%
	move->flinch = 10;
}

void	ft_iron_head(t_Moves *move)
{
	ft_strcpy(move->moveName, "Iron Head");
	move->movePow = 80;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'S';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "The user slams the target with its steel-hard head, has a 30% chance to cause flinching.");
	move->contact = 1;
	move->flinch = 30;
}

void	ft_fishious_rend(t_Moves *move)
{
	ft_strcpy(move->moveName, "Fishious Rend");
	move->movePow = 85;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'W';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Hits the enemy with user's fishy head, Doubles in Power if user attacks First.");
	move->contact = 1;
}

void	ft_blast_burn(t_Moves *move)
{
	ft_strcpy(move->moveName, "Blast Burn");
	move->movePow = 150;
	move->moveAcc = 90;
	move->movePP = 5;
	move->moveEle = 'Q';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "Hits the enemy with Massive Blast of Heat and Fire, User must Cooldown Next Turn.");
	move->cooldown = -1;
}

void	ft_roost(t_Moves *move)
{
	ft_strcpy(move->moveName, "Roost");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 10;
	move->moveEle = 'L';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Restores 50% of Users HP, Flying-type Pokemon lose their Flying type for the turn.");
	move->heal = 50;
}

void	ft_return(t_Moves *move)
{
	ft_strcpy(move->moveName, "Return");
	move->movePow = 102;
	move->moveAcc = 100;
	move->movePP = 20;
	move->moveEle = 'N';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "An Attack that grows more Powerful the more the Pokemon like the Trainer.");
	move->contact = 1;
}

void	ft_sleep_talk(t_Moves *move)
{
	ft_strcpy(move->moveName, "Sleep Talk");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 10;
	move->moveEle = 'N';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "Performs one of the Users other Moves at random whilst User is Asleep.");
}

void	ft_surf(t_Moves *move)
{
	ft_strcpy(move->moveName, "Surf");
	move->movePow = 90;
	move->moveAcc = 100;
	move->movePP = 15;
	move->moveEle = 'W';
	move->moveType = 'S';
	ft_strcpy(move->moveDescript, "User creates a Huge Wave and Crashes it Down on the Enemy.");
}

void	ft_protect(t_Moves *move)
{
	ft_strcpy(move->moveName, "Protect");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 10;
	move->moveEle = 'N';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "User Protects iteself from all Attacks, may Fail if used Consectively.");
	move->movePriority = 4;
}

void	ft_outrage(t_Moves *move)
{
	ft_strcpy(move->moveName, "Outrage");
	move->movePow = 120;
	move->moveAcc = 100;
	move->movePP = 10;
	move->moveEle = 'A';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "User goes on a Rampage for 2-3 Turns, becomes Confused afterwards.");
	move->contact = 1;
}

void	ft_soft_boiled(t_Moves *move)
{
	ft_strcpy(move->moveName, "Soft-Boiled");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 10;
	move->moveEle = 'N';
	move->moveType = 'T';
	ft_strcpy(move->moveDescript, "User eats a Soft-Boiled egg, restoring its own HP by up to 50%.");
	move->heal = 50;
}

void	ft_drill_peck(t_Moves *move)
{
	ft_strcpy(move->moveName, "Drill Peck");
	move->movePow = 80;
	move->moveAcc = 100;
	move->movePP = 20;
	move->moveEle = 'L';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "A Corkscrewing Attack that Hits the Enemy with the Users Sharp Beak acting as a Drill.");
	move->contact = 1;
}

void	ft_rock_slide(t_Moves *move)
{
	ft_strcpy(move->moveName, "Rock Slide");
	move->movePow = 75;
	move->moveAcc = 90;
	move->movePP = 10;
	move->moveEle = 'R';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "Hits Enemy with an Avalanche of Rocks and Boulders, may cause the Enemy to flinch.");
	move->flinch = 30;
}

void	ft_generic(t_Moves *move)
{
	ft_strcpy(move->moveName, "Error");
	move->movePow = 0;
	move->moveAcc = 0;
	move->movePP = 0;
	move->moveEle = 'N';
	move->moveType = 'P';
	ft_strcpy(move->moveDescript, "If This Move is Seen, Please Report Error.");
}

void	ft_move_set_4(t_Moves *move, int num)
{
	if (num == 37)
		ft_roost(move);
	else if (num == 38)
		ft_return(move);
	else if (num == 39)
		ft_sleep_talk(move);
	else if (num == 40)
		ft_surf(move);
	else if (num == 41)
		ft_protect(move);
	else if (num == 42)
		ft_outrage(move);
	else if (num == 43)
		ft_soft_boiled(move);
	else if (num == 44)
		ft_drill_peck(move);
	else if (num == 45)
		ft_rock_slide(move);
	else if (num == 46)
		ft_rest(move);
	else if (num == 47)
		ft_toxic(move);
}

void	ft_move_set_3(t_Moves *move, int num)
{
	if (num == 25)
		ft_sludge_bomb(move);
	else if (num == 26)
		ft_giga_drain(move);
	else if (num == 27)
		ft_slash(move);
	else if (num == 28)
		ft_water_pulse(move);
	else if (num == 29)
		ft_brave_bird(move);
	else if (num == 30)
		ft_crunch(move);
	else if (num == 31)
		ft_destiny_bond(move);
	else if (num == 32)
		ft_flamethrower(move);
	else if (num == 33)
		ft_ice_fang(move);
	else if (num == 34)
		ft_iron_head(move);
	else if (num == 35)
		ft_fishious_rend(move);
	else if (num == 36)
		ft_blast_burn(move);
}

void	ft_move_set_2(t_Moves *move, int num)
{
	if (num == 13)
		ft_meteor_mash(move);
	else if (num == 14)
		ft_psychic(move);
	else if (num == 15)
		ft_giga_impact(move);
	else if (num == 16)
		ft_steel_wing(move);
	else if (num == 17)
		ft_aerial_ace(move);
	else if (num == 18)
		ft_light_screen(move);
	else if (num == 19)
		ft_ancient_power(move);
	else if (num == 20)
		ft_reflect(move);
	else if (num == 21)
		ft_curse(move);
	else if (num == 22)
		ft_head_smash(move);
	else if (num == 23)
		ft_aqua_tail(move);
	else if (num == 24)
		ft_confuse_ray(move);
}

void	ft_move_set_1(t_Moves *move, int num)
{
	if (num == 1)
		ft_phantom_force(move);
	else if (num == 2)
		ft_x_scissor(move);
	else if (num == 3)
		ft_shadow_ball(move);
	else if (num == 4)
		ft_hone_claws(move);
	else if (num == 5)
		ft_thunderbolt(move);
	else if (num == 6)
		ft_nasty_plot(move);
	else if (num == 7)
		ft_focus_blast(move);
	else if (num == 8)
		ft_dig(move);
	else if (num == 9)
		ft_dragon_dance(move);
	else if (num == 10)
		ft_earthquake(move);
	else if (num == 11)
		ft_brine(move);
	else if (num == 12)
		ft_ice_beam(move);
}

void	ft_initialize_move(t_Moves *move, int num)
{
	ft_start(move, -1);
	if (num > 0 && num < 13)
		ft_move_set_1(move, num);
	else if (num > 12 && num < 25)
		ft_move_set_2(move, num);
	else if (num > 24 && num < 37)
		ft_move_set_3(move, num);
	else if (num > 36 && num < 48)
		ft_move_set_4(move, num);
	else
		ft_generic(move);
	move->or_movePP = move->movePP;
}


/*					Deleted / Moves Not Currently Being Used 			*/

// case 9:
// 	{
// 		ft_strcpy(move->moveName, "Transform");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 10;
// 		move->moveEle = 'N';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "User Transforms into a copy of the opponent, including base stats, moveName, typing and stat multipliers.");
// 		
// 	}
// 	case 10:
// 	{
// 		ft_strcpy(move->moveName, "Flare Blitz");
// 		move->movePow = 120;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'Q';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "User rams enemy whilst coated in Fire, User takes 1/3 of the damage done to the opponent as move->recoil.");
// 		move->contact = 1;
// 		move->recoil[0] = 1;
// 		move->recoil[1] = 33;
// 		
// 	}

// case 25:
// 	{
// 		ft_strcpy(move->moveName, "Spikes");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 20;
// 		move->moveEle = 'G';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "Sets spike on enemy's field, damages enemies that switch in.");
		
// 	}

// 	case 37:
// 	{
// 		ft_strcpy(move->moveName, "Body Slam");
// 		move->movePow = 85;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'N';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "User slams their body into the opponent, 30% chance to paralyze.");
// 		move->contact = 1;
// 		move->status[0] = 1;
// 		move->status[1] = 30;
		
// 	}
// 	case 38:
// 	{
// 		ft_strcpy(move->moveName, "Acrobatics");
// 		move->movePow = 55;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'L';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user nimbly strikes the target. Has double power if the user has no held item.");
// 		move->contact = 1;
		
// 		//??? damage increases if no held item. If flying gem is held, gem is consumed then move checks if no held item.

// 	}
// 	case 39:
// 	{
// 		ft_strcpy(move->moveName, "Air Slash");
// 		move->movePow = 75;
// 		move->moveAcc = 95;
// 		move->movePP = 15;
// 		move->moveEle = 'L';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "The user attacks with a blade of air that slices even the sky, 30% chance to cause flinching.");
// 		flinch = 30;
		
// 	}
// 	case 40:
// 	{
// 		ft_strcpy(move->moveName, "Amnesia");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 20;
// 		move->moveEle = 'P';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user temporarily empties its mind to forget its concerns, raises Sp. Def by 2 stages.");
// 		move->buff[0] = 5; move->buff[1] = 2; move->buff[2] = 100;
		
// 	}
// 	case 41:
// 	{
// 		ft_strcpy(move->moveName, "Aqua Jet");
// 		move->movePow = 40;
// 		move->moveAcc = 100;
// 		move->movePP = 20;
// 		move->moveEle = 'W';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user lunges at the target at a speed that makes it almost invisible, usually hits first");
// 		move->contact = 1;
// 		movePriority = 1;
		
// 	}
// 	case 42:
// 	{
// 		ft_strcpy(move->moveName, "Aqua Ring");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 20;
// 		move->moveEle = 'W';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user envelops itself in a veil made of water. It regains some 1/16th of its HP every turn.");
		
// 		//??? heals 1/16th health every turn until pokemon which used it swaps out, is passed with batton pass.
// 	}
// 	case 43:
// 	{
// 		ft_strcpy(move->moveName, "Aromatherapy");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 5;
// 		move->moveEle = 'M';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user releases a soothing scent. Clears all move->status conditions affecting the user's party.");
		
// 		//??? remove stat debuffs from entire ally team
// }
// 	case 44:
// 	{
// 		ft_strcpy(move->moveName, "Attack Order");
// 		move->movePow = 90;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'B';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user calls out its underlings to pummel the target. Has a high crit-ratio.");
// 		crit_ratio = 1;
		
// 	}
// 	case 45:
// 	{
// 		ft_strcpy(move->moveName, "Avalanche");
// 		move->movePow = 60;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'I';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The power of this attack move is doubled if the user has been hurt by the target in the same turn.");
// 		move->contact = 1;
// 		movePriority = -4;
		
// 		//??? Damage doubles if user hit on same turn prior to attack going through
// 	}
// 	case 46:
// 	{
// 		ft_strcpy(move->moveName, "Baton Pass");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 40;
// 		move->moveEle = 'N';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user switches places with a party Pokémon and passes along any stat changes.");
		
// 		//??? stat changes get swapped to the ally
// 	}
// 	case 49:
// 	{
// 		ft_strcpy(move->moveName, "Blizzard");
// 		move->movePow = 110;
// 		move->moveAcc = 70;
// 		move->movePP = 5;
// 		move->moveEle = 'I';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "A howling blizzard is summoned to strike opposing Pokémon, has a 10% chance to freeze. Always hits in hail");
// 		move->status[0] = 5; move->status[1] = 10; //Freeze 10%
		
// 		//??? accuracy = 0 in hail
// 	}
// case 51:
// 	{
// 		ft_strcpy(move->moveName, "Brick Break");
// 		move->movePow = 75;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'T';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user attacks with a swift chop destroying barriers, such as Light Screen and Reflect.");
// 		move->contact = 1;
		
// 		//??? destroys light screen and reflect

// 	}
// 	case 52:
// 	{
// 		ft_strcpy(move->moveName, "Bug Buzz");
// 		move->movePow = 90;
// 		move->moveAcc = 100;
// 		move->movePP = 10;
// 		move->moveEle = 'B';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "The user generates a damaging sound wave by vibration. 10% chance to lower Sp. Def of enemy by 1 stage.");
// 		move->deBuff[0] = 4; move->deBuff[1] = 1; move->deBuff[2] = 10; //Special Defense, 1 stage, 10%
		
// 	}
// 	case 53:
// 	{
// 		ft_strcpy(move->moveName, "Bulk Up");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 20;
// 		move->moveEle = 'T';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user tenses its muscles to bulk up its body, raises both Attack and Defense by 1 stage.");
// 		move->buff[0] = 1; move->buff[1] = 1; move->buff[2] = 100; //Attack, 1 stage, 100%
// 		move->buff2[0] = 2; move->buff2[1] = 1; move->buff2[2] = 100; //Defense, 1 stage, 100%
		
// 	}
// 	case 54:
// 	{
// 		ft_strcpy(move->moveName, "Bullet Seed");
// 		move->movePow = 25;
// 		move->moveAcc = 100;
// 		move->movePP = 30;
// 		move->moveEle = 'M';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user forcefully shoots seeds at the target. Two to five seeds are shot in rapid succession.");
// 		numHits[0] = 2; numHits[1] = 5;
		
// 	}
// 	case 55:
// 	{
// 		ft_strcpy(move->moveName, "Calm Mind");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 20;
// 		move->moveEle = 'P';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user quietly focuses its mind and calms its spirit, raising Sp. Atk and Sp. Def by 1 stage.");
// 		move->buff[0] = 3; move->buff[1] = 1; move->buff[2] = 100; //Special Attack, 1 stage, 100%
// 		move->buff2[0] = 4; move->buff2[1] = 1; move->buff[2] = 100; //Special Defense, 1 stage, 100%
		
// 	}
// 	case 56:
// 	{
// 		ft_strcpy(move->moveName, "Close Combat");
// 		move->movePow = 120;
// 		move->moveAcc = 100;
// 		move->movePP = 5;
// 		move->moveEle = 'T';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user fights the target up close without guarding itself. Lowers the user's Defense and Sp. Def by 1 stage.");
// 		move->buff[0] = 2; move->buff[1] = -1; move->buff[2] = 100; //Defense, -1 stage, 100%
// 		move->buff2[0] = 4; move->buff[1] = -1; move->buff[2] = 100; //Special Defense, -1 stage, 100%
		
// 	}
// 	case 57:
// 	{
// 		ft_strcpy(move->moveName, "Crabhammer");
// 		move->movePow = 100;
// 		move->moveAcc = 90;
// 		move->movePP = 10;
// 		move->moveEle = 'W';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The target is hammered with a large pincer. Has a high crit-ratio.");
// 		move->contact = 1;
// 		crit_ratio = 1;
		
// 	}
// 	case 58:
// 	{
// 		ft_strcpy(move->moveName, "Cross Posison");
// 		move->movePow = 70;
// 		move->moveAcc = 100;
// 		move->movePP = 20;
// 		move->moveEle = 'X';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "A slashing attack with a poisonous blade, has a 10% to cause poison. Has a high crit-ratio.");
// 		move->contact = 1;
// 		crit_ratio = 1;
// 		move->status[0] = 4; move->status[1] = 10; //Poison, 10%
		
// // 	}

// case 60:
// 	{
// 		ft_strcpy(move->moveName, "Dark Pulse");
// 		move->movePow = 80;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'D';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user releases a horrible aura imbued with dark thoughts. 20% chance to cause flinching.");
// 		flinch = 20;
		

// 	}
// 	case 61:
// 	{
// 		ft_strcpy(move->moveName, "Dazzling Gleam");
// 		move->movePow = 80;
// 		move->moveAcc = 100;
// 		move->movePP = 10;
// 		move->moveEle = 'F';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "The user damages opposing Pokémon by emitting a powerful flash.");
		

// 	}
// 	case 62:
// 	{
// 		ft_strcpy(move->moveName, "Defog");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 15;
// 		move->moveEle = 'L';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "A strong wind blows away the all barriers and hazards. This also lowers the target's evasiveness.");
		
// 		//??? removes hazards and barriers
// 	}
// case 64:
// {
// 	ft_strcpy(move->moveName, "Dragon Pulse");
// 	move->movePow = 85;
// 	move->moveAcc = 100;
// 	move->movePP = 10;
// 	move->moveEle = 'A';
// 	move->moveType = 'S';
// 	ft_strcpy(move->moveDescript, "The target is attacked with a shock wave generated by the user's gaping mouth.");

// }
// case 65:
// {
// 	ft_strcpy(move->moveName, "Drain Punch");
// 	move->movePow = 75;
// 	move->moveAcc = 100;
// 	move->movePP = 10;
// 	move->moveEle = 'T';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "An energy-draining punch. Users absorbs 50% damage as HP.");
// 	move->contact = 1;
// 	drain = 50;

// }
// case 66:
// {
// 	ft_strcpy(move->moveName, "Earth Power");
// 	move->movePow = 90;
// 	move->moveAcc = 100;
// 	move->movePP = 10;
// 	move->moveEle = 'G';
// 	move->moveType = 'S';
// 	ft_strcpy(move->moveDescript, "The user makes the ground under the target erupt with power. 10% chance to lower Sp. Def of enemy by 1 stage.");
// 	move->deBuff[0] = 4; move->deBuff[1] = 1; move->deBuff[2] = 10; //Sp. Def, 1 stage, 10%

// }
// case 67:
// {
// 	ft_strcpy(move->moveName, "Energy Ball");
// 	move->movePow = 90;
// 	move->moveAcc = 100;
// 	move->movePP = 10;
// 	move->moveEle = 'M';
// 	move->moveType = 'S';
// 	ft_strcpy(move->moveDescript, "The user draws power from nature and fires it at the target. 10% chance to lower Sp. Def of enemy by 1 stage.");
// 	move->deBuff[0] = 4; move->deBuff[1] = 1; move->deBuff[2] = 10; //Sp. Def, 1 stage, 10%

// }
// case 68:
// {
// 	ft_strcpy(move->moveName, "Explosion");
// 	move->movePow = 250;
// 	move->moveAcc = 100;
// 	move->movePP = 5;
// 	move->moveEle = 'N';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The user attacks everything around it by causing a tremendous explosion. The user faints upon using this move.");
// 	heal = -100;

// }
// case 69:
// {
// 	ft_strcpy(move->moveName, "Extreme Speed");
// 	move->movePow = 80;
// 	move->moveAcc = 100;
// 	move->movePP = 5;
// 	move->moveEle = 'N';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The user charges the target at blinding speed. This move always hits first.");
// 	move->contact = 1;
// 	movePriority = 2;

// }
// case 70:
// {
// 	ft_strcpy(move->moveName, "Facade");
// 	move->movePow = 70;
// 	move->moveAcc = 100;
// 	move->movePP = 20;
// 	move->moveEle = 'N';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "This attack move doubles its power if the user is poisoned, burned, or paralyzed.");
// 	move->contact = 1;

// 	//??? double power if user is poisoned burned or paralyzed
// }
// case 71:
// {
// 	ft_strcpy(move->moveName, "Fake Out");
// 	move->movePow = 40;
// 	move->moveAcc = 100;
// 	move->movePP = 10;
// 	move->moveEle = 'N';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "Hits first and makes the target flinch. It only works the first turn each time the user enters battle.");
// 	move->contact = 1;
// 	flinch = 100;

// 	//??? only works on first turn of user
// }
// case 72:
// {
// 	ft_strcpy(move->moveName, "Fire Blast");
// 	move->movePow = 110;
// 	move->moveAcc = 85;
// 	move->movePP = 5;
// 	move->moveEle = 'Q';
// 	move->moveType = 'S';
// 	ft_strcpy(move->moveDescript, "The target is attacked with an intense blast of all-consuming fire, has a 30% chance to cause burn.");
// 	move->status[0] = 3; move->status[1] = 30; //Burn, 30%

// }
// case 73:
// {
// 	ft_strcpy(move->moveName, "Fire Fang");
// 	move->movePow = 65;
// 	move->moveAcc = 95;
// 	move->movePP = 15;
// 	move->moveEle = 'Q';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The user bites with flame-cloaked fangs, has a 10% chance cause flinching and 10% chance to cause burn.");
// 	move->contact = 1;
// 	move->status[0] = 3; move->status[1] = 10; //Burn, 10%
// 	flinch = 10;

// }
// case 74:
// {
// 	ft_strcpy(move->moveName, "Fire Punch");
// 	move->movePow = 75;
// 	move->moveAcc = 100;
// 	move->movePP = 15;
// 	move->moveEle = 'Q';
// 	move->moveType = "Phsical");
// 	ft_strcpy(move->moveDescript, "The target is punched with a fiery fist, has a 10% chance to cause burn.");
// 	move->contact = 1;
// 	move->status[0] = 3; move->status[1] = 10; //Burn, 10%

// }

// case 76:
// 	{
// 		ft_strcpy(move->moveName, "Flash Cannon");
// 		move->movePow = 80;
// 		move->moveAcc = 100;
// 		move->movePP = 10;
// 		move->moveEle = 'S';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "The user gathers all its light energy and releases it all at once. 10% chance to lower Sp. Def of enemy by 1 stage.");
// 		move->deBuff[0] = 4; move->deBuff[1] = 1; move->deBuff[2] = 10; //Sp. Def, 1 stage, 10%
		
// 	}
// 	case 79:
// 	{
// 		ft_strcpy(move->moveName, "Fling");
// 		move->movePow = 30; //Every mon that has fling holds a flame orb so i just hard coded that shit :^)
// 		move->moveAcc = 100;
// 		move->movePP = 10;
// 		move->moveEle = 'D';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user flings its held item at the target to attack. This move's power and effects depend on the item.");
// 		move->status[0] = 3; move->status[1] = 100; //Burn, 100%
		
// 		//??? can only be used if user is holding an item, item is removed after used for the first time
// 	}
// 	case 80:
// 	{
// 		ft_strcpy(move->moveName, "Foul Play");
// 		move->movePow = 95;
// 		move->moveAcc = 100;
// 		move->movePP = 15;
// 		move->moveEle = 'D';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user turns the target's power against it. The higher the target's Attack stat, the greater the damage it deals.");
// 		move->contact = 1;
		
// 		//??? during damage calculations use targets attack stat.
// 	}
// 	case 81:
// 	{
// 		ft_strcpy(move->moveName, "Freeze-Dry");
// 		move->movePow = 70;
// 		move->moveAcc = 100;
// 		move->movePP = 20;
// 		move->moveEle = 'I';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "The user rapidly cools the target, has 10% chance to Freeze. This move is super effective on Water types");
// 		move->status[0] = 5; move->status[1] = 10; //Freeze 10%
		
// 		//??? treated as supereffective against water type pokemon.
// 	}
// 	case 82:
// 	{
// 		ft_strcpy(move->moveName, "Gunk Shot");
// 		move->movePow = 120;
// 		move->moveAcc = 80;
// 		move->movePP = 5;
// 		move->moveEle = 'X';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user shoots filthy garbage at the target to attack, has 30% chance to cause poison");
// 		move->status[0] = 4; move->status[1] = 10; //Poison 30%
		
// 	}
// 	case 83:
// 	{
// 		ft_strcpy(move->moveName, "Gyro Ball");
// 		move->movePow = 0;
// 		move->moveAcc = 100;
// 		move->movePP = 5;
// 		move->moveEle = 'S';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user tackles the target with a high-speed spin. The slower the user compared to the target, the greater the move's power.");
// 		move->contact = 1;
		
// 		//??? uses thisformula for power calculation:   Base Power = 25 * (TargetSpeed / UserSpeed)
// 	}
// 	case 84:
// 	{
// 		ft_strcpy(move->moveName, "Hammer Arm");
// 		move->movePow = 100;
// 		move->moveAcc = 90;
// 		move->movePP = 10;
// 		move->moveEle = 'T';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The user swings and hits with its strong, heavy fist. Lowers the user's Speed by 1 stage");
// 		move->contact = 1;
// 		move->buff[0] = 5; move->buff[1] = -1; move->buff[2] = 100; //Speed, -1 stage, 100%
		
// 	}
// 	case 85:
// 	{
// 		ft_strcpy(move->moveName, "Haze");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 30;
// 		move->moveEle = 'I';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user creates a haze that eliminates the stat changes of all the Pokémon in battle.");
		
// 		//??? reset all stat changes of current pokemon to 0;
// 	}
// 	case 86:
// 	{
// 		ft_strcpy(move->moveName, "Heal Bell");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 5;
// 		move->moveEle = 'N';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user makes a soothing bell chime to heal the move->status conditions of all the party Pokémon.");
		
// 		//??? literally the exact same as aromatherapy
// 	}
// 	case 87:
// 	{
// 		ft_strcpy(move->moveName, "Heal Order");
// 		move->movePow = 0;
// 		move->moveAcc = 0;
// 		move->movePP = 10;
// 		move->moveEle = 'B';
// 		move->moveType = 'T';
// 		ft_strcpy(move->moveDescript, "The user calls out its underlings to heal it. Restores 50% of the user's max HP.");
// 		heal = 50;
		
// 	}
// 	case 88:
// 	{
// 		ft_strcpy(move->moveName, "Iron Tail");
// 		move->movePow = 100;
// 		move->moveAcc = 75;
// 		move->movePP = 15;
// 		move->moveEle = 'S';
// 		move->moveType = 'P';
// 		ft_strcpy(move->moveDescript, "The target is slammed with a steel-hard tail, has 30% chance to lower target's Defense by 1 stage.");
// 		move->contact = 1;
// 		move->deBuff[0] = 2; move->deBuff[1] = 1; move->deBuff[2] = 30; //Defense, 1 stage, 30%
		
// 	}
// 	case 89:
// 	{
// 		ft_strcpy(move->moveName, "Hex");
// 		move->movePow = 65;
// 		move->moveAcc = 100;
// 		move->movePP = 10;
// 		move->moveEle = 'H';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "This relentless attack has double power against targets affected by move->status conditions.");
		
// 		//??? power is doubled to 130 if targeting target with burn/poison/paralyze/freeze/sleep
// 	}
// 	case 90:
// 	{
// 		ft_strcpy(move->moveName, "Hydro Pump");
// 		move->movePow = 110;
// 		move->moveAcc = 80;
// 		move->movePP = 5;
// 		move->moveEle = 'W';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "The target is blasted by a huge volume of water launched under great pressure.");
		
// 	}
// 	case 91:
// 	{
// 		ft_strcpy(move->moveName, "Hyper Voice");
// 		move->movePow = 90;
// 		move->moveAcc = 100;
// 		move->movePP = 10;
// 		move->moveEle = 'N';
// 		move->moveType = 'S';
// 		ft_strcpy(move->moveDescript, "The user lets loose a horribly echoing shout with the power to inflict damage.");
		
// 	}
// case 93:
// {
// 	ft_strcpy(move->moveName, "Ice Punch");
// 	move->movePow = 75;
// 	move->moveAcc = 100;
// 	move->movePP = 15;
// 	move->moveEle = 'I';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The target is punched with a icy fist, has a 10% chance to cause freeze.");
// 	move->contact = 1;
// 	move->status[0] = 5; move->status[1] = 10; //Freeze, 10%
	
// }
// case 94:
// {
// 	ft_strcpy(move->moveName, "Icicle Crash");
// 	move->movePow = 85;
// 	move->moveAcc = 90;
// 	move->movePP = 10;
// 	move->moveEle = 'I';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The user attacks by harshly dropping large icicles onto the target, has a 30% chance to cause flinching.");
// 	flinch = 30;
	
// }
// case 96:
// {
// 	ft_strcpy(move->moveName, "Knock Off");
// 	move->movePow = 65;
// 	move->moveAcc = 100;
// 	move->movePP = 20;
// 	move->moveEle = 'D';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The user slaps down the target's held item, preventing that item from being used in the battle.");
// 	move->contact = 1;
	
// 	//??? removes target's held item for the rest of the battle
// }
// case 97:
// {
// 	ft_strcpy(move->moveName, "Lava Plume");
// 	move->movePow = 80;
// 	move->moveAcc = 100;
// 	move->movePP = 15;
// 	move->moveEle = 'Q';
// 	move->moveType = 'S';
// 	ft_strcpy(move->moveDescript, "The user torches everything around it in an inferno of scarlet flames. has a 30% chance to cause burn.");
// 	move->status[0] = 3; move->status[1] = 30; //Burn, 30%
	
// }
// case 98:
// {
// 	ft_strcpy(move->moveName, "Leaf Blade");
// 	move->movePow = 90;
// 	move->moveAcc = 100;
// 	move->movePP = 15;
// 	move->moveEle = 'M';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The foe is slashed with a sharp leaf. Has a high crit-ratio.");
// 	move->contact = 1;
// 	crit_ratio = 1;
	
// }
// case 99:
// {
// 	ft_strcpy(move->moveName, "Leech Life");
// 	move->movePow = 80;
// 	move->moveAcc = 100;
// 	move->movePP = 10;
// 	move->moveEle = 'B';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "The user drains the target's blood. Users absorbs 50% damage as HP.");
// 	move->contact = 1;
// 	drain = 50;
	
// }
// case 100:
// {
// 	ft_strcpy(move->moveName, "Leech Seed");
// 	move->movePow = 0;
// 	move->moveAcc = 90;
// 	move->movePP = 10;
// 	move->moveEle = 'M';
// 	move->moveType = 'T';
// 	ft_strcpy(move->moveDescript, "A seed is planted on the target which drains 1/16th of the targets HP every turn.");
// 	//??? the same as aqua ring but also damages opponent for the same amount
	
// }
// case 101:
// {
// 	ft_strcpy(move->moveName, "Nuzzle");
// 	move->movePow = 20;
// 	move->moveAcc = 100;
// 	move->movePP = 20;
// 	move->moveEle = 'E';
// 	move->moveType = 'P';
// 	ft_strcpy(move->moveDescript, "User nuzzle up to the enemy with its Electrified Check, paralyzing them.");
// 	move->contact = 1;
// 	move->status[0] = 1;
// 	move->status[1] = 100;
	
// }

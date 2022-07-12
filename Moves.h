#ifndef MOVES
#define MOVES

typedef struct s_Moves
{
    char	moveName[26];
    int		movePow;    //stores the power of the move
    int		moveAcc;    //stores the accuracy of the move
    int		movePP;     //stores the current remaining PP of a move
    int		or_movePP;  //stores how many times a move can be used
    char	moveEle;     //stores the moves elemental type
    char	moveType;    //Physical (P), Special (S), Status (T)
    int		movePriority;   //stores whether a move has priority
    char	moveDescript[160];    //stores the moves description
    int		contact;    //whether the move makes contact
    int		crit_ratio;     //if a move has a high crit ration 0/1
    int		numHits[2];     //0 element = minimum hits, 1 element = maximum hits
    int		flinch; // percent chance to cause flinch
    int		cooldown; //-1 means wait 1 turn before attack, 1 means wait 1 turn after attack

    //buffs/debuffs element 0 = buff type, element 1 = buff amount, element 2 = chance to occur
    int		buff[3];  /// 1 = ATK, 2 = DEF, 3 = SP.ATK, 4 = SP.DEF, 5 = SPD, 6 = ACC, 69 = ancient power
    int		buff2[3];
    int		buff3[3];
    int		deBuff[3]; //if debuff element 1 is negative ==> actually buffs the opponent stats
    int		confuse[2];
    //first element = type of status, second element = chance to occur
    int		status[2];  //0= no status, 1= paralyze, 2= sleep, 3 = burn, 4 = poison, 5 = freeze, 6 = badly poison
    int		recoil[2]; //element 0 = yes or no, element 1 = recoil %

    //stuff that max has added
    int		drain; //moves that drain % of damage done, just store % in variable
    int		heal; //percentage that the move heals the user (% of health healed);
}	t_Moves;

void	ft_strcpy(char *dest, char *input);
char	ft_strcmp(char *first, char *second);
void	ft_initialize_move(t_Moves *move, int num);

/*					Move Function Sorting Sets:				*/
void	ft_move_set_1(t_Moves *move, int num);
void	ft_move_set_2(t_Moves *move, int num);
void	ft_move_set_3(t_Moves *move, int num);
void	ft_move_set_4(t_Moves *move, int num);

/*					MOVES LIST:								*/
void	ft_phantom_force(t_Moves *move);
void	ft_x_scissor(t_Moves *move);
void	ft_shadow_ball(t_Moves *move);
void	ft_hone_claws(t_Moves *move);
void	ft_thunderbolt(t_Moves *move);
void	ft_nasty_plot(t_Moves *move);
void	ft_focus_blast(t_Moves *move);
void	ft_dig(t_Moves *move);
void	ft_dragon_dance(t_Moves *move);
void	ft_earthquake(t_Moves *move);
void	ft_brine(t_Moves *move);
void	ft_ice_beam(t_Moves *move);
void	ft_meteor_mash(t_Moves *move);
void	ft_psychic(t_Moves *move);
void	ft_giga_impact(t_Moves *move);
void	ft_steel_wing(t_Moves *move);
void	ft_aerial_ace(t_Moves *move);
void	ft_light_screen(t_Moves *move);
void	ft_ancient_power(t_Moves *move);
void	ft_reflect(t_Moves *move);
void	ft_curse(t_Moves *move);
void	ft_head_smash(t_Moves *move);
void	ft_aqua_tail(t_Moves *move);
void	ft_confuse_ray(t_Moves *move);
void	ft_sludge_bomb(t_Moves *move);
void	ft_giga_drain(t_Moves *move);
void	ft_slash(t_Moves *move);
void	ft_water_pulse(t_Moves *move);
void	ft_brave_bird(t_Moves *move);
void	ft_crunch(t_Moves *move);
void	ft_destiny_bond(t_Moves *move);
void	ft_flamethrower(t_Moves *move);
void	ft_ice_fang(t_Moves *move);
void	ft_iron_head(t_Moves *move);
void	ft_fishious_rend(t_Moves *move);
void	ft_blast_burn(t_Moves *move);
void	ft_roost(t_Moves *move);
void	ft_return(t_Moves *move);
void	ft_sleep_talk(t_Moves *move);
void	ft_surf(t_Moves *move);
void	ft_protect(t_Moves *move);
void	ft_outrage(t_Moves *move);
void	ft_soft_boiled(t_Moves *move);
void	ft_drill_peck(t_Moves *move);
void	ft_rock_slide(t_Moves *move);

#endif

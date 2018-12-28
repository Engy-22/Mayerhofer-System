#ifndef GAME_H
#define GAME_H
#include "Team.h"
class Game
{
public:
	Game(Team* win, Team* lose, int win_score, int lose_score);
	Team* get_winner();
	Team* get_loser();
	int get_winner_score();
	int get_loser_score();
private:
	Team* winner;
	Team* loser;
	int winner_score;
	int loser_score;
};

#endif

#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <iostream>
#include <vector>
class Game;

class Team
{
public:
	Team(std::string team_name, char conf_type);
	void play_game(Game* game);
	std::string get_name();
	char get_conf_type();
	int get_num_wins();
	int get_num_losses();
	double get_win_percentage();
	double calculate_ranking_points(); // Algorithm for ranking teams
	void print();
private:
	std::vector<Game*> games;
	std::string name;
	char conf;  // P for P5, G for G5, F for FCS
	int wins;
	int losses;
	int ranking_points;

	// Helper methods for ranking algorithm below
	double ranking_points_for_game(Game* game);
	int convert_win_pct_to_ranking_points_for_win(double win_pct, char opp_conf_type);
	int convert_win_pct_to_ranking_points_for_loss(double win_pct, char opp_conf_type);
	double add_rank_points_for_score_margin(double r_points, int winner_score, int loser_score);
};

#endif
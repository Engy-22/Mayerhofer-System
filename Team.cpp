#include "Team.h"
#include "Game.h"
#include <iomanip>

Team::Team(std::string team_name, char conf_type) : name(team_name), conf(conf_type), wins(0), losses(0), ranking_points(0) {

}

void Team::play_game(Game* game) {
	games.push_back(game);

	if (game->get_winner()->get_name() == name) {
		wins++;
	}
	else {
		losses++;
	}
}

std::string Team::get_name() {
	return name;
}

char Team::get_conf_type() {
	return conf;
}

int Team::get_num_wins() {
	return wins;
}

int Team::get_num_losses() {
	return losses;
}

double Team::get_win_percentage() {
	double win_pct = static_cast<double>(wins) / (wins + losses);
	return win_pct;
}

double Team::calculate_ranking_points() {
	double ranking_points = 0;
	for (Game* game_ptr : games) {
		ranking_points += ranking_points_for_game(game_ptr);
	}
	ranking_points = ranking_points / (wins + losses);  // FIXME: adjust for games played
	ranking_points *= 10;  // FIXME: just to look nice when adjusting for games played
	return ranking_points;
}

void Team::print() {
	std::cout << name << ": " << wins << "-" << losses << " (" << get_win_percentage() << ")" << " (" << calculate_ranking_points() << ")";
}

double Team::ranking_points_for_game(Game* game) {
	double r_points = 0;
	if (game->get_winner()->get_name() == name) {  // if team is the winner
		r_points += static_cast<double>(convert_win_pct_to_ranking_points_for_win(game->get_loser()->get_win_percentage(), game->get_loser()->get_conf_type()));
	}
	else {  // if team is the loser
		r_points += static_cast<double>(convert_win_pct_to_ranking_points_for_loss(game->get_winner()->get_win_percentage(), game->get_winner()->get_conf_type()));
	}

	r_points += add_rank_points_for_score_margin(r_points, game->get_winner_score(), game->get_loser_score());
	return r_points;


}

int Team::convert_win_pct_to_ranking_points_for_win(double win_pct, char opp_conf_type) {
	if ((opp_conf_type == 'F') || 
		(opp_conf_type == 'G' && win_pct <= .4)) {
		return 1;
	}
	else if ((opp_conf_type == 'G' && win_pct > .4 && win_pct <= .6) || 
		(opp_conf_type == 'P' && win_pct < .4)) {
		return 2;
	}
	else if (opp_conf_type == 'P' && win_pct >= .4 && win_pct < .5) {
		return 3;
	}
	else if ((opp_conf_type == 'G' && win_pct > .6 && win_pct <= .75) || 
		(opp_conf_type == 'P' && win_pct >= .5 && win_pct < .6)) {
		return 4;
	}
	else if ((opp_conf_type == 'G' && win_pct > .75 && win_pct < .834) ||
		(opp_conf_type == 'P' && win_pct >= .6 && win_pct < .667)) {
		return 5;
	}
	else if ((opp_conf_type == 'G' && win_pct >= .834 && win_pct <= .916) || 
		(opp_conf_type == 'P' && win_pct >= .667 && win_pct <= .75)) {
		return 6;
	}
	else if ((opp_conf_type == 'G' && win_pct > .916) || 
		(opp_conf_type == 'P' && win_pct > .75 && win_pct < .917)) {
		return 7;
	}
	else if (opp_conf_type == 'P' && win_pct >= .917) {
		return 8;
	}
	else {
		std::cerr << "Error: in convert_win_pct_to_ranking_points_for_win in Team.cpp, function did not return properly" << std::endl;
		exit(1);
	}
}

int Team::convert_win_pct_to_ranking_points_for_loss(double win_pct, char opp_conf_type) {
	return convert_win_pct_to_ranking_points_for_win(win_pct, opp_conf_type) - 9;
}

double Team::add_rank_points_for_score_margin(double r_points, int winner_score, int loser_score) {
	if ((winner_score - loser_score) > 60)  // changed from 30 to 60
		r_points += r_points * 1;  // changed from 0.25 to 1
	else
		r_points += r_points * 1 * static_cast<double>(winner_score - loser_score) / 60.0; // changed to 1 and 60
	return r_points;
}

#ifndef SEASON_H
#define SEASON_H
#include "Team.h"
#include <string>
#include <map>

class Season
{
public:
	Season(std::string team_file, std::string scores_file);
	~Season();
	void print_FBS_teams_alphabetical_order();
	void print_mayerhofer_rankings();
	void predict_games(std::string future_games_file);
	void check_prediction_accuracy(std::string results_file);

private:
	std::map<std::string, Team*> teams;  // key: team name, value: team object pointer
	std::vector<Game*> games;
	std::vector<Team*> mayerhofer_rankings;

	void read_teams(std::string file_name);
	void read_scores(std::string file_name);
	std::string get_team_name(const std::string& line);
	char get_conf_type(const std::string& line);
	void open_file(std::ifstream& file, std::string file_name);
	void create_game(std::istringstream& stream, std::string token, char delimiter);
	void read_game(std::string& winner_name, int& winner_score, std::string& loser_name, int& loser_score, std::istringstream& stream, std::string token, char delimiter);
	std::string read_team_name_from_scores_file(const std::string& token);
	void throw_file_error(std::string file_name);
	void throw_conf_type_error(char conf_type);

	void generate_mayerhofer_rankings();  // uses the mayerhofer algorithm
};

bool mayerhofer_comparison(Team* lhs, Team* rhs);  // sorts the mayerhofer_rankings

#endif
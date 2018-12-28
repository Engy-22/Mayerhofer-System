#include "Season.h"
#include "Game.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>


Season::Season(std::string team_file, std::string scores_file)
{
	read_teams(team_file);
	read_scores(scores_file);
}

void Season::print_FBS_teams_alphabetical_order() {
	for (auto const& team : teams) {
		if (team.second->get_conf_type() != 'F') {
			team.second->print();
			std::cout << std::endl;
		}
	}
}

void Season::print_mayerhofer_rankings() {
	generate_mayerhofer_rankings();

	for (unsigned int i = 0; i < mayerhofer_rankings.size(); i++) {
		std::cout << i + 1 << ". ";
		mayerhofer_rankings.at(mayerhofer_rankings.size() - i - 1)->print();
		std::cout << std::endl;
	}
}

void Season::read_teams(std::string file_name) {
	std::ifstream file;
	std::string line;
	std::string team_name;
	char conf_type;

	open_file(file, file_name);

	while (getline(file, line)) {
		team_name = get_team_name(line);
		conf_type = get_conf_type(line);
		teams.insert(std::pair<std::string, Team*>(team_name, new Team(team_name, conf_type)));
	}

	file.close();

}

void Season::read_scores(std::string file_name) {
	std::ifstream file;
	std::string line;

	open_file(file, file_name);

	while (getline(file, line)) {
		std::istringstream line_stream(line);
		std::string token;
		int i = 0;  // i refers to the index of the token on each line (separated by commas)
		while(getline(line_stream, token, ',')) {
			if (i == 5) {  // reached the winning team name token
				create_game(line_stream, token, ',');
				break;
			}
			
			i++;
		}
	}

	file.close();
}

std::string Season::get_team_name(const std::string& line) {
	std::string team_name = line.substr(0, line.find(","));
	return team_name;
}

char Season::get_conf_type(const std::string& line) {
	char conf_type = line.at(line.find(",") + 1);
	if (conf_type != 'P' && conf_type != 'G' && conf_type != 'F') {
		throw_conf_type_error(conf_type);
	}
	return conf_type;
}

void Season::open_file(std::ifstream& file, std::string file_name) {
	file.open(file_name);
	if (!file.is_open()) {
		throw_file_error();
	}
}

void Season::create_game(std::istringstream& stream, std::string token, char delimiter) {
	std::string winner_name = read_team_name_from_scores_file(token);
	getline(stream, token, delimiter);  // get winning score
	int winner_score = std::stoi(token);
	getline(stream, token, delimiter);  // filter out next token
	getline(stream, token, delimiter);  // get losing team name
	std::string loser_name = read_team_name_from_scores_file(token);
	getline(stream, token, delimiter);  // get losing team score
	int loser_score = std::stoi(token);

	Team* winning_team = teams.at(winner_name);
	Team* losing_team = teams.at(loser_name);
	Game* game = new Game(winning_team, losing_team, winner_score, loser_score);
	
	winning_team->play_game(game);
	losing_team->play_game(game);

}

std::string Season::read_team_name_from_scores_file(const std::string& token) {
	if (token[0] == '(') {
		return token.substr(token.find(")") + 2);
	}
	return token;
}

void Season::throw_file_error() {
	std::cerr << "Error: could not load teams file" << std::endl;
	exit(1);
}

void Season::throw_conf_type_error(char conf_type) {
	std::cerr << "Error in teams file: Expected P, G or F but got " << "'" << conf_type << "'" << std::endl;
	exit(1);
}

void Season::generate_mayerhofer_rankings() {
	// clear out ranking vector is empty
	while (mayerhofer_rankings.size() != 0) {
		mayerhofer_rankings.pop_back();
	}
	for (auto const& pair : teams) {  // pair.second is the Team* because pair is <string, Team*>
		if (pair.second->get_conf_type() != 'F') {
			pair.second->calculate_ranking_points();
			mayerhofer_rankings.push_back(pair.second);
		}
	}
	std::sort(mayerhofer_rankings.begin(), mayerhofer_rankings.end(), mayerhofer_comparison);
}

bool mayerhofer_comparison(Team* lhs, Team* rhs) {
	return (lhs->calculate_ranking_points() < rhs->calculate_ranking_points());
}

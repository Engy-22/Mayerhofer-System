#include <iostream>
#include <set>
#include "Season.h"

void check_argc(int argc) {
	// program must have 3 or 5 arguments
	if (argc != 3 && argc != 5) {
		std::cerr << "Usage:" << std::endl;
		std::cerr << "Output rankings: ./mayerhofer_rankings <team_file> <scores_file>" << std::endl;
		std::cerr << "Predict games: ./mayerhofer_rankings <team_file> <scores_file> <predictions_file> P" << std::endl;
		std::cerr << "Check prediction success: ./mayerhofer_rankings <team_file> <scores_file> <predictions_file> R" << std::endl;
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	check_argc(argc);
	Season season(argv[1], argv[2]);
	if (argc == 3) season.print_mayerhofer_rankings();
	else if (argc == 5) {
		if (argv[4][0] == 'P') season.predict_games(argv[3]);
		else if (argv[4][0] == 'R') season.check_prediction_accuracy(argv[3]);
	}
	return 0;
}

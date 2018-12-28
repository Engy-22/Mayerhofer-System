#include <iostream>
#include <set>
#include "Season.h"

void check_argc(int argc) {
	if (argc != 3) {
		std::cerr << "Usage: ./rankings <team_file> <scores_file>" << std::endl;
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	check_argc(argc);
	Season season(argv[1], argv[2]);
	season.print_mayerhofer_rankings();
	return 0;
}

#include "Game.h"

Game::Game(Team* win, Team* lose, int win_score, int lose_score) : winner(win), loser(lose), winner_score(win_score), loser_score(lose_score) {

}

Team* Game::get_winner() {
	return winner;
}

Team* Game::get_loser() {
	return loser;
}

int Game::get_winner_score() {
	return winner_score;
}

int Game::get_loser_score() {
	return loser_score;
}
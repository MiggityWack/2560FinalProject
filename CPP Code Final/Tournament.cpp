//Tournament.cpp
#include "Tournament.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

Tournament::Player::Player(std::string tag, int score, int gamesPlayed)
    : tag(std::move(tag)), score(score), gamesPlayed(gamesPlayed) {}

std::string Tournament::Player::get_tag() const { return tag; }
int Tournament::Player::get_score() const { return score; }
int Tournament::Player::get_games_played() const { return gamesPlayed; }
void Tournament::Player::set_score(int scoreSet) { score = scoreSet; }
void Tournament::Player::add_win() { wins++; gamesPlayed++; }
void Tournament::Player::add_loss() { losses++; gamesPlayed++; }
void Tournament::Player::add_tie() { ties++; gamesPlayed++; }
std::string Tournament::Player::to_string() const {
    return tag + " " + std::to_string(score) + " " + std::to_string(gamesPlayed);
}
int Tournament::Player::get_wins() const { return wins; }

Tournament::Tournament() : playerCount(0), started(false), manuallySeeded(false) {}

Tournament::Player* Tournament::playerSearch(const std::string& tag) {
    for (auto& player : playerList) {
        if (player.get_tag() == tag) {
            return &player;
        }
    }
    return nullptr;
}

Tournament::Player* Tournament::searchPlayerCaseInsensitive(const std::string& tag) {
    std::string lowerTag = toLower(tag);
    for (auto& player : playerList) {
        if (toLower(player.get_tag()) == lowerTag) {
            return &player;
        }
    }
    return nullptr;
}

bool Tournament::checkForPlayers(const std::string& tag) {
    return playerSearch(tag) != nullptr;
}

void Tournament::addPlayerFromFile(const std::string& tag, int score, int gamesPlayed) {
    playerList.emplace_back(tag, score, gamesPlayed);
}

void Tournament::importPlayers(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file.\n";
        return;
    }

    std::string tag;
    int score, gamesPlayed;
    while (file >> tag >> score >> gamesPlayed) {
        addPlayerFromFile(tag, score, gamesPlayed);
        std::cout << "Loaded player: " << tag << " Score: " << score << " Games: " << gamesPlayed << std::endl; // Debug print
    }
}

void Tournament::savePlayers(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file.\n";
        return;
    }

    for (const auto& player : playerList) {
        file << player.to_string() << std::endl;
    }
}

void Tournament::sortPlayersByScore() {
    std::sort(playerList.begin(), playerList.end(), [](const Player& a, const Player& b) {
        return a.get_score() > b.get_score();
    });
}

void Tournament::reportMatch(Player* player1, Player* player2, int player1Wins, int player2Wins, bool disqual) {
    if (!player1 || !player2) {
        std::cout << "One or both players not found in the tournament.\n";
        return;
    }

    if (player1Wins > player2Wins) {
        player1->add_win();
        player2->add_loss();
        calibrate_score(*player1, *player2, player1Wins, player2Wins);
    } else if (player2Wins > player1Wins) {
        player2->add_win();
        player1->add_loss();
        calibrate_score(*player2, *player1, player2Wins, player1Wins);
    } else {
        player1->add_tie();
        player2->add_tie();
    }
}

void Tournament::calibrate_score(Player& winner, Player& loser, int winnerWins, int loserWins) {
    int scoreDiff = winner.get_score() - loser.get_score();
    int scoreShiftWinner = ((0.5 * scoreDiff) + 100) * std::pow(0.98, winner.get_games_played());
    int scoreShiftLoser = ((0.5 * scoreDiff) + 100) * std::pow(0.98, loser.get_games_played());

    winner.set_score(winner.get_score() + scoreShiftWinner);
    loser.set_score(loser.get_score() - scoreShiftLoser);
}





//Tournament.cpp
#include "tournamentClass.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "utils.h"
using namespace std;
Tournament::Player::Player(std::string tag, int score, int gamesPlayed)
    : tag(move(tag)), score(score), gamesPlayed(gamesPlayed) {}

string Tournament::Player::get_tag() const { return tag; }
int Tournament::Player::get_score() { return score; }
int Tournament::Player::get_games_played() { return gamesPlayed; }
void Tournament::Player::set_score(int scoreSet) { score = scoreSet; }
void Tournament::Player::add_win() { wins++; gamesPlayed++; }
void Tournament::Player::add_loss() { losses++; gamesPlayed++; }
void Tournament::Player::add_tie() { ties++; gamesPlayed++; }
const std::string Tournament::Player::stringify(){
    return tag + " " + to_string(score) + " " + to_string(gamesPlayed) + " ";
}
const std::string Tournament::Player::stringifyReport(){
    return tag + " has a score of " + to_string(score) + " with " + to_string(gamesPlayed) + " games played";
}
int Tournament::Player::get_wins() { return wins; }

Tournament::Tournament() : playerCount(0), started(false), manuallySeeded(false) {}

Tournament::Player* Tournament::playerSearch(const std::string& tag) {
    for (int i = 0; i<playerCount; i++) {
        if (playerList[i].get_tag() == tag) {
            return &playerList[i];
        }
    }
    return nullptr;
}

Tournament::Player* Tournament::searchPlayerCaseInsensitive(const std::string& tag) {
    string lowerTag = toLower(tag);
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

void Tournament::addPlayer(const std::string& tag, int score, int gamesPlayed) {
    playerList.emplace_back(tag, score, gamesPlayed);
    playerCount++;
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
        addPlayer(tag, score, gamesPlayed);
        std::cout << "Loaded player: " << tag << " Score: " << score << " Games: " << gamesPlayed << std::endl; // Debug print
    }
}

void Tournament::savePlayers(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file.\n";
        return;
    }

    for (int i = 0; i< playerCount; i++) {
        Player player = playerList[i];
        file << player.Tournament::Player::stringify() << std::endl;
    }
}

void Tournament::sortPlayersByScore() {
    std::sort(playerList.begin(), playerList.end(), [](Player& a, Player& b) {
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
        pair<int,int> result = calibrateScore(*player1, *player2, player2Wins, player1Wins);
        player1->set_score(result.first);
        player2->set_score(result.second);
    } else if (player2Wins > player1Wins) {
        player2->add_win();
        player1->add_loss();
        pair<int,int> result = calibrateScore(*player2, *player1, player2Wins, player1Wins);
        player2->set_score(result.first);
        player1->set_score(result.second);
    } else {
        player1->add_tie();
        player2->add_tie();
    }
}

pair<int,int> Tournament::calibrateScore(Player& winner, Player& loser, int winnerWins, int loserWins) {
    double scoreDenom = double(winner.get_score()) + double(loser.get_score());
    double odds = (double(winner.get_score())/scoreDenom)+0.0001;
    double scoreDiff = abs(double(winner.get_score()) - double(loser.get_score()));
    double scoreShiftWinner = double(abs(winnerWins-loserWins))*(scoreDiff+30)*(1-odds)*(1/(1+double(winner.get_games_played())));
    double scoreShiftLoser = double(abs(winnerWins-loserWins))*(scoreDiff+30)*(1-odds)*(1/(1+double(loser.get_games_played())));
    int winnerNew = winner.get_score() + int(scoreShiftWinner);
    int loserNew = loser.get_score() - int(scoreShiftLoser);
    pair<int, int> score;
    score.first=int(winnerNew);
    score.second=int(loserNew);
    return(score);
}

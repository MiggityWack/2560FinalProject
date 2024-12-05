//Tournament.h
#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
#include <vector>

class Tournament {
public:
    class Player {
    public:
        Player(std::string tag, int score, int gamesPlayed);
        std::string get_tag() const;
        int get_score() const;
        int get_games_played() const;
        void set_score(int scoreSet);
        void add_win();
        void add_loss();
        void add_tie();
        std::string to_string() const;
        int get_wins() const;

    private:
        std::string tag;
        int score;
        int gamesPlayed;
        int wins = 0;
        int losses = 0;
        int ties = 0;
    };

    Tournament();
    Player* playerSearch(const std::string& tag);
    Player* searchPlayerCaseInsensitive(const std::string& tag);
    bool checkForPlayers(const std::string& tag);
    void addPlayerFromFile(const std::string& tag, int score, int gamesPlayed);
    void importPlayers(const std::string& filename);
    void savePlayers(const std::string& filename);
    void sortPlayersByScore();
    void reportMatch(Player* player1, Player* player2, int player1Wins, int player2Wins, bool disqual);
    void calibrate_score(Player& winner, Player& loser, int winnerWins, int loserWins);

private:
    std::vector<Player> playerList;
    int playerCount;
    bool started;
    bool manuallySeeded;
};

#endif // TOURNAMENT_H






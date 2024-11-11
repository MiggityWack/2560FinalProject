#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "mainwindow.h"
#include <QApplication>
using namespace std;
class Tournament{
public:
    int playerCount;
    bool started;
    bool manuallySeeded;
    Tournament(){
        playerCount = 0;
        started = false;
        manuallySeeded = false;
    }
    class Player {
        string tag;
        int score;
        int gamesPlayed;
        int wins;
        int losses;
        int ties;

    public:
        Player(string tag) : tag(tag) {
            score = 1000;
            gamesPlayed = 0;
            wins = 0;
            losses = 0;
            ties = 0;
        }
        Player(string tag, int scoreHold) : tag(tag) {
            score = scoreHold;
            gamesPlayed = 0;
            wins = 0;
            losses = 0;
            ties = 0;
        }
        string get_record(){
            string record = to_string(wins) + "-" + to_string(losses) + "-" + to_string(ties);
            return(record);
        }
        string get_tag(){
            return(tag);
        }
        int get_score() {
            return(score);
        }
        void set_score(int scoreSet) {
            score = scoreSet;
        }
        int get_games_played(){
            return(gamesPlayed);
        }
        int get_wins() {
            return(wins);
        }
        void add_win() {
            wins++;
            gamesPlayed++;
        }
        int get_losses() {
            return(score);
        }
        void add_loss() {
            losses++;
            gamesPlayed++;
        }
        int get_ties() {
            return(score);
        }
        void add_tie() {
            score++;
            gamesPlayed++;
        }
    };
    vector<Player> playerList;
    Player playerSearch(string tag){
        for(int i = 0; i<playerCount; i++){
            if(playerList[i].get_tag() == tag){
                return playerList[i];
            }
        }
        return playerList[0];
    }
    void calibrate_score(Player winner, Player loser, int winnerWins, int loserWins){
        int scoreDiff = winner.get_score() - loser.get_score() + 100;
        int scoreShiftWinner = ((0.5*scoreDiff)+100)*pow(.98,winner.get_games_played());
        int scoreShiftLoser = ((0.5*scoreDiff)+100)*pow(.98,loser.get_games_played());
        winner.set_score(winner.get_score()+scoreShiftWinner);
        loser.set_score(loser.get_score()-scoreShiftLoser);
    }
    void addPlayer(string tag){
        Player newPlayer = Player(tag);
        playerList.push_back(newPlayer);
        playerCount++;
    }
    void addPlayerWithSkill(string tag, int score){
        Player newPlayer = Player(tag, score);
        playerList.push_back(newPlayer);
        playerCount++;
    }
    bool checkForPlayers(Player playerCheck){
        for(int i = 0; i<playerCount; i++){
            if(playerList[i].get_tag() == playerCheck.get_tag()){
                return true;
            }
        }
        return false;
    }
    void reportMatch(Player player1, Player player2, int player1Wins, int player2Wins, bool disqual){
        if(disqual){
            if(player1Wins > player2Wins){
                player1.add_win();
                player2.add_loss();
            }
            else{
                player2.add_win();
                player1.add_loss();
            }
        }
        else if(player1Wins == player2Wins){
            player1.add_tie();
            player2.add_tie();
        }
        else if(player1Wins > player2Wins){
            player1.add_win();
            player2.add_loss();
            calibrate_score(player1, player2, player1Wins, player2Wins);
            cout << player1.get_score();
        }
        else{
            player1.add_win();
            player2.add_loss();
            calibrate_score(player2, player1, player2Wins, player1Wins);
        }
    }
};
int main() {
    Tournament tourney;
    bool done = false;
    int choice = 0;
    string tag = "";
    bool player1Set;
    bool player2Set;
    string player1;
    string player2;
    int score;
    while(!done) {
        player1Set = false;
        player2Set = false;
        cout << "1 to break 2 to add 3 to report";
        cin >> choice;
        switch(choice) {
            case 1:
                done = true;
            break;
            case 2:
                cout << "Please insert the new player's tag" << endl;
            cin >> tag;
            cout << "Please insert the new player's score. If unknown, enter 1000" << endl;
            cin >> score;
            tourney.addPlayerWithSkill(tag, score);
            break;
            case 3:
                while(!player1Set)
                {
                    cout << "Please insert the first player's tag";
                    cin >> tag;
                    if(!tourney.checkForPlayers(tag))
                    {
                        cout << "That player is not in the tournament";
                    }
                    else{
                        player1 = tag;
                    }
                    player1Set = true;
                }
                while(!player2Set)
                {
                    cout << "Please insert the second player's tag";
                    cin >> tag;
                    if(!tourney.checkForPlayers(tag))
                    {
                        cout << "That player is not in the tournament";
                    }
                    else{
                        player2 = tag;
                    }
                    player2Set = true;
                }
                int player1Wins;
                int player2Wins;
                cout << "How many wins did " << player1 << " get?" << endl;
                cin >> player1Wins;
                cout << "How many wins did " << player2 << " get?" << endl;
                cin >> player2Wins;
                tourney.reportMatch(tourney.playerSearch(player1), tourney.playerSearch(player2), player1Wins, player2Wins, false);
                break;
        }
    }
    return 0;

}

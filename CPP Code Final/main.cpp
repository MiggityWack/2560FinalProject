//main.cpp:
#include <iostream>
#include <string>
#include "Tournament.h"

using namespace std;

int main() {
    Tournament tourney;
    string filename;

    cout << "Enter the player database filename (e.g., players.txt): ";
    cin >> filename;
    tourney.importPlayers(filename);

    bool done = false;
    while (!done) {
        cout << "\nMenu Options:\n"
             << "1. Exit\n"
             << "2. Add a new player\n"
             << "3. Report a match\n"
             << "4. Search for a player\n"
             << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                done = true;
                break;
            case 2: {
                string tag;
                int score;
                cout << "Enter player tag: ";
                cin >> tag;
                cout << "Enter player score: ";
                cin >> score;
                tourney.addPlayerFromFile(tag, score, 0);
                break;
            }
            case 3: {
                string player1, player2;
                int player1Wins, player2Wins;
                cout << "Enter first player tag: ";
                cin >> player1;
                cout << "Enter second player tag: ";
                cin >> player2;
                cout << "Enter wins for " << player1 << ": ";
                cin >> player1Wins;
                cout << "Enter wins for " << player2 << ": ";
                cin >> player2Wins;
                tourney.reportMatch(tourney.playerSearch(player1), tourney.playerSearch(player2), player1Wins, player2Wins, false);
                break;
            }
            case 4: {
                string tag;
                cout << "Enter the player's tag to search for: ";
                cin >> tag;
                Tournament::Player* player = tourney.searchPlayerCaseInsensitive(tag);
                if (player) {
                    cout << "Player found: " << player->to_string() << endl;
                } else {
                    cout << "Player not found." << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    cout << "Exiting program. Saving players to file...\n";
    tourney.savePlayers(filename);

    return 0;
}


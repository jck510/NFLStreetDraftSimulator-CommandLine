#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Team.h"


using namespace std;




int main() {

    Player playArray[100]; //array of players. Max is 100

    string name;
    string pos;
    int stat;


    int playerCounter = 0; //keeps track of which player is referenced in the array



    ifstream inputFile;
    inputFile.open("Roster.txt");

    ofstream AllPlayersFile;
    AllPlayersFile.open("AllPlayers.txt");

    ofstream DraftResultsFile;
    DraftResultsFile.open("DraftResults.txt");


    inputFile >> name; //gets the first name in the txt file


    while(name != "EXIT"){


        //the following code reads each piece of data needed to set the attributes of the player at the given array index
        //info provided from the inputFile
        playArray[playerCounter].setFirstName(name);
        inputFile >> name;
        playArray[playerCounter].setLastName(name);
        inputFile >> pos;
        playArray[playerCounter].setPosition(pos);
        inputFile >> stat;
        playArray[playerCounter].setPassing(stat);
        inputFile >> stat;
        playArray[playerCounter].setSpeed(stat);
        inputFile >> stat;
        playArray[playerCounter].setBlocking(stat);
        inputFile >> stat;
        playArray[playerCounter].setAgility(stat);
        inputFile >> stat;
        playArray[playerCounter].setCatching(stat);
        inputFile >> stat;
        playArray[playerCounter].setRunPower(stat);
        inputFile >> stat;
        playArray[playerCounter].setCarrying(stat);
        inputFile >> stat;
        playArray[playerCounter].setTackling(stat);
        inputFile >> stat;
        playArray[playerCounter].setCoverage(stat);
        inputFile >> stat;
        playArray[playerCounter].setDMoves(stat);

        playArray[playerCounter].Print(AllPlayersFile);
        playerCounter++;

        inputFile >> name;
    }

    Team team1;
    Team team2;

    string team1Name;
    string team2Name;
    int firstPick;

    int team1Pick;
    int team2Pick;


    cout << "Welcome to the NFL Street Current Player Draft!" << endl << "--------------------------------------------" << endl;
    cout << "Please enter the first player's name \n";
    cin >> team1Name;
    cout << "Please enter the second player's name \n";
    cin >> team2Name;
    cout << "Who will be drafting first?" << endl << "1) " << team1Name << endl << "2) " << team2Name << endl;
    cin >> firstPick;

    team1.setTeamName(team1Name);
    team2.setTeamName(team2Name);

    int selected[14]; //an array containing the numbers of each player that has been selected in the draft already
    for(int x = 0; x < 14; x++){ //will set each element to negative 1 so that when it is printing each player available it will not find a match unless it has been overridden with another value
        selected[x] = -1;
    }
    bool picked = false;

    int select = 0; //will count the number of players selected


    for(int i = 0; i < 7; i++){

        cout << "Round #" << i+1 << endl;

        cout << "Players Available" << endl << "-------------------------------------------" << endl;
        for(int playNum = 0; playNum < 100; playNum++){ //will go into each element in the player array to print all the available players
            for(int y = 0; y < 14; y++){
                if(selected[y] == playNum){
                    picked = true;
                }
            }

            if(!picked && playArray[playNum].calcRawScore() != 0){//player will print out as an available player if they have not been picked and if they are an actual player
                cout << playNum << ") " << playArray[playNum].getFirstName() << " " << playArray[playNum].getLastName() << " " << playArray[playNum].getPosition() << " Ovr: " << playArray[playNum].calcOverall() << endl;
            }
        picked = false; //will reset picked to false for the next iteration
        }

        if(firstPick == 2){
            cout << team2Name << " is now on the clock!" << endl << "Choose your player!" << endl;
            cin >> team2Pick;
            cout << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team2Name << "'s team has selected " << playArray[team2Pick].getFirstName() << " " << playArray[team2Pick].getLastName() << ", " << playArray[team2Pick].getPosition() << endl;
            DraftResultsFile << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team2Name << "'s team has selected " << playArray[team2Pick].getFirstName() << " " << playArray[team2Pick].getLastName() << ", " << playArray[team2Pick].getPosition() << endl;
            selected[select] = team2Pick;
            team2.AddPlayer(playArray[team2Pick],i); //adds the player to that team in the position of the initial loop counter
            select++; //increments the number of selected players



            cout << "Players Available" << endl << "--------------------------------------" << endl;
            for(int playNum2 = 0; playNum2 < 100; playNum2++){ //will go into each element in the player array to print all the available players
                for(int y = 0; y < 14; y++){
                    if(selected[y] == playNum2){
                        picked = true;
                    }
                }

                if(!picked && playArray[playNum2].calcRawScore() != 0){//player will print out as an available player if they have not been picked and if they are an actual player
                    cout << playNum2 << ") " << playArray[playNum2].getFirstName() << " " << playArray[playNum2].getLastName() << " " << playArray[playNum2].getPosition() << " Ovr: " << playArray[playNum2].calcOverall() << endl;
                }
                picked = false; //will reset picked to false for the next iteration
            }


            cout << "--------------------------------------\n" << team1Name << " is now on the clock!" << endl << "Choose your player!" << endl;
            cin >> team1Pick;
            cout << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team1Name << "'s team has selected " << playArray[team1Pick].getFirstName() << " " << playArray[team1Pick].getLastName() << ", " << playArray[team1Pick].getPosition() << endl;
            DraftResultsFile << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team1Name << "'s team has selected " << playArray[team1Pick].getFirstName() << " " << playArray[team1Pick].getLastName() << ", " << playArray[team1Pick].getPosition() << endl;
            selected[select] = team1Pick;
            team1.AddPlayer(playArray[team1Pick],i); //adds the player to that team in the position of the initial loop counter
            select++; //increments the number of selected players
        }
        else{
            cout << team1Name << " is now on the clock!" << endl << "Choose your player!" << endl;
            cin >> team1Pick;
            cout << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team1Name << "'s team has selected " << playArray[team1Pick].getFirstName() << " " << playArray[team1Pick].getLastName() << ", " << playArray[team1Pick].getPosition() << endl;
            DraftResultsFile << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team1Name << "'s team has selected " << playArray[team1Pick].getFirstName() << " " << playArray[team1Pick].getLastName() << ", " << playArray[team1Pick].getPosition() << endl;
            selected[select] = team1Pick;
            team1.AddPlayer(playArray[team1Pick],i); //adds the player to that team in the position of the initial loop counter
            select++; //increments the number of selected players

            cout << "Players Available" << endl << "--------------------------------------" << endl;
            for(int playNum2 = 0; playNum2 < 100; playNum2++){ //will go into each element in the player array to print all the available players
                for(int y = 0; y < 14; y++){
                    if(selected[y] == playNum2){
                        picked = true;
                    }
                }

                if(!picked && playArray[playNum2].calcRawScore() != 0){//player will print out as an available player if they have not been picked and if they are an actual player
                    cout << playNum2 << ") " << playArray[playNum2].getFirstName() << " " << playArray[playNum2].getLastName() << " " << playArray[playNum2].getPosition() << " Ovr: " << playArray[playNum2].calcOverall() << endl;
                }
                picked = false; //will reset picked to false for the next iteration
            }

            cout << team2Name << " is now on the clock!" << endl << "Choose your player!" << endl;
            cin >> team2Pick;
            cout << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team2Name << "'s team has selected " << playArray[team2Pick].getFirstName() << " " << playArray[team2Pick].getLastName() << ", " << playArray[team2Pick].getPosition() << endl;
            DraftResultsFile << "With the #" << select+1 << " Pick in the NFL Street Draft, " << team2Name << "'s team has selected " << playArray[team2Pick].getFirstName() << " " << playArray[team2Pick].getLastName() << ", " << playArray[team2Pick].getPosition() << endl;
            selected[select] = team2Pick;
            team2.AddPlayer(playArray[team2Pick],i); //adds the player to that team in the position of the initial loop counter
            select++; //increments the number of selected players
        }
    }

    cout << "This concludes the NFL Street Draft!\nThank you for your participation!" << endl;
    DraftResultsFile << endl << "This concludes the NFL Street Draft!\nThank you for your participation!" << endl << "Below are the draft results!\n-------------------------------------------------------\n";
    team1.printTeam(DraftResultsFile);
    team2.printTeam(DraftResultsFile);



    inputFile.close();
    AllPlayersFile.close();
    DraftResultsFile.close();


    return 0;
}


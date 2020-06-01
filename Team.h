#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

#ifndef NFLSTREETROSTERMAKER_TEAM_H
#define NFLSTREETROSTERMAKER_TEAM_H

class Team{

private:
    Player team[7]; //team will be an array of 7 players
    string teamName;
    double teamOverall;
    int teamRawScore;


public:

    Team();
    void setTeamName(string name);
    double calcOverall();
    int calcRawScore();
    void AddPlayer(Player newPlayer, int teamNum);
    string getTeamName();
    void printTeam(ofstream & file);


};

Team::Team(){
    teamName = "Nameless Team";
    teamOverall = 0;
    teamRawScore = 0;

}

void Team::setTeamName(string name){
    teamName = name;
}

double Team::calcOverall(){
    for(int i = 0; i < 7; i++){
        teamOverall = teamOverall + team[i].calcOverall();
    }
    teamOverall = teamOverall / 7; //will get the average overall
    return teamOverall;
}

int Team::calcRawScore(){
    for(int i = 0; i < 7; i++){
        teamRawScore = teamRawScore + team[i].calcRawScore();
    }
    return teamRawScore;
}

void Team::AddPlayer(Player newPlayer, int teamNum){
    team[teamNum] = newPlayer;
}

string Team::getTeamName(){
    return teamName;
}

void Team::printTeam(ofstream & file){

    file << getTeamName() << "'s Team" << endl << "Team Overall: " << calcOverall() << " Team RAW: " << calcRawScore() << endl << "------------------------------" << endl;
    for(int i = 0; i < 7; i++){
        team[i].Print(file);
    }
}


#endif //NFLSTREETROSTERMAKER_TEAM_H

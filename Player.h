#include <iostream>
#include <string>

using namespace std;

#ifndef NFLSTREETROSTERMAKER_PLAYER_H
#define NFLSTREETROSTERMAKER_PLAYER_H

const int MAX_STAT = 20;

class Player{

private:

    string firstName;
    string lastName;
    string position;
    double overall;
    int rawScore;

    //Stats
    int passing;
    int speed;
    int blocking;
    int agility;
    int catching;
    int runPower;
    int carrying;
    int tackling;
    int coverage;
    int dMoves;




public:

    Player();
    Player(string first, string last, string position, int pass, int spe, int block, int agi, int cat, int pow, int car, int tack, int cov, int dmov);
    double calcOverall();
    int calcRawScore();

    //setters
    void setFirstName(string name);
    void setLastName(string name);
    void setPosition(string pos);
    void setPassing(int pass);
    void setSpeed(int spe);
    void setBlocking(int block);
    void setAgility(int agi);
    void setCatching(int cat);
    void setRunPower(int pow);
    void setCarrying(int car);
    void setTackling(int tack);
    void setCoverage(int cov);
    void setDMoves(int dmov);

    //accessors

    string getFirstName();
    string getLastName();
    string getPosition();
    int getPassing();
    int getSpeed();
    int getBlocking();
    int getAgility();
    int getCatching();
    int getRunPower();
    int getCarrying();
    int getTackling();
    int getCoverage();
    int getDMoves();




    void Print(ofstream & outputFile);





};



Player::Player() {
    firstName = "Empty Name";
    lastName = "Empty Last Name";
    position = "Blank Position";
    passing = 0;
    speed = 0;
    blocking = 0;
    agility = 0;
    catching = 0;
    runPower = 0;
    carrying = 0;
    tackling = 0;
    coverage = 0;
    dMoves = 0;

    overall = 0;
    rawScore = 0;

}





Player::Player(string first, string last, string pos, int pass, int spe, int block, int agi, int cat, int pow, int car, int tack, int cov, int dmov) {
    firstName = first;
    lastName = last;
    position = pos;
    passing = pass;
    speed = spe;
    blocking = block;
    agility = agi;
    catching = cat;
    runPower = pow;
    carrying = car;
    tackling = tack;
    coverage = cov;
    dMoves = dmov;

    overall = 0;
    rawScore = 0;

}

double Player::calcOverall() {

    if(position == "QB"){
        overall = ((.5 * (passing * 5)) + (.2 * (speed * 5)) + (.075 * (agility * 5)) + (.075 * (runPower * 5)) + (.15 * (carrying * 5)));
    }
    else if(position == "RB"){
        overall = ((.3 * (speed * 5)) + (.15 * (agility * 5)) + (.20 * (runPower * 5)) + (.25 * (carrying * 5)) + (.1 * (catching * 5)));

    }
    else if(position == "WR"){
        overall = ((.3 * (catching * 5)) + (.25 * (speed * 5)) + (.20 * (agility * 5)) + (.03 * (runPower * 5)) + (.1 * (carrying * 5)) + (.07 * (blocking * 5)));
    }
    else if(position == "OL"){
        overall = ((.85 * (blocking * 5)) + (.1 * (dMoves * 5)) + (.05 * (tackling * 5)));
    }
    else if(position == "DL"){
        overall = ((.25 * (tackling * 5)) + (.15 * (speed * 5)) + (.5 * (dMoves * 5)) + (.10 * (blocking * 5)));
    }
    else if(position == "LB"){
        overall = ((.2 * (speed * 5)) + (.1 * (agility * 5)) + (.35 * (tackling * 5)) + (.15 * (coverage * 5)) + (.2 * (dMoves * 5)));
    }
    else if(position == "DB"){
        overall = ((.2 * (speed * 5)) + (.18 * (agility * 5)) + (.05 * (catching * 5)) + (.22 * (tackling * 5)) + (.35 * (coverage * 5)));
    }

    return overall;
}

int Player::calcRawScore(){
    rawScore = (passing + speed + blocking + agility + catching + runPower + carrying + tackling + coverage + dMoves);
    return rawScore;
}




void Player::setFirstName(string name){
    firstName = name;
}

void Player::setLastName(string name){
    lastName = name;
}

void Player::setPosition(string pos){
    position = pos;
}

void Player::setPassing(int pass){
    passing = pass;
}
void Player::setSpeed(int spe){
    speed = spe;
}
void Player::setBlocking(int block){
    blocking = block;
}
void Player::setAgility(int agi){
    agility = agi;
}
void Player::setCatching(int cat){
    catching = cat;
}
void Player::setRunPower(int pow){
    runPower = pow;
}
void Player::setCarrying(int car){
    carrying = car;
}
void Player::setTackling(int tack){
    tackling = tack;
}
void Player::setCoverage(int cov){
    coverage = cov;
}
void Player::setDMoves(int dmov){
    dMoves = dmov;
}

//accessors

string Player::getFirstName(){
    return firstName;
}

string Player::getLastName(){
    return lastName;
}

string Player::getPosition(){
    return position;
}

int Player::getPassing(){
    return passing;
}
int Player::getSpeed(){
    return speed;
}
int Player::getBlocking(){
    return blocking;
}
int Player::getAgility(){
    return agility;
}
int Player::getCatching(){
    return catching;
}
int Player::getRunPower(){
    return runPower;
}
int Player::getCarrying(){
    return carrying;
}
int Player::getTackling(){
    return tackling;
}
int Player::getCoverage(){
    return coverage;
}
int Player::getDMoves(){
    return dMoves;
}


void Player::Print(ofstream & outputFile){

    outputFile << getFirstName() << " " << getLastName() << endl << "Pos: " << getPosition() << " Ovr: " << calcOverall() << " RAW: " << calcRawScore() << endl;
    outputFile << "------------------------------" << endl;

    outputFile << "Passing :";
    for(int a = 0; a < getPassing(); a++){
        outputFile << "|";
    }
    outputFile << endl << "Speed   :";
    for(int b = 0; b < getSpeed(); b++){
        outputFile << "|";
    }
    outputFile << endl << "Blocking:";
    for(int c = 0; c < getBlocking();c++){
        outputFile << "|";
    }
    outputFile << endl << "Agility :";
    for(int d = 0; d < getAgility();d++){
        outputFile << "|";
    }
    outputFile << endl << "Catching:";
    for(int e = 0; e < getCatching();e++){
        outputFile << "|";
    }
    outputFile << endl << "RunPower:";
    for(int f = 0; f < getRunPower();f++){
        outputFile << "|";
    }
    outputFile << endl << "Carrying:";
    for(int g = 0; g < getCarrying();g++){
        outputFile << "|";
    }
    outputFile << endl << "Tackling:";
    for(int h = 0; h < getTackling();h++){
        outputFile << "|";
    }
    outputFile << endl << "Coverage:";
    for(int i = 0; i < getCoverage();i++){
        outputFile << "|";
    }
    outputFile << endl << "D-Moves :";
    for(int j = 0; j < getDMoves();j++){
        outputFile << "|";
    }
    outputFile << endl << "------------------------------" << endl << endl;

}



#endif //NFLSTREETROSTERMAKER_PLAYER_H

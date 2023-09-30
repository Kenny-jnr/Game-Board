#pragma once
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::ostream;
#include "GameState.hpp"

class GamePiece {
private:
std::string name; //name of player
std::string type; //type of player
GameState * state = new GameState; //gamestate of player

public:
//Constructor
GamePiece(std::string name1, std::string type1, GameState * state1);
GamePiece(const GamePiece& piece); //copy construtor
GamePiece& operator=(const GamePiece &x); //assignment
~GamePiece(); //destructor

//Member functions
string GetPlayer() const;
string GetType() const;
int GetPower() const;
int GetSpeed() const;

//comparison operators
friend bool operator ==(const GamePiece &a, const GamePiece &b);
friend bool operator !=(const GamePiece &a, const GamePiece &b);
friend bool operator <(const GamePiece &a, const GamePiece &b);
friend bool operator >(const GamePiece &a, const GamePiece &b);
friend bool operator <=(const GamePiece &a, const GamePiece &b);
friend bool operator >=(const GamePiece &a, const GamePiece &b);

//overloading output operator
friend ostream& operator<<(ostream & oss, const GamePiece &piece);

//helper functions
void Copy(const GamePiece &);
bool LessThan(const GamePiece &, const GamePiece&);
};
#pragma once
#include <map>
#include <string>
#include <vector>

class GameState {

private:
std::map<std::string, std::vector<std::string>> board; //The Board

public:
//to help check status of Board
int NumPieces();
int NumPieces(const std::string &name);
int NumPieces(const std::string &name, const std::string &type);

//helper functions
//help add and remove pieces to the board
void Append(const std::string &name, const std::string &type);
void Remove(const std::string &name, const std::string &type);

int NumType(const std::string &type); //this helper function checks for the number of a single type of piece, regardless of player
};
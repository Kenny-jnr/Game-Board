#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "GameState.hpp"

int GameState::NumPieces(){
    std::map<std::string, std::vector<std::string>>::iterator it; //iterator of map

    int count = 0;
    for(it = board.begin(); it != board.end(); it++){
        count += size(it->second); //loops through and counts the number of pieces on the board, by finding the size of each vectors in the map
    }return count;
}


int GameState::NumPieces(const std::string &name){
    std::map<std::string, std::vector<std::string>>::iterator it;

    int count = 0;
    for(it = board.begin(); it != board.end(); it++){
        if(it->first == name){ //returns the number of pieces a player has at a point
            count = size(it->second);
        }
    }return count;
}

int GameState::NumPieces(const std::string &name, const std::string &type){ 
    std::map<std::string, std::vector<std::string>>::iterator it;

    int count = 0;
    for(it = board.begin(); it != board.end(); it++){
        if(it->first == name){
            count = std::count(it->second.begin(), it->second.end(), type); //return the number of a specific type of piece a player has at that point
        }
    }return count;
}

void GameState::Append(const std::string &name, const std::string &type){
    std::map<std::string, std::vector<std::string>>::iterator it;
    
    for(it = board.begin(); it != board.end(); it++){
        if(it->first == name){
            it->second.push_back(type); //puts a new type into the vector of the players inventory
        }
    }
    if(it==board.end()){
        std::vector<std::string> vec{type}; //creates a new player to the game, in cases where that player is not already there, also adds his piece
        board.insert({name, vec});
    }
}

void GameState::Remove(const std::string &name, const std::string &type){
    std::map<std::string, std::vector<std::string>>::iterator it;
    for(it = board.begin(); it != board.end(); it++){
        if(it->first == name){
            auto rslt = find(it->second.begin(), it->second.end(), type);
            it->second.erase(rslt); //removes the name and type that was passed through it
        }
    }
}

int GameState::NumType(const std::string &type){
    std::map<std::string, std::vector<std::string>>::iterator it;

    int count = 0;
    for(it = board.begin(); it != board.end(); it++){
        count += std::count(it->second.begin(), it->second.end(), type); // counts the total number of a specific type of piece in the whole Board
    }return count;
}

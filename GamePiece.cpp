#include <string>
using std::to_string;
#include "GamePiece.hpp"

GamePiece::~GamePiece(){ //destructor
    state->Remove(name, type); //removes the piece from the map, Board, in Gamestate
}

void GamePiece::Copy(const GamePiece &piece){ //copies the attribute of that piece
    this -> name = piece.name;
    this -> type = piece.type;
    this -> state = piece.state;
}

GamePiece::GamePiece(std::string name1, std::string type1, GameState * state1){ 
    this -> name = name1;
    this -> type = type1;
    this -> state = state1;
    state->Append(name, type); //adds the initialized piece into the map "Board" in Gamestate
}

GamePiece::GamePiece(const GamePiece &piece){
    Copy(piece); //copies the attribute to "this"
    state->Append(name, type);
}

GamePiece& GamePiece::operator=(const GamePiece &piece){ 
    state->Remove(name, type); //removes and replaces the old piece with a new one
    Copy(piece);
    state->Append(name, type);
    return *this;
}

string GamePiece::GetPlayer()const{
    return this->name;
}

string GamePiece::GetType() const{
    return this->type;
}

int GamePiece::GetPower() const{
    if(this->type == "Warrior"){
        return 5;
    }else if(this->type == "Scout"){
        return 1;
    }else if(this->type == "Wizard"){
        return state->NumPieces(this->name, this->type); // returns the number of wizards in the board allocated to that player
    }else{
        return 0;
    }
}

int GamePiece::GetSpeed() const{
    if(this->type == "Warrior"){
        return 2;
    }else if(this->type == "Scout"){
        return 8;
    }else if(this->type == "Wizard"){
        // gets the number of wizards in the entire board, subtracts the wizard allocated to that player. then subtract that from 12.
        int speed = 12 - ((state->NumType(this->type)) - (state->NumPieces(this->name, this->type))); 
        if(speed < 2){
            return 1; //speed cant be lower than 0
        }return speed;
    }else{
        return 0;
    }
}

bool operator ==(const GamePiece &a, const GamePiece &b){ 
    return ((b.GetPower() == a.GetPower()) && (b.GetSpeed() == a.GetSpeed())); //checks the equality in speed and power of them both pieces
}

bool operator !=(const GamePiece &a, const GamePiece &b){
    return !(a == b); //contadiction of the above
}

bool LessThan(const GamePiece &a, const GamePiece &b){ //helper to check less than, besides the chances of equality.
    if(a.GetPower() < b.GetPower()){
        return true;
    }else if(a.GetPower() > b.GetPower()){ //check power first, then in case of equality, check for speed
        return false;
    }else{
        if(a.GetSpeed() < b.GetSpeed()){
            return true;
        }else{
            return false;
        }
    }
}

bool operator <(const GamePiece &a, const GamePiece &b){  
    if(a == b){
        return false;
    }
    return LessThan(a, b);
}

bool operator >(const GamePiece &a, const GamePiece &b){
    if(a == b){
        return false;
    }
    return !LessThan(a, b);
}

bool operator <=(const GamePiece &a, const GamePiece &b){
    return ((a == b) || (a < b)); //returns truth value of equal of lessthan
}

bool operator >=(const GamePiece &a, const GamePiece &b){
    return ((a == b) || (a > b));
}

ostream& operator<<(ostream & oss, const GamePiece &piece){
    oss << "(";
    oss << piece.GetPlayer() << "," << piece.GetType() << "," << to_string(piece.GetPower()) << "," << to_string(piece.GetSpeed());
    oss << ")";
    return oss;
}

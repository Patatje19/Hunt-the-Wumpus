#include "AI.hpp"
#include "calculations.hpp"
#include "config.hpp"
#include "gameplay.hpp"
#include "print.hpp"
#include "printInstructions.hpp"
#include "randomGenerate.hpp"
#include "statistics.hpp"


int left_chamber(int room, const std::vector<int> & rooms){
	if(room == 1){
		return rooms[rooms.size()-1];
	}
	else{
		return room - 1;
	}
	
}


int right_chamber(int room, const std::vector<int> & rooms){
	if(room == (rooms.size())){
		return 1;
	}
	else{
		return room + 1;
	}

}


int opposite_chamber(int room, const std::vector<int> & rooms){
	if(room > (rooms.size()/2)){
		return room - (rooms.size() / 2);
	}
	else{
		return room + (rooms.size() / 2);
	}
	
}


std::vector<int> room_generator(int roomsize){
	std::vector<int> rooms = {};
	
	for(unsigned int i = 1; i <= roomsize; i++){
		rooms.push_back(i);
	}
	
	return rooms;
	
}


char map_calc(const std::vector<int> & rooms, const std::vector<int> & bottemless_pits, int locatie_wumpus, 
const std::vector<int> & room_bat, int room){
	if(room == locatie_wumpus){
		return 'W';
	}
	for(unsigned i=0; i < bottemless_pits.size(); i++){
		if(bottemless_pits[i] == room){
			return '_';
		}
	}
	for(unsigned j=0; j < room_bat.size(); j++){
		if(room_bat[j] == room){
			return 'V';
		}
	}
	return ' ';
	
}

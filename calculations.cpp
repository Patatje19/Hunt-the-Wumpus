#include "wumpus.hpp"


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

#include "wumpus.hpp"


int random_room(){
	srand(time(NULL));
	
	return rand() % 8 + 1;
	
}


int left_chamber(int room, const std::vector<int> & rooms){
	if(room == 1){
		return rooms[rooms.size()-1];
	}
	else{
		return room - 1;
	}
	
}


int right_chamber(int room){
	if(room == 8){
		return 1;
	}
	else{
		return room + 1;
	}

}


int opposite_chamber(int room, const std::vector<int> & rooms){
	if(room > (rooms.size()/2)){
		return room - (rooms.size()/2);
	}
	else{
		return room + (rooms.size()/2);
	}
	
}

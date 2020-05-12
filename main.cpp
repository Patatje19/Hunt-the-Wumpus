#include "wumpus.hpp"


int main(){
	int start_room = random_room();
	int current_room = start_room;
	
	print_start(start_room); 
	
	std::vector<int> rooms = {1,2,3,4,5,6,7,8};
	
	while(true){
		user_movement(current_room, rooms);
	}
	
	return 0;
	
}

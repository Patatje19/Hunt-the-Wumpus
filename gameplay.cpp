#include "wumpus.hpp"


void user_movement(int & room, const std::vector<int> & rooms){
	print_room_options(room, rooms);

	int rechts	 = right_chamber(room);
	int links	 = left_chamber(room, rooms);
	int opposite = opposite_chamber(room, rooms);
	
	while(true){
		print_user_movement(room);
	
		if(room == rechts || room == links || room == opposite){
			print_current_room_true(room);
			break;
		}
		else{
			print_current_room_false();
		}
	}
	
}

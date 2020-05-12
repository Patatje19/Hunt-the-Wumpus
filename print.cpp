#include "wumpus.hpp"


void print_start(int room){
	std::cout << "HUNT THE WUMPUS" << std::endl;
	std::cout << "JE BENT IN KAMER " << room << std::endl;
	
}


void print_room_options(int room, const std::vector<int> & rooms){
	std::cout << "TUNNELS LEIDEN NAAR ";
	std::cout << left_chamber(room, rooms) << " ";
	std::cout << right_chamber(room, rooms) << " ";
	std::cout << opposite_chamber(room, rooms) << std::endl;
	
}


void print_user_movement(int & room){
	std::cout << "WAARHEEN? ";
	std::cin >> room;
	
}


void print_current_room_true(int & room){
	std::cout << "JE BENT IN KAMER " << room << std::endl;
	
}


void print_wrong_input(){
	std::cout << "NIET MOGELIJK!!!" << std::endl;
	
}


void print_load_config(){
	std::cout << "WIL JE HET CONFIGURATIE BESTAND LADEN? [J/N]" << std::endl;
	
}


void print_fell_in_pit(){
	std::cout << "YEET JE VIEL IN EEN PUT" << std::endl;
	
}


void print_game_over(){
	std::cout << "HAHAHA JE HEBT VERLOREN LOSER" << std::endl;
	
}


void print_smell_wumpus(){
	std::cout << "DE WUMPUS IS NABIJ" << std::endl; 
	
}

void print_gepakt_wumpus(){
		std::cout << "DE WUMPUS HEEFT JE GEPAKT" << std::endl; 

}

void print_shoot_or_move(){
	std::cout << "SCHIETEN OF BEWEGEN (S/B)? " << std::endl;

}


void print_user_shoot(int & room_shot){
   std::cout << "SCHIET NAAR KAMER: ";
   std::cin >> room_shot;

}

void print_wumpus_hit(){
	std::cout << "RAAK!" << std::endl;
	std::cout << "JE HEBT GEWONNEN" << std::endl;

}


void print_arrow_inventory(int arrows){
	std::cout << "JE HEBT NOG " << arrows << " PIJLEN OVER" << std::endl;

}


void print_current_room(int & room){
	std::cout << "JE BENT IN KAMER " << room << std::endl;

}

void print_wumpus_miss(){
	std::cout << "GEMIST" << std::endl;

}


void print_pick_up_bat(){
	std::cout << "VLEERMUIS HEEFT JE TE PAKKEN!!!" << std::endl;
	
}


void print_smell_bat(){
	std::cout << "VLEERMUIS IS IN DE BUURT" << std::endl; 
	
}

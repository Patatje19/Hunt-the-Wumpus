#include "AI.hpp"
#include "calculations.hpp"
#include "config.hpp"
#include "gameplay.hpp"
#include "print.hpp"
#include "printInstructions.hpp"
#include "randomGenerate.hpp"
#include "statistics.hpp"


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


void print_current_room_true(int room){
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


void print_current_room(int room){
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


void print_map(const std::vector<int> & rooms, const std::vector<int> & bottemless_pits, 
int locatie_wumpus, const std::vector<int> & room_bat){
	std::cout << "LEGENDA: WUMPUS = W, PUT = _ , VLEERMUIS = V" << std::endl;
	
	for(unsigned i = 0; i < (rooms.size()/2); i++){
		std::cout << "{ " << rooms[i] << ", " 
		<< map_calc(rooms, bottemless_pits, locatie_wumpus, room_bat, rooms[i]) << "}" 
		<< ", {" << rooms[i+(rooms.size()/2)] << ", " 
		<< map_calc(rooms, bottemless_pits, locatie_wumpus, room_bat, rooms[i+(rooms.size()/2)]) << "}" 
		<< std::endl;
	}
	
}


void print_roadmap(){
	std::cout << "WIL JE DE KAART LADEN? [J/N]" << std::endl;
	
}


void print_instructions_menu(){
	std::cout << "WIL JE DE INSTRUCTIES ZIEN? [J/N]" << std::endl;
	
}


void print_AI(){
	std::cout << "WIL JE DE COMPUTER LATEN SPELEN? [J/N]" << std::endl;

}


void print_stats_menu(){
	std::cout << "WIL JE DE STATISTIEKEN ZIEN? [J/N]" << std::endl;

}


void print_turns(int turns){
	std::cout << "HET AANTAL BEURTEN DAT JE ER OVER DEED: " << turns << std::endl;
	
}


void print_average(){
	std::cout << "HET GEMIDDELD AANTAL BEURTEN: " << read_stats() << std::endl;
	
}


void print_AI_turn(int turns){
	std::cout << "BEURT: " << turns << std::endl;
	
}


void treasure_open(){
	std::cout << "WIL JE DE KIST OPENEN? [J/N]" << std::endl;
	
}


void print_snake_bite(){
	std::cout << "SLANG YEET!!!" << std::endl;
	
}
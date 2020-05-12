#include "AI.hpp"
#include "calculations.hpp"
#include "config.hpp"
#include "gameplay.hpp"
#include "print.hpp"
#include "printInstructions.hpp"
#include "randomGenerate.hpp"
#include "statistics.hpp"


void print_instructions(){
	print_instructions_header();
	print_instructions_hazards();
	print_instructions_wumpus();
	print_instructions_player();
	print_instructions_config();
	
}


void print_instructions_wumpus(){
	std::cout << "WUMPUS:" << std::endl; 
	std::cout << "WUMPUS IS NIET BANG VOOR GEVAAR." << std::endl; 
	std::cout << "HIJ HEEFT ZUIGNAPPEN EN IS TE GROOT VOOR VLEERMUIZEN." << std::endl; 
	std::cout << "NORMAAL SLAAPT HIJ " << std::endl; 
	std::cout << "TWEE DINGEN MAKEN HEM WAKKER:" << std::endl; 
	std::cout << "DE SPELER DIE EEN PIJL OP DE WUMPUS SCHIET" << std::endl; 
	std::cout << "OF ALS DE SPELER IN DE WUMPUS ZIJN KAMER KOMT" << std::endl; 
	std::cout << "ALS JE MIS SCHIET DAN VERPLAATST DE WUMPUS" << std::endl; 
	std::cout << "ALS DE WUMPUS IN JOUW KAMER VERPLAATST DAN HEB JE VERLOREN " << std::endl; 
	std::cout << std::endl << std::endl;

}

void print_instructions_hazards(){
	std::cout << "GEVAREN:" << std::endl;
	std::cout << "BODEMLOZE PUTTEN: " << std::endl;
	std::cout << "WILLEKEURIGE KAMERS HEBBEN EEN PUT ALS JE ER INVALT IS HET SPEL VOORBIJ" << std::endl;
	std::cout << "VLEERMUIZEN:" << std::endl;
	std::cout << "WILLEKEURIGE KAMERS HEBBEN EEN VLEERMUIS" << std::endl;
	std::cout << "ALS DEZE JE TE PAKKEN HEEFT VERPLAATST DEZE JE NAAR EEN WILLEKEURIGE KAMER" << std::endl;
	std::cout << "ALS HIER EEN WUMPUS OF PUT IS BEN JE GAME-OVER" << std::endl;
	std::cout << "SCHATKIST:" << std::endl;
	std::cout << "ALS JE DE SCHATKIST TEGENKOMT KAN JE KIEZEN HEM WEL OF NIET TE OPENEN" << std::endl;
	std::cout << "DE INHOUD BIED KANS OP EEN PRIJS OF EEN VROEGTIJDIG EIND" << std::endl;
	std::cout << std::endl << std::endl;

}


void print_instructions_header(){
	std::cout << "WELKOM BIJ HUNT DE WUMPUS" << std::endl; 
	std::cout << "DE WUMPUS LEEFT EEN VAN DE KAMERS" << std::endl;
	std::cout << "ELKE KAMER IS VERBONDEN MET DRIE TUNNELS DIE NAAR ANDERE KAMERS LEIDEN" << std::endl;
	std::cout << std::endl << std::endl;

}


void print_instructions_player(){
	std::cout << "SPELER:" << std::endl;
	std::cout << "ELKE BEURT KUN JE SCHIETEN MET EEN PIJL OF BEWEGEN DOOR EEN TUNNEL" << std::endl;
	std::cout << "BEWEGEN:" << std::endl;
	std::cout << "JE KUNT NAAR EEN KAMER BEWEGEN DOOR EEN TUNNEL" << std::endl;
	std::cout << "SCHIETEN:" << std::endl; 
	std::cout << "JE VERLIEST ALS JE PIJLEN OP ZIJN" << std::endl;
	std::cout << "ALS DE PIJL MIS IS VERPLAATST DE WUMPUS ZICH NAAR EEN ANDERE KAMER" << std::endl;
	std::cout << "ALS JE DE WUMPUS RAAK SCHIET, WIN JE HET SPEL" << std::endl;
	std::cout << std::endl << std::endl;

 
}


void print_instructions_config(){
	std::cout << "CONFIGURATIE BESTAND:" << std::endl;
	std::cout << "IN HET CONFIGURATIE BESTAND KUN JE HET SPEL CONFIGURENEN" << std::endl;
	std::cout << "PER REGEL STAAT BESCHREVEN WAT JE KAN AANPASSEN" << std::endl;
	std::cout << "INDIEN JE EEN WAARDE LEEG LAAT DAN WORDT EEN STANDAARD WAARDE GEGEVEN" << std::endl; 
	std::cout << std::endl << std::endl;

}

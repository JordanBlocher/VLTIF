#include "gui.hpp"

#include <ncurses.h>
#include <iostream>

namespace gui{


void init_gui(){

   //initialize screen
   initscr();
   raw();
   keypad( stdscr, TRUE );
   noecho();
   curs_set(0);

   if( has_colors() == FALSE ){
      endwin();
      std::cout << "ERROR: Your terminal does not support color" << std::endl;
      exit(1);
   }
   
}


void cleanup_gui(){

   curs_set(1);
   endwin();

}


} //end of namespace gui

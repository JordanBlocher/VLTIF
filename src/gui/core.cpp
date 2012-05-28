#include "gui.h"

#include <ncurses.h>
#include <iostream>

namespace gui{


void init_gui(){

   //initialize screen
   initscr();
   raw();
   keypad( stdscr, TRUE );
   noecho();

   if( has_colors() == FALSE ){
      endwin();
      std::cout << "ERROR: Your terminal does not support color" << std::endl;
      exit(1);
   }
   
}


void cleanup_gui(){

   endwin();

}


} //end of namespace gui

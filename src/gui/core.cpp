#include "gui.h"

#include <ncurses.h>

namespace gui{


void init_gui(){

   //initialize screen
   initscr();
   raw();
   noecho();

}


void cleanup_gui(){

   endwin();

}


} //end of namespace gui

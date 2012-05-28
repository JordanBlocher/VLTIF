
#include "gui/gui.h"

/** 
  * Main Driver
  *
*/
int main( int argc, char* argv[] ){
  
    //menu selection choice
    int choice = 0;
    bool exit = false;

    //initialize ncurses
    gui::init_gui();

    ProgramOptions options = gui::load_config_data();

    //iterate until choice is given
    while( exit == false ){

        //give main menu
        choice = gui::main_menu( argc, argv );

        
        //check for all cases
        switch( choice ){

            /// Exit the program by breaking the loop
            case gui::EXIT_PROGRAM:
                exit = true;
                break;

            case gui::CONFIGURATION:
               gui::configuration( options );
               break;

        }

    }

    //cleanup ncurses
    gui::cleanup_gui();

    gui::save_config_data( options );

    return 0;
}


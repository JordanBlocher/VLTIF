
#include "detection/detection.hpp"
#include "gui/gui.hpp"

/** 
  * Main Driver
  *
*/
int main( int argc, char* argv[] ){
  
    //menu selection choice
    int choice = 0;
    bool exit = false;
    
    //initialize data
    ProgramOptions options = gui::load_config_data();

    //initialize ncurses
    gui::init_gui();


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

            case gui::PLAY_VIDEO:
               
               break;

            case gui::ALIGN_VIDEO:
               
               break;
            case gui::DETECTION:
               gui::detection( options );
               break;

        }

    }

    //cleanup ncurses
    gui::cleanup_gui();

    gui::save_config_data( options );

    return 0;
}


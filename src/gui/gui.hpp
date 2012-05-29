#ifndef __SRC_GUI_GUI_HPP__
#define __SRC_GUI_GUI_HPP__

#include "../structures/Program_Options.hpp"

namespace gui{

    enum WINDOWS {
        EXIT_PROGRAM       = 0,
        CONFIGURATION      = 1,
        PLAY_THERMAL_VIDEO = 2,
        PLAY_VISIBLE_VIDEO = 3,
        ALIGN_VIDEO        = 4,
        DETECTION          = 5
    };

    /**
      * init_gui
      *
    */
    void init_gui();

    /**
      * cleanup_gui
      *
    */
    void cleanup_gui();


    /**
      * Main Menu
      *
      * Function which presents the user with the main menu.
      * @param[in] argc number of arguments
      * @param[in] argv list of arguments
      * @return video screen
    */
    int main_menu( int argc, char * argv[] );


   void configuration( ProgramOptions& data );

   ProgramOptions load_config_data();

   void save_config_data( ProgramOptions const& data );

   void align_video( ProgramOptions& data );

}///end of gui namespace

#endif


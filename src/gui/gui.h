#ifndef __SRC_GUI_GUI_H__
#define __SRC_GUI_GUI_H__

namespace gui{

    enum WINDOWS {
        EXIT_PROGRAM  = 0,
        CONFIGURATION = 1
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




}///end of gui namespace

#endif


#include <string>
#include <utility>
#include <vector>

#include <ncurses.h>

#include "gui.h"
#include "../utilities/string_utilities.h"

using namespace std;

namespace gui{


int main_menu( int argc, char* argv[] ){

   int pos = 0;
   vector<pair<string,int> >  menu_pairs;
   menu_pairs.push_back( pair<string,int>(string("Configure Options"), CONFIGURATION ));
   menu_pairs.push_back( pair<string,int>(string("Exit Program"     ), EXIT_PROGRAM  ));

   //start loop
   while( true ){

      //clear the screen
      clear();

      printw("VLTIF - Visible Light Thermal Imaging Fusion\n");
      for( size_t i=0; i<menu_pairs.size(); i++){
         
         //set the cursor parameter
         if( i == pos )
            attron( A_BOLD | A_STANDOUT );

         //print information   

         printw(int2str(i).c_str());
         printw(" - ");
         printw(menu_pairs[i].first.c_str());
         printw("\n");

         if( i == pos )
            attroff( A_BOLD | A_STANDOUT );
      
      
      }
      
      move( pos+1, 0 );
      refresh(); 


      //accept user input
      int input  = getch();
      int choice = input - '0';
      
      //return option if user enters number
      if( choice < menu_pairs.size() )
         return menu_pairs[choice].second;

      //return option if user presses enter key
      if( input == KEY_ENTER )
         return menu_pairs[pos].second;
      if( input == KEY_RIGHT )
         return menu_pairs[pos].second;

      //change position if user presses arrow keys
      if( input == KEY_UP )
         pos++;
      
      if( input == KEY_DOWN )
         pos--;

      if( pos < 0 )
         pos = ((int)menu_pairs.size()) + pos; 
      
      if( pos >= ((int)menu_pairs.size()) )
         pos = ((int)menu_pairs.size()) - pos;

   }

   return 0;

}//end of main_menu function


} ///end of gui namespace


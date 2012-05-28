#include <ncurses.h>

#include <fstream>
#include <iostream>

#include "gui.h"

using namespace std;

namespace gui{

void print_window( ProgramOptions const& data, const int& pos, const int& start, const int& end );

void configuration( ProgramOptions& data ){

   bool exit_loop = false;
   bool exit_lock = false;
   int pos   = 0;
   int start = 0;
   int end   = std::min(10,data.get_max());
   int max   = data.get_max();

   while( exit_loop == false ){

      //clear console window
      clear();

      printw("Configuration Screen");
      move(2,0);
      print_window( data, pos, start, end );


      //refresh window
      move( 2+pos, 0);
      refresh();


      //check input 
      int input = getch();


      switch( input ){

         //left key 
         case KEY_LEFT:

            //allow the program to exit
            if( exit_lock == false ){
               exit_loop = true;
               break;
            }
            break;
         
         case KEY_UP:
            if( exit_lock == false ){
               pos--;
               if( pos < 0 )
                  pos = max + pos;
            }
            break;

         case KEY_DOWN:
            if( exit_lock == false ){
               pos++;
               if( pos >= max )
                  pos = pos - max;
            }
            break;

         case KEY_RIGHT:
            //this is if we want to change a field
            if( exit_lock == false ){
               //exit_lock = true;
            }
            

      }

   }


}//end of configuration


ProgramOptions load_config_data( ){

   ProgramOptions data;
   pair<string,string>  tmpStr;
   string assignOpr;

   std::ifstream fin;
   fin.open("data/options.cfg");

   fin >> tmpStr.first >> assignOpr >> tmpStr.second;

   while( !fin.eof() ){

      data.addElement( tmpStr );
      fin >> tmpStr.first >> assignOpr >> tmpStr.second;

   }

   fin.close();

   return data;

}

void save_config_data( ProgramOptions const& data ){

   std::ofstream fout;
   system("mv data/options.cfg  data/_options.cfg");
   fout.open("data/options.cfg");

   fout << "THERMAL_VIDEO_FILENAME = " << data.get_thermal_video_filename() << endl;
   fout << "VISIBLE_VIDEO_FILENAME = " << data.get_visible_video_filename() << endl;

   fout.close();

}

/** 
 * Order 
 *  - Thermal Video Filename
 *  - Visible Video Filename
 */
void print_window( ProgramOptions const& data, const int& pos, const int& start, const int& end ){

   for( int i=start; i<end; i++ ){

      switch( i ){

         case 0:

            printw("THERMAL_VIDEO_FILENAME = ");
            printw(data.get_thermal_video_filename().c_str());
            printw("\n");
            break;

         case 1:

            printw("VISIBLE_VIDEO_FILENAME = ");
            printw(data.get_visible_video_filename().c_str());
            printw("\n");
            break;

      }

   }


}

}//end of gui namespace 

#include "Program_Options.h"

using namespace std;

void ProgramOptions::addElement( pair<string,string>const& tmpStr ){

   //look for tags and convert accordingly

   /**  Thermal Video Filename */
   if( tmpStr.first == "THERMAL_VIDEO_FILENAME" )
      thermal_video_filename = tmpStr.second;
   
   /**  Visible Video Filename */
   if( tmpStr.first == "VISIBLE_VIDEO_FILENAME" )
      visible_video_filename = tmpStr.second;

   /** Add to raw data */
   raw_data.push_back(tmpStr);

}

string ProgramOptions::print()const{

   string info = "Program Data\n";

   info += string("THERMAL_VIDEO_FILENAME = ") + thermal_video_filename + string("\n");
   info += string("VISIBLE_VIDEO_FILENAME = ") + visible_video_filename + string("\n");

   return info;
}
      
std::string ProgramOptions::get_thermal_video_filename()const{
   return thermal_video_filename;
}

void ProgramOptions::set_thermal_video_filename( const string& new_filename ){
   thermal_video_filename = new_filename;
}

std::string ProgramOptions::get_visible_video_filename()const{
   return visible_video_filename;
}

void ProgramOptions::set_visible_video_filename( const string& new_filename ){
   visible_video_filename = new_filename;
}

int ProgramOptions::get_max()const{
   return 2;
}

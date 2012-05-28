#include "Program_Options.h"

using namespace std;

void ProgramOptions::addElement( pair<string,string>const& tmpStr ){

   //look for tags and convert accordingly

   /**  Thermal Video Filename */
   if( tmpStr.first == "THERMAL_VIDEO_FILENAME" )
      thermal_video_filename = tmpStr.second;


}

string ProgramOptions::print()const{

   string info = "Program Data\n";

   info += string("THERMAL_VIDEO_FILENAME = ") + thermal_video_filename;

   return info;
}

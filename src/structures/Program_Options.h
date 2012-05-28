#ifndef __SRC_STRUCTURES_PROGRAM_OPTIONS_H__
#define __SRC_STRUCTURES_PROGRAM_OPTIONS_H__

#include <string>
#include <utility>
#include <vector>


class ProgramOptions{

   public:


      void addElement( std::pair<std::string,std::string>const& tmpStr );

      std::string print()const;

      std::string get_thermal_video_filename()const;
      void set_thermal_video_filename( std::string const& new_filename );
      
      std::string get_visible_video_filename()const;
      void set_visible_video_filename( std::string const& new_filename );

      int get_max()const;

   private:
      
      std::string visible_video_filename;
      std::string thermal_video_filename;
      
      std::vector< std::pair< std::string, std::string> >  raw_data;

};

#endif


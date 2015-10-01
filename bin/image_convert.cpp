#include <iostream>
#include <string>

#include "image.h"
#include "imageIO.h"

int main(int argc, char** argv)
{
  // create a list of supported formats
  std::string support_list = "ppm, pfm";
#ifdef INCLUDE_PNG                   
  support_list = support_list + ", png";
#endif /* INCLUDE_PNG */             
#ifdef INCLUDE_OPENEXR                   
  support_list = support_list + ", exr";
#endif /* INCLUDE_OPENEXR */             
#ifdef INCLUDE_JPEG                   
  support_list = support_list + ", jpg";
#endif /* INCLUDE_JPEG */             
#ifdef INCLUDE_TIFF                   
  support_list = support_list + ", tif";
#endif /* INCLUDE_TIFF */             

  // parse commend line
  if(argc != 3)
  {
    std::cerr << "Usage: " << argv[0] << " <input image name> <output image name>" << std::endl;
    std::cerr << "  * Supported formats: " << support_list << std::endl;
    return -1;
  }

  // load and save images
  image img;
  ::io::importImage(argv[1], img);
  ::io::exportImage(argv[2], img);

  // Done.
  return 0;
}

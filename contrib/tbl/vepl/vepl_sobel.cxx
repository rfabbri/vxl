// This is tbl/vepl/vepl_sobel.cxx
#include "vepl_sobel.h"
#include <vipl/accessors/vipl_accessors_vil_image.h>
#include <vipl/vipl_sobel.h>
#include <vil/vil_memory_image_of.h>
#include <vil/vil_rgb.h>

vil_image vepl_sobel(vil_image const& image)
{
  // byte greyscale
  if (vil_pixel_format(image) == VIL_BYTE) {
    typedef unsigned char ubyte;
    vil_memory_image_of<ubyte> mem(image); // load in memory to pass to filter
    vil_memory_image_of<ubyte> out(image);
    vipl_sobel<vil_image,vil_image,ubyte,ubyte,vipl_trivial_pixeliter> op;
    op.put_in_data_ptr(&mem);
    op.put_out_data_ptr(&out);
    op.filter();
    return out;
  }

  // byte rgb
  else if (vil_pixel_format(image) == VIL_RGB_BYTE) {
    typedef unsigned char ubyte;
    vil_memory_image_of<vil_rgb<ubyte> > mem(image); // load in memory to pass to filter
    vil_memory_image_of<vil_rgb<ubyte> > out(image);
    vipl_sobel<vil_image,vil_image,vil_rgb<ubyte> ,vil_rgb<ubyte> ,vipl_trivial_pixeliter> op;
    op.put_in_data_ptr(&mem);
    op.put_out_data_ptr(&out);
    op.filter();
    return out;
  }

  // float
  else if (vil_pixel_format(image) == VIL_FLOAT) {
    vil_memory_image_of<float> mem(image); // load in memory to pass to filter
    vil_memory_image_of<float> out(image);
    vipl_sobel<vil_image,vil_image,float,float,vipl_trivial_pixeliter> op;
    op.put_in_data_ptr(&mem);
    op.put_out_data_ptr(&out);
    op.filter();
    return out;
  }

  // double
  else if (vil_pixel_format(image) == VIL_DOUBLE) {
    vil_memory_image_of<double> mem(image); // load in memory to pass to filter
    vil_memory_image_of<double> out(image);
    vipl_sobel<vil_image,vil_image,double,double,vipl_trivial_pixeliter> op;
    op.put_in_data_ptr(&mem);
    op.put_out_data_ptr(&out);
    op.filter();
    return out;
  }

  //
  else {
    vcl_cerr << __FILE__ ": vepl_sobel() not implemented for " << image << vcl_endl;
    return 0;
  }
}


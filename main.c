
/*********************************************************************************************

    This is public domain software that was developed by or for the U.S. Naval Oceanographic
    Office and/or the U.S. Army Corps of Engineers.

    This is a work of the U.S. Government. In accordance with 17 USC 105, copyright protection
    is not available for any work of the U.S. Government.

    Neither the United States Government, nor any employees of the United States Government,
    nor the author, makes any warranty, express or implied, without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or assumes any liability or
    responsibility for the accuracy, completeness, or usefulness of any information,
    apparatus, product, or process disclosed, or represents that its use would not infringe
    privately-owned rights. Reference herein to any specific commercial products, process,
    or service by trade name, trademark, manufacturer, or otherwise, does not necessarily
    constitute or imply its endorsement, recommendation, or favoring by the United States
    Government. The views and opinions of authors expressed herein do not necessarily state
    or reflect those of the United States Government, and shall not be used for advertising
    or product endorsement purposes.

*********************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "nvutility.h"


#include "binaryFeatureData.h"

#include "version.h"


int32_t main (int32_t argn, char **argv)
{
  uint32_t               i, j;
  int32_t                percent = 0, old_percent = -1, bfd_handle;
  BFDATA_SHORT_FEATURE   *feature = NULL;
  BFDATA_HEADER          bfd_header;
  BFDATA_POLYGON         bfd_polygon;
  FILE                   *fp;


  printf ("\n\n %s \n\n", VERSION);


  if (argn < 3)
    {
      fprintf (stderr, "Usage: dump_feature <bfd feature file> <output file>\n\n");
      fprintf (stderr, "Example: dump_feature pensacola.bfd pensacola_features.txt\n\n\n");
      exit (-1);
    }


  if ((bfd_handle = binaryFeatureData_open_file (argv[1], &bfd_header, BFDATA_READONLY)) < 0)
    {
      binaryFeatureData_perror ();
      exit (-1);
    }


  if ((fp = fopen (argv[2], "w")) == NULL)
    {
      fprintf (stderr,"\n\nUnable to open output file %s  -  %s\n\n", argv[2], strerror (errno));
      exit (-1);
    }


  fprintf (fp, 
           "#record number\tlatitude\tlongitude\tdepth\tconfidence\tdescription\tremarks\tpoly type\tpoly count lat lon...\n");


  if (binaryFeatureData_read_all_short_features (bfd_handle, &feature) < 0)
    {
      binaryFeatureData_perror ();
      exit (-1);
    }

  for (i = 0 ; i < bfd_header.number_of_records ; i++)
    {
      if (feature[i].confidence_level)
        {
          if (feature[i].poly_count)
            {
              if (binaryFeatureData_read_polygon (bfd_handle, i, &bfd_polygon) < 0)
                {
                  binaryFeatureData_perror ();
                  exit (-1);
                }

              fprintf (fp, "%05d\t%0.9lf\t%0.9lf\t%0.2f\t%d\t%s\t%s\t%d\t%d", i, feature[i].latitude, feature[i].longitude,
                       feature[i].depth, feature[i].confidence_level, feature[i].description, feature[i].remarks,
                       feature[i].poly_type, feature[i].poly_count);

              for (j = 0 ; j < feature[i].poly_count ; j++) fprintf (fp, " %0.9f %0.9f", bfd_polygon.latitude[j],
                                                                     bfd_polygon.longitude[j]);

              fprintf (fp, "\n");
            }
          else
            {
              fprintf (fp, "%05d\t%0.9lf\t%0.9lf\t%0.2f\t%d\t%s\t%s\n", i, feature[i].latitude, feature[i].longitude, feature[i].depth,
                       feature[i].confidence_level, feature[i].description, feature[i].remarks);
            }
        }

      percent = ((float) i / (float) bfd_header.number_of_records) * 100.0;
      if (percent != old_percent)
        {
          old_percent = percent;
          fprintf (stderr,"%03d%% Processed\r", percent);
          fflush (stderr);
        }
    }

  fprintf (stderr,"100%% Processed\n\n");
  fflush (stderr);


  binaryFeatureData_close_file (bfd_handle);


  fclose (fp);


  /*  Please ignore the following line.  It is useless.  Except...

      On some versions of Ubuntu, if I compile a program that doesn't use the math
      library but it calls a shared library that does use the math library I get undefined
      references to some of the math library functions even though I have -lm as the last
      library listed on the link line.  This happens whether I use qmake to build the
      Makefile or I have a pre-built Makefile.  Including math.h doesn't fix it either.
      The following line forces the linker to bring in the math library.  If there is a
      better solution please let me know at area.based.editor AT gmail DOT com.  */

  float ubuntu; ubuntu = 4.50 ; ubuntu = fmod (ubuntu, 1.0);


  return (0);
}

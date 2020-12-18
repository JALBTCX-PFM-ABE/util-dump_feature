
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


/*********************************************************************************************

    This program is public domain software that was developed by 
    the U.S. Naval Oceanographic Office.

    This is a work of the US Government. In accordance with 17 USC 105,
    copyright protection is not available for any work of the US Government.

    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*********************************************************************************************/

#ifndef VERSION

#define     VERSION     "PFM Software - dump_feature V1.14 - 07/23/14"

#endif

/*

    Version 1.0
    Jan C. Depner
    04/21/05


    Version 1.01
    Jan C. Depner
    05/04/06

    Minor format change to output.


    Version 1.02
    Jan C. Depner
    06/25/07

    Added polygon points to dump.


    Version 1.03
    Jan C. Depner
    10/22/07

    Added fflush calls after prints to stderr since flush is not automatic in Windows.


    Version 1.04
    Jan C. Depner
    04/07/08

    Replaced single .h files from utility library with include of nvutility.h


    Version 1.05
    Jan C. Depner
    09/17/08

    Added check_target_schema call.


    Version 1.10
    Jan C. Depner
    04/02/09

    Changed name to dump_feature from dump_target.  Replaced support for NAVO standard XML target file with
    Binary Feature Data (BFD) file support.


    Version 1.11
    Jan C. Depner
    05/28/09

    Fix polygon read screwup.  DOH!


    Version 1.12
    Jan C. Depner
    06/24/09

    Changed the BFD names to avoid collision with GNU Binary File Descriptor library.


    Version 1.13
    Jan C. Depner
    03/08/14

    Added a line to force the linker to use -lm on Ubuntu 12.04 LTS x86_64 using
    gcc 4.6.3.  See bottom of main.c for complete explanation.


    Version 1.14
    Jan C. Depner (PFM Software)
    07/23/14

    - Switched from using the old NV_INT64 and NV_U_INT32 type definitions to the C99 standard stdint.h and
      inttypes.h sized data types (e.g. int64_t and uint32_t).

*/


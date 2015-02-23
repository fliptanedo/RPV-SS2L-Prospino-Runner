/******************************************************************************** 
*   RPVgProspinoSpectrum.cpp by Flip Tanedo (pt267@cornell.edu)                 *
*   For updating the Prospino spectrum file (use with batch runs)               *
*   21 Jan 2013                                                                 *
*                                                                               *
*   Based on code used for changing Pythia input SUSY spectrum files.           *
*   Main usage: write a bash script which calls this program to update the      *
*   spectrum file.                                                              *
*                                                                               *
*   INPUT:                                                                      *
*     - output filename (file to be created)                                    *
*     - PID of particle whose mass should be updated                            *
*     - Mass that should replace the existing mass                              *
*                                                                               *
********************************************************************************/

#include "FlipCommandFileFixer.h"   // most of the meat is in this code
#include <fstream>                  // for file in/out
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 

    /****************************************************************************
    * DEFINE AND INITIALIZE PARAMETERS                                          *
    ****************************************************************************/

    string specfile = "prospino.in.les_houches";
    // assume this is the template file
    string blkmass = "Block MASS";
    string divider = "Block";
    
    string fileout  = "fileout.txt";    // file to be created
    string PID      = "1000006";        // stop PID as default
    string mass     = "200";            // default stop mass
    
    if (argc > 1)  PID      = argv[1];  // stop mass
    if (argc > 2)  mass     = argv[2];  // gluino mass
    if (argc > 3)  fileout  = argv[3];  // output file
    if (argc > 4)  specfile = argv[4];  // input spectrum file


    /****************************************************************************
    * UPDATE SPECTRUM USING "FLIP COMMAND FILE FIXER"                           *
    ****************************************************************************/

    string PIDline  = "   " + PID + "     " + mass; // line replacement
    
    if(!FixSpectrum(specfile, fileout, blkmass, divider, PID, PIDline)) 
        cout << "ERROR updating spectrum: " <<  PID << " " << mass << endl;
    
    // cout << PIDline << endl;
    
    return 0;
}
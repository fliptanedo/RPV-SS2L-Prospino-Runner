/******************************************************************************** 
*   RPVgProspinoSpectrum.cpp by Flip Tanedo (pt267@cornell.edu)                 *
*   For updating the Prospino spectrum file (use with batch runs)               *
*   22 Jan 2013                                                                 *
*                                                                               *
*   A small program (Python script probably would have been better) for taking  *
*   Prospino output and appending the NLO cross section to an output file.      *
*                                                                               *
*   INPUT:                                                                      *
*     - first mass that you're scanning over                                    *
*     - second mass that you're scanning over                                   *
*     - output filename (file to be created)                                    *
*     - input filename (Prospino output file, defaults to prospino.dat)         *
*                                                                               *
********************************************************************************/

#include <fstream>                  // for file in/out
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 

    /****************************************************************************
    * DEFINE AND INITIALIZE PARAMETERS                                          *
    ****************************************************************************/

    string mass01 = "mass01";
    string output = "RPVg_NLO.txt";
    string source = "prospino.dat";

    if (argc > 1)  mass01   = argv[1];  // alternate output file
    if (argc > 2)  output   = argv[2];  // alternate output file
    if (argc > 3)  source   = argv[3];  // alternate input file
    
    string word;
    
    // FILE STREAMS
    // ------------

    ofstream outstream;
    outstream.open(output.c_str(), ios::app); // append to end of file
    outstream.precision(6); 
    outstream.setf(ios::fixed);
    outstream.setf(ios::showpoint);
    
    ifstream instream;
    instream.open(source.c_str());
    
    /****************************************************************************
    * GRAB NLO K FACTOR                                                         *
    ****************************************************************************/

// ASSUMING THAT THE SOURCE FILE HAS THE FOLLOWING FORMAT
// ------------------------------------------------------
// bb  1  0     0.0    0.0    1.0  499.0  499.0  0.607 0.261E-01 0.784E-03 0.504E-01 0.640E-03 1.9310 0.261E-01 0.504E-01
// 
//     i1 i2  dummy0 dummy1 scafac  m1    m2      angle LO[pb]   rel_error NLO[pb]   rel_error   K    LO_ms[pb] NLO_ms[pb]  

    // getline(instream,line);
    // cout << line << endl;
    
    for(unsigned int iWord=0; iWord<16; iWord++){
        instream >> word;
    }

    outstream << mass01 << '\t' << word << endl;
    
    /****************************************************************************
    * CLEANUP FILE STREAMS                                                      *
    ****************************************************************************/

    instream.close();
    outstream.close();
    
    return 0;
}
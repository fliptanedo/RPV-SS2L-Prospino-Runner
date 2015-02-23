#!/bin/bash
# Scans over gluino mass and outputs NLO cross section
# Run: ./RPVgScanK.sh 720 5 16
# ------------------------------
# HOW TO USE
# arguments are as follows:
# $1 gluino mass starting value
# $2 gluino mass increment
# $3 gluino mass number of steps
# ------------------------------
# SPECIFY FILES
# ------------------------------
TEMPFILE=$(mktemp RPVg.temp.XXXX) 
SPECFILE=prospino.in.les_houches
KOUTFILE=RPVg_NLO.txt
KDATFILE=prospino.dat
#
for i in $(eval echo {0..$3});
    do
#   ------------------------------
#   MODIFY SPECTRUM
#   ------------------------------
    ./RPVgProspinoSpectrum 1000021 $(( $1 + $2*$i )) $TEMPFILE $SPECFILE
    mv $TEMPFILE $SPECFILE
#   ------------------------------
#    RUN PROSPINO
#   ------------------------------
#    ./prospino_2.run;
#   ------------------------------
#   OUTPUT TO DATA FILE
#   ------------------------------
    ./RPVgKout $(( $1 + $2*$i )) $KOUTFILE $KDATFILE 
    done
# ------------------------------
#!/bin/bash

# scputower.sh
# script to download from tower
# OG command of the form "scp -P 222 -r michael@91.69.16.29:/path/to/file /path/to/destination
# the script is called with 2 args "path/to/file" & "path/to/destination"

if [ "$1" == "-u" ]
then
	eval "scp -P 222 -r $2 michael@91.69.16.29:$3"
else if [ -n $2 ]
then
	eval "scp -P 222 -r michael@91.69.16.29:$1 $2"
else 
	echo "not enough args, expected 2 min 3 if upload"
fi
fi

#!/bin/bash

MPS_PATH=./test_maps/
MPS_COUNT=`ls -l ./test_maps/ | wc -l`

make

echo "Testing 0 args :\n"
./fdf
echo "Testing 2 args :\n"
./fdf ehuo ninhuo
echo "Testing non .fdf suffixed file :\n"
./fdf tuhotn
echo "Testing DNE .fdf file :\n"
./fdf utoh.fdf
echo "Testing all \"${MPS_PATH}\" maps: \n"

while [ "$MPS_COUNT" -gt 0 ]
do
	MPS_FILE=`ls ./test_maps/ | awk '{print $1}' | tail -${MPS_COUNT} | head -1`
	./fdf ${MPS_PATH}${MPS_FILE}
	echo "This is : $MPS_FILE"
	let MPS_COUNT-=1
done

exit 0

#!/bin/bash 

if [ -n $string1 ]		# string has not been declared or initialized.
then 
	echo "String \"string1\" is not null."
else
	echo "String \"string1\" is null."
fi

echo 

if [ -n "$string1" ] 		# This time, $string1 is quoted. 
then
	echo "String \"string1\" is not null."
else
	echo "String \"string1\" is null."
fi				# Quote strings within test brackets!



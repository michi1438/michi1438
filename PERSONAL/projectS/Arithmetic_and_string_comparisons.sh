#!/bin/bash 

a=6
b=3

#	Here "a" and "b" can be treated either as intergers or strings. 
#	There is some blurring bitween the arithmetic and string comparisons, 
#+	since Bash variables are not strongly typed.

#	Bash permits intergers operations and comparisons on variables 
#+	whose value consists of all-interger characters. 
#	Caution advised, however.

echo

if [ "$a" -ne "$b" ]
then 
	echo "$a is not equal to $b."
	echo "(arithmetic comparison)"
fi

echo

if [ "$a" != "$b" ]
then 
	echo "$a is not equal to $b."
	echo "(string comparison)"
	#	"4" != "5"
	# ASCII 52 != ASCII 53
fi

# In this particular instance, both "-ne" and "!=" act in the same way !

echo 

exit 0


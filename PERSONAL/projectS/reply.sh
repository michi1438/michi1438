#!/bin/bash
# reply.sh

echo 
echo -n "What is your favorite vegetable?"
read

echo "Your favorite vegetable is $REPLY."

echo 
echo -n "What is your favorite fruit then?"
read fruit 
echo "Your favorite fruit is $fruit."
echo "but..."
echo "Value of \$REPLY is still $REPLY."

echo 
exit 0

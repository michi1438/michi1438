#!/bin/bash4

echo "\$\$ outside of subshell = $$"
echo "\$BASH_SUBSHELL outside of subshell = $BASH_SUBSHELL"
echo "\$BASHPID outside of subshell = $BASHPID"

echo 

( echo "\$\$ outside of subshell = $$"
  echo "\$BASH_SUBSHELL outside of subshell = $BASH_SUBSHELL"
  echo "\$BASHPID outside of subshell = $BASHPID" )

 

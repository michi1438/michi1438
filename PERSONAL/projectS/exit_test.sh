#! /bin/bash

P4='$(read time junk < /proc/$$/schedstat; echo "@@@ $time @@@ ")'

set -x

true
echo "exit status of \"true\" = $?"

! true echo "exit status of \"! true\" = $?"

true 
!true
# No error, it just repeats the previous command (true).

ls | bogus_command 
echo $?

! ls | bogus_command 
echo $?

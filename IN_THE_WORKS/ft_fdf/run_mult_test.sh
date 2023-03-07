#!/bin/bash
#run_mult_test.sh
# Maybe test with -g3 -fsanitize=leak/address
#

OS=`uname`
MPS_PATH=test_maps/
MPS_COUNT=`ls -l ./test_maps/ | wc -l`
CFLAGS='-Werror -Wall -Wextra'
CC=gcc
FDF='leaks -atExit -- ./fdftest'

make fclean
make libfdf.a 

if [ ${OS} == "Darwin" ]
then
	${CC} ${CFLAGS} fdf.c -L./ -lfdf -Lft_libft_printf_gnl/ -lftprintf -Lminilibx_macos/ -lmlx -framework OpenGL -framework Appkit -o fdftest
fi

if [ ${OS} == "Linux" ]
then
	${CC} ${CFLAGS} fdf.c -L./ -lfdf -Lft_libft_printf_gnl/ -lftprintf -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -o fdftest
fi

echo "Testing 0 args :\n"
./fdftest
echo "Testing 2 args :\n"
$FDF fdhoh theuont
echo "Testing non .fdf suffixed file :\n"
$FDF run_mult_test.sh
echo "Testing DNE .fdf file :\n"
$FDF utoh.fdf
echo "Testing all \"${MPS_PATH}\" maps: \n"

while [ "$MPS_COUNT" -gt 0 ]
do
	MPS_FILE=`ls ./test_maps/ | awk '{print $1}' | tail -${MPS_COUNT} | head -1`
	$FDF ${MPS_PATH}${MPS_FILE}
	sleep 5
	echo "This is : $MPS_FILE"
	let MPS_COUNT-=1
done

make fclean
echo "Test is done !"

exit 0

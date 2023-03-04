#!/bin/bash
#run_mult_test.sh
# Maybe test with -g3 -fsanitize=leak/address
#

OS=`uname`
MPS_PATH=./test_maps/
MPS_COUNT=`ls -l ./test_maps/ | wc -l`
CFLAGS='-Werror -Wall -Wextra #-g -fsanitize=leak'
CC=gcc

make fclean
make libfdf.a

ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) fdf.c -L./ -lfdf -Lft_libft_printf_gnl/ -lftprintf -Lminilibx_macos/ -lmlx -framework OpenGL -framework Appkit -o fdf
endif
ifeq ($(OS), Linux)
	$(CC) $(CFLAGS) fdf.c -L./ -lfdf -Lft_libft_printf_gnl/ -lftprintf -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -o fdf 
endif

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

make fclean
echo "Test is done !"

exit 0

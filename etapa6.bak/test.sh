make clean
make
./etapa6 test.txt out.s
gcc -m32 -g -o out out.s
gdb out << END_TEXT
run
END_TEXT

make clean
make
./etapa6 t.lang out.s
gcc -g -o out out.s
gdb out << END_TEXT
run
END_TEXT

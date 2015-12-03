make clean
make

gdb etapa6 << END_TEXT
run t.lang out.s
END_TEXT

gcc -g -o out out.s
gdb out << END_TEXT
run
END_TEXT

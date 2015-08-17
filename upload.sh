cd parts/p1
make clean
tar cvzf etapa1.tgz .
cd ../../
mv parts/p1/etapa1.tgz public_html/etapa1.tgz 

sftp lhperin@html.inf.ufrgs.br << END_TEXT
put -r public_html
END_TEXT

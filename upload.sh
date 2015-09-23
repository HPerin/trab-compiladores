cd etapa1
make clean
tar cvzf etapa1.tgz .
cd ../
mv etapa1/etapa1.tgz public_html/etapa1.tgz

cd etapa2
make clean
tar cvzf etapa2.tgz .
cd ../
mv etapa2/etapa2.tgz public_html/etapa2.tgz

cd etapa3
make clean
tar cvzf etapa3.tgz .
cd ../
mv etapa3/etapa3.tgz public_html/etapa3.tgz

sftp lhperin@html.inf.ufrgs.br << END_TEXT
put -r public_html
put public_html/etapa1.tgz public_html/etapa1.tgz
put public_html/etapa2.tgz public_html/etapa2.tgz
put public_html/etapa3.tgz public_html/etapa3.tgz
put public_html/index.html public_html/index.html
END_TEXT

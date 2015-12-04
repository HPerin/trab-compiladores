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

cd etapa4
make clean
tar cvzf etapa4.tgz .
cd ../
mv etapa4/etapa4.tgz public_html/etapa4.tgz

cd etapa5
make clean
tar cvzf etapa5.tgz .
cd ../
mv etapa5/etapa5.tgz public_html/etapa5.tgz

cd etapa6
make clean
tar cvzf etapa6.tgz .
cd ../
mv etapa6/etapa6.tgz public_html/etapa6.tgz

sftp user@localhost << END_TEXT
put -r public_html
put public_html/etapa1.tgz public_html/etapa1.tgz
put public_html/etapa2.tgz public_html/etapa2.tgz
put public_html/etapa3.tgz public_html/etapa3.tgz
put public_html/etapa4.tgz public_html/etapa4.tgz
put public_html/etapa5.tgz public_html/etapa5.tgz
put public_html/etapa6.tgz public_html/etapa6.tgz
put public_html/index.html public_html/index.html
END_TEXT

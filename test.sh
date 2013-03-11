cd AnalyseurXML
make
./analyseXMl < $1
make clean
TEMP=$(grep SYSTEM $1)
${TEMP#}
echo $TEMP
echo dtd
echo $DTD
cd ../AnalyseurDTD
make
./analyseDTD < $2
make clean

cd AnalyseurXML

TEMP=$(grep -E '(<!DOCTYPE)(.*?)\"(.*?)\"' $1)
echo $TEMP[1]
echo dtd
echo $DTD
cd ../AnalyseurDTD
make
./analyseDTD < $2
make clean

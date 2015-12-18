#!/bin/sh

zoom=$1

if [ -z $zoom ]
then
	echo "usage: $0 zoomlevel"
	exit
fi

size=$((2**$zoom))

rm -rf $zoom
mkdir $zoom
cd $zoom

echo "start zoomlevel $zoom $size*$size"

for ((i=0; i<$size; i++))
do
	rm -rf $i
	mkdir $i
	cd $i
	for ((j=0; j<$size; j++))
	do
		wget -nv http://b.tile.openstreetmap.org/$zoom/$i/$j.png
		#axel -q http://b.tile.openstreetmap.org/$zoom/$i/$j.png
	done
	cd ..
done


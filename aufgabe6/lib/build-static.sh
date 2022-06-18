#!/bin/sh
for s in benotung.cpp fachnote.cpp fachnoten_liste.cpp ; do
    compile_command="gcc -cpp $s"
    echo $compile_command
    eval $compile_command
    if [ $? ne 0 ] ; then
        echo build failed
        exit 1
    fi
done
link_command="gcc -o benotung benotung.o"
echo $link_command
eval $link_command
if [ $? ne 0 ] ; then
    echo build failed
    exit 1
fi
link_command="gcc -o fachnote fachnote.o"
echo $link_command
eval $link_command
if [ $? ne 0 ] ; then
    echo build failed
    exit 1
fi
link_command="gcc -o fachnoten_liste fachnoten_liste.o"
echo $link_command
eval $link_command
if [ $? ne 0 ] ; then
    echo build failed
    exit 1
fi
echo build successful
lib_command="ar crs libaufgabe6.a benotung.o fachnote.o fachnoten_liste.o"
echo $lib_command
eval $lib_command
if [ $? ne 0 ] ; then
    echo libaufgabe6 erstellen failed
    exit 1
fi
echo libaufgabe6 erstellt
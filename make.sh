#! /bin/sh

g++ -MM *.cpp | sed -e 's/ .*.cpp//g' >> headerdepend
make
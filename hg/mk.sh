#!/bin/bash

dir_path=$1

echo "mkdir -p `pwd`/$dir_path/src"
mkdir -p `pwd`/$dir_path/src
echo "touch `pwd`/$dir_path/input.txt"
touch `pwd`/$dir_path/input.txt

if [ "$#" -eq 2 ]; then
    echo "touch `pwd`/$dir_path/src/$2"
	touch `pwd`/$dir_path/src/$2
fi
#!/bin/bash

dir_path=$1
src_fname=$2
num_args=$#


if [ "$num_args" -ge 2 ]; then
    echo "mkdir -p `pwd`/$dir_path/src"
    mkdir -p `pwd`/$dir_path/src
    echo "touch `pwd`/$dir_path/src/$src_fname"
    if [ `echo $src_fname | cut -d"." -f2` == "cpp" ]; then
        echo -e "#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n\treturn 0;\n}\n" > `pwd`/$dir_path/src/$src_fname
    else
        touch `pwd`/$dir_path/src/$src_fname
    fi
    if [ "$num_args" -eq 3 ]; then
        num_input=$3
        
        i=1
        while [ $i -le $num_input ]
        do
            echo "touch `pwd`/$dir_path/input.$i.txt"
            touch `pwd`/$dir_path/input.$i.txt
            i=`expr $i + 1`
        done
        # for i in {1..`echo $((num_input))`}
        # do
        #   echo "touch `pwd`/$dir_path/input.$i.txt"
        #   touch `pwd`/$dir_path/input.$i.txt
        # done
    else
        echo "touch `pwd`/$dir_path/input.1.txt"
        touch `pwd`/$dir_path/input.1.txt    
    fi

else
    echo "Usage: $0 [directory path] [source file name with extension] (number of input file. optional)"
    echo "Supported file extension: cpp, py, asm"
    echo "사용법: $0 [디렉토리 경로] [확장자 포함 소스파일 이름] (입력 파일 개수. 옵션)"
    echo "지원하는 확장자: cpp, py, asm"
    

fi
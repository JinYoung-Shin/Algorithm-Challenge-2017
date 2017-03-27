#!/bin/bash

cd $1
g++ src/$2.cpp -o bin/$2.out -std=c++11

COMPILER_RET_STATUS=$?
if [ "$COMPILER_RET_STATUS" != "0" ]
then
	echo "컴파일 에러!"
	exit 1
fi

INPUT_ARR=($(ls input*.txt))

for var in "${INPUT_ARR[@]}"
do
	echo "${var}: 입력 케이스 ---------"
	bin/$2.out < ${var}
	echo "----------------------------------------"
	echo ""
done

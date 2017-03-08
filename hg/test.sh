#!/bin/bash

cd $1
g++ src/$2.cpp -o bin/$2.out && bin/$2.out
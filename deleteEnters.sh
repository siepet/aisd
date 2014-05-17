#!/bin/bash
fileName=$1
tr -d '\n' < $fileName > tmp
rm $fileName
mv tmp $fileName

#!/bin/bash

option=$1
dataset=$2

make
./NUCLIUS $option $dataset
#echo "Dataset normalizing..."
#./libsvm-3.21/svm-scale testing-data.txt > testing-data-scale.txt
#echo "Dataset normalization done."
#./libsvm-3.21/svm-predict -b 1 testing-data-scale.txt LibSVMDatasetFormat_train.txt.model results

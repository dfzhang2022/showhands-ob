#!/bin/bash

# Get current directory
current_dir=$(pwd)

# Navigate to parser directory and run gen_parser.sh
cd $current_dir/test/case/
python3 miniob_test.py

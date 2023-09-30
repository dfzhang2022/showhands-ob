

#!/bin/bash

# Get current directory
current_dir=$(pwd)

# Navigate to parser directory and run gen_parser.sh
cd $current_dir/src/observer/sql/parser/
./gen_parser.sh

# Navigate back to build directory and run observer
cd $current_dir/build
./bin/observer -f ../etc/observer.ini -P cli

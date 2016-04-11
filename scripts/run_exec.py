#!python

import sys

temp_dir = "./../temp/"
executable = "./../bin/solver"
command = r"java -jar tester.jar -exec '" + executable + " -d' -vis " + " ".join(sys.argv[1:])

# make sure temp directory exists
import os

if not os.path.isdir(temp_dir):
    os.makedirs(temp_dir)

os.system(command)

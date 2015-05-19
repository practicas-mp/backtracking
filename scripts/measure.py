#!/usr/bin/python
import subprocess, sys


def execution_time(program_name, data_file):
	return double(subprocess.check_output([program_name, data_file, "t"])

def exact_data_file(n):
	return "data/set" + str(n) + "-exact.txt"

def approx_data_file(n):
	return "data/set" + str(n) + "-approx.txt"


program_name = sys.argv[1]
problem_sizes = [10, 50, 100, 1000, 10000]

print "exact data files"
for (i, problem_size) in enumerate(problem_sizes):
	print i, execution_time(exact_data_file(problem_size))

print "approx data files"
for (i, problem_size) in enumerate(problem_sizes):
	print i, execution_time(approx_data_file(problem_size))
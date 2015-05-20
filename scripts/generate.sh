#!/bin/bash

NUMBER_OF_PLAYERS=$1

python scripts/random-players.py $NUMBER_OF_PLAYERS > data/set${NUMBER_OF_PLAYERS}-approx.txt
python scripts/random-players.py $NUMBER_OF_PLAYERS 0 > data/set${NUMBER_OF_PLAYERS}-exact.txt
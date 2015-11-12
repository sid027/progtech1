#!/bin/bash

./random | tee random.dat
python random_plot.py

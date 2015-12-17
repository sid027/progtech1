#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author:  Dominik Gresch <greschd@gmx.ch>
# Date:    14.12.2015 14:33:29 CET
# File:    main.py

from __future__ import division, print_function

from pypenna import Simulation, Fishing

import random

def run(sim, time, of):
    while sim.time < time:
        sim.step()
        of.write('{0.time}\t{0.N}\n'.format(sim))

def main(N, M1, p1, M2, p2):
    random.seed(0)
    sim = Simulation(
        mutation_rate=1,
        bad_threshold=3,
        repr_age=7,
        N_max=200000,
        N_0=20000,
    )
    with open('population.dat', 'w') as of:
        of.write('# time\tN\n')
        run(sim, M1, of)
        sim.fishing = Fishing(probability=p1)
        run(sim, M2, of)
        sim.fishing = Fishing(probability=p2)
        run(sim, N, of)

if __name__ == "__main__":
    main(N=1600, M1=1000, p1=0.17, M2=1200, p2=0.22)

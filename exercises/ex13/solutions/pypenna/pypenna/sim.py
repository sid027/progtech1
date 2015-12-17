#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author:  Dominik Gresch <greschd@gmx.ch>
# Date:    14.12.2015 13:14:45 CET
# File:    sim.py

from __future__ import division, print_function

from .fish import Fish
from .genome import Genome
from .fishing import Fishing

import copy
import random

class Simulation(object):
    """
    Simulation class for Penna. 
    """
    def __init__(
            self,
            mutation_rate,
            bad_threshold,
            repr_age,
            N_max,
            N_0,
            fishing=None,
            pregnancy_prob=1
        ):
        Genome.bad_threshold = bad_threshold
        Genome.mutation_rate = mutation_rate
        Fish.repr_age = repr_age
        self.N_max = N_max
        self.time = 0

        if fishing is not None:
            self.fishing = fishing
        else:
            self.fishing = Fishing()

        Fish.pregnancy_prob = pregnancy_prob
        
        self.population = [Fish() for _ in range(N_0)]

    @property
    def N(self):
        """
        Number of fish in the population
        """
        return len(self.population)

    def step(self):
        """
        Performs the iteration for one year
        """
        for fish in self.population:
            fish.grow()

        self.population = [
            fish for fish in self.population
            if not fish.is_sick()
            if not random.random() < self.N / self.N_max
            if not self.fishing.is_fished(fish)
        ]

        # Copy the population to create the "parents" list.
        for fish in copy.copy(self.population):
            if fish.is_pregnant():
                self.population.append(fish.make_child())

        self.time += 1

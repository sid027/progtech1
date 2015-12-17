#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author:  Dominik Gresch <greschd@gmx.ch>
# Date:    14.12.2015 13:14:52 CET
# File:    fish.py

from __future__ import division, print_function

from .genome import Genome

import random

class Fish(object):
    def __init__ (self, genome=None, age=0):
        self.genome = Genome(genome)
        self.age = age

    def is_pregnant(self):
        """
        Returns whether a fish is pregnant or not.
        """
        if self.is_adult():
            return random.random() < self.__class__.pregnancy_prob
        return False
    
    def is_adult(self):
        """
        Returns whether the fish has reached the reproductive age.
        """
        return self.age >= self.__class__.repr_age
    
    def make_child(self):
        """
        Returns a child fish with age 0 and a genome that is a mutated
        version of the parent's genome.
        """
        child = Fish(Genome(self.genome))
        child.genome.mutate()

        return child

    def grow(self):
        """
        Makes the fish one year older.
        """
        self.age += 1
    
    def is_sick(self):
        """
        Returns whether the fish is sick due to too many bad genes.
        """
        return (
            self.genome.num_bad(self.age) >= self.genome.bad_threshold or
            self.age >= self.genome.gene_size
        )

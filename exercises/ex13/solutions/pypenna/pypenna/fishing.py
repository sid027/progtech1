#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author:  Dominik Gresch <greschd@gmx.ch>
# Date:    14.12.2015 13:38:07 CET
# File:    fishing.py

from __future__ import division, print_function

import random

class Fishing(object):
    """
    Class for determining whether a given fish is being fished, given
    a certain fishing probability and minimum fishing age.
    """
    def __init__(self, probability=0, min_age=0):
        self.probability = probability
        self.min_age = min_age

    def is_fished(self, fish):
        """
        Determines whether the given fish is being fished. Returns True
        if the fish gets fished, and False else.
        """
        if fish.age >= self.min_age:
            return random.random() < self.probability
        return False

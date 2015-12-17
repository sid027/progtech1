#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Author:  Dominik Gresch <greschd@gmx.ch>
# Date:    09.12.2015 19:09:43 CET
# File:    main.py

import hello
from include.world import world

def main():
    print('{} {}'.format(hello.hello(), world()))

if __name__ == "__main__":
    main()

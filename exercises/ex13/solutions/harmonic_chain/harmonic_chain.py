#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Programming Techniques for Scientific Simulations, HS 2015, Week13
# File:    harmonic_chain.py

from __future__ import (absolute_import, division, print_function,
                        unicode_literals)


import numpy as np


def omega_calculated(K, m, N):
    """Calculates omega from the eigenvalue problem."""
    W = 2 * np.eye(N) - np.eye(N, k=1)
    return np.sqrt(K / m * np.linalg.eigvalsh(W, UPLO='U'))


def omega_theoretical(K, m, N):
    """Calculates omega theoretically."""
    return np.sqrt(
        K / m * (2 - 2 * np.cos(
            np.pi * np.array(range(1, N + 1)) / (N + 1)
        ))
    )


def main(K=1., m=1., N=16):
    print(('{:25}' * 3 + '\n').format(
        'Omega (calculated)',
        'Omega (theoretical)',
        'relative error'
    ))
    for w1, w2 in zip(
        omega_calculated(K=K, m=m, N=N),
        omega_theoretical(K=K, m=m, N=N)
    ):
        print((3 * '{:<25.7g}').format(w1, w2, abs((w1 - w2) / w2)))

if __name__ == "__main__":
    main()

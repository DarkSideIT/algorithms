import random

def crc(data: str):
    h = 0
    for ki in data:
        ki_val = ord(ki)
        high_order = h & 0xf8000000
        h = h << 5
        h = h ^ (high_order >> 27)
        h = h ^ ki_val
    return h


def pjw(data):
    h = 0
    for ki in data:
        ki_val = ord(ki)
        h = (h << 4) + ki_val
        g = h & 0xf0000000
        if g != 0:
            h = h ^ (g >> 24)
            h = h ^ g
    return h


def buz(data):
    h = 0
    R = dict()
    for ki in data:
        ki_val = ord(ki)
        high_order = h & 0x80000000
        h = h << 1
        h = h ^ (high_order >> 31)
        if not (ki_val in R):
            R[ki_val] = random.randint(0, 0xFFFFFFFF)
        h = h ^ R[ki_val]
    return h


def hash_default(data):
    return hash(data)
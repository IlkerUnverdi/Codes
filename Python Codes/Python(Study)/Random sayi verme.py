#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Dec 24 17:27:27 2023

@author: ilkerunverdi
"""

import random

# 0 ile 1 arasinda
print(random.random())

# herhangi 2 sayi
print(random.uniform(19, 50))

#2 tam sayi

print(random.randint(10, 20))

#belirli sayi
print(random.sample(range(10), k=5))

#karistirma

mylist = list(range(5,15))
print(mylist)
random.shuffle(mylist)
print(mylist)
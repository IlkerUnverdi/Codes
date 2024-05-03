#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Dec 15 00:07:10 2023

@author: ilkerunverdi
"""

y = int(input("Please enter a number"))

x = 1

while(x <= y):
    if(x%7 == 0):
        print(x)
    x = x+1
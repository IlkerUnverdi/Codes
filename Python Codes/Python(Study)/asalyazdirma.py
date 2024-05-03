#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Dec 24 16:09:29 2023

@author: ilkerunverdi
"""

def asal(sayi):
    if (sayi <= 1):
        return False
    for i in range (2, sayi):
        if (sayi % i == 0):
            return False
    else:
        return True
    
for x in range (500, 700):
    if(asal(x)):
        print(x, end=" ")
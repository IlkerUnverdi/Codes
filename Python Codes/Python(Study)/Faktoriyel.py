#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Nov 24 16:23:37 2023

@author: ilkerunverdi
"""

def hesapla(n):
    if (n==1):
        return 1
    else:
        return (n*hesapla(n-1))
    
print (hesapla(5))
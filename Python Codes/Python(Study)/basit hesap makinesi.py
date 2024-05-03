#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec 14 17:05:31 2023

@author: ilkerunverdi
"""

sayi1 = float(input("Please enter the first number that you want to calculate: "))

while(True):
    islem = str(input("Which transaction do you want to do: "))
    if (islem == "+"):
        sayi2 = float(input("Please enter the second number that you want to calculate: "))
        sonuc = sayi1 + sayi2
        break
    elif(islem == "-"):
        sayi2 = float(input("Please enter the second number that you want to calculate: "))
        sonuc = sayi1 - sayi2
        break
    elif(islem == "*"):
        sayi2 = float(input("Please enter the second number that you want to calculate: "))
        sonuc = sayi1 * sayi2
        break
    elif(islem == "/"):
        sayi2 = float(input("Please enter the second number that you want to calculate: "))
        sonuc = sayi1 / sayi2
        break
    else:
        print("You put wrong transaction please re-enter it again: ")


print(sayi1, islem, sayi2, "=", sonuc)
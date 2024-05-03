#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Dec 24 17:00:01 2023

@author: ilkerunverdi
"""


def bolme(bolunen, bolen):
    try:
        bolum = bolunen / bolen
        global islemdurumu
        islemdurumu = "Basarili"
        return bolum
    except ZeroDivisionError:
        islemdurumu = "Basarisiz"
        print("Bolen 0 olamaz")
    except:
        print("Harf girmeyiniz hatali")
    finally:
        print("Fonksiyon cikisi")
        
print(bolme(12, 0))


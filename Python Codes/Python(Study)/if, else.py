#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Nov 24 15:34:26 2023

@author: ilkerunverdi
"""

kullanici_adi = input("Lutfen Kullanici adi giriniz: ")

if (kullanici_adi == "admin"):
    print("Hosgeldiniz")
else:
    print("Programa giris yetkiniz yoktur")
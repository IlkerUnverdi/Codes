#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec 25 18:29:22 2023

@author: ilkerunverdi
"""

class Otomobil():
    klima = "klima yok"
    tekersayisi = 4
    
    def __init__(self, marka, model , yil, km):
        self.marka = marka
        self.model = model
        self.yil = yil
        self.km = km


audi_oto = Otomobil("Audi", "A3", 2015, 20000)
opel_oto = Otomobil("Opel", "Astra", 2020, 5000)
mercedes_oto = Otomobil("Mercedes", "E 200", 1990, 350000)

audi_oto.klima = "Otomotik klima"
opel_oto.klima = "Manuel klima"

print(audi_oto.marka, audi_oto.model, audi_oto.yil, audi_oto.km, audi_oto.klima)
print(opel_oto.marka, opel_oto.model, opel_oto.yil, opel_oto.km, opel_oto.klima)
print(mercedes_oto.marka, mercedes_oto.model, mercedes_oto.yil, mercedes_oto.km, mercedes_oto.klima)

satilikaraclist = [audi_oto, opel_oto, mercedes_oto]


for i in satilikaraclist:
    print(i.marka, i.model, i.yil, i.km, i.klima)
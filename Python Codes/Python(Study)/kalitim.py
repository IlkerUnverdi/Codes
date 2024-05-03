#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec 25 18:51:36 2023

@author: ilkerunverdi
"""

class Karaaraci():
    hiz = 0
    def __init__(self, beygirgucu, tekersayisi):
        self.beygirgucu = beygirgucu
        self.tekersayisi = tekersayisi
        
    def hizayarla(self, deger):
        self.hiz = deger
        
class Otobus(Karaaraci):
    def __init__(self, beygirgucu, tekersayisi, yolcukapasitesi):
        Karaaraci.__init__(self, beygirgucu, tekersayisi)
        self.yolcukapasitesi = yolcukapasitesi
        
        
class Otomobil(Karaaraci):
    def __init__(self, beygirgucu, tekersayisi, camtavan):
        Karaaraci.__init__(self, beygirgucu, tekersayisi)
        self.camtavan = camtavan
        
otomobil1 = Otomobil(120, 4, "var")
otomobil1.hizayarla(70)       
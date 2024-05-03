#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec 18 13:09:33 2023

@author: ilkerunverdi
"""

import aritmetik # , aritmetik.karehesapla()
#from aritmetik import * , #aritmetik dosyasindaki fonksiyonlar kopyalayip 
#yapistirmis gibi olur 'aritmetik.' kullanilmaz
import mesaj

kullanicisayi = int(input("Bir sayi giriniz: "))

print(aritmetik.karehesapla(kullanicisayi))
print(aritmetik.kuphesapla(kullanicisayi))
mesaj.mesajyaz("Hosgeldiniz")
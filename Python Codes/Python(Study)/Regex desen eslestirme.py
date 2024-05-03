#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Dec 26 12:09:13 2023

@author: ilkerunverdi
"""

import re

cumle = "Modüler yapısı, sınıf dizgesini (sistem) ve her türlü veri alanı girişini destekler. Hemen hemen her türlü platformda çalışabilir (Unix, Linux, Mac, Windows, Amiga, Symbian). Python ile sistem programlama, kullanıcı arabirimi programlama, ağ programlama, web programlama, uygulama ve veri tabanı yazılımı programlama gibi birçok alanda yazılım geliştirebilirsiniz. Büyük yazılımların hızlı bir şekilde prototiplerinin üretilmesi ve denenmesi gerektiği durumlarda da C ya da C++ gibi dillere tercih edilir. Python 1980'lerin sonunda ABC programlama diline alternatif olarak tasarlanmıştı. Python 2.0, ilk kez 2000 yılında yayınlandı. 2008'de yayınlanan Python 3.0, dilin önceki versiyonuyla tam uyumlu değildir ve Python 2.x'te yazılan kodların Python 3.x'te çalışması için değiştirilmesi gerekmektedir. Python 2 versiyonun resmi geliştirilme süreci, dilin son sürümü olan Python 2.7.x serisi versiyonların ardından 1 Ocak 2020 itibarıyla resmi olarak sona erdi.[4][5] Python 2.x geliştirilme desteğinin sona ermesinin ardından, Python dilinin 3.7.x ve sonraki sürümlerinin geliştirilmesi devam etmektedir."

patern = "Python"

sonuc = re.search(patern, cumle)

print(sonuc.start(), sonuc.end())

count = 0

for bulunan in re.finditer(patern, cumle):
    print(bulunan.span(), bulunan.group())
    count = count + 1

print(count)

cumle2 = "Merhaba benim telefon numaram 532-1112233 beni ogleneden sonra arayabilirsiniz.."

# rakamlar icin \d
#harfler icin \w
#bosluk icin \s

patern = "\d\d\d-\d\d\d\d\d\d\d"

print(re.search(patern, cumle2))
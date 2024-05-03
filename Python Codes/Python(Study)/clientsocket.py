#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Dec 26 17:48:49 2023

@author: ilkerunverdi
"""

import socket

#Soketi olusturuyoruz
client_socket = socket.socket()

#Server sokete baglanti sagliyoruz
client_socket.connect(("192.168.1.132", 50000))

mesaj = "Client-2 sistemden selamlar..."
cikis_mesaji = "exit"

#Server sisteme mesaj gondermek
client_socket.send(bytes(cikis_mesaji, 'utf-8'))
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Dec 26 17:18:36 2023

@author: ilkerunverdi
"""

import socket

#Socket olusturma

server_socket = socket.socket()

server_socket.bind(('192.168.1.131', 50000)) 


server_socket.listen(5)
print("Socket olusturuldu baglanti beleniyor...")

while True:
    client_socket, adres = server_socket.accept()
    print(adres, "isimli bilgisayar ile baglanti kuruldu")
    
    #Client sistemden gelen mesaji ekrana yazdiriyoriz
    gelen_mesaj = client_socket.recv(1024).decode()
    print(gelen_mesaj)
    
    client_socket.close()
    
    
    if(gelen_mesaj == 'exit'):
        break
    
print("Hoscakalin...")
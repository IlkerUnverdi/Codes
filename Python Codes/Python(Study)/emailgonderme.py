#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Dec 26 12:32:19 2023

@author: ilkerunverdi
"""

import smtplib
from email.mime.text import MIMEText

try:
    #Create your SMPT session
    smtp = smtplib.SMTP('smtp.gmail.com', 587)
    
    #Use TLS to add security
    smtp.starttls()
    
    #User authentication
    smtp.login("ibrahimilkerunverdi@gmail.com", "3412684ilker")
    #smtp.login("testpython2022@gmail.com", "sifre")
    
    #Defining the message
    mesaj = "Hello, this is a test message.."
    
    #Sending the email
    smtp.sendmail("ibrahimilkerunverdi@gmail.com", "ilker.unverdi@hotmail.com", mesaj)
    #smtp.sendmail("sender_email_id", "reciever_email_id", message)
    
    #Terminating the session
    smtp.quit()
    print ("Email basariyla gonderildi")
    
except Exception as ex:
    print("Birseyler ters gitti",ex) 
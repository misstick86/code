#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 11/16/2019


import socket

HOST = '127.0.0.1'
PORT = 8000
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hello, world')
    data = s.recv(1024)
print('Received', repr(data))




'''


class A():

    def func(self):
        print('func')


a = A()
func = getattr(a,'',0)

print(func)

'''
#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 11/16/2019

import http


import socket,json,time
addr_port = ('127.0.0.1', 8001)
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(addr_port)
    s.listen(1)
    print("listen: http://%s:%s" % addr_port)
    while True:
        conn, addr = s.accept()
        with conn:
            data = conn.recv(1024)
            print('conn: IP %s, port: %s' % addr)
            print(data);
            if not data: break
            conn.send('HTTP/1.1 200 OK\r\n\r\n'.encode())
            conn.sendall(json.dumps({'code':200,'msg':'success'}).encode())
            conn.send(''.encode())
    s.close()
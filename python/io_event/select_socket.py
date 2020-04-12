#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 11/27/2019

import time
import socket, select,json

l_addr=('127.0.0.1',8000)
def serve():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind(l_addr)
    print("listen: http://%s:%s" % l_addr)
    s.listen(1)
    inputs =[s,]
    outputs=[]
    s.setblocking(False)
    while True:

        r,w,e=select.select(inputs,outputs,inputs)
        print("readables number: ", len(inputs))
        for obj in r:
            if obj==s:
                conn,addr=obj.accept()
                conn.setblocking(0)
                inputs.append(conn)

            else:
                data_recv = obj.recv(1024)
                if not data_recv:
                    inputs.remove(obj)
                    if obj in outputs:
                        outputs.remove(obj)
                    obj.close()
                if data_recv:
                    if obj not in outputs:
                        outputs.append(obj)

        for obj in w:
            # print('deal socket...')
            time.sleep(5)
            obj.send('HTTP/1.1 200 OK\r\n\r\n'.encode())
            obj.sendall(json.dumps({"ret":0,"msg":"success"}).encode())
            e.append(obj)

        for obj in e:
            inputs.remove(obj)
            if obj in outputs:
                outputs.remove(obj)
            obj.close()


if __name__=='__main__':
    serve()


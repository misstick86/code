#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 4/12/20


import select,socket,json,time

l_addr=('127.0.0.1',8000)


def server():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(l_addr)
    s.listen(1)
    print("listen: http://%s:%s" % l_addr)
    s.setblocking(0)
    epoll = select.epoll()
    epoll.register(s.fileno(),select.EPOLLIN)
    try:
        conn_dict={}
        while True:
            events = epoll.poll()
            print(len(events))
            for fd, event in events:
                if event == select.EPOLLIN:
                    if fd == s.fileno():
                        conn,addr = s.accept()
                        conn.setblocking(False)
                        epoll.register(conn.fileno(),select.EPOLLIN)
                        conn_dict[conn.fileno()]=conn
                    else:
                        print('input request...')
                        conn = conn_dict[fd]
                        data = conn.recv(1024)
                        if data:
                            epoll.modify(conn.fileno(),select.EPOLLOUT)
                elif event == select.EPOLLOUT:
                    time.sleep(1)
                    conn = conn_dict[fd]
                    conn.send('HTTP/1.1 200 OK\r\n\r\n'.encode())
                    conn.sendall(json.dumps({"ret":0,"msg":"success"}).encode())
                    conn.shutdown(socket.SHUT_RDWR)
                elif event == select.EPOLLHUP:
                    conn = conn_dict[fd]
                    epoll.unregister(conn.fileno())
                    conn.close()
    finally:
        epoll.unregister(s.fileno())
        epoll.close()
        s.close()


if __name__ == '__main__':
    server()

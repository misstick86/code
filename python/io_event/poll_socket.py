#! /usr/bin/env python
# -*- coding: utf-8 -*-
# __author__ = "busyboy"
# Date: 4/12/20


import select, socket,time,json

l_addr=('127.0.0.1',8000)

def server():
    # init socket
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind(l_addr)
    print("listen: http://%s:%s" % l_addr)
    s.listen(1)
    s.setblocking(True)
    # init poll
    my_poll = select.poll()
    my_poll.register(s.fileno(),select.EPOLLIN)
    conn_dict={}
    try:
        while True:
            events = my_poll.poll()
            print(len(events))
            for fd, event in events:
                if event == select.POLLIN:
                    print('poll in.....')
                    if fd == s.fileno():
                        conn,addr = s.accept()
                        conn.setblocking(False)
                        my_poll.register(conn.fileno(),select.EPOLLIN)
                        conn_dict[conn.fileno()]=conn
                    else:
                        conn = conn_dict[fd]
                        data = conn.recv(1024)
                        if data:
                            my_poll.modify(conn.fileno(),select.POLLOUT)
                elif event == select.POLLOUT:
                    time.sleep(1)
                    # print('deal requests...')
                    conn = conn_dict[fd]
                    conn.send('HTTP/1.1 200 OK\r\n\r\n'.encode())
                    conn.sendall(json.dumps({"ret":0,"msg":"success"}).encode())
                    my_poll.unregister(conn.fileno())
                    conn.close()
    except Exception as e:
        s.close()
    finally:
        print(123)
        s.close()
if __name__ == '__main__':
    server()
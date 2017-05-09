import random
import time
import socket

'''
=== port ===

8000: stop and wait
8001: go back n
'''

host = 'localhost'

def stop_and_wait():
    port = 8000
    count = 1
    error_maker = 0

    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)   # creating socket
        print('server socket created')
    except:
        print('Fail - cannot create server socket')
        exit(-1)

    try:
        server.bind((host, port))
    except:
        print('Fail - cannot bind server socket')
        exit(-1)

    print('server socket bind complete')

    while True:
        data_set = server.recvfrom(1024)
        data = data_set[0]
        client_addr = data_set[1]

        if not data:
            break
        
        error_maker = random.randint(0, 100)
        
        if error_maker%10==0:
            pass
        else:
            if str(data.decode('utf-8')) != str(count):
                reply = ('NAK').encode('utf-8')
            else:
                print(data.decode('utf-8'))
                reply = ('ACK Seq #' + data.decode('utf-8')).encode('utf-8')
                count += 1
            
            server.sendto(bytes(reply), client_addr)

    server.close()

def go_back_n():
    port = 8001
    slide_size = 4
    block_count = 1
    data_count = 0
    saver = set()

    try:
        server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)   # creating socket
        print('server socket created')
    except:
        print('Fail - cannot create server socket')
        exit(-1)

    try:
        server.bind((host, port))
    except:
        print('Fail - cannot bind server socket')
        exit(-1)

    print('server socket bind complete')

    while True:
        data_set = server.recvfrom(1024)
        data_count = data_count + 1
        data = data_set[0]
        client_addr = data_set[1]

        if not data:
            break

        saver.add(str(data.decode('utf-8')))
        print(str(data.decode('utf-8')))

        if data_count%4 == 0:
            data_count = 0
            if len(saver) != 4:
                reply = ('NAK - '+data.decode('utf-8')).encode('utf-8')
            else:
                print('== Receive Block: '+str(block_count)+' ==')
                reply = ('ACK Seq #' + data.decode('utf-8')).encode('utf-8')
                block_count = block_count + 1
            server.sendto(bytes(reply), client_addr)
            saver.clear()

    server.close()

if __name__ == '__main__':
    print('1) Stop and Wait  2) Go back N')
    selection = int(input())

    if selection==1:
        stop_and_wait()
    else:
        go_back_n()

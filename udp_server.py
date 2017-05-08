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
        
        if str(data.decode('utf-8')) != str(count):
            reply = ('NAK').encode('utf-8')
        else:
            print(data.decode('utf-8') + 'count : ' + str(count))
            reply = ('ACK Seq #' + data.decode('utf-8')).encode('utf-8')
            count += 1
        server.sendto(bytes(reply), client_addr)

    server.close()

def go_back_n():
    port = 8001

selection = int(input())

if selection==1:
    stop_and_wait()
else:
    go_back_n()

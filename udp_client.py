import socket

'''
=== port ===

8000: stop and wait
8001: go back n
'''

host = 'localhost'

def stop_and_wait():
    port = 8000

    try:
        client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        client.settimeout(1)
        print('client socket created')
    except:
        print('Fail - cannot create client socket')
        exit(-1)

    while True:
        msg = bytes(input().encode('utf-8'))
        
        try:
            client.sendto(msg, (host, port))
            acknowledged = False
            while not acknowledged:
                try:
                    data_set = client.recvfrom(1024)
                    reply = data_set[0]
                    server_addr = data_set[1]
                    acknowledged = True
                except socket.timeout:
                    print('== Re-Send == : ' + str(msg.decode('utf-8')))
                    client.sendto(msg, (host, port))

            print(str(reply.decode('utf-8')))
        except Exception as e:
            print(e)
            print('Fail - cannot send message')
            exit(-1)

def go_back_n():
    port = 8001

selection = int(input())

if selection==1:
    stop_and_wait()
else:
    go_back_n()

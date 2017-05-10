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
            if str(reply.decode('utf-8')) == 'NAK':
                print('== Need to Re-Send ==')

        except Exception as e:
            print(e)
            print('Fail - cannot send message')
            exit(-1)

def go_back_n():
    port = 8001
    slide_size = 4
    block = 0
    data = 1

    try:
        client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        client.settimeout(1)
        print('client socket created')
    except:
        print('Fail - cannot create client socket')
        exit(-1)
    
    while True:
        block = block + 1
        print('==Block '+str(block)+'==')
        
        # send block
        for i in range(0, 4):
            #msg = bytes(str(data).encode('utf-8'))
            #print(data)
            msg = bytes(input().encode('utf-8'))
            client.sendto(msg, (host, port))
            data = data + 1
        
        data_set = client.recvfrom(1024)
        reply = data_set[0]
        server_addr = data_set[1]

        m = str(reply.decode('utf-8'))
        print(m)
        
        # resend block
        if m[:3] == 'NAK':
            resend_block = m[6:]
            #resend_data = (int(resend_block)*4) - 3
            #resend_data = bytes(input().encode('utf-8'))
            print('== Re-Send: Block '+resend_block+' ==')
            for i in range(0, 4):
                #print(resend_data)
                resend_data = bytes(input().encode('utf-8'))
                client.sendto(str(resend_data).encode('utf-8'), (host, port))
                #resend_data = resend_data + 1

if __name__ == '__main__':
    print('1) Stop and Wait  2) Go back N')
    selection = int(input())

    if selection==1:
        stop_and_wait()
    else:
        go_back_n()
import java.io.*;
import java.net.*;
import java.util.*;

class ErrorControlClient
{
    public static void main(String[] args)throws IOException
    {
        Scanner input = new Scanner(System.in);
        String name, ip = "127.0.0.1";
        int selection = 0, port;

        Socket socket;

        System.out.print("1) Stop and wait   2) Go Back N : ");
        selection = input.nextInt();

        System.out.print("File name : ");
        name = input.next();

        if (selection==1)
        {
            System.out.println("=====Stop and Wait=====");
            port = 8000;
            socket = new Socket(ip,port);

            System.out.println("Connect!");
            System.out.println();
        }
        else if (selection==2)
        {
            System.out.println("=====Go Back N=====");
            port = 8001;
            socket = new Socket(ip,port);

            System.out.println("Connect!");
            System.out.println();
        }
        else
            System.out.println("Wrong selection!");
    }

    public static void stop_and_wait()
    {

    }

    public static void go_back_n()
    {

    }
}
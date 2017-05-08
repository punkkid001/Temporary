import java.io.*;
import java.net.*;
import java.util.*;

class ErrorControlClient
{
    public static void main(String[] args)throws IOException
    {
        Scanner input = new Scanner(System.in);
        Socket socket;
        
        InputStream in;
        DataInputStream d_in;
        OutputStream out;
        DataOutputStream d_out;

        String ip = "127.0.0.1";
        int selection = 0, port = 0;

        System.out.print("1) Stop and wait   2) Go Back N : ");
        selection = input.nextInt();

        if (selection==1)
        {
            System.out.println("=====Stop and Wait=====");
            port = 8000;
        }
        else if (selection==2)
        {
            System.out.println("=====Go Back N=====");
            port = 8001;
        }
        else
        {
            System.out.println("Wrong selection!");
            System.exit(-1);
        }
        
        socket = new Socket(ip,port);

        System.out.println("Connect!");
        System.out.println();

        in=socket.getInputStream();
        d_in=new DataInputStream(in);
        out=socket.getOutputStream();
        d_out=new DataOutputStream(out);

        BufferedOutputStream bos=new BufferedOutputStream(socket.getOutputStream());
        DataOutputStream dos=new DataOutputStream(bos);

        FileOutputStream f_out=new FileOutputStream("result");
        while(true)
        {
            int data=d_in.read();
            if(data==-1)
            {
                break;
            }
            f_out.write(data);
        }

        System.out.println("Done!");

        //Closing socket
        socket.close();
        in.close();
        d_in.close();
        out.close();
        d_out.close();
        f_out.close();
    }

    public static void stop_and_wait()
    {

    }

    public static void go_back_n()
    {

    }
}
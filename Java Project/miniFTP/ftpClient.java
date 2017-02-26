/**
 * Created by Jiyoon on 2015-06-10.
 */

import com.sun.corba.se.spi.orbutil.fsm.Input;

import java.util.*;
import java.io.*;
import java.net.*;

public class ftpClient
{
    public static void main(String[] args)throws IOException
    {
        Scanner input=new Scanner(System.in);
        String ip_addr;
        int port;

        System.out.print("Input IP address : ");
        ip_addr=input.next();
        System.out.print("Input Port number : ");
        port=input.nextInt();

        //making socket
        Socket socket=new Socket(ip_addr,port);
        System.out.println("Connect!");
        System.out.println();

        InputStream in=socket.getInputStream();
        DataInputStream D_in=new DataInputStream(in);
        OutputStream out=socket.getOutputStream();
        DataOutputStream D_out=new DataOutputStream(out);


        BufferedOutputStream bos=new BufferedOutputStream(socket.getOutputStream());
        DataOutputStream dos=new DataOutputStream(bos);

        //View file list
        System.out.println("<-------------File List------------->");
        String list_data;
        list_data = D_in.readUTF();
        while(list_data!=null)
        {
            System.out.println(list_data);
            if(D_in.available()>0)
               list_data=D_in.readUTF();
            else
                list_data=null;
        }

        System.out.println();

        //Downloading file
        System.out.print("What do you want to download? : ");
        String FileName=input.next();
        D_out.writeUTF(FileName);
        System.out.println("Downloading ..");

        FileOutputStream F_out=new FileOutputStream(FileName);
        while(true)
        {
            int data=D_in.read();
            if(data==-1)
            {
                break;
            }
            F_out.write(data);
        }

        System.out.println("Done!");

        //Closing socket
        socket.close();
        in.close();
        D_in.close();
        out.close();
        D_out.close();
        F_out.close();
    }
}

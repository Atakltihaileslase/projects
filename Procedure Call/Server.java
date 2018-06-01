import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Server implements Student {

    public Server() {}

    public static void main(String args[]) {

        try {
            Server obj = new Server();
            Student stu = (Student) UnicastRemoteObject.exportObject(obj, 0);

            // bind the remote object's stu in the registry
            Registry reg = LocateRegistry.getRegistry();
            reg.bind("Student", stu);

            System.err.println("Server ready");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }

    @Override
    public String getStudentInfo() throws RemoteException {
        return "Name: Ataklti Haileslase  NO.ID: ATR/0526/08  Department: Software Engineering";
    }
}
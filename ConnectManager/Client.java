public class Client {
    public static void main(String[] args) {
        ConnectManager.getInstance().startConnectThread(ConnectManager.CONNECTED_BY_AOA);
    }
}
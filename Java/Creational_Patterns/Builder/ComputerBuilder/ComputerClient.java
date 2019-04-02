public class ComputerClient {
    public static void main(String[] args) {
        Computer comp = new Computer.ComputerBuilder("500GB", "2GB").setBluetoothEnabled(true).setGraphicCardEnabled(true).build();

        System.out.println(comp);
    }
}
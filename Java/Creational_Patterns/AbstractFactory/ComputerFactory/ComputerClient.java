public class ComputerClient { 
    public static void main(String[] agrs) {
        Computer pc = ComputerFactory.getComputer(new PCFactory("4GB", "500GB", "i3"));

        Computer sv = ComputerFactory.getComputer(new ServerFactory("64GB", "10T", "i7"));

        System.out.println(pc);
        System.out.println(sv);

    }
}
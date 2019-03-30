public class HouseClient {
    public static void main(String[] args) {
        HouseDirector houseDirector = new HouseDirector();
        
        WoodBuilder woodBuilder = new WoodBuilder();

        BrickBuilder brickBuilder = new BrickBuilder();

        House woodHouse = houseDirector.constructHouse(woodBuilder);

        System.out.println("\n");

        House brickHouse = houseDirector.constructHouse(brickBuilder);

    }
}
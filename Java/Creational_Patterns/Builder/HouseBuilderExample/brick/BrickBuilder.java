public class BrickBuilder extends HouseBuilder {
    public House createHouse() {
        house = new BrickHouse();
        return house;
    }

    public Floor createFloor() {
        floor = new BrickFloor();
        return floor;
    }

    public Walls createWalls() {
        walls = new BrickWalls();
        return walls;
    }

    public Roof createRoof() {
        roof = new BrickRoof();
        return roof;
    }
}
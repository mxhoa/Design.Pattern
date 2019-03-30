public class ProductB extends Product {
    ProductB() {
        System.out.println("ProductB");
    }
    public void writeName(String name) {
        StringBuilder tempName = new StringBuilder().append(name);
        System.out.println("My reversed name is " + tempName.reverse());
    }
}
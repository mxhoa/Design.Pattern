public class DirectoryCompositeApp {
    public static void main(String[] args) {
        Indentation indentation = new Indentation();

        Directory dir1 = new Directory("dir1", indentation);
        Directory dir2 = new Directory("dir2", indentation);
        Directory dir3 = new Directory("dir3", indentation);
        
        File a = new File("a", indentation);
        File b = new File("b", indentation);
        File c = new File("c", indentation);
        File d = new File("d", indentation);
        File e = new File("e", indentation);

        dir1.add(a);
        dir1.add(dir2);
        dir1.add(b);

        dir2.add(c);
        dir2.add(d);
        dir2.add(dir3);

        dir3.add(e);


        dir1.ls();
    }
}
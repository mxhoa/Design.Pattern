Prototype
- A prototype pattern is used in software development when the type of objects to create is determined by a prototypical instance, which is cloned to produce new objects. This pattern is used, for example, when the inherent cost of creating a new object in the standard way (e.g., using the 'new' keyword) is prohibitively expensive for a given application.

Implementstaion: 
- Declare an abstract base class that specifies a pure virtual clone() method. Any class that needs a "polymorphic constructor" capability derives itself from the abstract base class, and implements the clone() operation.
Here the client code first invokes the factory method. This factory method, depending on the parameter, finds out the concrete class. On this concrete class, the clone() method is called and the object is returned by the factory method.
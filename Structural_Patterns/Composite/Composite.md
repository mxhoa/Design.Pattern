Composite
=======


Composite lets clients treat individual objects and compositions of objects uniformly. The Composite pattern can represent both the conditions. In this pattern, one can develop tree structures for representing part-whole hierarchies.



## 1. Applicability
Use the Composite pattern when 
    - you want to represent part-whole hieranchies of objects.
    - you want clients to be able to ignore the different between compositions of objects and individual objects. Clients will treat all objects in the composite structure uniformly.

## 2. Structure 

![](https://github.com/mxhoa/Software-Design-Patterns/blob/master/assets/structural_assets/Composite_structure_1.PNG)

A typical Composite object structure might look like this:
![](https://github.com/mxhoa/Software-Design-Patterns/blob/master/assets/structural_assets/Composite_structure_2.PNG)

## 3. Participants
- Component
    + declares the interface for objects in the composition.
    + implements default behavior for the interface common to all classes, as appropriate.
    + declares an interface for accessing and managing its chils components.
    + (optional) defines an interface for accessing a component's parent in the recursive structure, and implements it if that's appropriate.

- Leaf 
    + represents leaf objects in the composition. A leaf has no children.
    + defines behavior for primitive objects in the composition.

- Composite
    + defines behavior for components having children.
    + stores child components.
    + implements child-related operations in the Component interface.

- Client
    + manipulates objects in the composition through the Component interface.

## 4. Collaborations
- Clients use the Component class interface to interact with objects in the composite structure. If the recipient is a Leaf, then the request is handled directly. If the recipient is a Composite, the it usally forwards requests to its child components, possibly performing additional operations before and/or after forwarding.

base *p; // base pointer
base base_ob;
derived derived_ob;

p = &base_ob;
p = &derived_ob; // base pointer can point to derived object

/*
Key Notes:

1. A base-class pointer can point to a base object or any derived object.

2. Reverse assignment (derived pointer to base object) is not allowed directly.

3. This is the basis of runtime polymorphism.
*/

//For Java
Base ob = new Derived();

/*
Key Notes:

1. Base reference can refer to a Derived object.

2. Common Java polymorphism form.
*/
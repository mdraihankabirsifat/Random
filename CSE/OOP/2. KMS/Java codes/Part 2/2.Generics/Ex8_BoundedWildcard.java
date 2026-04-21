// https://github.com/mdraihankabirsifat/Random
//package generics;

// Base class
class Ex8_TwoD {

    int x, y;

    Ex8_TwoD(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

// Derived class
class Ex8_ThreeD extends Ex8_TwoD {

    int z;

    Ex8_ThreeD(int x, int y, int z) {
        super(x, y);
        this.z = z;
    }
}

// Further derived
class Ex8_FourD extends Ex8_ThreeD {

    int t;

    Ex8_FourD(int x, int y, int z, int t) {
        super(x, y, z);
        this.t = t;
    }
}

// Generic container
class Ex8_Coords<T extends Ex8_TwoD> {

    T[] coords;

    Ex8_Coords(T[] o) {
        coords = o;
    }
}

// Bounded wildcard class
class Ex8_BoundedWildcard {

    // Works for ALL types
    static void showXY(Ex8_Coords<?> c) {
        for (int i = 0; i < c.coords.length; i++) {
            System.out.println(c.coords[i].x + " " + c.coords[i].y);
        }
    }

    // Only ThreeD and subclasses
    static void showXYZ(Ex8_Coords<? extends Ex8_ThreeD> c) {
        for (int i = 0; i < c.coords.length; i++) {
            System.out.println(c.coords[i].x + " " + c.coords[i].y + " " + c.coords[i].z);
        }
    }

    // Only FourD
    static void showAll(Ex8_Coords<? extends Ex8_FourD> c) {
        for (int i = 0; i < c.coords.length; i++) {
            System.out.println(c.coords[i].x + " " + c.coords[i].y + " " + c.coords[i].z + " " + c.coords[i].t);
        }
    }

    public static void main(String[] args) {

        Ex8_TwoD[] twoD = {
            new Ex8_TwoD(1, 8),
            new Ex8_TwoD(2, 7),
            new Ex8_TwoD(3, 6),
            new Ex8_TwoD(4, 5)
        };

        Ex8_Coords<Ex8_TwoD> twoDCoords = new Ex8_Coords<>(twoD);

        Ex8_BoundedWildcard.showXY(twoDCoords);

        // ❌ ERROR (no z)
        // Ex8_BoundedWildcard.showXYZ(twoDCoords);
        
        Ex8_FourD[] fourD = {
            new Ex8_FourD(1, 8, 9, 16),
            new Ex8_FourD(2, 7, 10, 15),
            new Ex8_FourD(3, 6, 11, 14),
            new Ex8_FourD(4, 5, 12, 13)
        };

        Ex8_Coords<Ex8_FourD> fourDCoords = new Ex8_Coords<>(fourD);

        Ex8_BoundedWildcard.showXY(fourDCoords);
        Ex8_BoundedWildcard.showXYZ(fourDCoords);
        Ex8_BoundedWildcard.showAll(fourDCoords);
    }
}

/*
Key Notes:

1. <? extends X> = upper bound
2. Allows X + subclasses
3. Hierarchy:
   TwoD → ThreeD → FourD

1. showXY → works for all
2. showXYZ → needs z → ThreeD+
3. showAll → needs t → FourD only

Exam trap:
Method depends on available fields
 */

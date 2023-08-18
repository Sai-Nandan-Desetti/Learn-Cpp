Points and Vectors

Key learnings:
    - By our definition of `moveByVector()`, we need to access private members of `Vector3d`.
    - Thus, `moveByVector()` is a member function of `Point3d` that needs to be declared as a friend of `Vector3d`.
    - This declaration of friendship must happen inside the class definition of `Vector3d`.
        - Therefore, `point3d.h` must be `#included` in `vector3d.h`.
    - Since we're passing `const Vector3d&` as an argument to `moveByVector`, should we `#include "vector3d.h"` in `point3d.h`?
        - Then, that would lead to circular inclusion of `point3d.h` and `vector3d.h`.
            - Which makes no sense and results in a compiler error.
        - You only need to *forward declare* `Vector3d` above the definition of `Point3d`.

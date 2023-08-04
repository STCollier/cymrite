# Geometry

Defined in header [<cymrite/geometry.h>](../include/cymrite/geometry.h)


## `typedef cymrite_Vector2 cymrite_Point`

#### Description:
- A `typedef struct cymrite_Vector2` for creating a point in 2D space. Works effectively the same as a `cymrite_Vector2`

### Synopsis
```c
typedef struct {
	float x;
	float y;
} cymrite_Vector2;
```

<br/>


## `typedef struct cymrite_Line`

#### Description:
- A `typedef struct` for creating a line segment in 2D space

### Synopsis
```c
typedef struct {
	double x1;
	double y1;
	double x2;
	double y2;
} cymrite_Line;
```

<br/>


## `typedef struct cymrite_Circle`

#### Description:
- A `typedef struct` for creating a circle in 2D space

### Synopsis
```c
typedef struct {
	double x;
	double y;
	double radius;
} cymrite_Circle;
```

<br/>


## `typedef struct cymrite_Rectangle`

#### Description:
- A `typedef struct` for creating a rectangle in 2D space

### Synopsis
```c
typedef struct {
	double x;
	double y;
	double width;
	double height;
} cymrite_Rectangle;
```

<br/>


## `float cymrite_Point_distance(cymrite_Line line)`

#### Description:
- Function that calculates the distance between two points

#### Parameters:
- `line`: a `cymrite_Line`, used to calculate the distance

#### Returns:
- A float

### Example
```c
cymrite_Line line = {0, 0, 3, 4};

printf("%f\n", cymrite_Point_distance(line));
```
Output:
```
5.000000
```

<br/>


## `bool cymrite_Point_collisionPoint(cymrite_Point point1, cymrite_Point point2)`

#### Description:
- Function that determines if two points are colliding

#### Parameters:
- `point1`: a `cymrite_Point`, the value of the first point
- `point2`: a `cymrite_Point`, the value of the second point

#### Returns:
- A boolean

### Example
```c
cymrite_Point point1 = {0, 0};
cymrite_Point point2 = {0, 25};

printf("%s\n", cymrite_Point_collisionPoint(point1, point2) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_Point_collisionCircle(cymrite_Point point, cymrite_Circle circle)`

#### Description:
- Function that determines if a point and circle are colliding

#### Parameters:
- `point`: a `cymrite_Point`, the value of the point
- `circle`: a `cymrite_Circle`, the value of circle

#### Returns:
- A boolean

### Example
```c
cymrite_Point point = {0, 6};
cymrite_Circle circle = {0, 5, 2};

printf("%s\n", cymrite_Point_collisionCircle(point, circle) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Point_collisionLine(cymrite_Point point, cymrite_Line line)`

#### Description:
- Function that determines if a point and line are colliding

#### Parameters:
- `point`: a `cymrite_Point`, the value of the point
- `line`: a `cymrite_Line`, the value of line

#### Returns:
- A boolean

### Example
```c
cymrite_Point point = {0, 0};
cymrite_Line line = {0, 10, 10, 10};

printf("%s\n", cymrite_Point_collisionLine(point, line) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_Point_collisionRectangle(cymrite_Point point, cymrite_Rectangle rectangle)`

#### Description:
- Function that determines if a point and rectangle are colliding

#### Parameters:
- `point`: a `cymrite_Point`, the value of the point
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle

#### Returns:
- A boolean

### Example
```c
cymrite_Point point = {0, 5};
cymrite_Rectangle rectangle = {5, 5, 10, 5};

printf("%s\n", cymrite_pointRectangle(point, rectangle) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_Line_compare(cymrite_Line line1, cymrite_Line line2)`

#### Description:
- Function that determines if two lines are identical

#### Parameters:
- `line1`: a `cymrite_Line`, the value of the first line
- `line2`: a `cymrite_Line`, the value of the second line

#### Returns:
- A boolean

### Example
```c
cymrite_Line point = {0, 0, 5, 5.7};
cymrite_Line rectangle = {0, 0, 6.5, 6};

printf("%s\n", cymrite_pointRectangle(point, rectangle) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `double cymrite_Line_length(cymrite_Line line)`

#### Description:
- Function that returns the length of a line

#### Parameters:
- `line`: a `cymrite_Line`, the value of the line

#### Returns:
- A double

### Example
```c
cymrite_Line line = {0, 0, 0, 5};

printf("%ld\n", cymrite_Line_length(line));
```
Output:
```
5.000000
```

<br/>


## `bool cymrite_Line_collisionPoint(cymrite_Line line, cymrite_Point point)`

#### Description:
- Function that determines if a line and a point are colliding

#### Parameters:
- `line`: a `cymrite_Line`, the value of the line
- `point`: a `cymrite_Point`, the value of the point

#### Returns:
- A boolean

### Example
```c
cymrite_Line line = {0, 0, 5, 5};
cymrite_Point point = {5, 5};

printf("%s\n", cymrite_Line_collisionPoint(line, point) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Line_collisionLine(cymrite_Line line1, cymrite_Line line2)`

#### Description:
- Function that determines if two line segments are colliding

#### Parameters:
- `line1`: a `cymrite_Line`, the value of the first line
- `line2`: a `cymrite_Line`, the value of the second line

#### Returns:
- A boolean

### Example
```c
cymrite_Line line1 = {0, 5, 5, 0};
cymrite_Line line2 = {0, 0, 5, 5};

printf("%s\n", cymrite_Line_collisionLine(line1, line2) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Line_collisionCircle(cymrite_Line line, cymrite_Circle circle)`

#### Description:
- Function that determines if a line segment and a circle are colliding

#### Parameters:
- `line`: a `cymrite_Line`, the value of the line
- `circle`: a `cymrite_Circle`, the value of circle

#### Returns:
- A boolean

### Example
```c
cymrite_Line line = {0, 0, 5, 5};
cymrite_Circle line2 = {1, 1, 7};

printf("%s\n", cymrite_Line_collisionCircle(line1, circle) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Line_collisionRectangle(cymrite_Line line, cymrite_Rectangle rectangle)`

#### Description:
- Function that determines if a line and rectangle are colliding

#### Parameters:
- `line`: a `cymrite_Line`, the value of the line
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle

#### Returns:
- A boolean

### Example
```c
cymrite_Line line = {0, 0, 5, 5};
cymrite_Rectangle rectangle = {0, 0, 5, 5};

printf("%s\n", cymrite_lineRectangle(line, rectangle) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Circle_compare(cymrite_Circle circle1, cymrite_Circle circle2)`

#### Description:
- Function that determines if two circles are identical

#### Parameters:
- `circle1`: a `cymrite_Circle`, the value of the first circle
- `circle2`: a `cymrite_Circle`, the value of the second circle

#### Returns:
- A boolean

### Example
```c
cymrite_Circle circle2 = {0, 0, 5};
cymrite_Circle circle1 = {0, 0, 6};

printf("%s\n", cymrite_Circle_compare(rect1, rect2) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `double cymrite_Circle_area(cymrite_Circle circle)`

#### Description:
- Function that returns the area of a circle

#### Parameters:
- `circle`: a `cymrite_Circle`, the value of circle

#### Returns:
- A double

### Example
```c
cymrite_Circle circle = {0, 0, 5};

printf("%lf units squared\n", cymrite_Cirlce_area(circle));
```
Output:
```
78.54 units squared
```

<br/>


## `double cymrite_Circle_circumference(cymrite_Circle circle)`

#### Description:
- Function that returns the circumference of a cricle

#### Parameters:
- `circle`: a `cymrite_Circle`, the value of circle

#### Returns:
- A double

### Example
```c
cymrite_Circle circle = {0, 0, 5};

printf("%lf units\n", cymrite_Circle_circumference(circle));
```
Output:
```
31.42 units
```

<br/>


## `bool cymrite_Circle_collisionPoint(cymrite_Circle circle, cymrite_Point point)`

#### Description:
- Function that determines if a circle and point are colliding

#### Parameters:
- `circle`: a `cymrite_Circle`, the value of circle
- `point`: a `cymrite_Point`, the value of point

#### Returns:
- A boolean

### Example
```c
cymrite_Circle circle = {0, 0, 3};
cymrite_Point point = {1, 1};

printf("%s\n", cymrite_Circle_collisionPoint(circle, point) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Circle_collisionLine(cymrite_Circle circle, cymrite_Line line)`

#### Description:
- Function that determines if a circle and line are colliding

#### Parameters:
- `circle`: a `cymrite_Circle`, the value of circle
- `line`: a `cymrite_Line`, the value of line

#### Returns:
- A boolean

### Example
```c
cymrite_Circle circle = {0, 0, 3};
cymrite_Point line = {-1, -1, 4, 4};

printf("%s\n", cymrite_Circle_collisionLine(circle, line) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Circle_collisionCircle(cymrite_Circle circle1, cymrite_Circle circle2)`

#### Description:
- Function that determines if two circles are colliding

#### Parameters:
- `circle1`: a `cymrite_Circle`, the value of first circle
- `circle2`: a `cymrite_Circle`, the value of second circle

#### Returns:
- A boolean

### Example
```c
cymrite_Circle circle = {1, 1, 2};
cymrite_Circle circle2 = {-6, -6, 2}

printf("%s\n", cymrite_Circle_collisionLine(circle, line) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_Circle_collisionRectangle(cymrite_Circle circle, cymrite_Rectangle rectangle)`

#### Description:
- Function that determines if a circle and rectangle are colliding

#### Parameters:
- `circle`: a `cymrite_Circle`, the value of the circle
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle

#### Returns:
- A boolean

### Example
```c
cymrite_Circle circle = {0, 0, 5};
cymrite_Rectangle rectangle = {5, 5, 5, 5};

printf("%s\n", cymrite_Circle_collisionRectangle(circle, rectangle) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_Rectangle_compare(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2)`

#### Description:
- Function that determines two rectangles are identical

#### Parameters:
- `rectangle1`: a `cymrite_Rectangle`, the value of the first rectangle
- `rectangle2`: a `cymrite_Rectangle`, the value of the second rectangle

#### Returns:
- A boolean

### Example
```c
cymrite_Rectangle rectangle1 = {5, 5, 5, 5};
cymrite_Rectangle rectangle2 = {5, 5, 5, 5};

printf("%s\n", cymrite_Rectangle_compare(rectangle1, rectangle2) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `double cymrite_Rectangle_area(cymrite_Rectangle rectangle)`

#### Description:
- Function that returns the area of a given rectangle

#### Parameters:
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle

#### Returns:
- A double

### Example
```c
cymrite_Rectangle rectangle = {0, 0, 5, 5};

printf("%lf\n", cymrite_Rectangle_area(rectangle));
```
Output:
```
25.000000
```

<br/>


## `double cymrite_Rectangle_perimeter(cymrite_Rectangle rectangle)`

#### Description:
- Function that returns the perimeter of a given rectangle

#### Parameters:
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle

#### Returns:
- A double

### Example
```c
cymrite_Rectangle rectangle = {0, 0, 5, 5};

printf("%lf\n", cymrite_Rectangle_perimeter(rectangle));
```
Output:
```
20.000000
```

<br/>


## `bool cymrite_Rectangle_collisionPoint(cymrite_Rectangle rectangle, cymrite_Point point)`

#### Description:
- Function that determines if a rectangle and point are colliding

#### Parameters:
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle
- `point`: a `cymrite_Point`, the value of the point

#### Returns:
- A boolean

### Example
```c
cymrite_Rectangle rectangle = {0, 0, 5, 5};
cymrite_Point point = {1, 1};

printf("%s\n", cymrite_Rectangle_collisionPoint(rectangle, point) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Rectangle_collisionLine(cymrite_Rectangle rectangle, cymrite_Line line)`

#### Description:
- Function that determines if a rectangle and line are colliding

#### Parameters:
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle
- `line`: a `cymrite_Line`, the value of the line

#### Returns:
- A boolean

### Example
```c
cymrite_Rectangle rectangle = {0, 0, 5, 5};
cymrite_Point line = {-1, -1, 6, 6};

printf("%s\n", cymrite_Rectangle_collisionLine(rectangle, line) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_Rectangle_collisionCircle(cymrite_Rectangle rectangle, cymrite_Circle circle)`

#### Description:
- Function that determines if a rectangle and circle are colliding

#### Parameters:
- `rectangle`: a `cymrite_Rectangle`, the value of the rectangle
- `circle`: a `cymrite_Circle`, the value of the circle

#### Returns:
- A boolean

### Example
```c
cymrite_Rectangle rectangle = {0, 0, 5, 5};
cymrite_Point circle = {0, 10, 1};

printf("%s\n", cymrite_Rectangle_collisionCircle(rectangle, circle) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_Rectangle_collisionRectangle(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2)`

#### Description:
- Function that determines if two rectangles are colliding

#### Parameters:
- `rectangle1`: a `cymrite_Rectangle`, the value of the first rectangle
- `rectangle2`: a `cymrite_Rectangle`, the value of the second rectangle

#### Returns:
- A boolean

### Example
```c
cymrite_Rectangle rectangle1 = {0, 0, 5, 5};
cymrite_Rectangle rectangle2 = {5, 5, 10, 5};

printf("%s\n", cymrite_Rectangle_collisionRectangle(rectangle1, rectangle2) ? "true" : "false");
```
Output:
```
true
```

<br/>
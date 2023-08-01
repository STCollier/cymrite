# Geometry

Defined in header [<cymrite/geometry.h>](../include/cymrite/geometry.h)


## `typedef struct cymrite_Vector2`

#### Description:
- A `typedef struct` for creating a 2 dimensional vector, storing a `x` and `y` component

### Synopsis
```c
typedef struct {
	float x;
	float y;
} cymrite_Vector2;
```

<br/>


## `typedef struct cymrite_Vector2`

#### Description:
- A `typedef struct` for creating a 3 dimensional vector, storing a `x`, `y` and `z` component

### Synopsis
```c
typedef struct {
	float x;
	float y;
	float z;
} cymrite_Vector3;
```

<br/>


## `typedef struct cymrite_Point`

#### Description:
- A `typedef struct` for creating a point in 2D space

### Synopsis
```c
typedef struct {
	float x;
	float y;
} cymrite_Point;
```

<br/>


## `typedef struct cymrite_Line`

#### Description:
- A `typedef struct` for creating a line segment in 2D space

### Synopsis
```c
typedef struct {
	float x1;
	float y1;
	float x2;
	float y2;
} cymrite_Line;
```

<br/>


## `typedef struct cymrite_Circle`

#### Description:
- A `typedef struct` for creating a circle in 2D space

### Synopsis
```c
typedef struct {
	float x;
	float y;
	float radius;
} cymrite_Circle;
```

<br/>


## `typedef struct cymrite_Rectangle`

#### Description:
- A `typedef struct` for creating a rectangle in 2D space

### Synopsis
```c
typedef struct {
	float x;
	float y;
	float width;
	float height;
} cymrite_Rectangle;
```

<br/>


## `float cymrite_dist(cymrite_Line line)`

#### Description:
- Function that calculates the distance of a line

#### Parameters:
- `line`: a `cymrite_Line`, used to calculate the distance

#### Returns:
- A float

### Example
```c
cymrite_Line line = {0, 0, 3, 4};

printf("%f\n", cymrite_dist(line));
```
Output:
```
5.000000
```

<br/>


## `bool cymrite_pointPoint(cymrite_Point point1, cymrite_Point point2)`

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

printf("%s\n", cymrite_pointPoint(point1, point2) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_pointCircle(cymrite_Point point, cymrite_Circle circle)`

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

printf("%s\n", cymrite_pointCircle(point, circle) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_circleCircle(cymrite_Circle circle1, cymrite_Circle circle2)`

#### Description:
- Function that determines if two circles are colliding

#### Parameters:
- `circle1`: a `cymrite_Circle`, the value of the first circle
- `circle2`: a `cymrite_Circle`, the value of the second circle

#### Returns:
- A boolean

### Example
```c
cymrite_Circle circle1 = {0, 0, 5};
cymrite_Circle circle2 = {0, 0, 4};

printf("%s\n", cymrite_circleCircle(circle1, circle2) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_pointRectangle(cymrite_Point point, cymrite_Rectangle rectangle)`

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


## `bool cymrite_rectangleRectangle(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2)`

#### Description:
- Function that determines if two rectangles are colliding

#### Parameters:
- `rectangle1`: a `cymrite_Rectangle`, the value of the first rectangle
- `rectangle2`: a `cymrite_Rectangle`, the value of the second rectangle

#### Returns:
- A boolean

### Example
```c
cymrite_Rectangle rect1 = {0, 0, 5, 5};
cymrite_Rectangle rect2 = {5, 5, 10, 5};

printf("%s\n", cymrite_rectangleRectangle(rect1, rect2) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_circleRectangle(cymrite_Circle circle, cymrite_Rectangle rectangle)`

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

printf("%s\n", cymrite_circleRectangle(circle, rectangle) ? "true" : "false");
```
Output:
```
false
```

<br/>


## `bool cymrite_lineLine(cymrite_Line line1, cymrite_Line line2)`

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

printf("%s\n", cymrite_lineLine(line1, line2) ? "true" : "false");
```
Output:
```
true
```

<br/>


## `bool cymrite_lineRect(cymrite_Line line, cymrite_Rectangle rectangle)`

#### Description:
- Function that determines if two line segments are colliding

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
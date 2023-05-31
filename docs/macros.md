# Macros

Defined in header [<cymrite/macros.h>](../include/cymrite/macros.h)


## `CYMRITE_CAT(a, b)`

#### Description:
- Concatenates two values
	
#### Parameters:
- `a`: the first value to concatenate
- `b`: the second value to concatenate

### Example
```c
printf("%d", CYMRITE_CAT(6, 5));
```
Output:
```
65
```

<br/>


## `CYMRITE_CAT_PRIM(a, b)`

#### Description:
- Primitively concatenates two macros
	
#### Parameters:
- `a`: the first macro to concatenate
- `b`: the second maco to concatenate

### Example
```c
void cymrite_add(int a, int b) {
	printf("%d\n", a+b);
}

int main() {
	CYMRITE_CAT_PRIM(cymrite_, add)(2, 2);
}
```
Output:
```
4
```

<br/>


## `CYMRITE_STRINGIFY(x)`

#### Description:
- Stringifies a value
	
#### Parameters:
- `x`: the value to stringify

### Example
```c
printf("%s", CYMRITE_STRINGIFY(123));
```
Output:
```
123
```

<br/>


## `CYMRITE_ERROR(x)`

#### Description:
- Creates an error message with a given value
	
#### Parameters:
- `x`: the error message to display

### Example
```c
CYMRITE_ERROR("This is an error!")
```
Output:
<pre>main.c:12: <span style="color:red">error:</span> This is an error!<span></pre>


<br/>


## `CYMRITE_WARN(x)`

#### Description:
- Creates an warning message with a given value
	
#### Parameters:
- `x`: the warning message to display

### Example
```c
CYMRITE_WARN("This is a warning.")
```
Output:
<pre>main.c:12: <span style="color:purple">warning:</span> This is a warning.<span></pre>


<br/>


## `CYMRITE_LOG(x)`

#### Description:
- Logs a message with a given value
	
#### Parameters:
- `x`: the message to log

### Example
```c
CYMRITE_LOG("This is a message.")
```
Output:
<pre>main.c:12: This is a message.</pre>


<br/>


## `CYMRITE_ARRAY_SIZE(arr)`

#### Description:
- Gets the size of a given array
	
#### Parameters:
- `arr`: the arr to get the size of

### Example
```c
int arr[5] = {1, 2, 3, 4, 5};

printf("Size: %ld\n", CYMRITE_ARRAY_SIZE(arr));
```
Output:
```
Size: 5
```

<br/>


## `CYMRITE_UNUSED(x)`

#### Description:
- Suppresses unused variable warnings
	
#### Parameters:
- `x`: the variable to supress unused warnings from

### Example
```c
int x = 2;
int y = 4;

CYMRITE_UNUSED(y); //No warning: unused variable ‘y’ [-Wunused-variable]

printf("%d\n", x);
```
Output:
```
2
```
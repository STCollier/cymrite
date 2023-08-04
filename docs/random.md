# Geometry

Defined in header [<cymrite/random.h>](../include/cymrite/random.h)


## `void cymrite_setSeed(const int seed)`

#### Description:
- Function that sets a specific seed for generating random numbers

#### Parameters:
- `seed`: an integer value `const int seed`, used to set the seed

#### Returns:
- Void

### Synopsis
```c
cymrite_setSeed(1234);
```

<br/>


## `void cymrite_setRandomSeed()`

#### Description:
- Function that sets a random seed for generating random numbers. Should be called only once

#### Parameters:
- None

#### Returns:
- Void

### Synopsis
```c
cymrite_setRandomSeed();
```

<br/>


## `int cymrite_getRandom(const int minimum, const int maximum)`

#### Description:
- Function that returns a random number in a given range

#### Parameters:
- `minimum`: an integer value `const int minimum`, that is the lowest set number to generate
- `maximum`: an integer value `const int maximum`, that is the highest set number to generate

#### Returns:
- An integer

### Synopsis
```c
cymrite_setRandomSeed();

printf("%d\n", cymrite_getRandom(0, 10)); // Returns a random number 0-10
```

<br/>
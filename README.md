# JSONlang

JSONlang is a small embedded Domain-Specific Language (DSL) implemented in C++. It provides a JSON-like syntax for creating, manipulating, comparing, and printing structured data directly inside C++ programs.

The project uses C++ macros, operator overloading, and a custom JSON value class to make JSON-style operations more expressive and easier to write. It supports common JSON data types such as strings, numbers, booleans, arrays, objects, and null-like values.

---

## Overview

The main goal of JSONlang is to demonstrate how C++ can be extended with a small custom language-like interface. Instead of writing verbose C++ code for every JSON operation, the project introduces a set of macros and overloaded operators that allow users to write code in a more readable, JSON-inspired style.

At the center of the project is the `JSON_derulo` class, which represents a generic JSON value. Each instance can store one of the supported JSON-like types and provides operations for arithmetic, comparison, logical evaluation, indexing, appending, erasing, printing, and type inspection.

---


## Supported Data Types

JSONlang supports the following JSON-style data types:

* null-like values
* integers
* doubles
* strings
* booleans
* arrays
* objects

Examples of supported value creation:

```cpp
JSON(name) = STRING("Leonardo");
JSON(age) = NUMBER(22);
JSON(height) = NUMBER(1.80);
JSON(isStudent) = TRUE;
JSON(items) = ARRAY;
```

Objects and arrays are internally represented using C++ standard library containers. Arrays are stored using `std::vector`, while objects are stored using `std::list` of JSON values with associated keys.

---

## Project Structure

```text
.
??? JSONlang.h      # Macros, type definitions, class declaration, and function prototypes
??? JSONlang.cpp    # Implementation of constructors, operators, utilities, and printing logic
??? main.cpp        # Example usage file, if included
```

---

## Main Features

### JSON-Like Value Creation

The project provides macros for creating JSON-style values in a cleaner way:

```cpp
STRING("hello")
NUMBER(10)
NUMBER(3.14)
TRUE
FALSE
ARRAY
OBJECT
```

These macros wrap the construction of `JSON_derulo` objects and make the code look closer to a custom JSON language.

---

### Objects

Objects can be created using key-value pairs:

```cpp
JSON(person) = OBJECT {
    KEY(name) : STRING("Marselo"),
    KEY(age) : NUMBER(22),
    KEY(student) : TRUE
};
```

Each object entry has a key and a corresponding JSON value.

---

### Arrays

Arrays can store multiple JSON values and support appending new elements:

```cpp
JSON(numbers) = ARRAY;

numbers APPEND NUMBER(1);
numbers APPEND NUMBER(2);
numbers APPEND NUMBER(3);
```

Array elements can also be accessed using index notation:

```cpp
PRINT numbers[0];
```

---

### Printing

JSON values can be printed in a formatted JSON-like structure:

```cpp
PRINT person;
PRINT numbers;
```

The printing logic recursively handles objects, arrays, strings, numbers, booleans, and null-like values.

---

### Utility Functions

JSONlang includes helper operations for inspecting JSON values:

```cpp
SIZE_OF(json)
TYPE_OF(json)
HAS_KEY(json, key)
IS_EMPTY(json)
```

These functions allow users to check the size, type, emptiness, or key existence of a JSON value.

---

### Operator Support

The project overloads several C++ operators to support JSON-like operations.

Arithmetic operators:

```cpp
+
-
*
/
%
```

Comparison operators:

```cpp
>
>=
<
<=
==
!=
```

Logical operators:

```cpp
&&
||
!
```

Manipulation and access operators:

```cpp
[]
+=
```

These operators allow JSON values to be used in a more natural and expressive way.

---

## Example Usage

```cpp
#include "JSONlang.h"

PROGRAM_BEGIN

JSON(name) = STRING("Marselo");
JSON(age) = NUMBER(22);
JSON(isStudent) = TRUE;

JSON(numbers) = ARRAY;
numbers APPEND NUMBER(1);
numbers APPEND NUMBER(2);
numbers APPEND NUMBER(3);

JSON(person) = OBJECT {
    KEY(name) : name,
    KEY(age) : age,
    KEY(student) : isStudent,
    KEY(numbers) : numbers
};

PRINT person;

PROGRAM_END
```

---

## Example Output

```json
{
  "name": "Marselo",
  "age": 22,
  "student": true,
  "numbers": [
    1,
    2,
    3
  ]
}
```

---

## Compilation

To compile the project with `g++`, use:

```bash
g++ main.cpp JSONlang.cpp -o jsonlang
```

Then run it with:

```bash
./jsonlang
```

On Windows, the executable may be:

```bash
jsonlang.exe
```

---

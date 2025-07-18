

## 🧠 What are Bitwise Operators?

Bitwise operators in C++ work directly on the **binary representation** of integers. They manipulate **individual bits** (0s and 1s).

---

## 🔧 List of Bitwise Operators in C++

| Operator | Name                   | Description                                     |                                        |
| -------- | ---------------------- | ----------------------------------------------- | -------------------------------------- |
| `&`      | AND                    | Sets bit to 1 if both bits are 1                |                                        |
| \`       | \`                     | OR                                              | Sets bit to 1 if at least one bit is 1 |
| `^`      | XOR (Exclusive OR)     | Sets bit to 1 if only one bit is 1              |                                        |
| `~`      | NOT (One's Complement) | Inverts all bits (0 → 1, 1 → 0)                 |                                        |
| `<<`     | Left Shift             | Shifts bits to the left, fills 0s on the right  |                                        |
| `>>`     | Right Shift            | Shifts bits to the right (fills 0s or sign bit) |                                        |

We'll focus now on **bitwise logic operators (`&`, `|`, `^`, `~`)** with truth tables.

---

## ✅ 1. Bitwise AND (`&`)

**Rule:** Bit is `1` **only if both** bits are `1`.

### Truth Table:

| A | B | A & B |
| - | - | ----- |
| 0 | 0 | 0     |
| 0 | 1 | 0     |
| 1 | 0 | 0     |
| 1 | 1 | 1     |

### Example:

```cpp
int a = 6;    // 0110
int b = 3;    // 0011
int c = a & b; // 0010 (2)
```

---

## ✅ 2. Bitwise OR (`|`)

**Rule:** Bit is `1` if **at least one** bit is `1`.

### Truth Table:

| A | B | A \| B |
| - | - | ------ |
| 0 | 0 | 0      |
| 0 | 1 | 1      |
| 1 | 0 | 1      |
| 1 | 1 | 1      |

### Example:

```cpp
int a = 6;    // 0110
int b = 3;    // 0011
int c = a | b; // 0111 (7)
```

---

## ✅ 3. Bitwise XOR (`^`)

**Rule:** Bit is `1` if **only one** of the bits is `1` (not both).

### Truth Table:

| A | B | A ^ B |
| - | - | ----- |
| 0 | 0 | 0     |
| 0 | 1 | 1     |
| 1 | 0 | 1     |
| 1 | 1 | 0     |

### Example:

```cpp
int a = 6;    // 0110
int b = 3;    // 0011
int c = a ^ b; // 0101 (5)
```

---

## ✅ 4. Bitwise NOT (`~`)

**Rule:** Inverts all bits.

| A | \~A |
| - | --- |
| 0 | 1   |
| 1 | 0   |

⚠️ For integers, it inverts **all bits including the sign bit**, which makes it tricky for signed integers (due to 2's complement).

### Example:

```cpp
int a = 5;      // Binary: 00000000 00000000 00000000 00000101
int b = ~a;     // Inverts all bits: 11111111 11111111 11111111 11111010 → -6
```

🧠 Why `~5` gives `-6`?

* 5 → `00000000 00000000 00000000 00000101`
* `~5` → `11111111 11111111 11111111 11111010` = `-6` in **2's complement**

🧠  `(~a)` vs `~(a)`?


---

## 🧪 Quick Recap of Examples:

```cpp
int a = 6;     // 0110
int b = 3;     // 0011

a & b → 0010  → 2
a | b → 0111  → 7
a ^ b → 0101  → 5
~a    → 1001 (if 4-bit) or 2’s complement of a (platform-dependent)
```

---

## 🧠 Real-World Use Cases

| Operator | Use Case Example                                 |                       |
| -------- | ------------------------------------------------ | --------------------- |
| `&`      | Masking bits (e.g., `x & 0xFF` to get last byte) |                       |
| \`       | \`                                               | Setting specific bits |
| `^`      | Toggling bits (flip 0 to 1, 1 to 0)              |                       |
| `~`      | Flipping all bits (used in bit masks)            |                       |
| `<<`     | Multiplying by powers of 2                       |                       |
| `>>`     | Dividing by powers of 2 (if unsigned)            |                       |

---



---

## 🧠 What is the Left Shift Operator?

The **left shift operator `<<`** shifts all bits of a number **toward the left**, by the specified number of positions. It’s a **bitwise operator**, meaning it operates directly on the **binary representation** of the number.

- if we are left shifting an int a, n times i.e (a << n) is equals to a*2<sup>n</sup> 
---

## 🔬 What Happens When You Use `<<`?

Each shift to the left:

* **Moves all bits to the left**.
* **Fills the rightmost (least significant) bits with 0s**.
* **Discards the leftmost (most significant) bits** — they’re just lost.

### Example with `unsigned int`

```cpp
unsigned int x = 5; // 00000000 00000000 00000000 00000101
unsigned int y = x << 2;
```

**Step-by-step:**

* Binary of 5: `00000000 00000000 00000000 00000101`
* Left shift by 2:

  ```
  Before: 00000000 00000000 00000000 00000101
  After : 00000000 00000000 00000000 00010100 → Decimal: 20
  ```

💡 `5 << 2` = `5 * 2^2` = `20`

---

## 🔄 General Rule

```
value << n  ≡  value × 2^n
```

> As long as the result doesn't **overflow**, left shifting a value by `n` bits multiplies it by `2^n`.

---

## ⚠️ Signed vs Unsigned Left Shift

C++ treats **signed** and **unsigned** values differently when shifting:

### ✅ `unsigned int` (Safe and Well-defined)

Shifting bits left behaves as expected — it fills in zeros on the right and is **well-defined** by the C++ standard.

### ⚠️ `signed int` (Undefined Behavior on Overflow)

When left shifting **signed integers**, if the shift causes:

* The sign bit (most significant bit) to change (e.g., from `0` to `1`), or
* The value to exceed the maximum range of the type

...then the behavior is **undefined**. This means:

* It may work.
* It may crash.
* It may give garbage values.
* It may even be optimized away by the compiler.

---

## 🧪 Example 1: Signed Positive Shift (Safe)

```cpp
int x = 3;           // binary: 00000000 00000000 00000000 00000011
int y = x << 1;      // binary: 00000000 00000000 00000000 00000110 → 6
```

✅ Output:

```
y = 6
```

---

## 💥 Example 2: Signed Negative Shift (Danger!)

```cpp
int x = -1;          // binary (2's complement): 11111111 11111111 11111111 11111111
int y = x << 1;
```

Now the sign bit (MSB) is already 1. Left shift pushes another 1 into the second MSB position.

Binary:

```
Before: 11111111 11111111 11111111 11111111   // -1
After : 11111111 11111111 11111111 11111110   // ?
```

⚠️ This is **undefined behavior**!

It *might* behave like -2 on some compilers, but the C++ standard says this is not guaranteed.

---

## 🧪 Example 3: Overflow with Signed Int

```cpp
int x = 1 << 31;
```

* `1` in binary: `00000000 00000000 00000000 00000001`
* After shifting 31 bits: `10000000 00000000 00000000 00000000`

This sets the **sign bit**, resulting in what *looks like* the minimum signed int (`INT_MIN = -2147483648`), but this is **undefined behavior** in C++ because:

> Signed left shift of a positive number into the sign bit is not defined.

---

## ✅ How to Avoid Undefined Behavior

1. Use **unsigned int** if you're doing bit-level math.
2. Never shift more than or equal to the number of bits in the type (e.g., `x << 32` on a 32-bit `int` is undefined).
3. Check if the result of the shift fits within the variable type's range.

---

## 📌 Summary Table

| Case                | Behavior   | Safe? |
| ------------------- | ---------- | ----- |
| `5 << 2`            | 20         | ✅ Yes |
| `-1 << 1`           | Undefined  | ❌ No  |
| `unsigned(5) << 2`  | 20         | ✅ Yes |
| `1 << 31`           | Undefined  | ❌ No  |
| `unsigned(1) << 31` | 2147483648 | ✅ Yes |

---


---

## 👉 What is the Right Shift Operator (`>>`)?

The **right shift operator `>>`** shifts all bits in a number **toward the right**, by a specified number of positions.

- if we are left shifting an int a, n times i.e (a >> n) is equals to a/2<sup>n</sup> but in case of -ve integers it is system dependent
---

## 🔧 Syntax:

```cpp
result = number >> n;
```

* `number`: the value whose bits are being shifted.
* `n`: number of positions to shift right.

---

## 🔬 What Happens Internally?

* Each shift **to the right by 1** moves all bits one position to the right.
* The **leftmost bits** (MSB) are filled **based on the data type** (signed or unsigned).
* The **rightmost bits** (LSB) are discarded.

---

## ⚙️ Right Shift of `unsigned int`

### Behavior: Fills in **0s** from the left.

### Example:

```cpp
unsigned int x = 20; // Binary: 00000000 00000000 00000000 00010100
unsigned int y = x >> 2;
```

**Step-by-step:**

```
Original: 00000000 00000000 00000000 00010100 (20)
Shift >> 2:
          00000000 00000000 00000000 00000101 → 5
```

✅ `20 >> 2` = `20 / 2^2` = `5`

---

## 🧪 Rule of Thumb

```
value >> n  ≡  value / 2^n   (only for positive values)
```

⚠️ Not always valid for **negative numbers** due to **sign extension** (explained below).

---

## 🧨 Signed vs Unsigned Behavior

| Type           | What fills the left bits?       |
| -------------- | ------------------------------- |
| `unsigned int` | **Always 0**                    |
| `signed int`   | **Depends on the compiler**: \\ |

```
             Either 0 (logical shift) or copy of sign bit (arithmetic shift) |
```

---

## 🧪 Example 1: Signed Positive Right Shift (Safe)

```cpp
int x = 20;         // 00000000 00000000 00000000 00010100
int y = x >> 2;
```

Output:

```
y = 5
```

✅ Same as unsigned for positive numbers.

---

## 🧪 Example 2: Signed Negative Right Shift

```cpp
int x = -4;         // 2's complement: 11111111 11111111 11111111 11111100
int y = x >> 1;
```

Here, the MSB is `1` (because it’s negative).

Now, two possible results depending on **how the compiler handles right shifts of signed ints**:

### 1. **Arithmetic Shift (most common)**

* Fills in 1s from the left (sign extension)

```
Before: 11111111 11111111 11111111 11111100 (-4)
After : 11111111 11111111 11111111 11111110 (-2)
```

✅ Keeps the sign bit.

### 2. **Logical Shift (not common for signed)**

* Fills in 0s from the left:

```
After : 01111111 11111111 11111111 11111110 → a large positive number
```

❌ Changes sign, usually undesired.

> 📌 **In C++**, the right shift of **negative signed integers** is **implementation-defined**. It’s **usually arithmetic** (sign bit is preserved), but not guaranteed.

---

## 🧪 Example 3: Right Shift of `unsigned`

```cpp
unsigned int x = 240; // Binary: 00000000 00000000 00000000 11110000
unsigned int y = x >> 4;
```

```
Shift >> 4:
Original: 00000000 00000000 00000000 11110000 (240)
After   : 00000000 00000000 00000000 00001111 (15)
```

✅ Safe and predictable.

---

## ⚠️ Undefined/Implementation-Defined Behavior

| Scenario                                                              | Behavior                 |
| --------------------------------------------------------------------- | ------------------------ |
| Negative signed int >> n                                              | ❗ Implementation-defined |
| Shift more than or equal to bit width (e.g., `x >> 32` on 32-bit int) | ❌ Undefined behavior     |
| Right shift on unsigned types                                         | ✅ Well-defined           |

---

## 🧠 Summary Table

| Expression           | Description                                   | Output | Behavior    |
| -------------------- | --------------------------------------------- | ------ | ----------- |
| `20 >> 2`            | 20 divided by 4                               | 5      | ✅ Safe      |
| `-4 >> 1`            | Implementation-defined (-2 on most compilers) | -2     | ⚠️ Varies   |
| `unsigned(240) >> 4` | Logical shift, 0s inserted                    | 15     | ✅ Safe      |
| `int x = 1 >> 32`    | Too large shift                               | ❌ UB   | ❌ Undefined |

---

## 🔒 Best Practices

1. For portable behavior, **use unsigned types** when doing bit shifts.
2. Avoid shifting signed negative numbers.
3. Always ensure the shift amount is **less than** the bit width of the type (e.g., `< 32` for `int`).

---


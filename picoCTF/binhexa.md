# binhexa

This CTF tests your ability to do binary operations on binary numbers. There's no real step-by-step solution, as the input is random. At the end, the user must enter the answer in hexadecimal.

There are $6$ operations to perform: OR, AND, right shift, addition, left shift, and multiplication.

### OR

The OR operator '|' is a bitwise operation. It is performed on each individual bit. The following holds:

```
1 | 1 = 1
1 | 0 = 1
0 | 1 = 1
0 | 0 = 0
```

### AND

The bitwise AND operator '&' is also performed on each individual bit. The following is true:

```
1 & 1 = 1
1 & 0 = 0
0 & 1 = 0
0 & 0 = 0
```

### Right shift

There are two types of right shifts: arithmetic (ASR) and logical (LSR). ASR copies the signed bit - the Most Significant Bit, or MSB - as it shifts. LSR always pads with $0$ bits. This will be a logical shift right. It is literally shifting all the bits to the right a specified number of steps. For example,

```
1110 0001
```

Shifted logically right by $2$ becomes

```
0011 1000
```

### Addition

Adding binary is just base $2$ addition. This is defined as follows for two bits:

```
1 + 1 = 0 (carry 1)
1 + 0 = 1
0 + 1 = 1
0 + 0 = 0
```

It is important to note that if the answer is beyond $8$ bits, you are expected to extend the number of bits rather than truncate them. If we were restricted to $8$ bits, this would be seen as an overflow.

### Left Shift

Again, there are two types of left shift - arithmetic (ASL) and logical (LSL). We are dealing with logical shifts here. It's the same concept as the previous shift - we shift the bits over by a specified amount. Here is an example of left shift with the same bit string used previously:

```
1110 0001
```

Shifted left three becomes

```
0000 1000
```

### Multiplication

Multiplication is an odd one here. In my challenge, I was given a power of $2$ for one of my bit strings. For a bit string of value $(2^n)_{10}$, multiplication is the same as shifting left by $n$, so I solved it this way. Multiplication can be more difficult if you are dealing with a value that wasn't a power of $2$. In this case, there are a few ways to solve them.

One way is to convert both bit strings to base $10$, multiply them, then convert back to binary. 

Another way is to break up one of the bit strings into powers of $2$, shift the other bit string by each of the powers, and then add up the results. For example,

```
Bit string 1: 0000 1001
Bit string 2: 0000 0101
```

We have, in base $10$, $9$ for bit string $1$ and $5$ for bit string $2$. We can rewrite this as 

$9 \times (4 + 1) = 9 \times (2^2 + 2^0) = (9 \times 2^2) + (9 \times 2^0)$

It doesn't matter if we broke the $9$ down into powers of $2$ instead. This is equivalent to shifting bit string $1$ by $2$ and adding it to the original bit string $1$ ( $2^0$ implies shifting $0$ bits to the left). The result is:

```
  0010 0100
+ 0000 1001
  ---------
  0010 1101
```

### Hex Value

The final part of the challenge asks to give the last answer in hexadecimal. There is a mapping from all four binary bits to hex as follows:

```
1111 -> F
1110 -> E
1101 -> D
1100 -> C
1011 -> B
1010 -> A
1001 -> 9
1000 -> 8
0111 -> 7
0110 -> 6
0101 -> 5
0100 -> 4
0011 -> 3
0010 -> 2
0001 -> 1
0000 -> 0
```

This means the last example of `0010 1101` would be `0x2D` in hex.
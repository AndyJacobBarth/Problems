# endianness

This CTF gives us words that we need to present in their respective endian structure. It is not specified, but the input it's expecting is the hexadecimal form of the word, with respective endianness.

ASCII is technically endian-independent, but for the purposes of this exercise, we should provide each character in reverse order if little-endian or its original order if big-endian.

I believe the problem is random, but mine was

```
vydvu
```

Lowercase ASCII starts at hexadecimal `0x61`. For my particular characters, they were the following:

```
v    y    d    v    u
0x76 0x79 0x64 0x76 0x75
```

We are first asked to give this in little-endian. This means the least significant byte is given first and the most significant byte last:

```
7576647976
```

Note that `0x` to represent the hex is not necessary and will result in the wrong answer if submitted. Each hex character represents $4$ bits, and every $2$ hex characters represent a byte, which is why we are not completely reversing the whole hex string (ie. not answering as `576746...`).

After this, the program requests the input in big-endian. This is left-to-right as we read it:

```
7679647675
```

We are then given the flag.

Solution: **picoCTF{3ndi4n_sw4p_su33ess_02999450}**

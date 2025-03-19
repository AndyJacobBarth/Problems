This challenge has a .png file. Opening it reveals a QR code.

We can scan the QR code several ways, the most popular by phone. An alternative is using a website. At the time of this writing, I was able to find https://qrscanner.net/. Uploading the image there reveals the flag.

It's notable to mention that QR codes can be malicious. It's innocent enough to scan, which is why I prefer using a website over the phone. The white and black squares represents 1's and 0's that translate into text. There are many resources to further understand this process.

There is a tool built into the box if an internal resource is preferred. This is likely the intended way, and can be done via the command `zbarimg flag.png` to get the flag.

Solution: **picoCTF{p33k_@_b00_19eccd10}**
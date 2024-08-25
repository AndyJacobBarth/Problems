# [Crack the Hash](https://tryhackme.com/r/room/crackthehash)

A simple room that asks us to crack multiple hashes. We will use our own Kali Linux box. hashID and hashcat will help tremendously here. Note that hashID will show multiple values. The context of this exercise strongly indicates more popular encryption will be used.

## Task 1
### 48bb6e862e54f2a795ffc4e541caed4d

```
hashid 48bb6e862e54f2a795ffc4e541caed4d
```
  
- Results return `MD2, MD5, MD4, ...` This is likely MD5.

`hashcat --help | grep MD5`
- We can see parameter value for MD5 is 0.
  
`hashcat -m 0 48bb6e862e54f2a795ffc4e541caed4d --show`  
- Result: <b>easy</b>


### CBFDAC6008F9CAB4083784CBD1874F76618D2A97
`hashid CBFDAC6008F9CAB4083784CBD1874F76618D2A97`  
- Results strongly indicate SHA-1 is used here.  
  
`hashcat --help | grep SHA`  
- SHA-1 is 100  for hashcat.

`hashcat -m 100 CBFDAC6008F9CAB4083784CBD1874F76618D2A97 --show`  
- <b>password123</b>

### 1C8BFE8F801D79745C4631D09FFF36C82AA37FC4CCE4FC946683D7B336B63032
`hashid 1C8BFE8F801D79745C4631D09FFF36C82AA37FC4CCE4FC946683D7B336B63032`  
- Results strongly indicate SHA-256 is used here.
  
`hashcat --help | grep SHA`  
- SHA256 is 1400  for hashcat.
  
`hashcat -m 1400 1C8BFE8F801D79745C4631D09FFF36C82AA37FC4CCE4FC946683D7B336B63032 --show`  
- Result: <b>letmein</b>

### $2y$12$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom
`hashid \$2y\$12\$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom`  
- Results show this is bcrypt/Blowfish. Note that escape characters are needed for each '$'.
  
`hashcat --help | grep bcrpyt`  
- BCrypt is 3200.  

`hashcat -m 3200 \$2y\$12\$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom --show`  
- Result: <b>bleh</b>

### 279412f945939ba78ce0758d3fd83daa
`hashid 279412f945939ba78ce0758d3fd83daa`  
- This appears much like the first hash, so we would suspect MD5.
  
Attempting this attack with MD5 will have no results. Even attempting wordlists does not work. We should start suspecting different hash methods. MD4 is also listed and is fairly common.  

`hashcat --help | grep MD4`  
- MD4 is 900.  
  
`hashcat -m 900 279412f945939ba78ce0758d3fd83daa --show`  
- No results still.

In fact, this hash is not possible to crack within built-in wordlists for Kali Linux. We will see why after getting the result. To get the password, use an online MD4 hash cracker. dCode is a reliable source, and will provide the answer.  
- Result: <b>Eternity22</b>

Sources online don't give a sufficient answer as to why this specific problem is so arbitrarily hard compared to the rest of the CTF. MD4/MD5 hashes have no algorithmic way to crack, and a rainbow table must be utilized. So a wordlist must be used, but the following command proves we would never be able to crack this with any wordlist:  
`grep -r "Eternity22" /usr/share/wordlists/`  
However, search for "Eternity2" and you'll see very similar results:  
`grep -r "Eternity2" /usr/share/wordlists/`  
- rockyou.txt has both Eternity2 and Eternity23, among others.

If you make the MD4 hash for Eternity23 - 70f5ccf7520f8a599a16965e5d5fd80c - under hashcat for the rockyou.txt, it will work (Ironically, dCode cannot find this hash):  
`hashcat -a -0 -m 900 70f5ccf7520f8a599a16965e5d5fd80c /usr/share/wordlists/rockyou.txt --show`  
This is the only hash in the list requiring an outside source from Kali Linux, and I suspect this to be a typo from the CTF creator before they hashed it.

## Task 2
The following set is guaranteed to crack with the 'rock you' password list.

### F09EDCB1FCEFC6DFB23DC3505A882655FF77375ED8AA2D1C13F640FCCC2D0C85#

### 1DFECA0C002AE40B8619ECF94819CC1B

### Hash: $6$aReallyHardSalt$6WKUTqzq.UQQmrm0p/T7MPpMbGNnzXPMAXi4bJMl9be.cfi3/qxIf.hsGpS41BqMhSrHVXgMpdjS6xeKZAs02.
### Salt: aReallyHardSalt


### Hash: e5d8870e5bdd26602cab8dbe07a942c8669e56d6
### Salt: tryhackme

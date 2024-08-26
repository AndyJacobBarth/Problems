# [Crack the Hash](https://tryhackme.com/r/room/crackthehash)

A simple room that asks us to crack multiple hashes. We will use our own Kali Linux box. hashID and hashcat will help tremendously here. Note that hashID will show multiple values. The context of this exercise strongly indicates more popular encryption will be used. Hashcat can be used in place of hashID by using `hashcat <hash>`, which will provide an error message with suggested hashing algorithms to check against.  

When we find the encryption algorithm used, we will turn to a rainbow table attack. With a plaintext password list, we can hash each one and compare to the hash we're trying to crack. If it's a match, we're in. We'll use the rockyou.txt file. While it's only specified to work in Task 2, it should be enough for the first few tasks too.  Since TryHackMe gives you the number of characters for each solution, you can create a filtered rockyou.txt file with only matching string length passwords to speed up your searches.

In theory, there can be a match even if the password we're using isn't the original, called a collision. Collisions are considered rare, and while usually a good thing for an adversary, this exerise wants us to get the original password, regardless if the one we found has a matching hash. Fortunately, collisions should be of no concern for this CTF.

## Task 1
<details>
<summary> <b>Hash: 48bb6e862e54f2a795ffc4e541caed4d</b> </summary>
First, let's identify this bad boy.

```
$ hashid 48bb6e862e54f2a795ffc4e541caed4d  
Analyzing '48bb6e862e54f2a795ffc4e541caed4d'
[+] MD2 
[+] MD5 
[+] MD4
...
```

There are several results, with the more likely ones near the top. Common hashes are MD5 and MD4, so we will try these first. Hashcat uses a specific number for each hashing method, so let's search for it.

```
$ hashcat --help | grep MD5
      0 | MD5                                                        | Raw Hash
...
```

There's a lot of different variations of MD5 depending on our needs, but the simplest version should be sufficient. Now we can crack.

```
$ hashcat -a 0 -m 0 48bb6e862e54f2a795ffc4e541caed4d /usr/share/wordlists/rockyou.txt 
hashcat (v6.2.6) starting
...
Dictionary cache hit:
* Filename..: /usr/share/wordlists/rockyou.txt
* Passwords.: 14344385
* Bytes.....: 139921507
* Keyspace..: 14344385

48bb6e862e54f2a795ffc4e541caed4d:easy                     
                                                          
Session..........: hashcat
Status...........: Cracked
...
```

Result: <b>easy</b>  

Note: If you ever want to see cracked hashes, hashcat saves a potfile with each one. You can specify the path using `hashcat -a <attack> -m <method> <hash> <wordlist> --potfile-path <path>`. The default location is /home/User/.local/share/hashcat/hashcat.potfile.

</details>

<details>
<summary><b>Hash: CBFDAC6008F9CAB4083784CBD1874F76618D2A97</b></summary>
Round two baby. bring it.

```
$ hashid CBFDAC6008F9CAB4083784CBD1874F76618D2A97
Analyzing 'CBFDAC6008F9CAB4083784CBD1874F76618D2A97'
[+] SHA-1 
[+] Double SHA-1
...
```

Okay cool, this is more than likely a SHA-1 hash. Let's search for this, being aware that our search is case-sensitive.

```
$ hashcat --help | grep SHA                           
    100 | SHA1                                                       | Raw Hash
...
```

First result is the best result. Now just do the same as before.

```
$ hashcat -a 0 -m 100 CBFDAC6008F9CAB4083784CBD1874F76618D2A97 /usr/share/wordlists/rockyou.txt 
hashcat (v6.2.6) starting
...
cbfdac6008f9cab4083784cbd1874f76618d2a97:password123
...
```

Result: <b>password123</b>

</details>
<details>
<summary> <b>Hash: 1C8BFE8F801D79745C4631D09FFF36C82AA37FC4CCE4FC946683D7B336B63032</b> </summary>
We're getting in the groove of things. Let's do the same SHAbang (get it?).

```
$ hashid 1C8BFE8F801D79745C4631D09FFF36C82AA37FC4CCE4FC946683D7B336B63032
Analyzing '1C8BFE8F801D79745C4631D09FFF36C82AA37FC4CCE4FC946683D7B336B63032'
[+] Snefru-256 
[+] SHA-256
...
```  

SHA-256 is way more well-known than Snefru, so that's likely our best bet. HashID has a tendency to be completely wrong on its top result. Not sure why Snefru is so high up, a quick Google search indicates it's not common nor feasible to use. Sorry Snefru.
  
```
$ hashcat --help | grep SHA
    100 | SHA1                                                       | Raw Hash
   1300 | SHA2-224                                                   | Raw Hash
   1400 | SHA2-256                                                   | Raw Hash
...
$ hashcat -a 0 -m 1400 1C8BFE8F801D79745C4631D09FFF36C82AA37FC4CCE4FC946683D7B336B63032 /usr/share/wordlists/rockyou.txt
... 
1c8bfe8f801d79745c4631d09fff36c82aa37fc4cce4fc946683d7b336b63032:letmein
...
```
  
Result: <b>letmein</b>

</details>
<details>
<summary> <b>Hash: $2y$12$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom</b> </summary>
Alright, same song and dance, this'll be...

```
$ hashid $2y$12$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom 
Analyzing 'y'
[+] Unknown hash
```
[Death Note theme plays]  
Alright script kiddie, before you throw in the towel, let's stop and think about this. If you really know your hashes, a `$2<a/b/x/y>$` in the beginning strongly indicates bcrypt/Blowfish, and I promise you this is a legit hash. An error indicates there's probably some issue reading the hash. If you put $20 that it's because of the '$'s, you're correct. We need to put escape characters '\\' before them. Congrats on your \\$20.  

Fun fact: Github's markdown requires the same exact escape characters, so I have to put even more escape characters just to show the escape character.

```
$ hashid \$2y\$12\$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom  
Analyzing '$2y$12$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom'
[+] Blowfish(OpenBSD) 
[+] Woltlab Burning Board 4.x 
[+] bcrypt
$ hashcat --help | grep bcrypt 
   3200 | bcrypt $2*$, Blowfish (Unix)                               | Operating System
...
$ hashcat -a 0 -m 3200 \$2y\$12\$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom /usr/share/wordlists/rockyou.txt
...
$2y$12$Dwt1BZj6pcyc3Dy1FWZ5ieeUznr71EeNkJkUlypTsgbX1H68wsRom:bleh
...
```

Result: <b>bleh</b>

</details>
<details>
<summary> <b>Hash: 279412f945939ba78ce0758d3fd83daa</b> </summary>
Okay, this one appears simple, but there's a kicker. Let's begin.

```
$ hashid 279412f945939ba78ce0758d3fd83daa
Analyzing '279412f945939ba78ce0758d3fd83daa'
[+] MD2 
[+] MD5 
[+] MD4 
...
```

Now, beyond this point it gets hard. Let me tell you, I both like and don't like this problem. I don't like it because you won't find the solution with built-in Kali wordlists. You have to get a wordlist that happens to have the right password. This makes no sense, because the classic rockyou.txt built into Kali Linux should suffice. In fact, the second half of the CTF explicitly states the rockyou.txt file is enough. So for an entry level CTF, you don't have the tools in your attack box to solve it. Whack.  

On the other side, I like this problem BECAUSE you don't have the tools in your attack box to solve it. In the real world or just more advanced CTFs, you might need to get creative. Trying external wordlists or using an online tool with pre-downloaded wordlists will work if they happen to have the password in their list. dCode is a useful website that contains the correct password. Even so, you'll be left trying to check instances of MD5, MD4, and maybe even the other options if you get unlucky and don't get results from MD4 right away. It's a lot of time wasting simply because you're not equipped with the right wordlist.

If you have enough time, you can try brute force, utilizing the fact that only uppercase, lowercase, and numbers have been used (26 + 26 + 10 = 62), along with TryHackMe providing the exact amount of characters the password contains (10). This would technically work, but there's no guarantee special characters aren't used, and if you did it this way, you have 62^10 ~ 10^17 combinations to try. Assuming 1 billion (10^9) guesses per second, it'll take you 10^8 seconds to guess, which comes down to a little over 3 years. Good luck.  
  
Result: <b>Eternity22</b>

If you can't tell, I've spiraled into a rabbit hole of finding out why this answer was so hard to find. Other writeups for this all pretty much say they failed cracking it and just used a random website to crack it. I wasn't satisfied with that, so join me in this quick post-analysis.  

Let's prove the answer was not in any of our built-in wordlists:

```
grep -r "Eternity22" /usr/share/wordlists/

```

You see that white space of shame that screams 'No results'? We were hopeless from the start. Let's search for 'Eternity2' and see what pops up:

```
$ grep -r "Eternity2" /usr/share/wordlists/
/usr/share/wordlists/rockyou.txt:LoveForEternity2
/usr/share/wordlists/rockyou.txt:LoveEternity2
/usr/share/wordlists/rockyou.txt:Eternity23
/usr/share/wordlists/rockyou.txt:Eternity2
```

Looks like 'Eternity2' and 'Eternity23' were in our wordlist. Unfortunately, a change in just one character makes a completely different hash, so if we don't have exactly the right password, we would have no way of knowing how close we were when checking these entries. This leads me to suggest that possibly the CTF creator made a typo and hashed 'Eternity22' instead of 'Eternity23' for the problem.  

A more likely cause is that the CTF creator had a more advanced wordlist at their disposal. There are updated versions of the rockyou.txt file, and from downloading multiple different versions and probably some malware along the way, I can confirm that 'Eternity22' does indeed pop up in some of them. I'm still willing to bet the difficulty this has made this particular problem was unintentional.
</details>

## Task 2
The following set is guaranteed to crack with the 'rock you' password list.

<details>
<summary> <b>Hash: F09EDCB1FCEFC6DFB23DC3505A882655FF77375ED8AA2D1C13F640FCCC2D0C85</b> </summary>

```
$ hashid F09EDCB1FCEFC6DFB23DC3505A882655FF77375ED8AA2D1C13F640FCCC2D0C85
Analyzing 'F09EDCB1FCEFC6DFB23DC3505A882655FF77375ED8AA2D1C13F640FCCC2D0C85'
[+] Snefru-256 
[+] SHA-256
...
$ hashcat --help | grep SHA    
    100 | SHA1                                                       | Raw Hash
   1300 | SHA2-224                                                   | Raw Hash
   1400 | SHA2-256                                                   | Raw Hash
...
$ hashcat -a 0 -m 1400 F09EDCB1FCEFC6DFB23DC3505A882655FF77375ED8AA2D1C13F640FCCC2D0C85 /usr/share/wordlists/rockyou.txt
...
f09edcb1fcefc6dfb23dc3505a882655ff77375ed8aa2d1c13f640fccc2d0c85:paule
...
```

Result: <b>paule</b>

EZ-PZ. Next one.  

</details>
<details>
<summary> <b>Hash: 1DFECA0C002AE40B8619ECF94819CC1B</b> </summary>

```
$ hashid 1DFECA0C002AE40B8619ECF94819CC1B                                          
Analyzing '1DFECA0C002AE40B8619ECF94819CC1B'
[+] MD2 
[+] MD5 
[+] MD4 
[+] Double MD5 
[+] LM 
[+] RIPEMD-128 
[+] Haval-128 
[+] Tiger-128 
[+] Skein-256(128) 
[+] Skein-512(128) 
[+] Lotus Notes/Domino 5 
[+] Skype 
[+] Snefru-128 
[+] NTLM 
...
```

Why did I show a more expansive list this time? Well, if you attempt down the list, you'll see we exhaust the rockyou.txt file on MD2, MD5, MD4, and so on until we try NTLM. This is simply trial-and-error, but since we know the rockyou.txt file absolutely works, we're motivated to try more obscure hashing methods rather than subjecting to attempting brute-force or external wordlists on the more popular ones.

```
$ hashcat -a 0 -m 1000 1DFECA0C002AE40B8619ECF94819CC1B /usr/share/wordlists/rockyou.txt
...
1dfeca0c002ae40b8619ecf94819cc1b:n63umy8lkf4i
...
```

Result: <b>n63umy81kf4i</b>

</details>
<details>
<summary> <b>Hash: $6$aReallyHardSalt$6WKUTqzq.UQQmrm0p/T7MPpMbGNnzXPMAXi4bJMl9be.cfi3/qxIf.hsGpS41BqMhSrHVXgMpdjS6xeKZAs02.  

Salt: aReallyHardSalt</b> </summary>

Remember, we should use escape characters wherever the hash interpretation may fail. Also, a salt is provided, but we can see it already embedded in the hash, as some formats do. We can treat this as a normal hash.

```
$ hashid \$6\$aReallyHardSalt\$6WKUTqzq.UQQmrm0p/T7MPpMbGNnzXPMAXi4bJMl9be.cfi3/qxIf.hsGpS41BqMhSrHVXgMpdjS6xeKZAs02.
Analyzing '$6$aReallyHardSalt$6WKUTqzq.UQQmrm0p/T7MPpMbGNnzXPMAXi4bJMl9be.cfi3/qxIf.hsGpS41BqMhSrHVXgMpdjS6xeKZAs02.'
[+] SHA-512 Crypt 
$ hashcat --help | grep SHA512
   1750 | HMAC-SHA512 (key = $pass)                                  | Raw Hash authenticated
   1760 | HMAC-SHA512 (key = $salt)                                  | Raw Hash authenticated
  12100 | PBKDF2-HMAC-SHA512                                         | Generic KDF
  27300 | SNMPv3 HMAC-SHA512-384                                     | Network Protocol
  19200 | QNX /etc/shadow (SHA512)                                   | Operating System
  22200 | Citrix NetScaler (SHA512)                                  | Operating System
   7100 | macOS v10.8+ (PBKDF2-SHA512)                               | Operating System
   1800 | sha512crypt $6$, SHA512 (Unix)                             | Operating System
...
$ hashcat -a 0 -m 1800 \$6\$aReallyHardSalt\$6WKUTqzq.UQQmrm0p/T7MPpMbGNnzXPMAXi4bJMl9be.cfi3/qxIf.hsGpS41BqMhSrHVXgMpdjS6xeKZAs02. /usr/share/wordlists/rockyou.txt 
...
$6$aReallyHardSalt$6WKUTqzq.UQQmrm0p/T7MPpMbGNnzXPMAXi4bJMl9be.cfi3/qxIf.hsGpS41BqMhSrHVXgMpdjS6xeKZAs02.:waka99
...
...
```

This one takes a lot of computing power, so be patient. As mentioned in the beginning, you can run it through a filtered rockyou.txt file since TryHackMe specifies the solution's length: `awk 'length($0) == 6' /usr/share/wordlists/rockyou.txt > rockyou_length_6.txt`.  
Result: <b>waka99</b>

</details>
<details>
<summary> <b>Hash: e5d8870e5bdd26602cab8dbe07a942c8669e56d6  

Salt: tryhackme </b> </summary>

This one does not have the salt in the hash. We will need to specify it. Hashcat does this using ':' between the hash and salt.

```
$ hashid e5d8870e5bdd26602cab8dbe07a942c8669e56d6                                                                                           
Analyzing 'e5d8870e5bdd26602cab8dbe07a942c8669e56d6'
[+] SHA-1 
...
$ hashcat --help | grep SHA1                                                                                                                
    100 | SHA1                                                       | Raw Hash
    150 | HMAC-SHA1 (key = $pass)                                    | Raw Hash authenticated
    160 | HMAC-SHA1 (key = $salt)                                    | Raw Hash authenticated
...
$ hashcat -a 0 -m 160 e5d8870e5bdd26602cab8dbe07a942c8669e56d6:tryhackme /usr/share/wordlists/rockyou.txt
...
e5d8870e5bdd26602cab8dbe07a942c8669e56d6:tryhackme:481616481616
...
```

Result: <b>481616481616</b>  

Note that since a salt is required, we went with 160. This is indicative by the "key=\$salt" phrasing.
</details>
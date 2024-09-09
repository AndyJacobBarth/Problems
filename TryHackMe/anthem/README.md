# [Anthem](https://tryhackme.com/r/room/anthem)

<details>
<summary> <b>Let's run nmap and check what ports are open.</b> </summary>  

Okay cool, easy. We can be as loud as we want, so let's just run a simple Nmap scan:  

![alt text](image.png)

The scan I decided to do gives a lot of details (literally A for 'Aggressive') that does OS scanning, version scanning, script scanning, and traceroute. It may be a bit overkill, and OS scanning (-O) and version scanning (-sV) would likely be more than enough alone, and can take less time for Nmap to run.
</details>

<details>
<summary> <b>What port is for the web server?</b> </summary>  

Easy again. We see the answer prompts for two digits, and even without scanning we could guess the standard port $80$. Indeed, from our results on the previous problem, this is the case.

Solution: **$80$**
</details>

<details>
<summary> <b>What port is for remote desktop service?</b> </summary>  

Again, we got this answer from the first question. The standard port number is $3389$, and we can confirm this from our port scan where we see 'Microsoft Terminal Services'.

Solution: **$3389$**
</details>

<details>
<summary> <b>What is a possible password in one of the pages web crawlers check for?</b> </summary>
</details>

<details>
<summary> <b>What CMS is the website using?</b> </summary>
</details>

<details>
<summary> <b>What is the domain of the website?</b> </summary>  

You can easily extract this while you're painfully waiting for the website to load. Simply enter the attack box's IP in the URL and you can see it in as the title within the browser tab:  

![alt text](image-1.png)

Solution: **Anthem.com**
</details>

<details>
<summary> <b>What's the name of the Administrator</b> </summary>
</details>

<details>
<summary> <b>Can we find find the email address of the administrator?</b> </summary>
</details>

<details>
<summary> <b>What is flag 1?</b> </summary>
</details>

<details>
<summary> <b>What is flag 2?</b> </summary>
</details>

<details>
<summary> <b>What is flag 3?</b> </summary>

This flag can be found by stumbling around the 'author' section of the website. Navigate to `http://<IP>/authors/jane-doe`, which can be navigated naturally through the links on the site, and you'll see the following:  

![alt text](image-2.png)

Solution: **THM{L0L_WH0_D15}**
</details>

<details>
<summary> <b></b> </summary>
</details>

<details>
<summary> <b></b> </summary>
</details>

<details>
<summary> <b></b> </summary>
</details>
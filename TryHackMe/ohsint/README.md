# [OhSINT](https://tryhackme.com/r/room/ohsint)

We are provided with an image file and must gather as much intelligence on it as possible. There are multiple tools to our disposal, and even online tools will help. After all, this is an OSINT challenge. Good practice would be to download this on a VM or container.

<details>
  <summary><b>What is this user's avatar of?</b></summary>
  This question seems a bit odd, but it's getting right to the meat of the challenge. We only have an image of Windows XP to go off of, so let's look at the metadata. I found a size called ezgif that works fine. Here's everything provided:  

```
ExifTool Version Number	12.72
File Name	ezgif-3-49e9158406.jpg
Directory	.
File Size	234 kB
File Modification Date/Time	2024:08:26 18:20:39+02:00
File Access Date/Time	2024:08:26 18:20:39+02:00
File Inode Change Date/Time	2024:08:26 18:20:39+02:00
File Permissions	-rw-r--r--
File Type	JPEG
File Type Extension	jpg
MIME Type	image/jpeg
XMP Toolkit	Image::ExifTool 11.27
GPS Latitude	54 deg 17' 41.27" N
GPS Longitude	2 deg 15' 1.33" W
Copyright	OWoodflint
Image Width	1920
Image Height	1080
Encoding Process	Baseline DCT, Huffman coding
Bits Per Sample	8
Color Components	3
Y Cb Cr Sub Sampling	YCbCr4:2:0 (2 2)
GPS Latitude Ref	North
GPS Longitude Ref	West
GPS Position	54 deg 17' 41.27" N, 2 deg 15' 1.33" W
Image Size	1920x1080
Megapixels	2.1
```

GPS coordinates are interesting, but we also see an interesting copyright by OWoodflint. Let's check out who that is.  
A Google search shows an interesting Twitter account that looks like it was made specifically for a CTF. It has an avatar of a cat. Hmmm...  
Solution: <b>cat</b>
</details>
<details>
  <summary><b>What city is this person in?</b></summary>
  Well, the Twitter account says their location is in "Space". So this person has a little OpSec. I don't have a Twitter account, so I can't view any more details. We can try using an OSINT tool to extract more locations from OWoodflint, and certainly by using the online OSINT Tool Emails & Usernames, we can be redirected to a plethura of OSINT tools. One of these is Social Searcher, and looking up 'OWoodflint' extracts a GitHub page they made:  

```
  people_finder
Hi all, I am from London, I like taking photos and open source projects.

Follow me on twitter: @OWoodflint

This project is a new social network for taking photos in your home town.

Project starting soon! Email me if you want to help out: OWoodflint@gmail.com

https://oliverwoodflint.wordpress.com/
```

Remember when I said this guy has a little bit of OpSec? Throw that out the window.  
Solution: <b>London</b>
</details>
<details>
  <summary><b>What is the SSID of the WAP he connected to?</b></summary>
  One of his tweets is literally his BSSID. We can use WiGLE.net to search for it, but with a lot of abuse for using this site for OSINT, we do need to create an account. When you're able to obtain access, entering the BSSID from his Twitter - B4:5D:50:AA:86:41 - and using the map to navigate lat and long coordinates to the London area, you can zoom in on the purple indicator to get the SSID:  
  
![image](https://github.com/user-attachments/assets/c0f0667c-f532-4738-b5ae-a1b5d9470aee)  
  
Solution: <b>UnileverWifi</b>
</details>
<details>
  <summary><b>What is his personal email address?</b></summary>
  The guy who made this CTF appears to be working backwards now. We already got this info from their GitHub.  
  
Solution: <b>OWoodflint@gmail.com</b>
</details>
<details>
  <summary><b>What site did you find his email address on?</b></summary>
  This would've been a great earlier question. This is just a freebie.  
  
Solution: <b>Github</b>
</details>
<details>
  <summary><b>Where has he gone on holiday?</b></summary>
  This one is not too much harder. From the GitHub page, we see a WordPress site - https://oliverwoodflint.wordpress.com/. Here we get that they left for New York.  
  
Solution: <b>New York</b>
</details>
<details>
  <summary><b>What is the person's password?</b></summary>
  This one is just kind of weird. On the WordPress page, there is invisible text 'pennYDr0pper.!', which looks like a password. Why anyone would do this, I'm not sure. It's only white text, so you can highlight the page and find it. Alternatively, you can inspect the page with Developer's Tools. I was able to find it using OSINT Tools, where the GitHub page was displayed, and it showed all text regardless of formatting, including the password.  
  
Solution: <b>pennYDr0pper.!</b>
</details>

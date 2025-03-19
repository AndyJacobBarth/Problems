This problem wants us to find the correct file that has the checksum provided to us in `checksum.txt`. It gives us a program `decrypt.sh` that will do this for us.

The beginning of this challenge walks through how to SSH into the system. This write-up will not get into that.

We are given that the checksum is a SHA-256 hash, and even better we get a decrypt tool. This box comes with the `sha256sum` command, so not sure why we need `decrypt.sh`. Let's check out what this tool does:

```
cat decrypt.sh
```

From this, there's some error handling, then there's the part that we're really concerned about:

```
if ! openssl enc -d -aes-256-cbc -pbkdf2 -iter 100000 -salt -in "/home/ctf-player/drop-in/$file_name" -k picoCTF; then
    echo "Error: Failed to decrypt '$file_name'. This flag is fake! Keep looking!"
fi
```

It looks like we're actually dealing with AES-256 CBC, another form of encryption, based on the argument `-aes-256-cbc`. We also see that it takes 100,000 iterations and uses PBKDF2, which to my understanding adds complexity to the encryption, as with adding a random salt using `-salt` and finally the key `picoCTF`.

That's cool and all, but honestly not necessary to solve. 

Still, looking in the `files` directory, there's a lot of files. So we should automate this process to make our lives easier. We can do this with the following:

```
for file in "./files/*"; do
    decrypt.sh $file;
done
```

Putting this into Bash, we get a bunch of Error messages. Between all of them, however, is the flag we desire.

A more elegant, and likely intended, solution is to compare the SHA-256 hash of each file with the contents of `checksum.txt`. If there's a match, we can then use `decrypt.sh`. The code would look like the following:

```
for file in files/*; do
    if [[ "$(awk '{ print $1 }' checksum.txt )" == "$(sha256sum $file | awk '{ print $1 }' )" ]]; then
        decrypt.sh $file;
    fi
done
```

Solution: **picoCTF{trust_but_verify_8eee7195}**